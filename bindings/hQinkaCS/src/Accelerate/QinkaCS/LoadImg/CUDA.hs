module Accelerate.QinkaCS.LoadImg.CUDA
  (
  ) where

import           Accelerate.QinkaCS.LoadImg

import           Accelerate.QinkaCS.Tensor
import           Foreign.FAI
import           Foreign.FAI.Platform.CUDA
import           Foreign.FAI.Platform.Host

instance LoadSaveImg CUDA where
  readImageToBufferFloat is fp = do
    (host, tf) <- readImageToBufferFloatHost is fp
    cu <- dupBuffer True host
    return (cu, tf)
  writeImageFromBufferFloat is fp f cu = do
    host <- liftIO $ dupBufferIO True cu nullHostContext
    writeImageFromBufferFloatHost is fp f $ fst host
