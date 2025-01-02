#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

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

    //��������� ������
    Node* Clone();

    //������������� ���������
    friend Node* operator+(const List& list, const List& list2);
    friend Node* operator*(const List& list, const List& list2);

    // ���������� ��� ������������ ������
    ~List();
};