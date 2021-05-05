// queue_deque.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#include <iostream>
#include "deque.cpp"
template<class T>

class Queue {
public:
    Deque <T> deq;

    void PushBack(const T& el) {
        deq.Push_Back(el);
    }

    const T& operator[](size_t i) {
        return deq[i];
    }

    size_t Size() const {
        return deq.Size();
    }



    void PopFront() {
        deq.Pop_Front();
    }
};

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
