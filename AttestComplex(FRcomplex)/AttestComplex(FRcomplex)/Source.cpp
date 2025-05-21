#include "Header.h"
#include <iostream>

using namespace std;


int main() {
    srand(time(0));

    complex c1, c2, c3, c4, c5;
    input_complex(&c1);
    input_complex(&c2);
    input_complex(&c3);
    input_complex(&c4);
    input_complex(&c5);

    cout << "Our complex numbers:" << endl;
    cout << "c1 = "; output_complex(&c1); cout << endl;
    cout << "c2 = "; output_complex(&c2); cout << endl;
    cout << "c3 = "; output_complex(&c3); cout << endl;
    cout << "c4 = "; output_complex(&c4); cout << endl;
    cout << "c5 = "; output_complex(&c5); cout << endl << endl;

    // (((c1 + 4c2)^1/2) - (15c3 * 7c4^2)) / ((c1^3 + c4^2/7) * c5^3)

    // 4c2
    complex c2_4 = scalar_multiply(&c2, 4);

    // c1 + 4c2
    complex temp1 = pluss(&c1, &c2_4);

    //(c1 + 4c2)
    complex sqrt_temp1 = root(&temp1, 2);

    // 15c3
    complex c3_15 = scalar_multiply(&c3, 15);

    // 7c4
    complex c4_7 = scalar_multiply(&c4, 7);

    // (7c4)^2
    complex c4_7_sq = power(&c4_7, 2);

    // 15c3 *(7c4)^2
    complex temp2 = multiply(&c3_15, &c4_7_sq);

    // sqrt(...) - (...)
    complex numerator = minuss(&sqrt_temp1, &temp2);

    // c1^3
    complex c1_cubed = power(&c1, 3);

    // c4^2
    complex c4_sq = power(&c4, 2);

    // c4^2 / 7
    complex c4_sq_div7 = scalar_multiply(&c4_sq, 1.0 / 7.0);

    // c1^3 + c4^2/7
    complex temp3 = pluss(&c1_cubed, &c4_sq_div7);

    // c5^3
    complex c5_cubed = power(&c5, 3);

    // (...) * c5^3
    complex denominator = multiply(&temp3, &c5_cubed);

    //  numerator / denominator (obvious)
    complex result = div(&numerator, &denominator);

    cout << "Final result : ";
    output_complex(&result);
    cout << endl;

    return 0;
}