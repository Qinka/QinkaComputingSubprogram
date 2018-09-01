{-# LANGUAGE TypeFamilies #-}

module Accelerate.QinkaCS.Tensor
  ( Ten(..)
  , module Foreign.FAI.Types
  ) where

import           Foreign.FAI.Types
import           Foreign.ForeignPtr

data Ten sh p = Ten
  { tenFP :: !(ForeignPtr (Pf p Float))
  , tenSh :: !sh
  } deriving(Eq, Show)

instance Buffer (Ten sh p) where
  type BufferPlatform (Ten sh p) = p
  type BufferType     (Ten sh p) = Float
  type BufferShape    (Ten sh p) = sh
  getBufferPtr          = tenFP
  getBufferShape        = tenSh
  setBufferPtr   ten fp = ten {tenFP = fp}
  setBufferShape ten sh = ten {tenSh = sh}
  makeBuffer            = Ten
