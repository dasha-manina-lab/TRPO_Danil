#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <vector>

#include "primelist.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Ошибка: укажите нижнюю и верхнюю границы диапазона.\n";
        return 1;
    }

    long long left = 0, right = 0;
    std::istringstream leftInput(argv[1]);
    std::istringstream rightInput(argv[2]);
    leftInput >> left;
    rightInput >> right;

    if (leftInput.fail() || rightInput.fail() || left < 1 || right < 1 || left > INT_MAX || right > INT_MAX) {
        std::cerr << "Ошибка: нужно ввести два натуральных числа." << std::endl;
        return 1;
    }
    if (left > right) {
        std::swap(left, right);
    }

    std::vector<int> primes = primelist(static_cast<int>(left), static_cast<int>(right));
    for (int n : primes) {
        std::cout << n << '\n';
    }
    return 0;
}
