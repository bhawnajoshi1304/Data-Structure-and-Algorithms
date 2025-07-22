#include <iostream>
using namespace std;
template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void BubbleSort(T arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
    display(arr, n);
}
int main() {
    BubbleSort(new int[6]{10, 5, 2, 3, 8, 1}, 6);
    BubbleSort(new char[6]{'Z', 'D', 'E', 'A', 'J', 'I'}, 6);
    BubbleSort(new string[5]{"abp", "aaz", "sdf", "zxy", "ads"}, 5);
    return 0;
}