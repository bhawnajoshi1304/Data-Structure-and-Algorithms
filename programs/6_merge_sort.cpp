#include <iostream>
using namespace std;
template <typename T>
void display(T arr[], int r) {
    for (int i = 0; i < r; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void MergeSort(T a[], int l, int r) {
    if (r > l + 1) {
        T arr[r - l];
        int i = l, mid = l + (r - l) / 2, j = mid, k = 0;
        MergeSort(a, l, mid);
        MergeSort(a, mid, r);
        while (i < mid && j < r) {
            if (a[i] < a[j])
                arr[k++] = a[i++];
            else
                arr[k++] = a[j++];
        }
        while (i < mid)
            arr[k++] = a[i++];
        while (j < r)
            arr[k++] = a[j++];
        for (k = 0; k < r - l; k++)
            a[k + l] = arr[k];
    }
}
template <typename T>
void MergeSort(T arr[], int n) {
    MergeSort(arr, 0, n);
    display(arr, n);
}
int main() {
    MergeSort(new int[6]{10, 5, 2, 3, 8, 1}, 6);
    MergeSort(new char[6]{'Z', 'D', 'E', 'A', 'J', 'I'}, 6);
    MergeSort(new string[5]{"abp", "aaz", "sdf", "zxy", "ads"}, 5);
    return 0;
}