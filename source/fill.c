#include <qinka_cs/buffer/fill.h>
#include <config.h>
#include <math.h>
#include <stdlib.h>

#if ACC_REGION == OACC_ONLY
#pragma acc routine(rand) seq
#endif



void fill_N_scalar(float *A, float s, int n) {
    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(A, n, s)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(A, n, s)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            A[i] = s;
    }
}
void fill_HW_eye(float *A, int h) {
    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(A, h)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(A, h)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(A[0:h*h])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(A)
    #endif
    {
        int i, j;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < h; i++)
            #if ACC_LOOP == OACC_ENABLE
            #pragma acc loop
            #endif
            for (j = 0; j < h; j++)
                A[i * h + j] = (float)(i == j);
    }
}

#if ACC_REGION == OACC_DRVPTR
#include <curand.h>
#define CURAND_CALL(x) do { if((x)!=CURAND_STATUS_SUCCESS) { \
    printf("Error at %s:%d\n",__FILE__,__LINE__);\
    return ;}} while(0)
void fill_N_random(float *devA, int n) {
    curandGenerator_t gen;
    CURAND_CALL(curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_DEFAULT));
    CURAND_CALL(curandGenerateUniform(gen, devA, n));
}
#else
void fill_N_random(float *A, int n) {
    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc loop
        #endif
        for (i = 0; i < n; i++) {
            A[i] = (float)rand() * 0.999998f + 0.000001f;
        }
    }
}
#endif
