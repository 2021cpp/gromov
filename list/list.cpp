#define CATCH_CONFIG_MAIN
#include "list.h"
#include "catch.hpp"

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