#include <qinka_cs/qinka_computing_subprogram.h>
#include "test_prelude.h"

using namespace std;

TEST(print_infos, case0) {
    cout 
        << "Qinka Computing Subprogram infos" << endl
        << endl
        << "The current version is " << qinka_computing_subprogram_version_str() << endl
        << "\t Major version: " << qinka_computing_subprogram_version_major() << endl
        << "\t Minor version: " << qinka_computing_subprogram_version_minor() << endl
        << "\t Patch version: " << qinka_computing_subprogram_version_patch() << endl
        << "\t Diff  version: " << qinka_computing_subprogram_version_diff() << endl
        << endl
        << "The current accelerate backend is " << qinka_computing_subprogram_backend_type_str() << endl
        << "Accelerate backend id is " << qinka_computing_subprogram_backend_type_id() << endl;
}