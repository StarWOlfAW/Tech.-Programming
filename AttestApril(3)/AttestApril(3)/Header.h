#ifndef Main
#define Main
void input_matrix(float** a, int n);
void output_matrix(float** a, int n);
void mult(float** a, float** b, float** res, int n);
bool equal(float** a, float** b, int n);
void coeff(float** a, float k, float** res, int n);
void minus(float** a, float** b, float** res, int n);
void plusm(float** a, float** b, float** res, int n);
float** create_matrix(int n);
void free_matrix(float** m, int n);
#endif
