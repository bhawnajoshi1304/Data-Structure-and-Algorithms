#include <iostream>
using namespace std;
template <typename T>
void display(T arr[], int r) {
    for (int i = 0; i < r; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void MergeSort(T arr[], int l, int r) {
    int i = l, mid = l + (r - l) / 2, j = mid, k = 0;
    if (r - l > 1) {
        MergeSort(arr, l, mid);
        MergeSort(arr, mid, r);
        int m = mid - l;
        int n = r - mid;
        int gap = (m + n) / 2;
        while (gap != 0) {
            for (int i = l; i < l + m + n - gap; i++)
                if (arr[i] > arr[i + gap])
                    swap(arr[i], arr[i + gap]);
            if (gap == 1)
                gap = 0;
            else
                gap = (gap + 1) / 2;
        }
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