#include <test_prelude.h>
#include <qinka_cs/blas/basic_function.h>
#include <sequence_inline_function.h>

#define PI 3.141592653589793

#if IGNORE_VECTOR_ADD != 1
/**********************************************************************
 * 
 *  vector add forward test.
 * 
**********************************************************************/
TEST(forward_N_add, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        C[i] = A[i] + B[i];

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_add, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    forward_N_add(C, A, B, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_add, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    fill_random(A, m * n);
    fill_random(B, m * n);

    forward_N_add(C, A, B, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(C[i], A[i] + B[i]);
    }

    delete[] A;
    delete[] B;
    delete[] C;
}
/**********************************************************************
 * 
 *  vector add backward test. (matrix A)
 * 
**********************************************************************/
TEST(backward_N_add_A, random_case0) {
    const int m = 16, n = 16;
    float *dC = new float[m * n];
    float *d = new float[m * n];

    fill_random(dC, m * n);

    backward_N_add_A(d, dC, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(d[i], dC[i]);
    }

    delete[] d;
    delete[] dC;
}
/**********************************************************************
 * 
 *  vector add backward test. (matrix B)
 * 
**********************************************************************/
TEST(backward_N_add_B, random_case0) {
    const int m = 16, n = 16;
    float *dC = new float[m * n];
    float *d = new float[m * n];

    fill_random(dC, m * n);

    backward_N_add_B(d, dC, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(d[i], dC[i]);
    }

    delete[] d;
    delete[] dC;
}
#endif // IGNORE_VECTOR_ADD != 1

#if IGNORE_VECTOR_SUB != 1
/**********************************************************************
 * 
 *  vector subtraction forward test.
 * 
**********************************************************************/
TEST(forward_N_sub, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        C[i] = A[i] - B[i];

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_sub, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    forward_N_sub(C, A, B, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_sub, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    fill_random(A, m * n);
    fill_random(B, m * n);

    forward_N_sub(C, A, B, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(C[i], A[i] - B[i]);
    }

    delete[] A;
    delete[] B;
    delete[] C;
}
/**********************************************************************
 * 
 *  vector sub backward test. (matrix A)
 * 
**********************************************************************/
TEST(backward_N_sub_A, random_case0) {
    const int m = 16, n = 16;
    float *dC = new float[m * n];
    float *d = new float[m * n];

    fill_random(dC, m * n);

    backward_N_sub_A(d, dC, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(d[i], dC[i]);
    }

    delete[] d;
    delete[] dC;
}
/**********************************************************************
 * 
 *  vector sub backward test. (matrix B)
 * 
**********************************************************************/
TEST(backward_N_sub_B, random_case0) {
    const int m = 16, n = 16;
    float *dC = new float[m * n];
    float *d = new float[m * n];

    fill_random(dC, m * n);

    backward_N_sub_B(d, dC, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(d[i], -dC[i]);
    }

    delete[] d;
    delete[] dC;
}
#endif // IGNORE_VECTOR_SUB != 1

#if IGNORE_VECTOR_PRD != 1
/**********************************************************************
 * 
 *  vector dot product forward test.
 * 
**********************************************************************/
TEST(forward_N_dotprd, no_paralel_case0){
    int m = 4096, n = 4096;
    float *matA = new float[m * n];
    float *matB = new float[m * n];
    float *matC = new float[m * n];

    for (int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            matC[i * n + j] = matA[i * n + j] * matB[i * n + j];
    
    EXPECT_EQ(1,1);

    delete[] matA;
    delete[] matB;
    delete[] matC;
}


TEST(forward_N_dotprd, parallel_case1) {
    int m = 4096, n = 4096;
    float *matA = new float[m * n];
    float *matB = new float[m * n];
    float *matC = new float[m * n];
    
    forward_N_dot_prd(matC, matA, matB, m * n);

    EXPECT_EQ(1,1);

    delete[] matA;
    delete[] matB;
    delete[] matC;
}


TEST(forward_N_dotprd, eye_case2) {
    const int m = 4, n = 4;
    float *ones = new float[m * n];
    float *ra   = new float[m * n];
    float *rt   = new float[m * n];

    fill_with(ones, 1, m * n);
    fill_random(ra, m * n);

    forward_N_dot_prd(rt, ra, ones, m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_EQ(ra[i],rt[i]);
    }

    delete[] rt;
    delete[] ra;
    delete[] ones;
}

TEST(forward_N_dotprd, eye_case3) {
    const int m = 4, n = 4;
    float *ones = new float[m * n];
    float *ra   = new float[m * n];
    float *rt   = new float[m * n];

    fill_with(ones, 1, m * n);
    fill_random(ra, m * n);

    forward_N_dot_prd(rt, ones, ra, m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_EQ(ra[i],rt[i]);
    }

    delete[] rt;
    delete[] ra;
    delete[] ones;
}
/**********************************************************************
 * 
 *  vector dot product backward test. (for matrix A)
 * 
**********************************************************************/
TEST(backward_N_dot_prd_A, specific_case0){
    const int m = 4, n = 4;
    float *dA = new float[m * n];
    float  B[]    = { 0.7621, 0.6257, 0.8195, 0.4130
                    , 0.6573, -1.8253, 0.6445, 0.1668
                    , 0.7199, 1.2139, 0.3834, 0.6247
                    ,-0.6626, 0.3394, -1.1363, 0.0735};
    float dC[] = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

    backward_N_dot_prd_A(dA, B, dC, m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_NEAR(dA[i],B[i],0.0002);
    }

    delete[] dA;
}

TEST(backward_vector_dot_prd_A, random_Case1) {
    const int m = 4, n = 4;
    float *dA = new float[m * n];
    float * B = new float[m * n];
    float  dC[] = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

    fill_random(B, m * n);

    backward_N_dot_prd_A(dA, B, dC, m * n);
    
    for(int i = 0; i < m * n; ++i) {
        EXPECT_NEAR(dA[i],B[i],0.0002);
    }

    delete[] dA;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector dot product backward test. (for matrix B)
 * 
**********************************************************************/
TEST(backward_N_dot_prd_B, specific_case0){
    const int m = 4, n = 4;
    float *dB = new float[m * n];
    float  A[]    = { 0.7621, 0.6257, 0.8195, 0.4130
                    , 0.6573, -1.8253, 0.6445, 0.1668
                    , 0.7199, 1.2139, 0.3834, 0.6247
                    ,-0.6626, 0.3394, -1.1363, 0.0735};
    float dC[] = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

    backward_N_dot_prd_B(dB, A, dC, m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_NEAR(dB[i],A[i],0.0002);
    }

    delete[] dB;
}

TEST(backward_vector_dot_prd_B, random_Case1) {
    const int m = 4, n = 4;
    float *dB = new float[m * n];
    float * A = new float[m * n];
    float  dC[] = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};

    fill_random(A, m * n);

    backward_N_dot_prd_B(dB, A, dC, m * n);
    
    for(int i = 0; i < m * n; ++i) {
        EXPECT_NEAR(dB[i],A[i],0.0002);
    }

    delete[] dB;
    delete[] A;
}
#endif // IGNORE_VECTOR_PRD != 1

#if IGNORE_VECTOR_DOT_DIV != 1
/**********************************************************************
 * 
 *  vector dot-division forward test.
 * 
**********************************************************************/
TEST(forward_N_dot_div, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        C[i] = A[i] / B[i];

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_dot_div, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    forward_N_dot_div(C, A, B, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_dot_div, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    fill_random(A, m * n);
    fill_random(B, m * n);

    forward_N_dot_div(C, A, B, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(C[i], A[i] / B[i]);
    }

    delete[] A;
    delete[] B;
    delete[] C;
}
/**********************************************************************
 * 
 *  vector dot-division backward test. (matrix A)
 * 
**********************************************************************/
TEST(backward_N_dot_div_A, random_case0) {
    const int m = 16, n = 16;
    float *dC = new float[m * n];
    float *B = new float[m * n];
    float *d = new float[m * n];

    fill_random(dC, m * n);

    backward_N_dot_div_A(d, B, dC, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(d[i], dC[i]/B[i]);
    }

    delete[] d;
    delete[] dC;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector dot-division backward test. (matrix B)
 * 
**********************************************************************/
TEST(backward_N_dot_div_B, random_case0) {
    const int m = 16, n = 16;
    float *dC = new float[m * n];
    float *d = new float[m * n];
    float *B = new float[m * n];
    float *A = new float[m * n];

    fill_random(dC, m * n);

    backward_N_dot_div_B(d, A, B, dC, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(d[i], -dC[i] * A[i]/B[i] / B[i] );
    }

    delete[] d;
    delete[] dC;
}

#endif // IGNORE_VECTOR_DIV != 1


#if IGNORE_VECTOR_SCALE != 1
/**********************************************************************
 * 
 *  vector scale forward test.
 * 
**********************************************************************/
TEST(forward_N_scale, no_parallel_case0) {
    int m = 4096, n = 4096;
    float *matA = new float[m * n];
    float *matB = new float[m * n];

    for (int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            matB[i * n + j] = matA[i * n + j] * 2;

    EXPECT_EQ(1,1);

    delete[] matA;
    delete[] matB;
}

TEST(forward_N_scale, parallel_case1) {
    int m = 4096, n = 4096;
    float *matA = new float[m * n];
    float *matB = new float[m * n];

    float s = 2;
    forward_N_scale(matB, matA, &s, m * n);

    EXPECT_EQ(1,1);

    delete[] matA;
    delete[] matB;
}

TEST(forward_N_scale, s1_case2) {
    int m = 16, n = 16;
    float *matA = new float[m * n];
    float *matB = new float[m * n];
    fill_random(matA, m * n);
    float s = 1;

    forward_N_scale(matB, matA, &s, m * n);

    for(int i = 0; i < m * n; i++) {
        EXPECT_EQ(matA[i], matB[i]);
    }

    delete[] matA;
    delete[] matB;
}

TEST(forward_N_scale, s0_case3) {
    int m = 16, n = 16;
    float *matA = new float[m * n];
    float *matB = new float[m * n];
    fill_random(matA, m * n);
    float s = 0;

    forward_N_scale(matB, matA, &s, m * n);

    for(int i = 0; i < m * n; i++) {
        EXPECT_EQ(0, matB[i]);
    }

    delete[] matA;
    delete[] matB;
}

/**********************************************************************
 * 
 *  vector scale backward test. (for matrix A)
 * 
**********************************************************************/
TEST(backward_N_scale_A, specific_case0) {
    const int m = 4, n = 4;
    float *dA = new float[m * n];
    float dB[] = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
    float s = 3.1416;

    backward_N_scale_A(dA, &s, dB, m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_NEAR(dA[i],s,0.00005);
    }

    delete[] dA;
}
TEST(backward_N_scale_A, random_case1) {
    const int m = 4, n = 4;
    float *dA = new float[m * n];
    float dB[] = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
    float s;

    fill_random(&s, 1);

    backward_N_scale_A(dA, &s, dB, m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_NEAR(dA[i],s,0.00005);
    }

    delete[] dA;
}

/**********************************************************************
 * 
 *  vector scale backward test. (for scalar s)
 * 
**********************************************************************/
TEST(backward_N_scale_s, specific_case0) {
    const int m = 4, n = 4;
    float ds = 0;
    float dB[] = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
    float A[] = { 1.0648, 0.2398, -0.5973, 0.8604
                , -0.0897, 0.2770, -0.6439, 0.2394
                , 0.0973, 0.8857, 0.5930, 0.8655
                , -0.1681, 0.6876, 0.9303, -0.1169};

    backward_N_scale_s(&ds, A, dB, m * n);

    EXPECT_NEAR(ds, 5.1248, 0.0002);
}
TEST(backward_N_scale_s, random_case1) {
    const int m = 4, n = 4;
    float ds = 0;
    float dB[] = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
    float *A = new float[m * n];

    fill_random(A, m * n);

    backward_N_scale_s(&ds, A, dB, m * n);

    float sum = 0;
    for(int i = 0; i < m*n; ++i)
        sum += A[i];

    EXPECT_NEAR(ds, sum, 0.00002);

    delete[] A;
}
#endif // IGNORE_VECTOR_SCALE != 1


#if IGNORE_VECTOR_ABS != 1
/**********************************************************************
 * 
 *  vector abs forward test.
 * 
**********************************************************************/
TEST(forward_N_abs, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = fabsf(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_abs, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_abs(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_abs, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_abs(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], fabsf(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector abs backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_abs_A, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *A = new float[m * n];
    float *dA = new float[m * n];

    fill_random(dB, m * n);
    fill_random(A, m * n);

    backward_N_abs_A(dA, dB, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], dB[i] * sign(A[i]));
    }

    delete[] dA;
    delete[]  A;
    delete[] dB;
}
#endif // IGNORE_VECTOR_ABS != 1

#if IGNORE_VECTOR_SIGN != 1
/**********************************************************************
 * 
 *  vector sign forward test.
 * 
**********************************************************************/
TEST(forward_N_sign, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = sign(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_sign, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_sign(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_sign, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_sign(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], sign(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector sign backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_sign_A, random_case0) {
    const int m = 16, n = 16;
    float *dA = new float[m * n];

    backward_N_sign_A(dA, 0, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], 0);
    }

    delete[] dA;
}
#endif // IGNORE_VECTOR_SIGN != 1

#if IGNORE_VECTOR_EXP != 1
/**********************************************************************
 * 
 *  vector exp forward test.
 * 
**********************************************************************/
TEST(forward_N_exp, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = expf(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_exp, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_exp(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_exp, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_exp(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], expf(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector exp backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_exp_A, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *B = new float[m * n];
    float *dA = new float[m * n];

    fill_random(dB, m * n);
    fill_random(B, m * n);

    backward_N_exp_A(dA, dB, B, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], dB[i] * B[i]);
    }

    delete[] dA;
    delete[]  B;
    delete[] dB;
}
#endif // IGNORE_VECTOR_EXP != 1

#if IGNORE_VECTOR_EXPM1 != 1
/**********************************************************************
 * 
 *  vector forward test.
 * 
**********************************************************************/
TEST(forward_N_expm1, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = expm1f(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_expm1, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_expm1(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_expm1, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_expm1(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], expm1f(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_expm1_A, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *B = new float[m * n];
    float *dA = new float[m * n];

    fill_random(dB, m * n);
    fill_random(B, m * n);

    backward_N_expm1_A(dA, dB, B, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], dB[i] * (B[i] + 1));
    }

    delete[] dA;
    delete[]  B;
    delete[] dB;
}
#endif // IGNORE_VECTOR_EXPM1 != 1

#if IGNORE_VECTOR_LOG != 1
/**********************************************************************
 * 
 *  vector log forward test.
 * 
**********************************************************************/
TEST(forward_N_log, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = logf(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_log, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_log(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_log, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_log(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], logf(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector log backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_log_A, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *A = new float[m * n];
    float *dA = new float[m * n];

    fill_random(dB, m * n);
    fill_random(A, m * n);

    backward_N_log_A(dA, dB, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], dB[i] / A[i]);
    }

    delete[] dA;
    delete[]  A;
    delete[] dB;
}
#endif // IGNORE_VECTOR_LOG != 1

#if IGNORE_VECTOR_LOGIP != 1
/**********************************************************************
 * 
 *  vector log1p forward test.
 * 
**********************************************************************/
TEST(forward_N_log1p, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = log1pf(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_log1p, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_log1p(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_log1p, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_log1p(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], log1pf(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector log1p backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_log1p_A, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *A = new float[m * n];
    float *dA = new float[m * n];

    fill_random(dB, m * n);
    fill_random(A, m * n);

    backward_N_log1p_A(dA, dB, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], dB[i] / (A[i] + 1));
    }

    delete[] dA;
    delete[]  A;
    delete[] dB;
}
#endif // IGNORE_VECTOR_LOGIP != 1

#if IGNORE_VECTOR_SQRT != 1
/**********************************************************************
 * 
 *  vector sqrt forward test.
 * 
**********************************************************************/
TEST(forward_N_sqrt, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = sqrtf(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_sqrt, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_sqrt(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_sqrt, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_sqrt(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], sqrtf(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector sqrt backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_sqrt_A, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *A = new float[m * n];
    float *dA = new float[m * n];

    fill_random(dB, m * n);
    fill_random(A, m * n);

    backward_N_sqrt_A(dA, dB, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], dB[i] / 2 /  sqrtf(A[i]));
    }

    delete[] dA;
    delete[]  A;
    delete[] dB;
}
#endif // IGNORE_VECTOR_SQRT != 1

#if IGNORE_VECTOR_POW != 1
/**********************************************************************
 * 
 *  vector pow forward test.
 * 
**********************************************************************/
TEST(forward_N_pow, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float x = 9.21924;

    for(int i = 0; i < m * n; ++i)
        B[i] = powf(A[i], x);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_pow, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float x = 9.21924;

    forward_N_pow(B, A, &x, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_pow, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float x = 9.21924;

    fill_random(A, m * n);

    forward_N_pow(B, A, &x, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], powf(A[i],x));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector pow backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_pow_A, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *A = new float[m * n];
    float *dA = new float[m * n];
    float  *B = new float[m * n];
    float x = 9.21924;

    fill_random(dB,m * n);
    fill_random(A,m * n);
    for(int i = 0; i < m * n; ++i)
        B[i] = powf(A[i],x);

    for(int i = 0; i < m * n; ++i)
        B[i] = powf(A[i], x);

    fill_random(dB, m * n);

    backward_N_pow_A(dA, dB, A, B, &x, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], dB[i] * x * powf(A[i], x - 1));
    }

    delete[] dA;
    delete[]  A;
    delete[] dB;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector pow backward test. (for scalar x)
 * 
**********************************************************************/
TEST(backward_N_pow_x, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *A = new float[m * n];
    float  dx = 0;
    float  *B = new float[m * n];
    float x = 9.21924;

    fill_random(dB,m * n);
    fill_random(A,m * n);
    for(int i = 0; i < m * n; ++i)
        B[i] = powf(A[i], x);

    backward_N_pow_w(&dx, dB, A, B, &x, m * n);

    float sum = 0;
    for(int i = 0; i < m * n; ++i)
        sum += dB[i]* powf(A[i],x) * logf(A[i]);
    
    EXPECT_NEAR(dx, sum,0.00001);

    delete[]  B;
    delete[]  A;
    delete[] dB;
}
#endif // IGNORE_VECTOR_POW != 1

#if IGNORE_VECTOR_CEIL != 1
/**********************************************************************
 * 
 *  vector ceil forward test.
 * 
**********************************************************************/
TEST(forward_N_ceil, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = ceil(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_ceil, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_ceil(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_ceil, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_ceil(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], ceil(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector ceil backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_ceil_A, random_case0) {
    const int m = 16, n = 16;
    float *dA = new float[m * n];

    backward_N_ceil_A(dA, 0, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], 0);
    }

    delete[] dA;
}
#endif // IGNORE_VECTOR_CEIL != 1

#if IGNORE_VECTOR_FLOOR != 1
/**********************************************************************
 * 
 *  vector floor forward test.
 * 
**********************************************************************/
TEST(forward_N_floor, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = floor(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_floor, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_floor(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_floor, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_floor(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], floor(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector floor backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_floor_A, random_case0) {
    const int m = 16, n = 16;
    float *dA = new float[m * n];

    backward_N_floor_A(dA, 0, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], 0);
    }

    delete[] dA;
}
#endif // IGNORE_VECTOR_FLOOR != 1


#if IGNORE_VECTOR_ERF != 1
/**********************************************************************
 * 
 *  vector erf forward test.
 * 
**********************************************************************/
TEST(forward_N_erf, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = erff(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_erf, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_erf(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_erf, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_erf(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], erff(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector erf backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_erf_A, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *A = new float[m * n];
    float *dA = new float[m * n];

    fill_random(dB, m * n);
    fill_random(A, m * n);

    backward_N_erf_A(dA, dB, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], dB[i] * 2 / sqrtf((float)PI) * exp(- A[i] * A[i]));
    }

    delete[] dA;
    delete[]  A;
    delete[] dB;
}
#endif // IGNORE_VECTOR_ERF != 1


#if IGNORE_VECTOR_ERFC != 1
/**********************************************************************
 * 
 *  vector erfc forward test.
 * 
**********************************************************************/
TEST(forward_N_erfc, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    for(int i = 0; i < m * n; ++i)
        B[i] = erfcf(A[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_erfc, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];

    forward_N_erfc(B, A, m * n);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
}
TEST(forward_N_erfc, random_case2) {
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];

    fill_random(A, m * n);

    forward_N_erfc(B, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(B[i], erfcf(A[i]));
    }

    delete[] A;
    delete[] B;
}
/**********************************************************************
 * 
 *  vector erfc backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_erfc_A, random_case0) {
    const int m = 16, n = 16;
    float *dB = new float[m * n];
    float  *A = new float[m * n];
    float *dA = new float[m * n];

    fill_random(dB, m * n);
    fill_random(A, m * n);

    backward_N_erfc_A(dA, dB, A, m * n);

    for(int i = 0; i < m * n; ++i){
        EXPECT_FLOAT_NEAR(dA[i], - dB[i] * 2 / sqrtf((float)PI) * exp(- A[i] * A[i]));
    }

    delete[] dA;
    delete[]  A;
    delete[] dB;
}
#endif // IGNORE_VECTOR_ERFC != 1

#if IGNORE_VECTOR_MAX != 1
#define max(i,j) ((i) >= (j) ? (i) : (j))
/**********************************************************************
 * 
 *  vector max forward test. 
 * 
**********************************************************************/
TEST(forward_N_max, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    for(int i = 0; i < m; ++i)
        for(int j =0; j < n; ++j)
            C[i] = max(A[i], B[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_max, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    forward_N_max(C, A, B, m * n);
    
    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_max, specific_case2) {
    
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    for(int i = 0; i < m * n; ++i) {
        A[i] = (float)i;
        B[i] = (float)(m * n - i);
    }

    forward_N_max(C, A, B, m * n);
    
    for(int i = 0; i < m * n; ++i) {
        EXPECT_FLOAT_EQ(C[i], max(i, m * n -i));
    }

    delete[] A;
    delete[] B;
    delete[] C;
}

inline float bMax(float a, float b) {
    if (a > b)
        return 1;
    else if (a == b)
        return 0.5;
    else
        return 0;
}
/**********************************************************************
 * 
 *  vector max backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_max_A, specific_case0) {

    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *dC = new float[m * n];
    float *dA = new float[m * n];

    for(int i = 0; i < m * n; ++i) {
        A[i] = (float)i;
        B[i] = (float)(m * n - i);
    }
    fill_random(dC, m * n);

    backward_N_max_A(dA, dC, A, B, m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_FLOAT_EQ(dA[i], dC[i] * bMax(A[i], B[i]));
    }

    delete[]  A;
    delete[]  B;
    delete[] dA;
    delete[] dC;
}
/**********************************************************************
 * 
 *  vector max backward test. (for vector B)
 * 
**********************************************************************/
TEST(backward_N_max_B, specific_case0) {

    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *dC = new float[m * n];
    float *dB = new float[m * n];

    for(int i = 0; i < m * n; ++i) {
        A[i] = (float)i;
        B[i] = (float)(m * n - i);
    }
    fill_random(dC, m * n);

    backward_N_max_B(dB, dC, A, B, m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_FLOAT_EQ(dB[i], dC[i] * bMax(B[i], A[i]));
    }

    delete[]  A;
    delete[]  B;
    delete[] dB;
    delete[] dC;
}
#undef max
#endif // IGNORE_VECTOR_MAX = =1

#if IGNORE_VECTOR_MIN != 1
#define min(i,j) ((i) <= (j) ? (i) : (j))
/**********************************************************************
 * 
 *  vector min forward test. 
 * 
**********************************************************************/
TEST(forward_N_min, no_parallel_case0) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    for(int i = 0; i < m; ++i)
        for(int j =0; j < n; ++j)
            C[i] = min(A[i], B[i]);

    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_min, parallel_case1) {
    const int m = 8192, n = 8192;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    forward_N_min(C, A, B, m * n);
    
    EXPECT_EQ(1,1);

    delete[] A;
    delete[] B;
    delete[] C;
}
TEST(forward_N_min, specific_case2) {
    
    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *C = new float[m * n];

    for(int i = 0; i < m * n; ++i) {
        A[i] = (float)i;
        B[i] = (float)(m * n - i);
    }

    forward_N_min(C, A, B, m * n);
    
    for(int i = 0; i < m * n; ++i) {
        EXPECT_FLOAT_EQ(C[i], min(i, m * n -i));
    }

    delete[] A;
    delete[] B;
    delete[] C;
}

inline float bMin(float a, float b) {
    if (a < b)
        return 1;
    else if (a == b)
        return 0.5;
    else
        return 0;
}
/**********************************************************************
 * 
 *  vector min backward test. (for vector A)
 * 
**********************************************************************/
TEST(backward_N_min_A, specific_case0) {

    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *dC = new float[m * n];
    float *dA = new float[m * n];

    for(int i = 0; i < m * n; ++i) {
        A[i] = (float)i;
        B[i] = (float)(m * n - i);
    }
    fill_random(dC, m * n);

    backward_N_min_A(dA, dC, A, B, m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_FLOAT_EQ(dA[i], dC[i] * bMin(A[i], B[i]));
    }

    delete[]  A;
    delete[]  B;
    delete[] dA;
    delete[] dC;
}
/**********************************************************************
 * 
 *  vector min backward test. (for vector B)
 * 
**********************************************************************/
TEST(backward_N_min_B, specific_case0) {

    const int m = 16, n = 16;
    float *A = new float[m * n];
    float *B = new float[m * n];
    float *dC = new float[m * n];
    float *dB = new float[m * n];

    for(int i = 0; i < m * n; ++i) {
        A[i] = (float)i;
        B[i] = (float)(m * n - i);
    }
    //fill_random(dC, m * n);
    fill_with(dC, 1, m * n);
    fill_with(dB, 2, m * n);

    backward_N_min_B(dB, dC, A, B,  m * n);

    for(int i = 0; i < m * n; ++i) {
        EXPECT_FLOAT_EQ(dB[i], dC[i] * bMin(B[i], A[i]));
    }

    delete[]  A;
    delete[]  B;
    delete[] dB;
    delete[] dC;
}
#undef min
#endif // IGNORE_VECTOR_MIN = =1