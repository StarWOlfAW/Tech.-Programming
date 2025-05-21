#include "Header.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


double abs_complex(complex* c1) {
    return sqrt(c1->Re * c1->Re + c1->Im * c1->Im);
}


complex multiply(complex* c1, complex* c2) {
    complex res;
    res.Re = c1->Re * c2->Re - c1->Im * c2->Im;
    res.Im = c1->Im * c2->Re + c1->Re * c2->Im;
    return res;
}


complex power(complex* c1, int n) {
    complex res;
    res.Re = 1;
    res.Im = 0;
    for (int i = 0; i < n; i++) {
        res = multiply(&res, c1);
    }
    return res;
}


complex root(complex* c, int n) {
    if (n <= 0) {
        complex zero;
        zero.Re = 0;
        zero.Im = 0;
        return zero;
    }

    double r = pow(abs_complex(c), 1.0 / n);
    double theta = atan2(c->Im, c->Re) / n;

    complex res;
    res.Re = r * cos(theta);
    res.Im = r * sin(theta);
    return res;
}


complex pluss(complex* c1, complex* c2) {
    complex res;
    res.Re = c1->Re + c2->Re;
    res.Im = c1->Im + c2->Im;
    return res;
}


complex minuss(complex* c1, complex* c2) {
    complex res;
    res.Re = c1->Re - c2->Re;
    res.Im = c1->Im - c2->Im;
    return res;
}


complex div(complex* c1, complex* c2) {
    complex res;
    double denominator = c2->Re * c2->Re + c2->Im * c2->Im;
    res.Re = (c1->Re * c2->Re + c1->Im * c2->Im) / denominator;
    res.Im = (c1->Im * c2->Re - c1->Re * c2->Im) / denominator;
    return res;
}

complex scalar_multiply(complex* c, double scalar) {
    complex res;
    res.Re = c->Re * scalar;
    res.Im = c->Im * scalar;
    return res;
}


void input_complex(complex* c) {
    c->Re = rand() % 19 - 9;
    c->Im = rand() % 19 - 9;
}

void output_complex(complex* c) {
    cout << c->Re;
    if (c->Im >= 0)
        cout << "+";
    cout << c->Im << "i";
}