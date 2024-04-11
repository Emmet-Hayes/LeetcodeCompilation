#pragma once

#include "Solution.h"
#include "ListNode.h"

#include <list>
#include <unordered_map>
#include <vector>


class LinkedList : public Solution
{
public:
    LinkedList() : Solution("LinkedList", "Common challenge problems involving linked lists.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<LinkedList>(*this); }
    
    static ListNode* createLinkedList(const std::vector<int>& arr);
    static void destroyLinkedList(ListNode* toDestroy);

    ListNode* reverseLinkedList(ListNode* head);
    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2);
    bool linkedListCycle(ListNode* head);
    void reorderList(ListNode* head);
    ListNode* removeNthNodeFromEnd(ListNode* head, int n);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    int findDuplicate(const std::vector<int>& nums);
    ListNode* mergeKLists(const std::vector<ListNode*>& lists);
    ListNode* reverseKGroup(ListNode* head, int k);

    // Reverse Linked List 2
    // Remove Duplicates From List 2
    // Rotate List
    // Partition List
    // Sort List
    // Delete Middle Node
    // Odd Even Linked List
    // Maximum Twin Sum
    // Intersection of Two Lists
    // Palindrome Linked List
    // Linked List Cycle 2
    // Swap Nodes in Pairs

    class LRUCache
    {
    public:
        LRUCache(int capacity) : cap(capacity) {}

        int get(int key);
        void put(int key, int value);

    private:
        int cap;
        std::list<std::pair<int, int>> cachelist; // List of key-value pairs
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cachemap; // Map keys to iterators of list elements
    };
};