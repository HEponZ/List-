#include "Header.h"

void List::append(int value) noexcept
{
    Node* newNode = new Node{ value };

    if (head == nullptr)
    {   // ������ ����
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
    {   // ������ ����
        throw "������ ����. �������� ����������.\n";
    }
    else if (head == tail)
    {   // � ������ ���� �������
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
        throw "������ ����. ����������� ����������.\n";
    }

    Node* new_node;
    Node* new_head = nullptr; //��������� ��� ������ ������ ������
    Node* new_tail = nullptr; //��������� ��� ������ ������ ������
    Node* current = head; //��������� ����������� �� ������ ������� ������

    //���� ������� �� ������ ��������� �� �������, �� ���� �� ������ �� ����� ������
    while (current != nullptr)
    {
        //��������� ���� � ������� ���������� ������
        new_node = new Node{ current->data };
        //���� ����� ������ ����
        if (new_head == nullptr)
        {
            //�� ������ � ����� �������������� � ������ ���������
            //� �������� ������������ �����
            new_head = new_tail = new_node;
        }
        else
        {
            //��������� ������ ���������� ��������� � ������
            new_tail->next = new_node;
            //����� �������������� � ���������� ���������
            new_tail = new_node;
        }
        //������� � ���������� ����
        current = current->next;
    }
    //������� ������ ����� ������
    return new_head;
}

Node* operator+(const List& list, const List& list2)
{
    Node* new_node;
    Node* new_head = nullptr; //��������� ��� ������ ������ ������
    Node* new_tail = nullptr; //��������� ��� ������ ������ ������
    Node* current = list.head; //��������� ����������� �� ������ ������� ������ 1
    Node* current2 = list2.head; //��������� ����������� �� ������ ������� ������ 2

    //���� ������� �� ������ ��������� �� �������, �� ���� �� ������ �� ����� ������
    while (current != nullptr)
    {
        //����� ���� ������� ������ ��������� �������� ���� �����
        new_node = new Node{ current->data + current2->data };
        //���� ����� ������ ����
        if (new_head == nullptr)
        {
            //�� ������ � ����� �������������� � ������ ���������
            //� �������� ������������ �����
            new_head = new_tail = new_node;
        }
        else
        {
            //��������� ������ ���������� ��������� � ������
            new_tail->next = new_node;
            //����� �������������� � ���������� ���������
            new_tail = new_node;
        }
        //�������� � ��������� �����
        current = current->next;
        current2 = current2->next;
    }

    //������� ������ ����� ������
    return new_head;
}

Node* operator*(const List& list, const List& list2)
{
    Node* new_node;
    Node* new_head = nullptr; //��������� ��� ������ ������ ������
    Node* new_tail = nullptr; //��������� ��� ������ ������ ������
    Node* current = list.head; //��������� ����������� �� ������ ������� ������
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