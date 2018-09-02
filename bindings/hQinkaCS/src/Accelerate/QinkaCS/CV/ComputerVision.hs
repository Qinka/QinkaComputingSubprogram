{-# LANGUAGE TypeFamilies  #-}
{-# LANGUAGE TypeOperators #-}

module Accelerate.QinkaCS.CV.ComputerVision where

import           Accelerate.QinkaCS.Binding.ComputerVision
import           Accelerate.QinkaCS.Exception
import           Accelerate.QinkaCS.Tensor
import           Control.Monad
import           Foreign.FAI
import           Foreign.Ptr
import           Foreign.Storable

cvColorBackgroundMask :: (FAI p,  Shape sh, Storable c, c ~ Pf p Float)
                      => Ten (Z  :. Int) p -- ^ color
                      -> Ten (sh :. Int) p -- ^ image
                      -> Accelerate p (Ten (sh :. Int) p)
cvColorBackgroundMask color image = do
  when (colorSh' /= colorSh) $ throw $ UnmatchShape colorSh colorSh'
  maskBuf <- newBuffer $ getBufferShape image
  liftIO $ withBuffer color $ \pColor ->
    withBuffer image $ \pImage ->
    withBuffer maskBuf $ \pMask ->
    color_background_mask (castPtr pMask) (castPtr pImage) (castPtr pColor)
                          (shLen pixelSh) (shLen colorSh)
  return maskBuf
  where (pixelSh :. colorSh ) = getBufferShape image
        (Z       :. colorSh') = getBufferShape color

cvColorBackgroundMaskRGBRang :: ( FAI p, Shape sh
                                , Storable c, c ~ Pf p Float
                                )
                             => Ten (sh :. Int) p -- ^ image
                             -> (Float, Float, Float)
                             -> (Float, Float, Float)
                             -> Accelerate p (Ten (sh :. Int) p)
cvColorBackgroundMaskRGBRang image (aR, aG, aB) (bR, bG, bB) = do
  when (shLen colorSh /= 3) $ throw $ RGBNeeded colorSh
  maskBuf <- newBuffer $ getBufferShape image
  liftIO $ withBuffer' image $ \pImage ->
    withBuffer' maskBuf $ \pMask ->
    color_background_mask_rgb_rang pMask pImage (shLen pixelSh) aR aG aB bR bG bB
  return maskBuf
  where (pixelSh :. colorSh ) = getBufferShape image

cvColorRGB2HSV :: (FAI p,  Shape sh, Storable c, c ~ Pf p Float)
               => Ten (sh :. Int) p -- ^ image
               -> Accelerate p (Ten (sh :. Int) p)
cvColorRGB2HSV image = do
  when (colorSh /= 3) $ throw $ RGBNeeded colorSh
  hsvBuf <- newBuffer $ getBufferShape image
  liftIO $ withBuffer' image $ \pImage ->
    withBuffer' hsvBuf $ \pHSV ->
    color_rgb_to_hsv pHSV pImage (shLen pixelSh)
  return hsvBuf
  where (pixelSh :. colorSh ) = getBufferShape image


cvColorHSV2RGB :: (FAI p,  Shape sh, Storable c, c ~ Pf p Float)
               => Ten (sh :. Int) p -- ^ image
               -> Accelerate p (Ten (sh :. Int) p)
cvColorHSV2RGB image = do
  when (colorSh /= 3) $ throw $ HSVNeeded colorSh
  rgbBuf <- newBuffer $ getBufferShape image
  liftIO $ withBuffer' image $ \pImage ->
    withBuffer' rgbBuf $ \pRGB ->
    color_hsv_to_rgb pRGB pImage (shLen pixelSh)
  return rgbBuf
  where (pixelSh :. colorSh ) = getBufferShape image
