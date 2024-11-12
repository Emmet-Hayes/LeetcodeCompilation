#include "LinkedList.h"

#include <queue>


ListNode* LinkedList::createLinkedList(const std::vector<int>& arr)
{
    if (arr.size() < 1) return nullptr; // list of size 0 is nullptr

    ListNode* curr = new ListNode(arr[0]);
    ListNode* head = curr;

    for (unsigned i = 1; i < arr.size(); ++i)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

void LinkedList::destroyLinkedList(ListNode* toDestroy)
{
    ListNode* curr = toDestroy;

    while (curr)
    {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

/** Reverse Linked List (Google/Meta - Easy)
* Given the head of a singly linked list, reverse the list, and 
* return the reversed list.
* 
* Time: O(n)
* Space: O(1)
*/
ListNode* LinkedList::reverseLinkedList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr)
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


/** Merge Two Sorted Lists (Microsoft - Easy)
* You are given the heads of two sorted linked lists list1 and list2.
*
* Merge the two lists into one sorted list. The list should be made 
* by splicing together the nodes of the first two lists.
*
* Return the head of the merged linked list.
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
ListNode* LinkedList::mergeTwoSortedLists(ListNode* list1, ListNode* list2)
{
    ListNode dummy;
    ListNode* tail = &dummy;

    // do the merging step here
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // attach the remaining values from the list that still has values in it
    tail->next = list1 ? list1 : list2;

    return dummy.next;
}


/** Linked List Cycle (Amazon - Easy)
* Given head, the head of a linked list, determine if the linked list has a cycle 
* in it.
*
* There is a cycle in a linked list if there is some node in the list that can be 
* reached again by continuously following the next pointer. Internally, pos is 
* used to denote the index of the node that tail's next pointer is connected to. 
* Note that pos is not passed as a parameter.
*
* Return true if there is a cycle in the linked list. Otherwise, return false.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
bool LinkedList::linkedListCycle(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode* slow = head;
    ListNode* fast = head->next;

    // at some point, the fast pointer will be the same as slow if there is a cycle
    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr) // hit end of list, no cycle
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true; // found a cycle if slow == fast
}


/** Reorder List (LinkedIn - Medium)
* You are given the head of a singly linked-list. The list can be represented as:
*
* L0 → L1 → ... → Ln - 1 → Ln
* Reorder the list to be on the following form:
*
* L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → ...
* You may not modify the values in the list's nodes. Only nodes themselves may 
* be changed.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
void LinkedList::reorderList(ListNode* head)
{
    if (!head || !head->next)
        return;

    ListNode* slow = head;
    ListNode* fast = head;

    // find the midpoint
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse the second half
    ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    while (curr)
    {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    slow->next = nullptr; // cut off first half from second

    // merge the two halves
    ListNode* first = head; // ascending
    ListNode* second = prev; // descending
    while (second)
    {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}


/** Remove Nth Node From End of List (Oracle - Medium)
* Given the head of a linked list, remove the nth node from the end 
* of the list and return its head.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
ListNode* LinkedList::removeNthNodeFromEnd(ListNode* head, int n)
{
    if (!head) return nullptr;
    ListNode dummy(0); // handle edge cases
    dummy.next = head;

    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    for (int i = 0; i <= n; ++i)
        fast = fast->next;

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    if (slow && slow->next)
    {
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
    }

    return dummy.next;
}


/** Add Two Numbers (Amazon - Medium)
* You are given two non-empty linked lists representing two non-negative integers. 
* The digits are stored in reverse order, and each of their nodes contains a single 
* digit. Add the two numbers and return the sum as a linked list.
*
* You may assume the two numbers do not contain any leading zero, except the number 
* 0 itself.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
ListNode* LinkedList::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode dummyHead(0);
    ListNode* current = &dummyHead;
    int carry = 0;

    while (l1 || l2)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int digitsum = carry + x + y; // sum the digits plus any carry from last iteration
        carry = digitsum / 10; // store the carry for the next iteration
        current->next = new ListNode(digitsum % 10);
        current = current->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    if (carry > 0) // if we have carry leftover we create a new node to hold it
        current->next = new ListNode(carry);

    return dummyHead.next;
}


/** Find the Duplicate Number (Amazon - Medium)
* Given an array of integers nums containing n + 1 integers where each integer 
* is in the range [1, n] inclusive.
* 
* There is only one repeated number in nums, return this repeated number.
* 
* You must solve the problem without modifying the array nums and uses only 
* constant extra space.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int LinkedList::findDuplicate(const std::vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[0];

    bool found = false;
    while (!found)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
            break;
    }

    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return fast;
}


/** Merge k-sorted Lists (Meta - Hard)
* You are given an array of k linked-lists lists, each linked-list is sorted 
* in ascending order.
*
* Merge all the linked-lists into one sorted linked-list and return it.
* 
* Complexity:
* Time: O(n log n)
* Space: O(n)
*/
ListNode* LinkedList::mergeKLists(const std::vector<ListNode*>& lists)
{
    auto comparator = [](ListNode* l1, ListNode* l2) { return l1->val > l2->val; };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comparator)> pq(comparator);

    for (ListNode* list : lists)
        if (list)
            pq.push(list);

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!pq.empty())
    {
        ListNode* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) pq.push(node->next);
    }

    return dummy.next;
}


/** Reverse Nodes in k-Group (Microsoft - Hard)
* Given the head of a linked list, reverse the nodes of the list k at a time, 
* and return the modified list.
* k is a positive integer and is less than or equal to the length of the 
* linked list. If the number of nodes is not a multiple of k then left-out nodes, 
* in the end, should remain as it is.
*
* You may not alter the values in the list's nodes, only nodes themselves may 
* be changed.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
ListNode* LinkedList::reverseKGroup(ListNode* head, int k)
{
    if (head == nullptr || k == 1) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* curr = &dummy, * nex = &dummy, * pre = &dummy;
    int count = 0;

    while (curr->next != nullptr)
    {
        count++;
        curr = curr->next;
    }

    while (count >= k)
    {
        curr = pre->next;
        nex = curr->next;
        for (int i = 1; i < k; ++i)
        {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        count -= k;
    }

    return dummy.next;
}


/** LRU Cache (Twitch - Medium)
* data structure that follows the constraints of a Least Recently Used (LRU) cache.
*
* LRUCache class implementation:
*
* LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
* int get(int key) Return the value of the key if the key exists, otherwise return -1.
* void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
* The functions each run in O(1) average time complexity.
* 
* Complexity:
* Time: O(1)
* Space: O(1)
*/
int LinkedList::LRUCache::get(int key)
{
    auto it = cachemap.find(key);
    if (it == cachemap.end()) return -1; // Key not found

    // Move the accessed item to the front of the cache
    cachelist.splice(cachelist.begin(), cachelist, it->second);
    return it->second->second; // Return the value of the key-value pair
}

void LinkedList::LRUCache::put(int key, int value)
{
    auto it = cachemap.find(key);

    // Key exists, update the value and move it to the front
    if (it != cachemap.end()) 
    {
        it->second->second = value; // Update value
        cachelist.splice(cachelist.begin(), cachelist, it->second);
        return;
    }

    // Check if we need to evict the least recently used item
    if (static_cast<int>(cachelist.size()) == cap) 
    {
        auto& lru = cachelist.back();
        cachemap.erase(lru.first); // Erase from map using key
        cachelist.pop_back(); // Remove least recently used item
    }

    // Insert new item at the front of the cache
    cachelist.emplace_front(key, value);
    cachemap[key] = cachelist.begin(); // Store iterator to the new element
}
