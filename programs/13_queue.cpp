#include <iostream>
using namespace std;
template <typename T>
class node
{
public:
	T data;
	node<T> *next;
	node(T val)
	{
		data = val;
		next = NULL;
	}
};
template <typename T>
class queue {
	node<T> *front, *back;
public:
	queue() {
		front = back = NULL;
	}
	bool empty() {
		return front == NULL;
	}
	void enqueue(T data) {
		node<T> *new_node = new node<T>(data);
		if (front != NULL)
			back->next = new_node;
		else
			front = new_node;
		back = new_node;
	}
	T dequeue() {
		T val;
		if (front == NULL) {
			return val;
		}
		else {
			node<T> *tmp = front;
			front = front->next;
			val = tmp->data;
			delete tmp;
			return val;
		}
	}
	void display() {
		if (front == NULL)
			cout << "Queue is empty \n";
		else {
			node<T> *tmp = front;
			while (tmp != NULL) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			cout << "\n";
		}
	}
};
void sampleIntQueue() {
	queue<int> q;
	cout << "Queue is empty: " << q.empty() << "\n";
	q.enqueue(9);
	cout << "Queue is empty: " << q.empty() << "\n";
	q.enqueue(5);
	cout << "Queue elements: ";
	q.display();
	cout << q.dequeue() << " deleted.\n";
	for (int i = 20; i > 10; i -= 1)
		q.enqueue(i);
	cout << q.dequeue() << " deleted.\n";
	cout << "Queue elements: ";
	q.display();
}
void sampleCharQueue() {
	queue<char> q;
	cout << "Queue is empty: " << q.empty() << "\n";
	q.enqueue('A');
	cout << "Queue is empty: " << q.empty() << "\n";
	q.enqueue('C');
	cout << "Queue elements: ";
	q.display();
	cout << q.dequeue() << " deleted.\n";
	for (int i = 'Z'; i > 'F'; i -= 1)
		q.enqueue(i);
	cout << q.dequeue() << " deleted.\n";
	cout << "Queue elements: ";
	q.display();
}
int main() {
	sampleIntQueue();
	cout << "\n";
	sampleCharQueue();
	return 0;
}