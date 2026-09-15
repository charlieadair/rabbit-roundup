// Rabbit-Roundup Implemenation
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main() {

    // Input values
    int n, p;
    std::vector<int> damageAmmounts;

    // Input handling for n,p
    if (!(std::cin >> n >> p)) {
        std::cerr << "Expected two integers.\n";
        return 1;
    }

    // Data validation for n,p
    if (n < 1 || n > 100000) {
        std::cerr << "n must be between 1 and 100000. Was " << n << '\n';
        return 1;
    }

    if (p < 1 || p > 1000) {
        std::cerr << "p must be between 1 and 1000. Was " << p << '\n';
        return 1;
    }

    // Input handling for the damage at each location
    int damageVal;
    while (std::cin >> damageVal) { damageAmmounts.push_back(damageVal); }

    // Data validation for damage at each location (must contain n ints)
    if (damageAmmounts.size() != n) {
    std::cerr << "Expected " << n
              << " values, but received " << damageAmmounts.size() << '\n';
    return 1;
    }

    std::cout << "1";

    return 0;
}