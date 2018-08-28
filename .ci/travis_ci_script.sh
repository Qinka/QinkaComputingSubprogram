#!/bin/bash

# Copyright (C) 2018 Johann Lee <me@qinka.pro>
## Command
function common_init() {
    echo
    echo Pre-install
    echo

    echo Fetching the system\' name
    export OS_CORENAME=$(lsb_release -c | awk '{print $2}')
    export OS_DISTRIBUTOR=$(lsb_release -i | awk '{print $3}')
    echo Using $OS_DISTRIBUTOR $OS_CORENAME for building

    export APT=apt-get
    echo Updating $APT source
    sudo $APT update
}


## Qinka Computing Subprogram
function qinkacs_init() {
    echo
    echo Init for Qinka Computing Subprogram
    echo
    echo Build gtest
    cd /usr/src/gtest/
    sudo cmake -DCMAKE_INSTALL_PREFIX=/usr/ .
    sudo make
    sudo find .
}

function qinkacs_build() {
    echo
    echo build Qinka Computing Subprogram
    cd $TRAVIS_BUILD_DIR
    mkdir build
    cd build
    export QCS_BUILD_DIR=`pwd`

    local TEST_STATUS ACC_CMAKE_FLAGS
    # test enable
    if [ -n "$RUN_TEST" ]; then
        TEST_STATUS=On
    else
        TEST_STATUS=Off
    fi

    case $ACC_BACKEND in
        OpenMP)
            ACC_CMAKE_FLAGS="-DENABLE_OPENMP=On"
            ;;
        OpenMP-target)
            ACC_CMAKE_FLAGS="-DENABLE_OPENMP=On -DENABLE_OPENMP_TARGET=On"
            ;;
        OpenACC)
            ACC_CMAKE_FLAGS="-DENABLE_OPENMP=Off -DENBALE_OPENACC=On"
            ;;
        *)
            ACC_CMAKE_FLAGS="-DENABLE_OPENMP=Off"
            ;;
    esac


    cmake -DBUILD_TESTS=$TEST_STATUS $ACC_CMAKE_FLAGS -DGTEST_ROOT=/usr/src/gtest ..
    cmake --build .

    cd $TRAVIS_BUILD_DIR
}

function qinkacs_test() {
    echo
    echo Run testing of Qinka Computing Subprogram
    cd $QCS_BUILD_DIR
    ctest -V
}

function qinkacs_succ() {
    echo "Nothing to do"
}

## hQinkaCS
function hQinkaCS_init() {
    sudo $APT install -y ghc-$GHC_VER 

    if [ -n "$LLVM" ]; then
        echo
        echo Using llvm-$LLVM
        echo
        sudo $APT install -y lldb-$LLVM llvm-$LLVM llvm-$LLVM-dev llvm-$LLVM-runtime
    fi

    #
    # I was planning enable the CUDA test, but the Travis-CI do not support such things.
    # So it's abandoned now.
    #
    if [ -n "$CUDA" ]; then
        echo CUDA should be disable.
        exit 3
    fi

    echo Setting up ghc-$GHC_VER
    export PATH=/opt/ghc/$GHC_VER/bin:$PATH
    ghc -V

    mkdir -p $HOME/.local/bin
    export PATH=$HOME/.local/bin:$PATH
    travis_retry curl -L https://www.stackage.org/stack/linux-x86_64 | tar xz --wildcards --strip-components=1 -C ~/.local/bin '*/stack'


    echo Configuring
    stack config set system-ghc --global true
    qinkacs_init
}

function hQinkaCS_build() {
    echo hQinkaCS task
    ## LLVM
    if [ -n "$LLVM" ]; then
        echo Enable LLVM
        export X_LLVM_FLAGS=" --ghc-options -fllvm --ghc-options -pgmlo --ghc-options opt-$LLVM --ghc-options -pgmlc --ghc-options llc-$LLVM "
    fi

    ## THREADED
    if [ -n "$THREADED" ]; then
        echo Enable -threaded
        export X_THREADED_FLAGS=" --ghc-options -threaded --ghc-options -with-rtsopts=-N "
    fi 

    ## 
    if [ -n "$DEBUG" ]; then
        echo Enable debug
        export X_DEBUG_FLAGS=" --ghc-options -rtsopts=all --ghc-options -g"
    else
        export X_DEBUG_FLAGS=" --ghc-options -rtsopts=some --ghc-options --ghc-options --ghc-options -O3"
    fi

    if [ -n "$CUDA" ]; then
        echo Enable CUDA
        export X_CUDA_FLAGS=" "
    else
        echo Disable CUDA
        export X_CUDA_FLAGS=" --flag FAI:-enable-cuda "
    fi

    cd $TRAVIS_BUILD_DIR
    export FLAGS="$X_THREADED_FLAGS $X_LLVM_FLAGS $X_DEBUG_FLAGS $X_CUDA_FLAGS"
    echo Using flags: $FLAGS
    stack build $FLAGS hQinkaCS hQinkaCS-binding
}

function hQinkaCS_test() {
    echo "Nothing to do"
}

function hQinkaCS_succ() {
    echo "Nothing to do"
}