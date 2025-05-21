#ifndef Source
#define Source
struct complex {
    double Re;
    double Im;
};

double abs_complex(complex* c1);
complex multiply(complex* c1, complex* c2);
complex power(complex* c1, int n);
complex root(complex* c, int n);
complex pluss(complex* c1, complex* c2);
complex minuss(complex* c1, complex* c2);
complex div(complex* c1, complex* c2);
complex scalar_multiply(complex* c, double scalar);
void input_complex(complex* c);
void output_complex(complex* c);
#endif


