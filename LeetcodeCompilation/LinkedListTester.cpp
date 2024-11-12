#include "LinkedListTester.h"

#include <unordered_set>


bool LinkedListTester::testAllProblems()
{
    ListNode* list1 = LinkedList::createLinkedList({ 1, 2, 3, 4, 5 });
    ListNode* revlist1 = LinkedList::createLinkedList({ 5, 4, 3, 2, 1 });
    addTestCase(testReverseLinkedList(list1, revlist1));
    LinkedList::destroyLinkedList(list1);
    LinkedList::destroyLinkedList(revlist1);

    ListNode* list2 = LinkedList::createLinkedList({ 1, 2 });
    ListNode* revlist2 = LinkedList::createLinkedList({ 2, 1 });
    addTestCase(testReverseLinkedList(list2, revlist2));
    LinkedList::destroyLinkedList(list2);
    LinkedList::destroyLinkedList(revlist2);

    ListNode* list3 = LinkedList::createLinkedList({ 1, 2, 4 });
    ListNode* list4 = LinkedList::createLinkedList({ 1, 3, 4 });
    ListNode* mergedlist1 = LinkedList::createLinkedList({ 1, 1, 2, 3, 4, 4 });
    addTestCase(testMergeTwoSortedLists(list3, list4, mergedlist1));
    LinkedList::destroyLinkedList(list3); // list3 contains both list3 and list4 after merge.
    LinkedList::destroyLinkedList(mergedlist1);

    ListNode* list5 = LinkedList::createLinkedList({});
    ListNode* list6 = LinkedList::createLinkedList({});
    ListNode* mergedlist2 = LinkedList::createLinkedList({});
    addTestCase(testMergeTwoSortedLists(list5, list6, mergedlist2));
    LinkedList::destroyLinkedList(list5); // list5 contains both list5 and list6 after merge.
    LinkedList::destroyLinkedList(mergedlist2);

    ListNode* list7 = LinkedList::createLinkedList({});
    ListNode* list8 = LinkedList::createLinkedList({ 0 });
    ListNode* mergedlist3 = LinkedList::createLinkedList({ 0 });
    addTestCase(testMergeTwoSortedLists(list7, list8, mergedlist3));
    LinkedList::destroyLinkedList(list7); // list3 contains both list7 and list8 after merge.
    LinkedList::destroyLinkedList(mergedlist3);

    // linked list cycle requires custom linked lists that contain cycles for testing
    ListNode* list9 = LinkedList::createLinkedList({ 3, 2, 0, -4 });
    ListNode* curr = list9; // creating a cycle for testing
    while (curr->next)
        curr = curr->next;
    curr->next = list9;
    addTestCase(testLinkedListCycle(list9, true));
    curr->next = nullptr;
    LinkedList::destroyLinkedList(list9);

    ListNode* list10 = LinkedList::createLinkedList({ 1, 2 });
    curr = list10; // creating a cycle for testing
    while (curr->next)
        curr = curr->next;
    curr->next = list10;
    addTestCase(testLinkedListCycle(list10, true));
    curr->next = nullptr;
    LinkedList::destroyLinkedList(list10);

    ListNode* list11 = LinkedList::createLinkedList({ 1 });
    addTestCase(testLinkedListCycle(list11, false));
    LinkedList::destroyLinkedList(list11);

    ListNode* list12 = LinkedList::createLinkedList({ 1, 2, 3, 4 });
    ListNode* reorderedList1 = LinkedList::createLinkedList({ 1, 4, 2, 3 });
    addTestCase(testReorderList(list12, reorderedList1));
    LinkedList::destroyLinkedList(list12);
    LinkedList::destroyLinkedList(reorderedList1);

    ListNode* list13 = LinkedList::createLinkedList({ 1, 2, 3, 4, 5 });
    ListNode* reorderedList2 = LinkedList::createLinkedList({ 1, 5, 2, 4, 3 });
    addTestCase(testReorderList(list13, reorderedList2));
    LinkedList::destroyLinkedList(list13);
    LinkedList::destroyLinkedList(reorderedList2);
    
    ListNode* list14 = LinkedList::createLinkedList({ 1, 2, 3, 4, 5 });
    ListNode* listremoved1 = LinkedList::createLinkedList({ 1, 2, 3, 5 });
    addTestCase(testRemoveNthNodeFromEnd(list14, 2, listremoved1));
    LinkedList::destroyLinkedList(list14);
    LinkedList::destroyLinkedList(listremoved1);

    ListNode* list15 = LinkedList::createLinkedList({ 1 });
    ListNode* listremoved2 = LinkedList::createLinkedList({});
    addTestCase(testRemoveNthNodeFromEnd(list15, 1, listremoved2));

    ListNode* list16 = LinkedList::createLinkedList({ 1, 2 });
    ListNode* listremoved3 = LinkedList::createLinkedList({ 1 });
    addTestCase(testRemoveNthNodeFromEnd(list16, 1, listremoved3));
    LinkedList::destroyLinkedList(list16);
    LinkedList::destroyLinkedList(listremoved3);

    ListNode* add1 = LinkedList::createLinkedList({ 2, 4, 3 });
    ListNode* add2 = LinkedList::createLinkedList({ 5, 6, 4 });
    ListNode* total1 = LinkedList::createLinkedList({ 7, 0, 8 });
    addTestCase(testAddTwoNumbers(add1, add2, total1));
    LinkedList::destroyLinkedList(add1);
    LinkedList::destroyLinkedList(add2);
    LinkedList::destroyLinkedList(total1);

    ListNode* add3 = LinkedList::createLinkedList({ 0 });
    ListNode* add4 = LinkedList::createLinkedList({ 0 });
    ListNode* total2 = LinkedList::createLinkedList({ 0 });
    addTestCase(testAddTwoNumbers(add3, add4, total2));
    LinkedList::destroyLinkedList(add3);
    LinkedList::destroyLinkedList(add4);
    LinkedList::destroyLinkedList(total2);

    ListNode* add5 = LinkedList::createLinkedList({ 9, 9, 9, 9, 9, 9, 9 });
    ListNode* add6 = LinkedList::createLinkedList({ 9, 9, 9, 9 });
    ListNode* total3 = LinkedList::createLinkedList({ 8, 9, 9, 9, 0, 0, 0, 1 });
    addTestCase(testAddTwoNumbers(add5, add6, total3));
    LinkedList::destroyLinkedList(add5);
    LinkedList::destroyLinkedList(add6);
    LinkedList::destroyLinkedList(total3);

    addTestCase(testFindDuplicate({ 1, 3, 4, 2, 2 }, 2));
    addTestCase(testFindDuplicate({ 3, 1, 3, 4, 2 }, 3));
    addTestCase(testFindDuplicate({ 3, 3, 3, 3, 3 }, 3));

    addTestCase(testLRUCache());

    std::vector<ListNode*> lists;
    lists.push_back(LinkedList::createLinkedList({ 1, 4, 5 }));
    lists.push_back(LinkedList::createLinkedList({ 1, 3, 4 }));
    lists.push_back(LinkedList::createLinkedList({ 2, 6 }));
    ListNode* mergedlist4 = LinkedList::createLinkedList({ 1, 1, 2, 3, 4, 4, 5, 6 });
    addTestCase(testMergeKSortedLists(lists, mergedlist4));
    LinkedList::destroyLinkedList(mergedlist4);

    std::vector<ListNode*> emptylists;
    ListNode* mergedlist5 = LinkedList::createLinkedList({});
    addTestCase(testMergeKSortedLists(emptylists, mergedlist5));


    ListNode* list17 = LinkedList::createLinkedList({ 1, 2, 3, 4, 5 });
    ListNode* kgroup1 = LinkedList::createLinkedList({ 2, 1, 4, 3, 5 });
    addTestCase(testReverseKGroup(list17, 2, kgroup1));
    LinkedList::destroyLinkedList(list17);
    LinkedList::destroyLinkedList(kgroup1);

    ListNode* list18 = LinkedList::createLinkedList({ 1, 2, 3, 4, 5 });
    ListNode* kgroup2 = LinkedList::createLinkedList({ 3, 2, 1, 4, 5 });
    addTestCase(testReverseKGroup(list18, 3, kgroup2));
    LinkedList::destroyLinkedList(list18);
    LinkedList::destroyLinkedList(kgroup2);

    return runAllTests();
}

