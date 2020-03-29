#include <iostream>

int sum_of_two_digits(int first_digit, int second_digit) {
    return first_digit + second_digit;
}

int main() {
    int a = 10;
    int b = 10;
    std::cin >> a;
    std::cin >> b;
    std::cout << sum_of_two_digits(a, b) << "\n";
    system("pause");
    return 0;
}
