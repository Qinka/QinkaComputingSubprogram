#pragma once

#ifndef _QINKA_COMPUTING_SUBPROGRAM_H_
#define _QINKA_COMPUTING_SUBPROGRAM_H_


#ifdef __cplusplus
extern "C" {
#endif // ! __cplusplus

const char * qinka_computing_subprogram_version_str();
int qinka_computing_subprogram_version_major();
int qinka_computing_subprogram_version_minor();
int qinka_computing_subprogram_version_patch();
int qinka_computing_subprogram_version_diff();

const char * qinka_computing_subprogram_backend_type_str();
int qinka_computing_subprogram_backend_type_id();

#ifdef __cplusplus
}
#endif // ! __cplusplus


#endif // ! _QINKA_COMPUTING_SUBPROGRAM_H_