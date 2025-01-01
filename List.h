#pragma once
#include <iostream>

using namespace std;

//узел
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

    // Добавление элемента в конец списка
    void append(int value)noexcept;

    // Удаление элемента из конца списка
    void removeLast();

    // Печать списка
    void print() const noexcept;

    // Поиск элемента в списке
    bool search(int value) const noexcept;

    Node* Clone()
    {
        if (head == nullptr)
        {
            throw "Список пуст. Копирование невозможно.\n";
        }

        Node* new_head = nullptr; //Указатель для головы нового списка
        Node* new_tail = nullptr; //Указатель для хвоста нового списка
        Node* current = head; //Указатель указывающий на первый элемент списка

        //Пока куррент не станет указывать на нуллпрт, то есть мы дойдем до конца списка
        while (current != nullptr) 
        {
            //Временный узел в который копируются данные
            Node* new_node = new Node{ current->data };
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

    friend /*const*/ Node* operator+(const List& list,const List& list2)
    {
        Node* new_head = list.head;
        Node* current = list.tail;

        current->next = list2.head;

        return new_head;
    }

    // Деструктор для освобождения памяти
    ~List();
};