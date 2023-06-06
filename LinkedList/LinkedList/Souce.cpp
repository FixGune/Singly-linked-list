#include <iostream>
#include <windows.h>
#include "List.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List* list = new List();
	for (int i = 0; i < 5; i++) {
		list->Push_back(i * 2);
	}
	list->Show();
	list->Push_back(1);
	list->Push_front(1);
	list->Show();
	list->RemoveAt(2);
	list->Show();
	list->RemoveSimilar(1);
	list->Show();
}