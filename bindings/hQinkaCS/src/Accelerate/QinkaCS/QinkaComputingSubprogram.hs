module Accelerate.QinkaCS.QinkaComputingSubprogram where

import           Accelerate.QinkaCS.Binding.QinkaComputingSubprogram

qinkaComputingSubprgramVersionStr :: String
qinkaComputingSubprgramVersionStr = qinka_computing_subprogram_version_str

qinkaComputingSubprgramVersion :: (Int, Int, Int, Int)
qinkaComputingSubprgramVersion = ( qinka_computing_subprogram_version_major
                                 , qinka_computing_subprogram_version_minor
                                 , qinka_computing_subprogram_version_patch
                                 , qinka_computing_subprogram_version_diff
                                 )

qinkaComputingSubprgramBackend   :: String
qinkaComputingSubprgramBackend   = qinka_computing_subprogram_backend_type_str
qinkaComputingSubprgramBackendId :: Int
qinkaComputingSubprgramBackendId = qinka_computing_subprogram_backend_type_id
