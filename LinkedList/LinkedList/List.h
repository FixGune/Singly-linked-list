#pragma once
#include <iostream>

using namespace std;

class Node {
	int _data;
	Node* _next;
public:

	Node();
	void SetNext(Node* node);
	void SetData(int data);

	int GetData();
	Node* GetNext();

};

class List {
	Node* _head;
public:
	void SetHead(Node* node);

	Node* GetHead();

	List();

	void Push_back(int data);
	void Push_front(int data);
	void Show();
	void RemoveAt(int index);
	void RemoveSimilar(int index);
};