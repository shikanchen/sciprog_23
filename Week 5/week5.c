#include <stdio.h>
#include <math.h>

// calculate Fibonacci sequence
void fibonacci_sequence(int n) {
    
    // declare vars
    int i;
    unsigned long long fib[n];
    fib[0] = 0;
    fib[1] = 1;
    printf("Fibonacci Series up to %d: %llu %llu ", n, fib[0], fib[1]);

    // loop to setter all elements up to n
    for (i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("%llu ", fib[i]);
    }
    printf("\n");
}

// calculate artanh using Maclaurin series
double approximate_artanh(double x, double precision) {
    double approx_val = 0.0;
    double te = x;
    int k = 1;

    // loop for fabs is lower than precision
    while (fabs(te) > precision) {
        approx_val += te;
        te = te * x * x * (2 * k - 1) / (2 * k + 1);
        k++;
    }

    return approx_val;
}

// calculate logarithmic artanh
double logarithmic_artanh(double x) {
    return 0.5 * log((1 + x) / (1 - x));
}

int main() {
    
    // scan and calculate fib sequence
    int count;
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &count);
    fibonacci_sequence(count);

    // scan for delta of Artanh calculation
    double delta;
    printf("Enter the delta for artanh calculation: ");
    scanf("%lf", &delta);

    // calculate and store results for artanh
    double x, artanh1_val, artanh2_val;
    printf("x, artanh1(x), artanh2(x), Difference\n");
    for (x = -0.9; x <= 0.9; x += 0.01) {
        artanh1_val = approximate_artanh(x, delta);
        artanh2_val = logarithmic_artanh(x);
        printf("%.2f, %.10f, %.10f, %.10f\n",
               x, artanh1_val, artanh2_val, fabs(artanh1_val - artanh2_val));
    }

    return 0;
}
