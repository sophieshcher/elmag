#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(0));

    int N;
    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> arr(N);

    cout << "Original array: ";
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 20 - 10;
        cout << arr[i] << " ";
    }
    cout << endl;

    for (auto i = arr.begin(); i != arr.end();)
    {
        if (*i % 2 == 0)
            i = arr.erase(i);
        else
            i++;
    }

    cout << "Array (odd elements only): ";

    if (arr.empty())
        cout << "All elements were even.";
    else
        for (int i = 0; i < arr.size(); i++)
        {
            int element = arr[i];
            cout << element << " ";
        }

    return 0;
}
