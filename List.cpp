#include "List.h"

void List::append(int value) noexcept
{
    Node* newNode = new Node{ value };

    if (head == nullptr)
    {   // Список пуст
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void List::removeLast()
{
    if (head == nullptr)
    {   // Список пуст
        throw "Список пуст. Удаление невозможно.\n";
    }
    else if (head == tail)
    {   // В списке один элемент
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node* temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
}

void List::print() const noexcept
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

bool List::search(int value) const noexcept
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

List::~List()
{
    Node* current = head;

    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}