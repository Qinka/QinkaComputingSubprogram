{-# LANGUAGE TypeFamilies #-}

module Accelerate.QinkaCS.Buffer.Fill
    ( scale
    , random
    , eye2D
    )where

import           Accelerate.QinkaCS.Binding.Fill
import           Accelerate.QinkaCS.Tensor
import           Foreign.FAI
import           Foreign.Ptr
import           Foreign.Storable

scale :: ( FAI p, Shape sh
         , Storable c, c ~ Pf p Float
         )
      => sh -> Float -> Accelerate p (Ten sh p)
scale sh s = do
  buf <- newBuffer sh
  liftIO $ withBuffer' buf $ \p ->
    fill_N_scalar p s $ shLen sh
  return buf

eye2D :: (FAI p , Storable c, c ~ Pf p Float)
        => Int -> Accelerate p (Ten DIM2 p)
eye2D i = do
  buf <- newBuffer $ Z :. i :. i
  liftIO $ withBuffer buf $ \p ->
    fill_HW_eye (castPtr p) i
  return buf

random :: ( FAI p, Shape sh
          , Storable c, c ~ Pf p Float
          )
       => sh -> Accelerate p (Ten sh p)
random sh = do
  buf <- newBuffer sh
  liftIO $ withBuffer' buf $ \p ->
    fill_N_random p $ shLen sh
  return buf
