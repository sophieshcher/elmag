#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double h = 0.2;
    vector<double> x_vals = {0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 3.8};
    vector<double> y_vals = {0.4000, 1.4848, 2.6811, 3.9983, 5.4465, 7.0371, 8.7826, 10.6967, 12.7945, 15.0926, 17.6093, 20.3647, 23.3808, 26.6819, 30.2945, 34.2479, 38.5741, 43.3084};
    
    int n = x_vals.size();
    vector<vector<double>> dy(n, vector<double>(5, 0)); 

    for (int i = 0; i < n; i++) {
        dy[i][0] = y_vals[i];
    }
    
    for (int j = 1; j <= 4; j++) {
        for (int i = 0; i < n - j; i++) {
            dy[i][j] = dy[i+1][j-1] - dy[i][j-1];
        }
    }

    cout << fixed << setprecision(4);
    cout << "Table with results 13:" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "  x  |    y    |   y'   |  y''   " << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(4) << x_vals[i] << " | " << setw(7) << y_vals[i] << " | ";

        if (i >= 2 && i < n - 2) {
            double d1 = (y_vals[i-2] - 8 * y_vals[i-1] + 8 * y_vals[i+1] - y_vals[i+2]) / (12 * h);
            cout << setw(11) << d1 << " | ";
        } else {
            cout << "    -----   | ";
        }

        if (i >= 2 && i < n - 2) {
            double d2 = (1.0 / (h * h)) * (dy[i-1][2] - (1.0/12.0) * dy[i-2][4]);
            cout << setw(11) << d2 << endl;
        } else {
            cout << "    -----" << endl;
        }
    }
    cout << "------------------------------------------------------------" << endl;
    int idx = 13;
    double target_x = x_vals[idx];
    
    double xx_d1 = (y_vals[idx-2] - 8 * y_vals[idx-1] + 8 * y_vals[idx+1] - y_vals[idx+2]) / (12 * h);
    double xx_d2 = (1.0 / (h * h)) * (dy[idx-1][2] - (1.0/12.0) * dy[idx-2][4]);
    
    cout << "\nResults for xx = " << target_x << ":" << endl;
    cout << "First derivative y' (formula 5.7): " << xx_d1 << endl;
    double d1_stirling = (1.0 / h) * (
    (dy[idx-1][1] + dy[idx][1]) / 2.0 - 
    (1.0 / 6.0) * (dy[idx-2][3] + dy[idx-1][3]) / 2.0
);

cout << "First derivative y' (Stirling method): " << d1_stirling << endl;
    cout << "Second derivative y'' (formula 5.9): " << xx_d2 << endl;

    return 0;
}