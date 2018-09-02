{-# LANGUAGE CPP                  #-}
{-# LANGUAGE FlexibleContexts     #-}
{-# LANGUAGE FlexibleInstances    #-}
{-# LANGUAGE TemplateHaskell      #-}
{-# LANGUAGE TypeFamilies         #-}
{-# LANGUAGE UndecidableInstances #-}

module Accelerate.QinkaCS.Wrapper
  ( bestContextIO
  , bestContext
  , Wrappered(..)
  , module X
  ) where

import           Foreign.FAI                                   as X
import           Foreign.FAI.Platform.Host                     as X
import           Foreign.FAI.Platform.Host.Debug               as X

import           Accelerate.QinkaCS.BLAS.BasicFunction         as X
import           Accelerate.QinkaCS.BLAS.HyperbolicFunction    as X
import           Accelerate.QinkaCS.BLAS.MatrixFunction        as X
import           Accelerate.QinkaCS.BLAS.TrigonometricFunction as X
import           Accelerate.QinkaCS.Buffer.Fill                as X
import           Accelerate.QinkaCS.CV.ComputerVision          as X
import           Accelerate.QinkaCS.LoadImg                    as X
import           Accelerate.QinkaCS.ML.ActivationFunction      as X
import           Accelerate.QinkaCS.QinkaComputingSubprogram   as X
import           Accelerate.QinkaCS.Tensor                     as X

import           Control.Monad                                 as X
import           Control.Monad.Catch                           as X
import           Control.Monad.Logger                          as X
import           Foreign.Storable                              as X
import           GHC.Stack                                     as X
import           System.Environment                            as X


#ifdef __CUDA_ENABLE
import           Accelerate.QinkaCS.LoadImg.CUDA               as X
import           Foreign.FAI.Platform.CUDA                     as X
import           Foreign.FAI.Platform.CUDA.Debug               as X
#endif

import           Accelerate.QinkaCS.TH                         (mkBestContext)

mkBestContext


class    (LoadSaveImg p, FAI p, ContextLogger p, Storable (Pf p Float)) => Wrappered p

instance (LoadSaveImg p, FAI p, ContextLogger p, Storable (Pf p Float)) => Wrappered p
