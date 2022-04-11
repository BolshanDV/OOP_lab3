//
// Created by Дмитрий on 09.04.2022.
//

#ifndef OOP_LAB3_LIST_H
#define OOP_LAB3_LIST_H
#include "struct.h"
#include <string>
#include <ctime>
#include <typeinfo>

using namespace std;

template<class T>
class List
{
private:
    class Node
    {
    public:
        T data;
        Node* next;

        Node(T t = T(), Node* n = nullptr);
    };
    Node* head;
    int size;

public:
    List();
    void pushBack(T value);
    int getSize() { return size;}
    T& operator[] (int);
};

template <class T>
List<T>::Node::Node(T t, Node* n)
{
    data = t;
    next = n;
}

template<class T>
List<T>::List()
{
    size = 0;
    head = nullptr;
}

template<class T>
void List<T>::pushBack(T value)
{
    if (head == nullptr) {
        string s = typeid(value).name();
        head = new Node(value);
    }
    else
    {
        for (Node* current = head; ; current = current->next)
            if (current->next == nullptr)
            {
                current->next = new Node(value);
                break;
            }
    }
    size++;
}
template<class T>
T& List<T>::operator[](int index){
    if (index > size - 1 || index < 0)
    {
        string message = "Недопустимый индекс";
        message.append(to_string(index));
        throw out_of_range(message);
    }
    Node* current = head;
    for (int i = 0; i < index; i++)
        current = current->next;
    return current->data;
}
#endif //OOP_LAB3_LIST_H
