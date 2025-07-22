#include <iostream>
using namespace std;
template <typename T>
void display(T arr[], int right) {
    for (int i = 0; i < right; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void QuickSort(T arr[], int left, int right) {
    if (right > left + 1) {
        int x = left;
        for (int i = left + 1; i < right; i++)
            if (arr[i] < arr[left])
                swap(arr[i], arr[++x]);
        if (x != left)
            swap(arr[left], arr[x]);
        QuickSort(arr, left, x);
        QuickSort(arr, x + 1, right);
    }
}
template <typename T>
void QuickSort(T arr[], int n) {
    QuickSort(arr, 0, n);
    display(arr, n);
}
int main() {
    QuickSort(new int[6]{10, 5, 2, 3, 8, 1}, 6);
    QuickSort(new char[6]{'Z', 'D', 'E', 'A', 'J', 'I'}, 6);
    QuickSort(new string[5]{"abp", "aaz", "sdf", "zxy", "ads"}, 5);
    return 0;
}