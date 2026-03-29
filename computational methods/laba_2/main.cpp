#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

void printMatrix(const string& name, const vector<vector<double>>& mat) {
    cout << name << ":\n";
    for (const auto& row : mat) {
        for (double val : row)
            cout << fixed << setprecision(4) << setw(10) << val << " ";
        cout << endl;
    }
    cout << endl;
}

void printVector(const string& name, const vector<double>& x) {
    cout << name << ": ";
    for (double val : x) cout << fixed << setprecision(4) << val << "  ";
    cout << endl;
}

bool isSymmetric(const vector<vector<double>>& A, double eps = 1e-6) {
    int n = A.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (abs(A[i][j] - A[j][i]) > eps)
                return false;
    return true;
}


void solveSquareRoot(vector<vector<double>> A, vector<double> b) {
    int n = b.size();
    cout << "\n=== Square Root Method ===\n";


    if (!isSymmetric(A)) {
        cout << "Matrix is not symmetric! Method may fail.\n";
    }

    cout << "Initial matrix A:\n";
    printMatrix("A", A);
    printVector("b", b);

    vector<vector<double>> T(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        cout << "Processing row i = " << i << endl;

        double sumD = 0.0;
        for (int k = 0; k < i; ++k)
            sumD += T[k][i] * T[k][i];
        T[i][i] = sqrt(A[i][i] - sumD);
        cout << "  T[" << i << "][" << i << "] = " << T[i][i] << endl;

        for (int j = i + 1; j < n; ++j) {
            double sumO = 0.0;
            for (int k = 0; k < i; ++k)
                sumO += T[k][i] * T[k][j];
            T[i][j] = (A[i][j] - sumO) / T[i][i];
            cout << "  T[" << i << "][" << j << "] = " << T[i][j] << endl;
        }

        printMatrix("T (upper triangular)", T);
    }

    cout << "\nSolving T^T y = b:\n";
    vector<double> y(n);
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int k = 0; k < i; ++k)
            sum += T[k][i] * y[k];
        y[i] = (b[i] - sum) / T[i][i];
        cout << "y[" << i << "] = " << y[i] << endl;
    }

    cout << "\nSolving T x = y:\n";
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int k = i + 1; k < n; ++k)
            sum += T[i][k] * x[k];
        x[i] = (y[i] - sum) / T[i][i];
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    printVector("Result (Square Root Method)", x);
}

void solveSimpleIteration(vector<vector<double>> A, vector<double> b, double eps) {
    int n = b.size();
    vector<double> x(n, 0.0);
    int iterations = 0;
    double diff;

    for (int i = 0; i < n; ++i) {
        if (abs(A[i][i]) < 1e-12) {
            cout << "Zero diagonal element detected! Method may fail.\n";
            return;
        }
    }

    cout << "\n=== Simple Iteration Method (Jacobi) ===\n";
    cout << "Initial guess: zero vector\n";

    do {
        vector<double> x_new(n, 0.0);
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i)
                    sum += A[i][j] * x[j];
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        diff = 0.0;
        for (int i = 0; i < n; ++i)
            diff = max(diff, abs(x_new[i] - x[i]));

        x = x_new;
        ++iterations;

        if (iterations <= 5 || iterations % 10 == 0) {
            cout << "Iteration " << iterations << ", diff = " << diff << endl;
            printVector("  x", x);
        }
    } while (diff > eps && iterations < 10000);

    cout << "Simple Iteration Method (Iterations: " << iterations << "): ";
    printVector("", x);
}

void solveSeidel(vector<vector<double>> A, vector<double> b, double eps) {
    int n = b.size();
    vector<double> x(n, 0.0);
    int iterations = 0;
    double diff;

    cout << "\n=== Seidel Method ===\n";
    cout << "Initial guess: zero vector\n";

    do {
        vector<double> x_old = x;
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i != j)
                    sum += A[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        diff = 0.0;
        for (int i = 0; i < n; ++i)
            diff = max(diff, abs(x[i] - x_old[i]));

        ++iterations;

        if (iterations <= 5 || iterations % 10 == 0) {
            cout << "Iteration " << iterations << ", diff = " << diff << endl;
            printVector("  x", x);
        }
    } while (diff > eps && iterations < 10000);

    cout << "Seidel Method (Iterations: " << iterations << "): ";
    printVector("", x);
}



