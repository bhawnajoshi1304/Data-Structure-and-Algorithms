#include <iostream>
#include <math.h>
using namespace std;
template <typename T>
int BSearch(T arr[], int n, T val) {
    int left = 0, right = n, mid;
    while (left <= right)
    {
        mid = floor((left + right) / 2);
        if (val == arr[mid])
            return mid;
        else if (val < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main() {
    cout << "7 found at index: " << BSearch(new int[9]{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, 7) << "\n";
    cout << "D found at index: " << BSearch(new char[6]{'A', 'B', 'C', 'D', 'E', 'F'}, 6, 'D') << "\n";
    cout << "Z found at index: " << BSearch(new char[6]{'A', 'B', 'C', 'D', 'E', 'F'}, 6, 'Z') << "\n";
    return 0;
}