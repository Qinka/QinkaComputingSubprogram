#include <qinka_cs/blas/basic_function.h>
#include <config.h>
#include <math.h>
#include <sequence_inline_function.h>

void forward_N_add(float *C, float *A, float *B, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(C, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(C, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(C[0:n]), copyin(A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(C, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            C[i] = A[i] + B[i];
    }
}
void backward_N_add_A(float *dA, float *dC, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dC, dA, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dC, dA, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dC[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dC)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dC[i];
    }
}
void backward_N_add_B(float *dB, float *dC, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dB, dC, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dB, dC, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dB[0:n]), copyin(dC[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dB, dC)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dB[i] = dC[i];
    }
}


void forward_N_sub(float *C, float *A, float *B, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(C, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(C, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(C[0:n]), copyin(A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(C, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            C[i] = A[i] - B[i];
    }
}
void backward_N_sub_A(float *dA, float *dC, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dC, dA, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dC, dA, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dC[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dC)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dC[i];
    }
}
void backward_N_sub_B(float *dB, float *dC, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dB, dC, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dB, dC, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dB[0:n]), copyin(dC[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dB, dC)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dB[i] = -dC[i];
    }
}


void forward_N_dot_prd(float *C, float *A, float *B, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(C, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(C, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(C[0:n]), copyin(A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(C, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            C[i] = A[i] * B[i];
    }
}
void backward_N_dot_prd_A(float *dA, float *B, float *dC, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dC, dA, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dC, dA, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dC[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dC, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dC[i] * B[i];
    }
}
void backward_N_dot_prd_B(float *dB, float *A, float *dC, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dC, dB, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dC, dB, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dB[0:n]), copyin(dC[0:n], A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dB, dC, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dB[i] = dC[i] * A[i];
    }
}


void forward_N_dot_div(float *C, float *A, float *B, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(C, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(C, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(C[0:n]), copyin(A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(C, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            C[i] = A[i] / B[i];
    }
}
void backward_N_dot_div_A(float *dA, float *B, float *dC, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dC, dA, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dC, dA, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dC[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dC, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dC[i] / B[i];
    }
}
void backward_N_dot_div_B(float *dB, float *A, float *B, float *dC, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dC, dB, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dC, dB, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dB[0:n]), copyin(dC[0:n], A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dB, dC, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dB[i] = - dC[i] * A[i] / B[i] / B[i];
    }
}


void forward_N_scale(float *B, float *A, float *s, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, s, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, s, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n], s[1])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A, s)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = A[i] * (*s);
    }
}
void backward_N_scale_A(float *dA, float *s, float *dB, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, s, dB, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, s, dB, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], s[1])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = (*s) * dB[i];
    }
}
void backward_N_scale_s(float *ds, float *A, float *dB, int n){

    #if   ACC_LOOP != OACC_ENABLE
    float sum = 0;
    #endif

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(A, ds, dB, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(A, ds, dB, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(ds[0]), copyin(dB[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(ds, dB)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for reduction(+:sum)
        #elif ACC_LOOP == OACC_ENABLE
        float sum = 0;
        #pragma acc parallel loop reduction(+:sum)
        #endif
        for (i = 0; i < n; i++)
            sum += dB[i] * A[i];
        *ds = sum;
    }
}

//abs
void forward_N_abs(float *B, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = fabsf(A[i]);
    }
}
void backward_N_abs_A(float *dA, float *dB, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dB[i] * sign(A[i]);
    }
}
//sign
void forward_N_sign(float *B, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = sign(A[i]);
    }
    
}
void backward_N_sign_A(float *dA, float *dB, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = .0f;
    }
}
//exp
void forward_N_exp(float *B, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = expf(A[i]);
    }
}
void backward_N_exp_A(float *dA, float *dB, float *B, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dB, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dB, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dB[i] * B[i];
    }
}
//expm1
void forward_N_expm1(float *B, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = expm1f(A[i]);
    }
}
void backward_N_expm1_A(float *dA, float *dB, float *B, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dB, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dB, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dB[i] * (B[i] + 1);
    }
}
//log
void forward_N_log(float *B, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = logf(A[i]);
    }
}
void backward_N_log_A(float *dA, float *dB, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dB[i] / A[i];
    }
}
//logp1
void forward_N_log1p(float *B, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = log1pf(A[i]);
    }
}
void backward_N_log1p_A(float *dA, float *dB, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dB[i] / (A[i] + 1);
    }
}
//sqrt
void forward_N_sqrt(float *B, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = sqrtf(A[i]);
    }
}
void backward_N_sqrt_A(float *dA, float *dB, float *A, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dB[i] / 2 / sqrtf(A[i]);
    }
}
//pow
void forward_N_pow(float *B, float *A, float *x, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, x, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, x,  n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n], x[1])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A, x)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = powf(A[i], (*x));
    }
}
void backward_N_pow_A(float *dA, float *dB, float *A, float *B, float *x, int n) {

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dB, A, B, x, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dB, A, B, x, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], A[0:n], B[0:n], x[1])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB, A, B, x)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dB[i] * B[i] * (*x) / A[i];
    }
}
void backward_N_pow_w(float *dx, float *dB, float *A, float *B, float *x, int n) {

    #if   ACC_LOOP != OACC_ENABLE
    float sum = 0;
    #endif

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dx, dB, A, B, x, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dx, dB, A, B, x, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dx[0]), copyin(dB[0:n], A[0:n], B[0:n], x[1])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dx, dB, A, B, x)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for reduction(+:sum)
        #elif ACC_LOOP == OACC_ENABLE
        float sum = 0;
        #pragma acc parallel loop reduction(+:sum)
        #endif
        for (i = 0; i < n; i++)
            sum += dB[i] * B[i] * logf(A[i]);
        *dx = sum;
    }
}
//ceil
void forward_N_ceil(float *B, float *A, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = ceilf(A[i]);
    }
}
void backward_N_ceil_A(float *dA, float *dB, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = .0f;
    }
}
//floor
void forward_N_floor(float *B, float *A, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = floorf(A[i]);
    }
}
void backward_N_floor_A(float *dA, float *dB, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = .0f;
    }
}
//erf
void forward_N_erf(float *B, float *A, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = erff(A[i]);
    }
}
void backward_N_erf_A(float *dA, float *dB, float *A, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] =  1.1283791670955126f * dB[i] * expf(- A[i] * A[i]) ; // 1.1283791670955126 = 2 / sqrt(pi)
    }
}
//erfc
void forward_N_erfc(float *B, float *A, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(B, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(B, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(B[0:n]), copyin(A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(B, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            B[i] = erfcf(A[i]);
    }
}
void backward_N_erfc_A(float *dA, float *dB, float *A, int n){

    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dB, A, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dB[0:n], A[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dB, A)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = - 1.1283791670955126f * dB[i] * expf(- A[i] * A[i]) ; // 1.1283791670955126 = 2 / sqrt(pi)
    }
}

//max
void forward_N_max(float *C, float *A, float *B, int n) {
    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(C, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(C, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(C[0:n]), copyin(A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(C, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            C[i] = (A[i] >= B[i]) * A[i] + (B[i] > A[i]) * B[i];
    }
}
void backward_N_max_A(float *dA, float *dC, float *A, float *B, int n) {
    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dC, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dC, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dC[0:n], A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dC, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dC[i] * ((A[i] > B[i]) + (A[i] == B[i]) * 0.5f);
    }
}
void backward_N_max_B(float *dB, float *dC, float *A, float *B, int n) {
    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dB, dC, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dB, dC, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dB[0:n]), copyin(dC[0:n], A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dB, dC, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dB[i] = dC[i] * ((B[i] > A[i]) + (A[i] == B[i]) * 0.5f);
    }
}


//max
void forward_N_min(float *C, float *A, float *B, int n) {
    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(C, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(C, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(C[0:n]), copyin(A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(C, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            C[i] = (A[i] <= B[i]) * A[i] + (B[i] < A[i]) * B[i];
    }
}
void backward_N_min_A(float *dA, float *dC, float *A, float *B, int n) {
    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dA, dC, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dA, dC, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dA[0:n]), copyin(dC[0:n], A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dA, dC, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dA[i] = dC[i] * ((A[i] < B[i]) + (A[i] == B[i]) * 0.5f);
    }
}
void backward_N_min_B(float *dB, float *dC, float *A, float *B, int n) {
    
    #if   ACC_REGION == OMP_ONLY
    #pragma omp parallel shared(dB, dC, A, B, n)
    #elif ACC_REGION == OMP_TARGET
    #pragma omp target parallel shared(dB, dC, A, B, n)
    #elif ACC_REGION == OACC_ONLY
    #pragma acc data copyout(dB[0:n]), copyin(dC[0:n], A[0:n], B[0:n])
    #elif ACC_REGION == OACC_DRVPTR
    #pragma acc data deviceptr(dB, dC, A, B)
    #endif
    {
        int i;

        #if   ACC_LOOP == OMP_ENABLE
        #pragma omp for
        #elif ACC_LOOP == OACC_ENABLE
        #pragma acc parallel loop
        #endif
        for (i = 0; i < n; i++)
            dB[i] = dC[i] * ((B[i] < A[i]) + (A[i] == B[i]) * 0.5f);
    }
}