// Rabbit-Roundup Implemenation
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>

// Creates a new array from the sites where the cost per site is decremented by p
std::vector<int> makeSavingsArray(std::vector<int> sites, int p, int n) {
    std::vector<int> savings;
    for (int i = 0; i < n; i++) {
        savings.push_back(sites[i] - p);
    }
    return savings;
}

// Recursively finds the savings subarray with the greatest sum.
int maxSavings(const std::vector<int>& savings, int lo, int hi) {

    // Base case returns 0 because the savings isn't    going to be negative.
    int range = hi - lo + 1;
    if (range == 1) {
        return savings[lo] < 0 ? 0 : savings[lo];
    }

    int mid = lo + (hi - lo) / 2;

    // Recurse left and right sides
    int left = maxSavings(savings, lo, mid);
    int right = maxSavings(savings, mid + 1, hi);

    // Evaluate the seam
    int walkLeft = INT_MIN;
    int runningSum = 0;
    for (int i = mid; i >= lo; i--) {
        runningSum += savings[i];
        walkLeft = (walkLeft > runningSum) ? walkLeft : runningSum;
    }

    int walkRight = INT_MIN;
    runningSum = 0;
    for (int i = mid + 1; i <= hi; i++) {
        runningSum += savings[i];
        walkRight = (walkRight > runningSum) ? walkRight : runningSum;
    }

    int middleSum = walkRight + walkLeft;

    // The max is always found exclusively in the middleSum, left or right
    return std::max({middleSum, left, right});
}

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
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> damageVal)) { 
            // the number of integers on line 2 must be = n
            std::cerr << "Expected " << n
            << " values, but received " << damageAmmounts.size() << '\n';
            return 1;
        }
        damageAmmounts.push_back(damageVal);
    }

    std::vector<int> savingsPerSite = makeSavingsArray(damageAmmounts,p, n);


    printf("%d\n", maxSavings(savingsPerSite, 0, n - 1 ) );

    return 0;
}