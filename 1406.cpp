#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

struct node {
	char data;
	node* next;
	node* prev;
};

struct Editor {
	node* front;
	node* rear;
	node* cursor;
	int len;

	Editor() {
		len = 0;
		cursor = new node;
		front = new node;
		rear = new node;
		front->next = NULL;
		front->prev = front;
		rear->next = rear;
		rear->prev = NULL;
		front->data = '#';
		rear->data = '#';
	}

	void init() {
		cursor = rear->prev;
	}

	void enqueue(char data) {
		node* n = new node;
		n->data = data;
		if (len == 0) {
			n->prev = front;
			n->next = rear;
			front->next = n;
			rear->prev = n;
		}
		else {
			n->next = rear;
			n->prev = rear->prev;
			rear->prev->next = n;
			rear->prev = n;
		}
		len++;
	}

	void dequeue() {
		
		if (cursor != front) {
			node* n = new node;
			cursor->next->prev = cursor->prev;
			cursor->prev->next = cursor->next;
			len--;

			n = cursor;
			cursor = cursor->prev;
			delete n;
		}
	}

	void insert(char data) {
		node* n = new node;
		n->data = data;
		n->next = cursor->next;
		n->prev = cursor;

		cursor->next->prev = n;
		cursor->next = n;
		cursor = n;
		len++;
	}

	void Left() {
		cursor = cursor->prev;
	}
	void Right() {
		if (cursor == rear->prev) return;
		cursor = cursor->next;
	}
	void print() {
		node n;
		n = *front->next;
		for (int i = 0; i < len; i++) {
			cout << n.data;
			n = *n.next;
		}
		cout << endl;
	}
	void printcursor() {
		cout << cursor->data<<endl;
	}
};

int main() {
	Editor editor;

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		editor.enqueue(s[i]);
	}
	editor.init();

	int ordernum;
	cin >> ordernum;
	for (int i = 0; i < ordernum; i++) {
		char order;
		cin >> order;
		if (order == 'P') {
			char data;
			cin >> data;
			editor.insert(data);
		}
		else if (order == 'L') {
			editor.Left();
		}
		else if (order == 'D') {
			editor.Right();
		}
		else if (order == 'B') {
			editor.dequeue();
		}
	}
	editor.print();
	return 0;
}
