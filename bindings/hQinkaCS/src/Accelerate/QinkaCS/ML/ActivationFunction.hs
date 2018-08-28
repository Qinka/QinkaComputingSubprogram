{-# LANGUAGE TemplateHaskell #-}
{-# LANGUAGE TypeFamilies    #-}

module Accelerate.QinkaCS.ML.ActivationFunction where

import           Accelerate.QinkaCS.Binding.ActivationFunction
import           Accelerate.QinkaCS.TH
import           Foreign.FAI
import           Foreign.Ptr

mkBindingFAI 'forward_N_sigmoid             True  []
mkBindingFAI 'backward_N_sigmoid_A          True  []
mkBindingFAI 'forward_N_ReLU                True  []
mkBindingFAI 'backward_N_ReLU_A             True  []
