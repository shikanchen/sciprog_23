#include <stdio.h>

// Iterative for GCD
int gcd_iterative(int a, int b) {
    
    // break loop when b is 0
    while (b != 0) {
        
        // save old b using dummy as a temp var
        int dummy = b;
        
        // update b
        b = a % b;
        
        // pass dummy to a
        a = dummy;
    }
    
    // return the final gcd
    return a;
}

// Recursive for GCD
int gcd_recursive(int a, int b) {
    
    // exit
    if (b == 0)
        
        // return the basis case gcd
        return a;
    
    // call a%b for new b
    else
        
        // return the gcd recursively
        return gcd_recursive(b, a % b);
}

int main() {
    
    // init two numbers
    int num1, num2;
    
    // read two numbers
    printf("Enter two integers separated by a space (a b): ");
    scanf("%d %d", &num1, &num2);

    // get GCD iteratively
    int iterative_gcd = gcd_iterative(num1, num2);
    printf("GCD (Iterative) of %d and %d is %d\n", num1, num2, iterative_gcd);

    // get GCD recursively
    int recursive_gcd = gcd_recursive(num1, num2);
    printf("GCD (Recursive) of %d and %d is %d\n", num1, num2, recursive_gcd);

    return 0;
}
