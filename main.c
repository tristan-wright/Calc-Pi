#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 180

int simulate(double nPoints);
int generate_point(void);
double calculate_distance(int x, int y);
int power(int base, int exp);

int main() {
    // Max Points 1000000000;
    return simulate(10000000);

}

int simulate(double nPoints) {
    time_t t;
    srand((unsigned) time(&t));
    int totalIn = 0;


    for (int i = 0; i < nPoints; ++i) {
        int x = generate_point();
        int y = generate_point();

        double distance = calculate_distance(x, y);
        if (distance < RADIUS) {
            totalIn++;
        }
    }

    double pi = 4.0 * (totalIn / nPoints);
    printf("%lf", pi);

    return EXIT_SUCCESS;

}

int power(int base, int exp) {
    int result = 1;
    for (;exp > 0; exp--) {
        result = result * base;
    }
    return result;
}

double calculate_distance(int x, int y) {
    int result = power(x, 2) + power(y, 2);
    return sqrt(result);
}


int generate_point(void) {
    int negation = rand() % 2;
    int point = rand() % RADIUS;

    if (negation) {
        point = point * -1;
        return point;
    }
    return point;
}