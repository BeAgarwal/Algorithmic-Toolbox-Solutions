#include <iostream>

using std::cin;
using std::cout;

int gcd_naive(int a, int b) {
    int cd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > cd) {
                cd = d;
            }
        }
    }
    return cd;
}

int euclid_gcd(int a, int b) {
    int divisor = a >= b ? a : b;
    int dividend = a <= b ? a : b;
    while (divisor != 0) {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

int main() {
    int a, b;

    std::cin >> a >> b;
    std::cout << euclid_gcd(a, b) << std::endl;
    return 0;
}