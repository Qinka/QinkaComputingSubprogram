{-# LANGUAGE ForeignFunctionInterface #-}

module Accelerate.QinkaCS.Binding.QinkaComputingSubprogram
  ( qinka_computing_subprogram_version_str
  , qinka_computing_subprogram_version_major
  , qinka_computing_subprogram_version_minor
  , qinka_computing_subprogram_version_patch
  , qinka_computing_subprogram_version_diff
  , qinka_computing_subprogram_backend_type_str
  , qinka_computing_subprogram_backend_type_id
  ) where

#include <qinka_cs/qinka_computing_subprogram.h>

import Foreign.Ptr
import Foreign.C

{#fun pure qinka_computing_subprogram_version_str
  {} -> `String' #}
{#fun pure qinka_computing_subprogram_version_major
  {} -> `Int' #}
{#fun pure qinka_computing_subprogram_version_minor
  {} -> `Int' #}
{#fun pure qinka_computing_subprogram_version_patch
  {} -> `Int' #}
{#fun pure qinka_computing_subprogram_version_diff
  {} -> `Int' #}

{#fun pure qinka_computing_subprogram_backend_type_str
  {} -> `String' #}
{#fun pure qinka_computing_subprogram_backend_type_id
  {} -> `Int' #}