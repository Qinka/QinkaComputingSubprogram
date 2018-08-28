#include <qinka_cs/qinka_computing_subprogram.h>
#include <config.h>
#include <config_gen.h>

static
const char * _qinka_computing_subprogram_ver_str = _QINKA_CS_VER_STR;
static
const char * _qinka_computing_subprogram_backend_str = _ACC_BACKEND_STR;

const char * qinka_computing_subprogram_version_str() {
    return _qinka_computing_subprogram_ver_str;
}

int qinka_computing_subprogram_version_major() {
    return _QINKA_CS_VER_MAJOR;
}

int qinka_computing_subprogram_version_minor() {
    return _QINKA_CS_VER_MINOR;
}

int qinka_computing_subprogram_version_patch() {
    return _QINKA_CS_VER_PATCH;
}

int qinka_computing_subprogram_version_diff() {
    return _QINKA_CS_VER_DIFF;
}

const char * qinka_computing_subprogram_backend_type_str() {
    return _qinka_computing_subprogram_backend_str;
}

int qinka_computing_subprogram_backend_type_id() {
    return _ACC_BACKEND_ID;
}