#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double calcPolynom(double x) {
    vector<double> coeffs = { 0.22, -3.27, -2.74, 2.81, -3.36, 2.0 };
    double result = coeffs[0];
    for (size_t i = 1; i < coeffs.size(); i++) {
        result = result * x + coeffs[i];
    }
    return result;
}

double calcCubeRoot(double x) {
    double temp_x = x;
    int m = 0;
    if (temp_x >= 1.0) {
        while (temp_x >= 1) {
            temp_x /= 2;
            m++;
        }
    }
    else if (temp_x > 0 && temp_x < 0.5) {
        while (temp_x < 0.5) {
            temp_x *= 2.0;
            m--;
        }
    }
    double y = pow(2, m / 3);
    // cout << y;
    double epsilon = 1e-15;

    while (true) {
        double y_next = (1.0 / 3.0) * ((2.0 * y * y * y + x) / (y * y));
        if (abs(y_next - y) < epsilon) {
            return y_next;
        }
        y = y_next;
    }
}

int main() {
    cout << "=== Task 13.a: P(xi) ===" << endl;
    
    cout.width(10); cout << "k";
    cout.width(15); cout << "xi";
    
    cout.width(25); cout << "P(xi)" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int k = 16; k <= 20; k++) {
        double xi = 0.80 + 0.05 * k;
        double p_val = calcPolynom(xi);

        cout.unsetf(ios::floatfield); 
        cout.width(10); 
        cout << k;

        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(3);
        cout.width(15); 
        cout << xi;

        cout.setf(ios::scientific, ios::floatfield);
        cout.precision(5);
        cout.width(25); 
        cout << p_val << endl;
    }
    cout << endl;

    cout << "=== Task 13.b: Table cube roots ===" << endl;
    cout << "Precision: 10^-15" << endl;
    
    cout.width(10); cout << "k";
    cout.width(15); cout << "x";
    cout.width(20); cout << "y0 (start)";
    cout.width(25); cout << "y = cbrt(x)" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    for (int k = 0; k <= 15; k++) {
        double x = 3 + k;
        double y_val = calcCubeRoot(x);

     
        cout.unsetf(ios::floatfield);
        cout.width(10); 
        cout << k;

     
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(1);
        cout.width(15); 
        cout << x;

        cout.precision(3); 
        cout.width(20); 
        cout << y0;
     
        cout.precision(15);
        cout.width(25); 
        cout << y_val << endl;
    }

    return 0;
}