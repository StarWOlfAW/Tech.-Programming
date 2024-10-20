#include <iostream>
using namespace std;
int main()
{
    double x, N, E;
    int k, znak;
    double chisl, znam, sl, s;
    cout << "Enter x "; cin >> x;
    cout << "Enter n "; cin >> N;
    cout << "Enter e "; cin >> E;

    //1
    s = 0; chisl = 1; znam = 1; znak = 1; k = 2;
    for (int i = 1; i <= N; i++)
    {
        sl = znak * chisl / znam;
        s = s + sl;
        chisl = chisl * x;
        znam = znam * k;
        znak = znak * (-1);
        k = k + 1;
    }
    cout << "S1=" << s << " n=" << N << endl;

    //2
    s = 0; chisl = 1; znam = 1; znak = 1; k = 2;
    for (int i = 1; i <= N; i++)
    {
        sl = znak * chisl / znam;
        s = s + sl;
        chisl = chisl * x;
        znam = znam * k;
        znak = znak * (-1);
        k = k + 1;
    }
    cout << "S2=" << s << " n=" << N << endl;

    //3
    s = 0; chisl = 1; znam = 1; znak = 1; k = 2;
    for (int i = 1; i <= N; i++)
    {
        sl = znak * chisl / znam;
        s = s + sl;
        chisl = chisl * x;
        znam = znam * k;
        znak = znak * (-1);
        k = k + 1;
    }
    cout << "S3=" << s << " n=" << N << endl;
    cout << "Tochoe znachenie \n sin(x)/x=" << pow(2.71828 , -x) << endl;
    system("pause");
    return 0;
}