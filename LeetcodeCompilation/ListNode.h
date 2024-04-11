#pragma once


struct ListNode
{
    ListNode(int _val = 0, ListNode* _next = nullptr)
    :   val  { _val }
    ,   next { _next }
    {}

    int val;
    ListNode* next;
};
