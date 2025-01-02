#include "Header.h"

void print_with_head(Node* head)
{
	Node* current = head;

	while (current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << "\n";
}