#include <iostream>
using namespace std;
template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void SelectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int temp = i;
        for (int j = i + 1; j < n; j++)
            if (arr[temp] > arr[j])
                temp = j;
        if (temp != i)
            swap(arr[i], arr[temp]);
    }
    display(arr, n);
}
int main() {
    SelectionSort(new int[6]{10, 5, 2, 3, 8, 1}, 6);
    SelectionSort(new char[6]{'Z', 'D', 'E', 'A', 'J', 'I'}, 6);
    SelectionSort(new string[5]{"abp", "aaz", "sdf", "zxy", "ads"}, 5);
    return 0;
}