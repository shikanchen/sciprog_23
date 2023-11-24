#include <stdio.h>
#include <math.h>

int main() {
    
    // declare vars
    double a = 0;
    double b = M_PI / 3;
    int N = 12;
    double h = (b - a) / N;
    double sum = tan(a) + tan(b);

    // sum for 2 * f(x_i)
    for (int i = 1; i < N; i++) {
        double x_i = a + i * h;
        sum += 2 * tan(x_i);
    }
    
    // calculate the area
    double area = (b - a) * sum / (2 * N);
    
    // print the result
    printf("Trapezoidal Rule Result: %f\n", area);
    printf("Actual Result (log(2)): %f\n", log(2));
    printf("Difference: %f\n", area - log(2));
    
    return 0;
}
