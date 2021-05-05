// queue_list.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef SORTING_QUEUE_LIST_H
#define SORTING_QUEUE_LIST_H

#include <iostream>

template <typename T> class Item
{
    T node; Item* next;
public:
    Item(const T& elem, Item* n = 0)
    {
        node = elem; next = n;
    }

    T& get_node()
    {
        return node;
    }

    Item*& get_next()
    {
        return next;
    }
};

template <typename T> class Queue
{
    Item<T>* head, * tail; T rab;
public:
    Queue() { tail = head = 0; }

    bool empty() { return head == 0; }

    void put(const T& elem)
    {
        if (tail == 0) tail = head = new Item<T>(elem);
        else tail = (tail->get_next() = new Item<T>(elem));
    }

    T& get()
    {
        Item<T>* p = head;
        rab = head->get_node();
        head = head->get_next();
        delete p;
        if (head == 0) tail = 0;
        return rab;
    }
};

#endif //SORTING_QUEUE_LIST_H

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
