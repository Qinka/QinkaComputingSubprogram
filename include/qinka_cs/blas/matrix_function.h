#pragma once

#ifndef _BLAS__MATRIX_FUNCTION_H_
#define _BLAS__MATRIX_FUNCTION_H_

#ifdef __cplusplus
extern "C" {
#endif // ! __cplusplus

/****************
 * 
 * Matrix product options
 * 
****************/
/**
 * @brief $ C = A \times B$
 * 
 * @param C matrix $C_{m \times s}$
 * @param A matrix $A_{m \times n}$
 * @param B matrix $B_{n \times s}$
 * @param m size
 * @param n size
 * @param s size
 */
void forward_HW_mul2D(float *C, float *A, float *B, int m, int n, int s);

/**
 * @brief $\frac{\partial L}{\partial A} = \frac{\partial L}{\partial C} \frac{\partial C}{\partial A}=  \frac{\partial L}{\partial C} B^\intercal$
 * 
 * @param dA matrix $\frac{\partial L}{\partial A}_{(m \times n)}$
 * @param dC matrix $\frac{\partial L}{\partial C}_{(m \times s)}$
 * @param B  matrix $A_{n \times s}$
 * @param m size
 * @param n size
 * @param s size
 */
void backward_HW_mul2D_A(float *dA, float *dC, float *B, int m, int n, int s);

/**
 * @brief $\frac{\partial L}{\partial B} =  \frac{\partial C}{\partial B} \frac{\partial L}{\partial C} = A^\intercal \frac{\partial L}{\partial C}$
 * 
 * @param dB matrix $\frac{\partial L}{\partial B}_{(n \times s)}$
 * @param A  matrix $A_{m \times n}$
 * @param dC matrix $\frac{\partial L}{\partial C}_{(s \times n)}$
 * @param m size
 * @param n size
 * @param s size
 */
void backward_HW_mul2D_B(float *dB, float *A, float *dC, int m, int n, int s);

#ifdef __cplusplus
}
#endif // ! __cplusplus

#endif // ! _BLAS__MATRIX_FUNCTION_H_