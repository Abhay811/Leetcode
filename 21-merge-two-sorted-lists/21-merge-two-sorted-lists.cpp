/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr, **temp = &head, **target;
        for (; list1 && list2; *target = (*target) -> next)
        {
            target = (list1 -> val) < (list2 -> val) ? &list1 : &list2;
            *temp = *target;
            temp = &(*temp) -> next;
        }
        *temp = (ListNode*)((uintptr_t) list2 | (uintptr_t) list1);
        return head;
    }
};