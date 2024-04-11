#pragma once

#include "LinkedList.h"
#include "Tester.h"


class LinkedListTester : public Tester
{
public:
    LinkedListTester() : Tester { "Linked List" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<LinkedListTester>(*this); }

private:
    bool testReverseLinkedList(ListNode* head, ListNode* expected);
    bool testMergeTwoSortedLists(ListNode* list1, ListNode* list2, ListNode* expected);
    bool testLinkedListCycle(ListNode* head, bool expected);
    bool testReorderList(ListNode* head, ListNode* expected);
    bool testRemoveNthNodeFromEnd(ListNode* head, int n, ListNode* expected);
    bool testAddTwoNumbers(ListNode* l1, ListNode* l2, ListNode* expected);
    bool testFindDuplicate(std::vector<int> nums, int expected);
    bool testLRUCache();
    bool testMergeKSortedLists(std::vector<ListNode*> lists, ListNode* expected);
    bool testReverseKGroup(ListNode* head, int k, ListNode* expected);

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

    void printList(ListNode* head);

    LinkedList ll;
};