void solveGauss(vector<vector<double>> A, vector<double> B) {
    int n = B.size();
    cout << "\n=== Gaussian Elimination ===\nInitial augmented matrix:\n";
    printMatrix("A", A);
    printVector("b", B);

    for (int k = 0; k < n; k++) {
        double pivot = A[k][k];
        // cout << "Step " << k + 1 << ": pivot element = " << pivot << endl;

        for (int j = k; j < n; j++)
            A[k][j] /= pivot;
        B[k] /= pivot;

        for (int i = k + 1; i < n; i++) {
            double factor = A[i][k];
            for (int j = k; j < n; j++)
                A[i][j] -= factor * A[k][j];
            B[i] -= factor * B[k];
        }

        // cout << "After step " << k + 1 << ":\n";
        // printMatrix("A", A);
        // printVector("b", B);
    }

    vector<double> X(n);
    for (int i = n - 1; i >= 0; i--) {
        X[i] = B[i];
        for (int j = i + 1; j < n; j++)
            X[i] -= A[i][j] * X[j];
    }
    printVector("Result (Gaussian Method)", X);
}

void solveCholeskyGeneral(vector<vector<double>> A, vector<double> b) {
    int n = b.size();
    vector<vector<double>> B(n, vector<double>(n, 0));
    vector<vector<double>> C(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) C[i][i] = 1;

    cout << "=== Cholesky Scheme (LU decomposition) ===Initial matrix A:";
    // printMatrix("A", A);
    // printVector("b", b);

    for (int j = 0; j < n; j++) {
        // cout << "Processing column j = " << j << endl;

        for (int i = j; i < n; i++) {
            double sum = 0;
            for (int k = 0; k < j; k++) sum += B[i][k] * C[k][j];
            B[i][j] = A[i][j] - sum;
        }

        for (int i = j + 1; i < n; i++) {
            double sum = 0;
            for (int k = 0; k < j; k++) sum += B[j][k] * C[k][i];
            C[j][i] = (A[j][i] - sum) / B[j][j];
        }

        // cout << "After j = " << j << ":";
        // printMatrix("B (lower triangular)", B);
        // printMatrix("C (upper triangular with unit diagonal)", C);
    }

    // cout << "Solving B y = b:";
    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int k = 0; k < i; k++) sum += B[i][k] * y[k];
        y[i] = (b[i] - sum) / B[i][i];
        // cout << "y[" << i << "] = " << y[i] << endl;
    }

    // cout << "Solving C x = y:";
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int k = i + 1; k < n; k++) sum += C[i][k] * x[k];
        x[i] = y[i] - sum;
        // cout << "x[" << i << "] = " << x[i] << endl;
    }
    printVector("Result (Cholesky Scheme)", x);
}


int main() {
    cout << "Task 13-a (Gaussian Method):" << endl;
    solveGauss({{1, -0.2, -0.8}, {3, -1, -1}, {1.1, 1, -2}}, {0, 14, 1.4});

    cout << "Task 13-b (Cholesky Scheme):" << endl;
    solveCholeskyGeneral({{2.1, -4.5, -2}, {3, 2.5, 4.3}, {-6, 3.5, 2.5}}, {19.07, 3.21, -18.25});

    cout << "Task 13-с (Square Root Method):" << endl;
    solveSquareRoot({{5.68, 1.12, 0.95, 1.32, 0.83}, 
                     {1.12, 3.78, 2.12, 0.57, 0.91}, 
                     {0.95, 2.12, 6.63, 1.29, 1.57}, 
                     {1.32, 0.57, 1.29, 4.07, 1.25}, 
                     {0.83, 0.91, 1.57, 1.25, 5.71}}, {6.19, 3.21, 4.28, 6.25, 4.95});
    cout << "Task 13-d (Seidel Method, Simple Iteration):" << endl;
    solveSimpleIteration({{24.61, 2.42, 3.85}, {2.31, 31.49, 1.52}, {3.49, 4.85, 29.12}}, {30.24, 39.95, 42.81}, 1e-4);
    
    solveSeidel({{24.61, 2.42, 3.85}, {2.31, 31.49, 1.52}, {3.49, 4.85, 29.12}}, {30.24, 39.95, 42.81}, 1e-4);

    return 0;
}