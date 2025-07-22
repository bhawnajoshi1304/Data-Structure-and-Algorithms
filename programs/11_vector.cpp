#include <bits/stdc++.h>
using namespace std;
template <typename T>
class dynamicArray {
    T *arr;
    int capacity;
    int size;
public:
    dynamicArray() {
        arr = new T[1];
        capacity = 1;
        size = 0;
    }
    void push_back(T data) {
        if (size == capacity) {
            T *temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i += 1) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[size] = data;
        size += 1;
    }
    void push_back(T data, int index) {
        if (index == capacity)
            push_back(data);
        else
            arr[index] = data;
    }
    T get(int index) {
        if (index < size)
            return arr[index];
    }
    void pop() { size--; }
    void remove(int index) {
        if (index < size) {
            for (int i = index; i < size - 1; i += 1) {
                arr[i] = arr[i + 1];
            }
            pop();
        }
    }
    int getSize() { return size; }
    int getcapacity() { return capacity; }
    void print() {
        for (int i = 0; i < size; i += 1) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
void sampleIntArray() {
    dynamicArray<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    cout << "Vector size : " << v.getSize() << "\n";
    cout << "Vector capacity : " << v.getcapacity() << "\n";
    cout << "Vector elements : ";
    v.print();
    v.push_back(100, 1);
    cout << "After updating 1st index \n";
    cout << "Vector elements of type int : ";
    v.print();
    cout << "Element at 1st index of type int: " << v.get(1) << "\n";
    v.pop();
    cout << "After deleting last element \n";
    cout << "Vector size of type int: " << v.getSize() << "\n";
    cout << "Vector capacity of type int : " << v.getcapacity() << "\n";
    cout << "Vector elements of type int: ";
    v.print();
    v.remove(1);
    cout << "After deleting 2nd element \n";
    cout << "Vector size of type int: " << v.getSize() << "\n";
    cout << "Vector capacity of type int : " << v.getcapacity() << "\n";
    cout << "Vector elements of type int: ";
    v.print();
}
void sampleCharArray() {
    dynamicArray<char> v1;
    v1.push_back('A');
    v1.push_back('B');
    v1.push_back('C');
    v1.push_back('D');
    cout << "Vector size : " << v1.getSize() << "\n";
    cout << "Vector capacity : " << v1.getcapacity() << "\n";
    cout << "Vector elements of type char : ";
    v1.print();
    cout << "Element at 1st index of type char: " << v1.get(1) << "\n";
    v1.pop();
    cout << "After deleting last element \n";
    cout << "Vector size of type char: " << v1.getSize() << "\n";
    cout << "Vector capacity of type char : " << v1.getcapacity() << "\n";
    cout << "Vector elements of type char: ";
    v1.print();
    v1.remove(1);
    cout << "After deleting 2nd element \n";
    cout << "Vector size of type char: " << v1.getSize() << "\n";
    cout << "Vector capacity of type char : " << v1.getcapacity() << "\n";
    cout << "Vector elements of type char: ";
    v1.print();
}
int main()
{
    sampleIntArray();
    cout << "\n";
    sampleCharArray();
    return 0;
}