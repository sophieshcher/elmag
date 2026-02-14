#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>  
using namespace std;

int main() {
    int K[10][10];
    // srand(time(0));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            K[i][j] = rand() % 19 - 9; 
        }
    }

    cout << "Matrix K:" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(3)<< K[i][j];
        }
        cout << endl;
    }
    cout << "Matrix after changing:"<< endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            if (K[i][j] > 0)
                K[i][j] = 0;
                cout<< setw(3) << K[i][j];
        }
        cout << endl;
    }

    // cout << "Matrix after changing:"<< endl;
    //  for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j <= i; j++) { 
    //         cout<< setw(3) << K[i][j];  
    //     }
    //     cout << endl;
    // }
    return 0;
}
