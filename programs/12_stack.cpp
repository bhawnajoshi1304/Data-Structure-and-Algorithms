#include <iostream>
using namespace std;
template <typename T>
class node {
public:
	T data;
	node<T> *next;
	node(T val) {
		data = val;
		next = NULL;
	}
};
template <typename T>
class stack {
	node<T> *top;
public:
	stack() {
		top = NULL;
	}
	bool empty() {
		return top == NULL;
	}
	void push(T data) {
		node<T> *new_node = new node<T>(data);
		new_node->next = top;
		top = new_node;
	}
	T peek() {
		if (top == NULL) {
			return;
		}
		else {
			return top->data;
		}
	}
	void pop() {
		if (top == NULL) {
			cout << "Stack is empty.\n";
		}
		else {
			node<T> *tmp = top;
			top = top->next;
			delete tmp;
		}
	}
	void display() {
		if (top == NULL)
			cout << "Stack is empty.\n";
		else {
			node<T> *tmp = top;
			while (tmp) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			cout << "\n";
		}
	}
};
void sampleIntStack() {
	stack<int> s;
	cout << "Stack is empty: " << s.empty() << "\n";
	s.push(9);
	cout << "Stack is empty: " << s.empty() << "\n";
	s.push(3);
	s.push(5);
	for (int i = 20; i > 10; i -= 1)
		s.push(i);
	cout << "Stack elements: ";
	s.display();
	s.pop();
	cout << "Stack elements: ";
	s.display();
}
void sampleCharStack() {
	stack<char> s;
	cout << "Stack is empty: " << s.empty() << "\n";
	s.push('A');
	cout << "Stack is empty: " << s.empty() << "\n";
	s.push('V');
	s.push('E');
	for (int i = 'Z'; i > 'R'; i -= 1)
		s.push(i);
	cout << "Stack elements: ";
	s.display();
	s.pop();
	cout << "Stack elements: ";
	s.display();
}
int main() {
	sampleIntStack();
	cout << "\n";
	sampleCharStack();
	return 0;
}