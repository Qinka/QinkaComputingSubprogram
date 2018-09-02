
module Accelerate.QinkaCS.Exception
  ( UnmatchShape(..)
  , UnmatchSize(..)
  , RGBNeeded(..)
  , HSVNeeded(..)
  , UnsupportedImageFormat(..)
  , module Control.Monad.Catch
  , module GHC.Stack
  , module Foreign.FAI.Types.Exception
  , throw
  ) where

import           Control.Monad.Catch
import           Data.Typeable
import           Foreign.FAI
import           Foreign.FAI.Types.Exception
import           GHC.Stack

data UnmatchShape sh1 sh2 = UnmatchShape sh1 sh2
  deriving(Eq)
instance (Show sh1, Show sh2) => Show (UnmatchShape sh1 sh2) where
  show (UnmatchShape s1 s2) = "The unmatch the shape " ++ show s1 ++ ", which should be " ++ show s2
instance (Show sh1, Show sh2, Typeable sh1, Typeable sh2) => Exception (UnmatchShape sh1 sh2)

data UnmatchSize = UnmatchSize Int Int
  deriving(Eq)
instance Show UnmatchSize where
  show (UnmatchSize s1 s2) = "The unmatch the size " ++ show s1 ++ ", which should be " ++ show s2
instance Exception UnmatchSize

newtype RGBNeeded = RGBNeeded Int
  deriving(Eq)
instance Show RGBNeeded where
  show (RGBNeeded i) = "The Color should be RGB format, which can not be " ++ show i ++ " colors"
instance Exception RGBNeeded

newtype HSVNeeded = HSVNeeded Int
  deriving(Eq)
instance Show HSVNeeded where
  show (HSVNeeded i) = "The Color should be HSV format, which can not be " ++ show i ++ " colors"
instance Exception HSVNeeded

newtype UnsupportedImageFormat = UnsupportedImageFormat String
  deriving(Eq)
instance Show UnsupportedImageFormat where
  show (UnsupportedImageFormat u) = "The format " ++ u ++ " is not supported!"
instance Exception UnsupportedImageFormat
