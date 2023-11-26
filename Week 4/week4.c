#include <stdio.h>
#include <math.h>

// Global array to store tan(x) values
#define SIZE 13
double tan_values[SIZE];

// Function to convert degrees to radians
double degrees2radians(double degree) {
    return degree * (M_PI / 180.0);
}

// calculate the area under the curve using the Trapezoidal Rule
double trapezoidal_area(int points) {
    // declare vars
    int i;
    double a = 0;
    double b = degrees2radians(60);
    double h = (b - a) / (points - 1);
    double area = (tan(a) + tan(b)) / 2.0;
    
    // add the middle terms
    for (i = 1; i < points - 1; i++) {
        double x = a + i * h;
        area += tan(x);
    }
    
    // times the height
    area *= h;
    return area;
}

int main() {
    
    // Declare var
    int i;
    
    // Calculate tan(x) values
    for (i = 0; i < SIZE; i++) {
        double degree = i * 5;
        double radians = degrees2radians(degree);
        tan_values[i] = tan(radians);
        printf("tan(%lf degrees) = %lf\n", degree, tan_values[i]);
    }
    
    // use trapezoidal rule to get the area
    double area = trapezoidal_area(SIZE);
    printf("Area under the curve from 0 to 60 degrees using the Trapezoidal Rule: %lf\n", area);
    
    return 0;
}
