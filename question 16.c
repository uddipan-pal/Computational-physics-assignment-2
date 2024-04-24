#include <stdio.h>
#include <math.h>
//question 16
double exact_solution(double t) {
    return pow(t + 1, 2) - 0.5 * exp(t);
}

double euler_method(double t, double y, double h) {
    return y + h * (y - pow(t, 2) + 1);
}

double error_bound(double t, double h) {
    return 0.2 * (1 + t + h);
}

int main() {
    double t0 = 0.0;  // initial time
    double y0 = 0.5;  // initial value of y
    double h = 0.2;   // step size
    double t, y, err, bound;

    printf("t\tExact\t\tEuler\t\tError\t\tError Bound\n");
    printf("--------------------------------------------------\n");

    for (t = t0; t <= 2; t += h) {
        y = euler_method(t, y0, h);
        err = fabs(y - exact_solution(t));
        bound = error_bound(t, h);
        printf("%.1f\t%.6f\t%.6f\t%.6f\t%.6f\n", t, exact_solution(t), y, err, bound);
        y0 = y;  // update y for the next step
    }

    return 0;
}
