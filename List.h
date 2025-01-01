#pragma once
#include <iostream>

using namespace std;

//����
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() noexcept : head(nullptr), tail(nullptr) {}

    // ���������� �������� � ����� ������
    void append(int value)noexcept;

    // �������� �������� �� ����� ������
    void removeLast();

    // ������ ������
    void print() const noexcept;

    // ����� �������� � ������
    bool search(int value) const noexcept;

    Node* Clone()
    {
        if (head == nullptr)
        {
            throw "������ ����. ����������� ����������.\n";
        }

        Node* new_head = nullptr; //��������� ��� ������ ������ ������
        Node* new_tail = nullptr; //��������� ��� ������ ������ ������
        Node* current = head; //��������� ����������� �� ������ ������� ������

        //���� ������� �� ������ ��������� �� �������, �� ���� �� ������ �� ����� ������
        while (current != nullptr) 
        {
            //��������� ���� � ������� ���������� ������
            Node* new_node = new Node{ current->data };
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

    friend /*const*/ Node* operator+(const List& list,const List& list2)
    {
        Node* new_head = list.head;
        Node* current = list.tail;

        current->next = list2.head;

        return new_head;
    }

    // ���������� ��� ������������ ������
    ~List();
};