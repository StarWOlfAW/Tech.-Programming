#include <iostream>
#include <vector>

int main() {
    long long number;
    using namespace std;
    cout << "Введите число: ";
    cin >> number;

    int minDigit = 9, maxDigit = 0;
    vector<int> digits;

    // Извлекаем цифры и находим минимальную и максимальную
    while (number > 0) {
        int digit = number % 10;
        digits.push_back(digit);
        if (digit < minDigit) minDigit = digit;
        if (digit > maxDigit) maxDigit = digit;
        number /= 10;
    }

    // Выводим цифры между минимальной и максимальной
    cout << "Цифры между минимальной и максимальной: ";
    for (int i = digits.size() - 1; i >= 0; --i) { // Перебираем в обратном порядке
        if (digits[i] > minDigit && digits[i] < maxDigit) {
            cout << digits[i];
        }
    }

    std::cout << std::endl;

    return 0;
}
