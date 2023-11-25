#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    for (int order = 1; order <= 15; ++order) {
        
        // init
        double est = 1.0;
        double factorial = 1.0;
        
        // calculate factorial and add to est
        for (int i = 1; i <= order; ++i) {
            factorial *= i;
            est += 1.0 / factorial;
        }
        
        // print result each iteration
        printf("Estimate of e with %d order polynomial: %.15f\n", order, est);
    }

    // print actual e
    printf("Actual value of e: %.15f\n", M_E);

    return 0;
}
