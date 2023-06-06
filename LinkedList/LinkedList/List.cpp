#include "List.h"

#pragma region Setter,Getter,Constructer

void List::SetHead(Node* node) {
	_head = node;
}

Node* List::GetHead() {
	return _head;
}

int Node::GetData() {
	return _data;
}

Node* Node::GetNext() {
	return _next;
}

void Node::SetData(int data) {
	_data = data;
}

void Node::SetNext(Node* node) {
	_next = node;
}

Node::Node() {
	_data = 0;
	_next = nullptr;
}

List::List() {
	_head = nullptr;
}
#pragma endregion

void List::Push_back(int data) // Добавление в конец
{
	Node* temp = new Node();
	temp->SetData(data);
	if (GetHead() == nullptr) // Проверка на наличие начала списка
	{
		SetHead(temp);
	}
	else
	{
		// Находим последний узел в списке
		Node* last = GetHead();
		while (last->GetNext() != nullptr) {
			last = last->GetNext();
		}

		// Добавляем новый узел в конец списка
		last->SetNext(temp);
	}
}

void List::Push_front(int data) // Добавление в начало
{
	Node* temp = new Node();
	temp->SetData(data);
	if (GetHead() == nullptr)
	{
		SetHead(temp);
	}
	else 
	{
		temp->SetNext(GetHead());
		SetHead(temp);
	}
}

void List::Show() // Вывод списка
{
	cout << "Список выглядит так: \n";
	Node* temp = new Node();
	temp = GetHead();
	while (temp != nullptr) // Перебор списка
	{
		cout << temp->GetData() << "  ";
		temp = temp->GetNext();
	}
	cout << "\n";
}

void List::RemoveAt(int index) //Удаление элемента по значению
{
	Node* prev = new Node();
	Node* temp = new Node();
	temp = GetHead();
	prev = GetHead();
	bool flag = false;
	if (temp != nullptr && temp->GetData() == index) {
		SetHead(temp->GetNext());
		delete temp;
		return;
	}
	temp = temp->GetNext();
	while (temp != nullptr)
	{
		if (temp != nullptr && temp->GetData() == index)
		{
			prev->SetNext(temp->GetNext());
			delete temp;
			cout << "Элемент удалён\n";
			flag = true;
			break;
		}
		prev = temp;
		temp = temp->GetNext();
	}
	if (!flag)
	{
		cout << "Такого элемента нет\n";
	}
}

void List::RemoveSimilar(int index) 
{
	Node* prev = new Node();
	Node* temp = new Node();
	temp = GetHead();
	prev = GetHead();
	bool flag = false;
	if (temp != nullptr && temp->GetData() == index) {
		SetHead(temp->GetNext());
		delete temp;
		return;
	}
	temp = temp->GetNext();
	while (temp != nullptr)
	{
		if (temp != nullptr && temp->GetData() == index)
		{
			prev->SetNext(temp->GetNext());
			delete temp;
			cout << "Элемент удалён\n";
			flag = true;
			temp = prev;
		}
		prev = temp;
		temp = temp->GetNext();
	}
	if (!flag)
	{
		cout << "Такого элемента нет\n";
	}
}