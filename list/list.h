// list.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef SORTING_LIST_H
#define SORTING_LIST_H

#include <iostream>

typedef int TValue;

class TNode {
public:
    TNode* prev, * next;
    TValue val;


    TNode* find(TNode* root, const TValue& value)
    {
        TNode* cur = root;
        while (cur)
        {
            if (cur->val == value)
            {
                return cur;
            }
            cur = cur->next;
            if (cur == root)
            {
                return nullptr;
            }
        }
    }

    TNode* del(TNode* node)
    {
        if (!node) return nullptr;
        if (node->prev)
        {
            node->prev->next = node->next;
        }
        if (node->next)
        {
            node->next->prev = node->prev;
        }
        TNode* ret = node->next;
        delete node;
        return ret;
    }
    TNode* insert_after(TNode* node, TValue value)
    {
        TNode* node_next = new TNode;
        node_next->val = value;
        node_next->prev = node;
        if (node)
        {
            node_next->next = node->next;
            node->next = node_next;
        }
        else
        {
            node_next->next = nullptr;
        }
        if (node_next->next)
        {
            node_next->next->prev = node_next;
        }
        return node_next;
    }
    TNode* insert_before(TNode* node, TValue value)
    {
        TNode* node_prev = new TNode;
        node_prev->val = value;
        node_prev->next = node;
        if (node)
        {
            node_prev->prev = node->prev;
            node->prev = node_prev;
        }
        else
        {
            node_prev->prev = nullptr;
        }
        if (node_prev->prev)
        {
            node_prev->prev->next = node_prev;
        }
        return node_prev;
    }
};

#endif //SORTING_LIST_H

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
