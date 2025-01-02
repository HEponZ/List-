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

    // Добавление элемента в конец списка
    void append(int value)noexcept;

    // Удаление элемента из конца списка
    void removeLast();

    // Печать списка
    void print() const noexcept;

    // Поиск элемента в списке
    bool search(int value) const noexcept;

    //Клонируют список
    Node* Clone();

    //Перегруженные операторы
    friend Node* operator+(const List& list, const List& list2);
    friend Node* operator*(const List& list, const List& list2);

    // Деструктор для освобождения памяти
    ~List();
};