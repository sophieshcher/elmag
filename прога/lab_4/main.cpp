#include <iostream>
// #include <ctime>
using namespace std;

int main() {
    int N;

    cout << "Enter number of elements: ";
    cin >> N;

    int* Arr = new int[N];

    // srand(time(nullptr));
    cout << "Original array: ";
    for (int i = 0; i < N; i++) {
        Arr[i] = rand() % 100; 
        cout << Arr[i] << " ";
    }
    cout << endl;

// ......

    int countOdd = 0;
    for (int i = 0; i < N; i++) {
        if (Arr[i] % 2 != 0) countOdd++;
    }
    

    if (countOdd == 0) {
        cout << "No odd elements found." << endl;
        delete[] Arr;
        return 0;
    }

    int* NewArr = new int[countOdd];

  
    int* ptrArr = Arr;     
    int* ptrNew = NewArr;  
    for (int i = 0; i < N; i++) {
        if (*(ptrArr + i) % 5 == 0) {
            *ptrNew = *ptrArr++;
            ptrNew++;         
        }
    }

    cout << "New array (odd elements only) - using index: ";
    for (int i = 0; i < countOdd; i++) {
        cout << NewArr[i] << " ";
    }
    cout << endl;

    cout << "New array (odd elements only) - using pointer arithmetic: ";
    ptrNew = NewArr;
    for (int i = 0; i < countOdd; i++) {
        cout << *ptrNew++ << " ";
    }


    delete[] Arr;
    delete[] NewArr;

    return 0;
}
