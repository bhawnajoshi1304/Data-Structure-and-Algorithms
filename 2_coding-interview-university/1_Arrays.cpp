#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
// Elements
    // Array
    // Capacity
    // Size
// Functions
    // Get(i)
    // Set(i,x)
    // GetSize()
    // GetCapacity()
    // IsEmpty()
    // Push_back(x) --- O(n) worst case
    // Pop_back()
    // Insert(i,x)
    // Delete(i) --- O(n) worst case
    // search(i)
    // Remove(x)
private:
	int* array = NULL;
	int capacity;
	int size;
public:
	DynamicArray() {
		capacity = 1;
		size = 0;
		array = new int[capacity];
	}
	DynamicArray(int capacity) {
        // Set capacity greater than or equal to nearest power of 2 
		this->capacity = 1 << (int(log2(capacity-1))+1);
		array = new int[capacity];
		size = 0;
	}

	int getSize() { return size; }

	int getCapacity() { return capacity; }

    int get(int i) { return array[i]; }

    void set(int i, int val) { array[i]=val; }

	void push_back(int value) {
		if (size == capacity) {
			resize();
		}
		array[size] = value;
		size++;
	}

	void pop_back() {
		array[size - 1] = 0;
		size--;
		if (size == (capacity >> 1)) {
			resize();
		}
	}

	void resize() {
		int newCapacity = 1 << (int(log2(size))+1);;
		int* temp = new int[newCapacity];
		for (int i = 0; i < size; i++) {
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
        capacity = newCapacity;
	}

	int search(int key) {
		for (int i = 0; i < size; i++) {
			if (array[i] == key) {
				return i;
			}
		}
		return -1;
	}

	void insertAt(int index, int value) {
		if (size == capacity) {
			resize();
		}
		for (int i = size - 1; i >= index; i--) {
			array[i + 1] = array[i];
		}
		array[index] = value;
		size++;
	}

	void deleteAt(int index) {
		for (int i = index; i < size; i++) {
			array[i] = array[i + 1];
		}
		array[size - 1] = 0;
		size--;
		if (size <= (capacity >> 1)) {
			resize();
		}
	}

    void remove(int val) {
        int index = search(val);
        if(index != -1) deleteAt(index);
    }

	void printArrayDetails() {
		cout << "Elements of array: ";
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << ", No of elements in array: " << size << ", Capacity of array: " << capacity << "\n";
	}

	bool isEmpty() { return size == 0; }
};

void testDynamicArray()
{
	DynamicArray da(16);

	da.push_back(1);
	da.push_back(2);
	da.push_back(3);
	da.push_back(4);
	da.push_back(5);
	da.push_back(6);
	da.push_back(7);

	da.printArrayDetails();

    cout << "Element at index 2: " << da.get(2) << "\n";

    da.set(0,6);
    cout << "Change element at index 0 to 6: " << da.get(0) << "\n";

	da.resize();
	cout << "Capacity of array after shrinking: "
		<< da.getCapacity() << "\n";

	cout << "After inserting 50 at index 3 " << "\n";
	da.insertAt(3, 50);
	da.printArrayDetails();


	cout << "After inserting 2 at last " << "\n";
	da.push_back(2);
	da.printArrayDetails();

	cout << "After delete last element:\n";
	da.pop_back();
	da.printArrayDetails();

	cout << "After deleting at index 3:\n";
	da.deleteAt(3);
	da.printArrayDetails();

	cout << "Searching 3 in array:\n";
	int index1 = da.search(3);
	cout << "Element found at index (-1: not found): " << index1 << "\n";
	cout << "Searching 5 in array:\n";
	int index2 = da.search(5);
	cout << "Element found at index (-1: not found): " << index2 << "\n";

	cout << "After deleting 3 in array:\n";
	da.remove(3);
	da.printArrayDetails();
}

int main(){
    // Fixed size array.
    int arr[2];
    cout<<"Enter 2 array elements:\n";
    for(int i=0;i<2;i+=1)
    cin>>arr[i];
    cout<<"Array elements: ";
    for(int i=0;i<2;i+=1)
    cout<<arr[i]<<" ";
    cout<<"\n\n";
    
    // Dynamically allocated array: size decided at run-time
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    cout<<"Enter "<<size<<" array elements:\n";
    int *arr1 = new int[size];
    for(int i=0;i<size;i+=1)
    cin>>arr[i];
    cout<<"Array elements: ";
    for(int i=0;i<size;i+=1)
    cout<<arr[i]<<" ";
    cout<<"\n\n";

    // Dynamic array: Resizable array
    testDynamicArray();
    return 0;
}
