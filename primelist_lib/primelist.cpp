#include "primelist.h"

namespace {

// Проверка числа на простоту перебором делителей.
// Достаточно проверить делители до sqrt(n): если у n есть делитель
// больше sqrt(n), то есть и парный делитель меньше sqrt(n).
bool isprime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

} // namespace

std::vector<int> primelist(int l, int r) {
    std::vector<int> result;
    // long long - чтобы счётчик не переполнился при r == INT_MAX
    for (long long n = l; n <= r; ++n) {
        if (isprime(static_cast<int>(n))) {
            result.push_back(static_cast<int>(n));
        }
    }
    return result;
}
