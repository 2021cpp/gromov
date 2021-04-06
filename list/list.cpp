#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

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

TEST_CASE("òåñò")
{
    TNode* head = nullptr;
    TValue the_very_first = 1u;
    head = TNode().insert_after(head, the_very_first);
    TNode* tail = head;
    int N = 7, K = 3;
    for (int i = 2; i <= N; ++i)
    {
        tail = TNode().insert_after(tail, i);
    }
    tail->next = head;
    head->prev = tail;
    TNode* cur = head;
    for (int count = 0; count < N - 1; ++count)
    {
        for (int i = 0; i < K - 1; ++i)
        {
            cur = cur->next;
        }
        cur = TNode().del(cur);
    }

    REQUIRE(cur->val == 4);

    TNode().del(cur);
}
