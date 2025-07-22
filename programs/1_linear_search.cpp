#include <iostream>
using namespace std;
template <typename T>
int LSearch(T arr[], int n, T val) {
    for (int i = 0; i < n; i += 1) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}
int main() {
    cout << "7 found at index: " << LSearch(new int[9]{1, 4, 2, 3, 5, 9, 7, 6, 8}, 9, 7) << "\n";
    cout << "D found at index: " << LSearch(new char[6]{'A', 'B', 'C', 'F', 'D', 'E'}, 6, 'D') << "\n";
    cout << "Z found at index: " << LSearch(new char[6]{'A', 'B', 'C', 'F', 'D', 'E'}, 6, 'Z') << "\n";
    return 0;
}