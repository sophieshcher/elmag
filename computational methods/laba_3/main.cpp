#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void task_13_a() {
    auto f = [](double x) { return pow(x, 5) - x - 0.2; };
    auto df = [](double x) { return 5 * pow(x, 4) - 1; };
    auto ddf = [](double x) { return 20 * pow(x, 3); };

    double a = 0.0, b = 2.0, h = 0.1; 
    double x0 = 0;
    for (double i = a; i <= b; i += h) {
        if (f(i) * f(i + h) < 0) {
            a = i;
            b = i + h;
            break;
        }
    }

    if (f(a) * ddf(a) > 0) x0 = a;
    else x0 = b;

    cout << "--- 13.a (Newton) ---" << endl;
    cout << "Isolated interval: [" << a << ", " << b << "]" << endl;
    cout << "Selected x0 = " << x0 << setprecision(6) << endl;

    double x_k = x0;
    double eps = 1e-4;
    int iter = 0;

    while (true) {
        iter++;
        double x_next = x_k - f(x_k) / df(x_k); 
        if (abs(x_next - x_k) < eps) { 
            x_k = x_next;
            break;
        }
        x_k = x_next;
    }
    cout << "Result: " << x_k << " Iterations: " << iter << "\n" << endl;

}

void task_13_b() {
    double x = 0.5, y = 0.2; 
    double eps = 1e-5;
    int iterations = 0;

    cout << "--- 13.b ---" << endl;
    while (true) {
        iterations++;
        
        double F = exp(x * y) - pow(x, 2) + y - 1;
        double G = pow(x + 0.5, 2) + pow(y, 2) - 1;

        double f_x = y * exp(x * y) - 2 * x;
        double f_y = x * exp(x * y) + 1;
        double g_x = 2 * (x + 0.5);
        double g_y = 2 * y;

        double J = f_x * g_y - f_y * g_x;

        double delta_x = (F * g_y - f_y * G) / J;
        double delta_y = (f_x * G - F * g_x) / J;

        x -= delta_x;
        y -= delta_y;

        if (max(abs(delta_x), abs(delta_y)) < eps) break;
    }

    cout << "Result: x = " << x << ", y = " << y << endl;
    cout << "Iterations: " << iterations << "\n" << endl;
}


void task_13_с() {
    double x = 0.5, y = 0.2;
    double eps = 1e-5;
    int iterations = 0;

    cout << "---  13.c ---" << endl;
    while (true) {
        iterations++;
        double y_new = 1.0 - exp(x * y) + pow(x, 2);
        double x_new = sqrt(abs(1.0 - pow(y, 2))) - 0.5;

        if (abs(x_new - x) < eps && abs(y_new - y) < eps) {
            x = x_new; y = y_new;
            break;
        }
        x = x_new; y = y_new;
        if (iterations > 1000) break; 
    }

    cout << "Result: x = " << x << ", y = " << y << endl;
    cout << "Iterations: " << iterations  << endl;
}


int main() {
    task_13_a();
    task_13_b();
    task_13_с();

    return 0;
}