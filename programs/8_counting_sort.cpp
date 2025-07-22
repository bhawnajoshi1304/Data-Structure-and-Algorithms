#include <iostream>
#include <map>
using namespace std;
template <typename T>
void display(T arr[], int right) {
    for (int i = 0; i < right; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void CountingSort(T arr[], int n) {
    map<T, int> f;
    for (int i = 0; i < n; i++)
        if (f.find(arr[i]) == f.end())
            f[arr[i]] = 1;
        else
            f[arr[i]] += 1;
    int c = 0;
    for (auto i : f) {
        for (int j = 0; j < i.second; j += 1)
            arr[j + c] = i.first;
        c += i.second;
    }
    display(arr, n);
}
int main() {
    CountingSort(new int[6]{1, 5, 2, 1, 5, 1}, 6);
    CountingSort(new char[6]{'Z', 'D', 'Z', 'I', 'J', 'I'}, 6);
    CountingSort(new string[5]{"ads", "aaz", "sdf", "zxy", "ads"}, 5);
    return 0;
}