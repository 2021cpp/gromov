// QuickSort.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef SORTING_QUICK_SORT_H
#define SORTING_QUICK_SORT_H

#include <iostream>
#include <vector>
#include <random>

template< class RandomIt >

void QuickSort(RandomIt a, int n)
{
    int mid = (n + 1) / 2;
    int right_pos = 0;
    std::swap(*a, *(a + mid - 1));
    for (int i = 0; i < n; ++i) {
        if (*(a + i) < *a) {
            std::swap(*(a + right_pos + 1), *(a + i));
            right_pos += 1;
        }
    }
    std::swap(*(a + right_pos), *a);
    if (right_pos > 0)
        QuickSort(a, right_pos);
    if (right_pos < n - 1)
        QuickSort(a + right_pos + 1, n - right_pos - 1);
    return;
}

#endif //SORTING_QUICK_SORT_H

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