bool LinkedListTester::testReverseLinkedList(ListNode* head, ListNode* expected)
{
    if (getVerbose())
    {
        ListNode* headcopy = head;
        ss << "\nReverse Linked List Test Run on Input List:\n [ ";
        printList(headcopy);
        ss << "]\n";
    }
    ListNode* actual = ll.reverseLinkedList(head);
    if (getVerbose())
    {
        ListNode* actualcopy = actual;
        ListNode* expectedcopy = expected;

        ss << "Result:   [ ";
        printList(actualcopy);
        ss << "]\nExpected: [ ";
        printList(expectedcopy);
        ss << "]\n";
    }

    while (actual && expected)
    {
        if (actual->val != expected->val)
            return false;

        actual = actual->next;
        expected = expected->next;
    }

    if (actual || expected)
        return false;

    return true;
}

bool LinkedListTester::testMergeTwoSortedLists(ListNode* list1, ListNode* list2, ListNode* expected)
{
    if (getVerbose())
    {
        ListNode* list1copy = list1;
        ListNode* list2copy = list2;
        ss << "\nMerge Two Sorted Linked Lists Test Run on Input List:\n1: [ ";
        printList(list1copy);
        ss << "]\n2: [ ";
        printList(list2copy);
    }
    ListNode* actual = ll.mergeTwoSortedLists(list1, list2);
    if (getVerbose())
    {
        ListNode* actualcopy = actual;
        ListNode* expectedcopy = expected;

        ss << "]\nResult:   [ ";
        printList(actualcopy);
        ss << "]\nExpected: [ ";
        printList(expectedcopy);
        ss << "]\n";
    }
    while (actual && expected)
    {
        if (actual->val != expected->val)
            return false;

        actual = actual->next;
        expected = expected->next;
    }

    if (actual || expected)
        return false;

    return true;
}

