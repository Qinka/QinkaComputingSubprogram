{-# LANGUAGE TypeFamilies #-}

module Accelerate.QinkaCS.BLAS.MatrixFunction where

import           Accelerate.QinkaCS.Binding.MatrixFunction
import           Accelerate.QinkaCS.Tensor
import           Control.Monad
import           Foreign.FAI
import           Foreign.Ptr
import           Foreign.Storable

hwForwardMul :: (FAI p, Storable c, c ~ Pf p Float)
             => Ten DIM2 p -- | A
             -> Ten DIM2 p -- | B
             -> Accelerate p (Ten DIM2 p)
hwForwardMul b1 b2 = Accelerate $ \cc -> do
  let Z :. m  :. n = getBufferShape b1
      Z :. n' :. s = getBufferShape b2
  when (n /= n') $ error "shape error"
  (outB, cc') <- newBufferIO (Z :. m :. s) cc
  withBuffer' b1 $ \p1 -> withBuffer' b2 $ \p2 -> withBuffer' outB $ \po ->
    forward_HW_mul2D po p1 p2 m n s
  return (outB, cc')


hwBackwardMulA :: (FAI p, Storable c, c ~ Pf p Float)
               => Ten DIM2 p -- | dC
               -> Ten DIM2 p -- |  B
               -> Accelerate p (Ten DIM2 p)
hwBackwardMulA b1 b2 = Accelerate $ \cc -> do
  let Z :. m :. s  = getBufferShape b1
      Z :. n :. s' = getBufferShape b2
  when (s /= s') $ error "shape error"
  (outB, cc') <- newBufferIO (Z :. m :. s) cc
  withBuffer' b1 $ \p1 -> withBuffer' b2 $ \p2 -> withBuffer' outB $ \po ->
    backward_HW_mul2D_A po p1 p2 m n s
  return (outB, cc')

hwBackwardMulB :: (FAI p, Storable c, c ~ Pf p Float)
               => Ten DIM2 p -- |  A
               -> Ten DIM2 p -- | dC
               -> Accelerate p (Ten DIM2 p)
hwBackwardMulB b1 b2 = Accelerate $ \cc -> do
  let Z :. m  :. n = getBufferShape b1
      Z :. m' :. s = getBufferShape b2
  when (m /= m') $ error "shape error"
  (outB, cc') <- newBufferIO (Z :. m :. s) cc
  withBuffer' b1 $ \p1 -> withBuffer' b2 $ \p2 -> withBuffer' outB $ \po ->
    backward_HW_mul2D_B po p1 p2 m n s
  return (outB, cc')
