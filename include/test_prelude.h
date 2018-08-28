#pragma once

#ifndef _TEST_PRELUDE_H_
#define _TEST_PRELUDE_H_

#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <cmath>

#define EXPECT_FLOAT_NEAR(x,y) EXPECT_NEAR((x),(y), fabsf(((x) + (y)) * 0.00006))


void fill_eye(float * mat, int row_num);
void fill_zero(float *mat, int num);
void fill_random(float *mat, int num);
void copy(float *dstMat, float *srcMat, int num);
void fill_with(float *mat, float f, int num);


#endif // ! _TEST_PRELUDE_H_
