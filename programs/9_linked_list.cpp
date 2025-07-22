#include <bits/stdc++.h>
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
class linkedList {
	node<T> *head;
public:
	linkedList() {
		head = NULL;
	}
	bool empty() {
		return head == NULL;
	}
	void pushBack(T data) {
		node<T> *new_node = new node<T>(data);
		new_node->next = NULL;
		if (head == NULL)
			head = new_node;
		else {
			node<T> *tmp = head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_node;
		}
	}
	void pushFront(T data) {
		node<T> *new_node = new node<T>(data);
		new_node->next = head;
		head = new_node;
	}
	T topFront() {
		if (head == NULL) {
			return;
		}
		else {
			return head->data;
		}
	}
	T topBack() {
		if (head == NULL) {
			return;
		}
		else {
			node<T> *tmp = head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			return tmp->data;
		}
	}
	void popFront() {
		if (head == NULL) {
			cout << "Linked List is empty.\n";
		}
		else {
			node<T> *tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	void popBack() {
		if (head == NULL) {
			cout << "Linked List is empty.\n";
		}
		else {
			node<T> *tmp = head;
			while (tmp->next->next != NULL)
				tmp = tmp->next;
			delete tmp->next;
			tmp->next = NULL;
		}
	}
	bool find(T key) {
		if (head == NULL)
			return false;
		else {
			node<T> *tmp = head;
			while (tmp != NULL) {
				if (tmp->data == key)
					return true;
				tmp = tmp->next;
			}
		}
		return false;
	}
	void erase(T data) {
		int f = 0;
		node<T> *tmp = head;
		if (head == NULL)
			cout << "Linked List is empty.\n";
		else {
			while (true) {
				if (tmp->next == NULL)
					break;
				else if (tmp->next->data == data) {
					f = 1;
					node<T> *temp = tmp->next;
					tmp->next = tmp->next->next;
					delete temp;
					break;
				}
				else
					tmp = tmp->next;
			}
		}
	}
	void insertBefore(T data, T before) {
		int f = 0;
		node<T> *new_node = new node<T>(data);
		new_node->next = NULL;
		if (head == NULL) {
			f = 1;
			cout << "Linked List is empty\n";
		}
		else if (head->data == before) {
			f = 1;
			pushFront(data);
		}
		else {
			node<T> *tmp = head;
			while (1) {
				if (tmp->next == NULL || tmp->next->data == before)
					break;
				tmp = tmp->next;
			}
			if (tmp->next != NULL && tmp->next->data == before) {
				new_node->next = tmp->next;
				tmp->next = new_node;
				f = 1;
			}
		}
		if (f == 0) {
			cout << "Before element not found \n";
		}
	}
	void insertSorted(T data) {
		node<T> *new_node = new node<T>(data);
		new_node->next = NULL;
		if (head == NULL || head->data > data)
			pushFront(data);
		else {
			node<T> *tmp = head;
			while (true) {
				if (tmp->next == NULL || tmp->next->data > data)
					break;
				tmp = tmp->next;
			}
			new_node->next = tmp->next;
			tmp->next = new_node;
		}
	}
	void insertAfter(T data, T after) {
		int f = 0;
		node<T> *new_node = new node<T>(data);
		new_node->next = NULL;
		if (head == NULL) {
			f = 1;
			cout << "Linked List is empty\n";
		}
		else {
			node<T> *tmp = head;
			while (1) {
				if (tmp->data == after || tmp->next == NULL)
					break;
				tmp = tmp->next;
			}
			if (tmp->data == after) {
				f = 1;
				new_node->next = tmp->next;
				tmp->next = new_node;
			}
		}
		if (f == 0) {
			cout << "After element not found\n";
		}
	}
	void display() {
		if (head == NULL)
			cout << "Linked List is empty \n";
		else {
			node<T> *tmp = head;
			while (tmp) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			cout << "\n";
		}
	}
};
void sampleIntLinkedList() {
	linkedList<int> l;
	cout << "Linked List is empty: " << l.empty() << "\n";
	l.pushBack(9);
	cout << "Linked List is empty: " << l.empty() << "\n";
	l.insertAfter(7, 9);
	l.insertBefore(8, 9);
	l.pushFront(3);
	l.pushBack(5);
	l.erase(5);
	for (int i = 20; i > 10; i -= 1)
		l.insertSorted(i);
	cout << "Linked List elements: ";
	l.display();
	l.popBack();
	l.popFront();
	cout << "Linked List elements: ";
	l.display();
	cout << "15 is present in Linked List: " << l.find(15) << "\n";
}
void sampleCharLinkedList() {
	linkedList<char> l;
	cout << "Linked List is empty: " << l.empty() << "\n";
	l.pushBack('A');
	cout << "Linked List is empty: " << l.empty() << "\n";
	l.insertAfter('C', 'A');
	l.insertBefore('B', 'A');
	l.pushFront('T');
	l.pushBack('R');
	l.erase('A');
	for (int i = 'Z'; i > 'E'; i -= 1)
		l.insertSorted(i);
	cout << "Linked List elements: ";
	l.display();
	l.popBack();
	l.popFront();
	cout << "Linked List elements: ";
	l.display();
	cout << "J is present in Linked List: " << l.find('J') << "\n";
}
int main() {
	sampleIntLinkedList();
	cout << "\n";
	sampleCharLinkedList();
	return 0;
}