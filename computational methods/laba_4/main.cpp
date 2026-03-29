#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void task_1_lagrange() {
    double target_x = 3.88;
    vector<double> x_nodes = {2.0, 2.3, 2.5, 3.0, 3.5, 3.8, 4.0};
    vector<double> y_nodes = {5.848, 6.127, 6.300, 6.694, 7.047, 7.243, 7.368};
    
    double result_y = 0;
    int n = x_nodes.size();

    for (int i = 0; i < n; i++) {
        double Li = 1.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                Li *= (target_x - x_nodes[j]) / (x_nodes[i] - x_nodes[j]);
            }
        }
        result_y += y_nodes[i] * Li;
    }

    cout << "--- Task 1: Lagrange Interpolation ---" << endl;
    cout << "Value y(" << target_x << ") = " << fixed << setprecision(7) << result_y << endl << endl;
}

void task_2_aitken() {
    double target_x = 1.178;
    vector<double> x_nodes = {1.00, 1.08, 1.13, 1.20, 1.27, 1.31, 1.38};
    vector<double> f_nodes = {1.17520, 1.30254, 1.38631, 1.50946, 1.21730, 1.22361, 1.23470};
    
    int n = x_nodes.size();
    vector<vector<double>> P(n, vector<double>(n));
    for (int i = 0; i < n; i++) P[i][0] = f_nodes[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            P[i][j] = (P[i][j-1] * (x_nodes[i+j] - target_x) - 
                       P[i+1][j-1] * (x_nodes[i] - target_x)) / 
                      (x_nodes[i+j] - x_nodes[i]);
        }
    }

    cout << "--- Task 2: Aitken's Scheme ---" << endl;
    cout << "Value f(" << target_x << ") = " << setprecision(5) << P[0][n-1] << endl << endl;
}

void task_3_inverse_interpolation() {
    auto f = [](double x) { 
        return sqrt(x) - 2.0 * cos(M_PI * x / 2.0); 
    };

    double a = 0.7, b = 0.8, h = 0.02; 
    vector<double> x_vals, y_vals;

    for (double x = a; x <= b + 0.0001; x += h) {
        x_vals.push_back(x);
        y_vals.push_back(f(x));
    }

    double target_y = 0;
    double root_x = 0;
    int n = x_vals.size();

    for (int i = 0; i < n; i++) {
        double Li = 1.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                Li *= (target_y - y_vals[j]) / (y_vals[i] - y_vals[j]);
            }
        }
        root_x += x_vals[i] * Li;
    }

    cout << "--- Task 3: Inverse Interpolation ---" << endl;
    cout << "Root of the equation x = " << setprecision(4) << root_x << endl;
}

int main() {
    task_1_lagrange();
    task_2_aitken();
    task_3_inverse_interpolation();
    return 0;
}