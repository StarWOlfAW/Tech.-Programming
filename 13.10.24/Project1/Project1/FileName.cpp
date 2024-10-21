#include <iostream>
#include <vector>

int main() {
    int number;
    using namespace std;
    cout << "Enter numbers: ";
    cin >> number;

    int minDigit = 9, maxDigit = 0;
    vector<int> digits;

   
    while (number > 0) {
        int digit = number % 10;
        digits.push_back(digit);
        if (digit < minDigit) minDigit = digit;
        if (digit > maxDigit) maxDigit = digit;
        number /= 10;
    }

   
    c
    for (int i = digits.size() - 1; i >= 0; --i) { 
        if (digits[i] > minDigit && digits[i] < maxDigit) {
            cout << digits[i];
        }
    }

    std::cout << std::endl;

    return 0;
}
