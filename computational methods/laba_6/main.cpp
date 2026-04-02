#include <iostream>
#include <cmath>
#include <iomanip>

double f_a(double x) { return exp(x * x); }

void task_a() {
    double a = 0, b = 1;
    int n = 10;
    double h = (b - a) / n;
    
    double sum_odd = 0, sum_even = 0;
    for(int i = 1; i < n; i++) {
        if(i % 2 != 0) sum_odd += f_a(a + i * h);
        else sum_even += f_a(a + i * h);
    }
    
    double I = (h / 3) * (f_a(a) + f_a(b) + 4 * sum_odd + 2 * sum_even);
    
    double f4_max = 76 * exp(1); 
    double R = (pow(h, 4) * (b - a) / 180) * f4_max;

    std::cout << "Task a) Simpson's rule: I = " << std::fixed << std::setprecision(6) << I << std::endl;
    std::cout << "Error estimate |R| <= " << R << std::endl;
}

double f_b(double x) { return 1.0 / (1.0 + x); }

void task_b() {
    double a = 0, b = 1, eps = 1e-4;
    double h = sqrt(12 * eps / (1.0 * 2.0));
    int n = ceil((b - a) / h);
    h = (b - a) / n; 

    double sum = 0.5 * (f_b(a) + f_b(b));
    for(int i = 1; i < n; i++) sum += f_b(a + i * h);
    double I = sum * h;

    std::cout << "Task b) Trapezoidal rule (h=" << h << "): I = " << I << std::endl;
}

void task_c() {
    double x_max = 0.5;
    double I = 0, term;
    int k = 0;
    do {
        term = pow(-1, k) * pow(x_max, 2 * k + 1) / pow(2 * k + 1, 2);
        I += term;
        k++;
    } while (std::abs(term) > 1e-4); 

    std::cout << "Task c) Power series: I = " << I << " (Terms used: " << k << ")" << std::endl;
}

void task_d() {
    double x[] = {0.263560, 1.413403, 3.596425, 7.085810, 12.640801};
    double A[] = {0.521756, 0.398667, 0.075942, 0.003612, 0.000023};
    
    std::cout << "Task d) Laguerre Quadrature (n=5):" << std::endl;
    for(int i = 0; i <= 4; i++) {
        double a = 0.6 + 0.2 * (6 + i); 
        double I = 0;
        for(int j = 0; j < 5; j++) {
            I += A[j] * (1.0 / (a + sqrt(x[j])));
        }
        std::cout << "k=" << 6+i << ", a=" << a << " -> I = " << I << std::endl;
    }
}

double f_e(double x, double y) { return 1.0 / (1.0 + 0.1 * (x + y)); }

void task_e() {
    double ax = 0, bx = 2, ay = 0.5, by = 1.5;
    int nx = 10, ny = 5;
    double hx = (bx - ax) / nx, hy = (by - ay) / ny;

    auto inner_integral = [&](double x) {
        double sum = 0.5 * (f_e(x, ay) + f_e(x, by));
        for(int j = 1; j < ny; j++) sum += f_e(x, ay + j * hy);
        return sum * hy;
    };

    double total_sum = 0.5 * (inner_integral(ax) + inner_integral(bx));
    for(int i = 1; i < nx; i++) total_sum += inner_integral(ax + i * hx);
    double I = total_sum * hx;

    std::cout << "Task e) Double integral (Repeated Trapezoidal): I = " << I << std::endl;
}

int main() {
    task_a(); task_b(); task_c(); task_d(); task_e();
    return 0;
}