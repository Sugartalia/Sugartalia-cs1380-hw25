/* Natalia Robertson - CS 1380 HW25 */
#include <stdio.h>

/* Precondition: n >= 0 */
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

/* Precondition: n >= 0 */
/* WHY: naive fib repeats the same work, so it gets very slow past n = 40. */
long long fib(int n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

/* Returns 0 if a is NULL or n <= 0 */
int max_in_array(const int *a, int n) {
    if (a == NULL || n <= 0) {
        return 0;
    }
    if (n == 1) {
        return a[0];
    }
    int rest = max_in_array(a + 1, n - 1);
    if (a[0] > rest) {
        return a[0];
    }
    return rest;
}

int is_palindrome(const char *s, int i, int j) {
    if (s == NULL) {
        return 0;
    }
    if (i >= j) {
        return 1;
    }
    if (s[i] != s[j]) {
        return 0;
    }
    return is_palindrome(s, i + 1, j - 1);
}

int main(void) {
    printf("factorial(0) = %lld\n", factorial(0));
    printf("factorial(5) = %lld\n", factorial(5));
    printf("fib(0) = %lld\n", fib(0));
    printf("fib(10) = %lld\n", fib(10));

    int nums[] = {3, 9, 2, 7, 5};
    printf("max_in_array = %d\n", max_in_array(nums, 5));

    printf("is_palindrome(racecar) = %d\n", is_palindrome("racecar", 0, 6));
    printf("is_palindrome(hello) = %d\n", is_palindrome("hello", 0, 4));

    return 0;
}
