#include <stdio.h>
#include <stdbool.h>

/* Ελέγχει αν ένας αριθμός είναι πρώτος */
bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

/* Βρίσκει την αναπαράσταση Goldbach (n = p + q) */
void solve_goldbach(long long n) {
    if (n <= 2 || n % 2 != 0) {
        printf("Goldbach's conjecture is applicable only to even numbers greater than 2!\n");
        return;
    }
    for (long long p = 2; p <= n / 2; p++) {
        if (is_prime(p) && is_prime(n - p)) {
            printf("%lld = %lld + %lld\n", n, p, n - p);
            return;
        }
    }
}

int main(void) {
    long long n;
    char choice;

    while (1) {
        printf("Give me a number: ");
        fflush(stdout);

        int res = scanf("%lld", &n);
        if (res == EOF) {
            printf("EOF detected, exiting\n");
            return 0;
        }
        if (res != 1) {
            fprintf(stderr, "Invalid input: expected an integer\n");
            return 1;
        }

        if (n < 0 || n > 10000000000LL) {
            fprintf(stderr, "Number should be in the range [0, 10000000000]\n");
            return 1;
        }

        printf("Choose how to test %lld - ('p' for prime, 'g' for goldbach) ", n);
        fflush(stdout);

        res = scanf(" %c", &choice);
        if (res == EOF) {
            printf("EOF detected, exiting\n");
            return 0;
        }

        if (choice == 'p') {
            if (is_prime(n)) {
                printf("%lld is prime\n", n);
            } else {
                printf("%lld is not prime\n", n);
            }
        } else if (choice == 'g') {
            solve_goldbach(n);
        } else {
            fprintf(stderr, "Invalid choice: expected 'p' or 'g'\n");
            return 1;
        }
    }

    return 0;
}
