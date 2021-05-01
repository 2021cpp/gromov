// HeapSort.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef SORTING_HEAP_SORT_H
#define SORTING_HEAP_SORT_H

#include <iostream>
#include <vector>
#include <random>

template< class RandomIt >
void SiftDown(RandomIt b, int root, int bottom)
{
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
        {
            maxChild = root * 2;
        }
        else
        {
            if (*(b + root * 2) > * (b + root * 2 + 1))
            {
                maxChild = root * 2;
            }
            else
            {
                maxChild = root * 2 + 1;
            }
        }
        if (*(b + root) < *(b + maxChild))
        {
            std::swap(*(b + root), *(b + maxChild));
            root = maxChild;
        }
        else
        {
            done = 1;
        }
    }
}

template< class RandomIt >
void HeapSort(RandomIt b, RandomIt e)
{
    for (int i = (e - b) / 2; i >= 0; i--)
    {
        SiftDown(b, i, (e - b) - 1);
    }
    for (int i = (e - b) - 1; i >= 1; i--)
    {
        std::swap(*b, *(b + i));
        SiftDown(b, 0, i - 1);
    }
}

#endif //SORTING_HEAP_SORT_H

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
