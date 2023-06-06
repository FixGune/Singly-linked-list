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

void List::Push_back(int data) // ���������� � �����
{
	Node* temp = new Node();
	temp->SetData(data);
	if (GetHead() == nullptr) // �������� �� ������� ������ ������
	{
		SetHead(temp);
	}
	else
	{
		// ������� ��������� ���� � ������
		Node* last = GetHead();
		while (last->GetNext() != nullptr) {
			last = last->GetNext();
		}

		// ��������� ����� ���� � ����� ������
		last->SetNext(temp);
	}
}

void List::Push_front(int data) // ���������� � ������
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

void List::Show() // ����� ������
{
	cout << "������ �������� ���: \n";
	Node* temp = new Node();
	temp = GetHead();
	while (temp != nullptr) // ������� ������
	{
		cout << temp->GetData() << "  ";
		temp = temp->GetNext();
	}
	cout << "\n";
}

void List::RemoveAt(int index) //�������� �������� �� ��������
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
			cout << "������� �����\n";
			flag = true;
			break;
		}
		prev = temp;
		temp = temp->GetNext();
	}
	if (!flag)
	{
		cout << "������ �������� ���\n";
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
			cout << "������� �����\n";
			flag = true;
			temp = prev;
		}
		prev = temp;
		temp = temp->GetNext();
	}
	if (!flag)
	{
		cout << "������ �������� ���\n";
	}
}