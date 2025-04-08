#include "Header.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int n = 3;
    float** A = create_matrix(n);
    float** B = create_matrix(n);
    float** C = create_matrix(n);

    input_matrix(A, n);
    input_matrix(B, n);
    input_matrix(C, n);

    float a_coeff = 9.9f;
    float b_coeff = 6.0f;
    float c_coeff = 3.0f;

    float** c1 = create_matrix(n);  // a*A
    float** c2 = create_matrix(n);  // b*B
    float** c3 = create_matrix(n);  // c*C

    float** c4 = create_matrix(n);  // A + B + C
    float** c5 = create_matrix(n);  // (A+B+C)^2 (Ñ|ÑuÑrÑpÑë ÑâÑpÑÉÑÑÑé)

    float** c6 = create_matrix(n);  // A^2
    float** c7 = create_matrix(n);  // B^2
    float** c8 = create_matrix(n);  // C^2

    float** c9 = create_matrix(n);  // AB
    float** c10 = create_matrix(n); // BA
    float** c11 = create_matrix(n); // AC
    float** c12 = create_matrix(n); // CA
    float** c13 = create_matrix(n); // BC
    float** c14 = create_matrix(n); // CB

    float** c15 = create_matrix(n); // a^2*A^2
    float** c16 = create_matrix(n); // b^2*B^2
    float** c17 = create_matrix(n); // c^2*C^2

    float** c18 = create_matrix(n); // a*b*AB
    float** c19 = create_matrix(n); // a*b*BA
    float** c20 = create_matrix(n); // a*c*AC
    float** c21 = create_matrix(n); // a*c*CA
    float** c22 = create_matrix(n); // b*c*BC
    float** c23 = create_matrix(n); // b*c*CB

    float** c24 = create_matrix(n); // ÑPÑÇÑpÑrÑpÑë ÑâÑpÑÉÑÑÑé: ÑÉÑÖÑ}Ñ}Ñp ÑrÑÉÑuÑá Ñ{ÑÄÑ}ÑÅÑÄÑ~ÑuÑ~ÑÑÑÄÑr

    //(aA + bB + cC)^2
    coeff(A, a_coeff, c1, n);
    coeff(B, b_coeff, c2, n);
    coeff(C, c_coeff, c3, n);

    plusm(c1, c2, c4, n);  // aA + bB
    plusm(c4, c3, c4, n);  // aA + bB + cC
    mult(c4, c4, c5, n);  // (aA + bB + cC)^2

    //a^2A^2 + b^2B^2 + c^2C^2 + abAB + abBA + acAC + acCA + bcBC + bcCB
    
    mult(A, A, c6, n);   // A^2
    mult(B, B, c7, n);    // B^2
    mult(C, C, c8, n);    // C^2

    mult(A, B, c9, n);    // AB
    mult(B, A, c10, n);   // BA
    mult(A, C, c11, n);   // AC
    mult(C, A, c12, n);   // CA
    mult(B, C, c13, n);   // BC
    mult(C, B, c14, n);   // CB

    coeff(c6, a_coeff * a_coeff, c15, n);  // a^2*A^2
    coeff(c7, b_coeff * b_coeff, c16, n);  // b^2*B^2
    coeff(c8, c_coeff * c_coeff, c17, n);  // c^2*C^2

    coeff(c9, a_coeff * b_coeff, c18, n);  // ab*AB
    coeff(c10, a_coeff * b_coeff, c19, n); // ab*BA
    coeff(c11, a_coeff * c_coeff, c20, n); // ac*AC
    coeff(c12, a_coeff * c_coeff, c21, n); // ac*CA
    coeff(c13, b_coeff * c_coeff, c22, n); // bc*BC
    coeff(c14, b_coeff * c_coeff, c23, n); // bc*CB

    plusm(c15, c16, c24, n);   // a^2A^2 + b^2B^2
    plusm(c24, c17, c24, n);   // + c^2C^2
    plusm(c24, c18, c24, n);   // + abAB
    plusm(c24, c19, c24, n);   // + abBA
    plusm(c24, c20, c24, n);   // + acAC
    plusm(c24, c21, c24, n);   // + acCA
    plusm(c24, c22, c24, n);   // + bcBC
    plusm(c24, c23, c24, n);   // + bcCB

    cout << "Left side " << endl;
    output_matrix(c5, n);
    cout << "Right side " << endl;
    output_matrix(c24, n);

    if (equal(c5, c24, n)) {
        cout << "Equal " << endl;
    }
    else {
        cout << "Not equal" << endl;
    }
    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    free_matrix(c1, n);
    free_matrix(c2, n);
    free_matrix(c3, n);
    free_matrix(c4, n);
    free_matrix(c5, n);
    free_matrix(c6, n);
    free_matrix(c7, n);
    free_matrix(c8, n);
    free_matrix(c9, n);
    free_matrix(c10, n);
    free_matrix(c11, n);
    free_matrix(c12, n);
    free_matrix(c13, n);
    free_matrix(c14, n);
    free_matrix(c15, n);
    free_matrix(c16, n);
    free_matrix(c17, n);
    free_matrix(c18, n);
    free_matrix(c19, n);
    free_matrix(c20, n);
    free_matrix(c21, n);
    free_matrix(c22, n);
    free_matrix(c23, n);
    free_matrix(c24, n);

    return 0;
}
