{-# LANGUAGE TemplateHaskell #-}
{-# LANGUAGE TypeFamilies    #-}

module Accelerate.QinkaCS.BLAS.HyperbolicFunction where

import           Accelerate.QinkaCS.Binding.HyperbolicFunction
import           Accelerate.QinkaCS.TH
import           Foreign.FAI
import           Foreign.Ptr

mkBindingFAI 'forward_N_cosh                True []
mkBindingFAI 'backward_N_cosh_A             True []
mkBindingFAI 'forward_N_sinh                True []
mkBindingFAI 'backward_N_sinh_A             True []
mkBindingFAI 'forward_N_tanh                True []
mkBindingFAI 'backward_N_tanh_A             True []
mkBindingFAI 'forward_N_atanh               True []
mkBindingFAI 'backward_N_atanh_A            True []
mkBindingFAI 'forward_N_acosh               True []
mkBindingFAI 'backward_N_acosh_A            True []
mkBindingFAI 'forward_N_asinh               True []
mkBindingFAI 'backward_N_asinh_A            True []
