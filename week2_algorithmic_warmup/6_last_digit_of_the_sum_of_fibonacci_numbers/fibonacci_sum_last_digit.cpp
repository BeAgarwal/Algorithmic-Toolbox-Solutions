#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long prev = 0;
    long long curr = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_prev = prev;
        prev = curr;
        curr = tmp_prev + curr;
        sum += curr;
    }

    return sum % 10;
}

int get_fibonacci_last_digit_fast(long long n) {
    if (n <= 1)
        return n;

    int prev = 0;
    int curr = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_prev = prev % 10;
        prev = curr % 10;
        curr = tmp_prev + curr % 10;
    }
    return curr % 10;
}

int fibonacci_sum_fast(long long n) {
    int new_n = (n + 2) % 60;
    int new_last = get_fibonacci_last_digit_fast(new_n);
    if (new_last == 0) {
        return 9;
    } else {
        return new_last - 1;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}