bool LinkedListTester::testLinkedListCycle(ListNode* head, bool expected)
{
    if (getVerbose())
    {
        ListNode* headcopy = head;
        ss << "\nLinked List Cycle Test Run on Input List:\n1: [ ";
        std::unordered_set<ListNode*> visited;
        while (headcopy && visited.find(headcopy) == visited.end())
        {
            ss << headcopy->val << " ";
            visited.insert(headcopy);
            headcopy = headcopy->next;
            if (headcopy)
                ss << "-> ";
        }
        ss << "]\n";
    }
    bool actual = ll.linkedListCycle(head);
    if (getVerbose())
        ss << "Result: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool LinkedListTester::testReorderList(ListNode* head, ListNode* expected)
{
    if (getVerbose())
    {
        ListNode* headcopy = head;
        ss << "\nReorder Linked List Test Run on Input List:\n [ ";
        printList(headcopy);
        ss << "]\n";
    }
    ll.reorderList(head);
    if (getVerbose())
    {
        ListNode* actualcopy = head;
        ListNode* expectedcopy = expected;

        ss << "Result:   [ ";
        printList(actualcopy);
        ss << "]\nExpected: [ ";
        printList(expectedcopy);
        ss << "]\n";
    }
    while (head && expected)
    {
        if (head->val != expected->val)
            return false;

        head = head->next;
        expected = expected->next;
    }

    if (head|| expected)
        return false;

    return true;
}

bool LinkedListTester::testRemoveNthNodeFromEnd(ListNode* head, int n, ListNode* expected)
{
    if (getVerbose())
    {
        ListNode* headcopy = head;
        ss << "\nRemove Nth Node From End Linked List Test Run on Input List:\nn: " << n << "\n [ ";
        printList(headcopy);
        ss << "]\n";
    }
    ListNode* actual = ll.removeNthNodeFromEnd(head, n);
    if (getVerbose())
    {
        ListNode* actualcopy = actual;
        ListNode* expectedcopy = expected;

        ss << "Result:   [ ";
        printList(actualcopy);
        ss << "]\nExpected: [ ";
        printList(expectedcopy);
        ss << "]\n";
    }
    while (actual && expected)
    {
        if (actual->val != expected->val)
            return false;

        actual = actual->next;
        expected = expected->next;
    }

    if (actual || expected)
        return false;

    return true;
}

bool LinkedListTester::testAddTwoNumbers(ListNode* l1, ListNode* l2, ListNode* expected)
{
    if (getVerbose())
    {
        ListNode* list1copy = l1;
        ListNode* list2copy = l2;
        ss << "\nAdd Two Numbers Linked Lists Test Run on Input List:\n1: [ ";
        printList(list1copy);
        ss << "]\n2: [ ";
        printList(list2copy);
        ss << "]\n";
    }
    ListNode* actual = ll.addTwoNumbers(l1, l2);
    if (getVerbose())
    {
        ListNode* actualcopy = actual;
        ListNode* expectedcopy = expected;

        ss << "Result:   [ ";
        printList(actualcopy);
        ss << "]\nExpected: [ ";
        printList(expectedcopy);
        ss << "]\n";
    }
    bool result = true;
    while (actual && expected)
    {
        if (actual->val != expected->val)
            result = false;

        actual = actual->next;
        expected = expected->next;
    }

    if (actual || expected)
        result = false;

    // this function creates a new list, so we should delete it before we finish the test.
    LinkedList::destroyLinkedList(actual);

    return result;
}

bool LinkedListTester::testFindDuplicate(std::vector<int> nums, int expected)
{
    int actual = ll.findDuplicate(nums);
    if (getVerbose())
    {
        ss << "\nFind Duplicate (Linked List) Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool LinkedListTester::testLRUCache()
{
    LinkedList::LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    if (1 != cache.get(1)) return false;
    cache.put(3, 3); // evict LRU key 2 since 1 was used recently
    if (-1 != cache.get(2)) return false;
    cache.put(4, 4); // evict LRU key 1 since its now not recently used
    if (-1 != cache.get(1)) return false;
    if (3 != cache.get(3)) return false;
    if (4 != cache.get(4)) return false;
    return true;
}

bool LinkedListTester::testMergeKSortedLists(std::vector<ListNode*> lists, ListNode* expected)
{
    if (getVerbose())
    {
        ss << "\nMerge K Sorted Linked Lists Test Run on Input List Vector:\n[\n";
        for (ListNode* head : lists)
        {
            ListNode* headcopy = head;
            printList(headcopy);
            ss << "\n";
        }
        ss << "]\n";
    }
    ListNode* actual = ll.mergeKLists(lists);
    if (getVerbose())
    {
        ListNode* actualcopy = actual;
        ListNode* expectedcopy = expected;

        ss << "Result:   [ ";
        printList(actualcopy);
        ss << "]\nExpected: [ ";
        printList(expectedcopy);
        ss << "]\n";
    }

    bool result = true;
    while (actual && expected)
    {
        if (actual->val != expected->val)
            result = false;
        actual = actual->next;
        expected = expected->next;
    }

    if (actual || expected)
        result = false;

    LinkedList::destroyLinkedList(actual);
    LinkedList::destroyLinkedList(expected);

    return result;
}

bool LinkedListTester::testReverseKGroup(ListNode* head, int k, ListNode* expected)
{
    if (getVerbose())
    {
        ListNode* headcopy = head;
        ss << "\nReverse K Group Linked List Test Run on Input List:\nk: " << k << "\n [ ";
        printList(headcopy);
        ss << "]\n";
    }
    ListNode* actual = ll.reverseKGroup(head, k);
    if (getVerbose())
    {
        ListNode* actualcopy = actual;
        ListNode* expectedcopy = expected;

        ss << "Result:   [ ";
        printList(actualcopy);
        ss << "]\nExpected: [ ";
        printList(expectedcopy);
        ss << "]\n";
    }
    while (actual && expected)
    {
        if (actual->val != expected->val)
            return false;

        actual = actual->next;
        expected = expected->next;
    }

    if (actual || expected)
        return false;

    return true;
}

void LinkedListTester::printList(ListNode* head)
{
    while (head)
    {
        ss << head->val << " ";
        head = head->next;
        if (head)
            ss << "-> ";
    }
}

