#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

#include "primelist.h"

int main() {
    long long left = 0, right = 0;
    std::cin >> left >> right;

    if (std::cin.fail() || left < 1 || right < 1 || left > INT_MAX || right > INT_MAX) {
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
