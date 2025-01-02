#include "Header.h"

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

Node* List::Clone()
{
    if (head == nullptr)
    {
        throw "Список пуст. Копирование невозможно.\n";
    }

    Node* new_node;
    Node* new_head = nullptr; //Указатель для головы нового списка
    Node* new_tail = nullptr; //Указатель для хвоста нового списка
    Node* current = head; //Указатель указывающий на первый элемент списка

    //Пока куррент не станет указывать на нуллпрт, то есть мы дойдем до конца списка
    while (current != nullptr)
    {
        //Временный узел в который копируются данные
        new_node = new Node{ current->data };
        //Если новый список пуст
        if (new_head == nullptr)
        {
            //То голова и хвост приравниваются к одному указателю
            //И являются единственным узлом
            new_head = new_tail = new_node;
        }
        else
        {
            //Указатель ньюнод становится последним в списке
            new_tail->next = new_node;
            //Хвост приравнивается к последнему указателю
            new_tail = new_node;
        }
        //Переход к следующему узлу
        current = current->next;
    }
    //Возврат головы новго списка
    return new_head;
}

Node* operator+(const List& list, const List& list2)
{
    Node* new_node;
    Node* new_head = nullptr; //Указатель для головы нового списка
    Node* new_tail = nullptr; //Указатель для хвоста нового списка
    Node* current = list.head; //Указатель указывающий на первый элемент списка 1
    Node* current2 = list2.head; //Указатель указывающий на первый элемент списка 2

    //Пока куррент не станет указывать на нуллпрт, то есть мы дойдем до конца списка
    while (current != nullptr)
    {
        //Новый узел который хранит сложенные значения двух узлов
        new_node = new Node{ current->data + current2->data };
        //Если новый список пуст
        if (new_head == nullptr)
        {
            //То голова и хвост приравниваются к одному указателю
            //И являются единственным узлом
            new_head = new_tail = new_node;
        }
        else
        {
            //Указатель ньюнод становится последним в списке
            new_tail->next = new_node;
            //Хвост приравнивается к последнему указателю
            new_tail = new_node;
        }
        //Переходы к следующим узлам
        current = current->next;
        current2 = current2->next;
    }

    //Возврат головы новго списка
    return new_head;
}

Node* operator*(const List& list, const List& list2)
{
    Node* new_node;
    Node* new_head = nullptr; //Указатель для головы нового списка
    Node* new_tail = nullptr; //Указатель для хвоста нового списка
    Node* current = list.head; //Указатель указывающий на первый элемент списка
    Node* current2 = list2.head;

    while (current != nullptr)
    {
        new_node = new Node{ current->data * current2->data };
        if (new_head == nullptr)
        {
            new_head = new_tail = new_node;
        }
        else
        {
            new_tail->next = new_node;
            new_tail = new_node;
        }
        current = current->next;
        current2 = current2->next;
    }

    return new_head;
}