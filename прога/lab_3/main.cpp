#include <iostream>
using namespace std;

int main() {
    
    int array[18]={-3, 5, -9, -1, 4, -10, 2, 6};

    int minValue = array[0];
    int minIndex = 0;

    for (int i = 1; i < 18; i++) {
        if (array[i] < minValue) {
            minValue = array[i];
        }
    }
    cout << "Min element af array: " << minValue << endl;
    cout << "It's index: " << endl;
    for (int i = 0; i < 18; i++) {
        if (array[i] == minValue) {
            minIndex = i;
            cout << minIndex << " ";
        }
    }
    return 0;
}