#include <iostream>
using namespace std;
template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void InsertionSort(T arr[], int n) {
    for (int i = 1; i < n; i += 1) {
        T curr = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > curr) {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        if (arr[j] > curr)
            arr[j] = curr;
    }
    display(arr, n);
}
int main() {
    InsertionSort(new int[6]{10, 5, 2, 3, 8, 1}, 6);
    InsertionSort(new char[6]{'Z', 'D', 'E', 'A', 'J', 'I'}, 6);
    InsertionSort(new string[5]{"abp", "aaz", "sdf", "zxy", "ads"}, 5);
    return 0;
}