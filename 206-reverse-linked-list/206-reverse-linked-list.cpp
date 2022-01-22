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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* temp = head, *t, *t2;
        t = t2 = nullptr;
        while(temp)
        {
            t = t2;
            t2 = temp;
            temp = temp -> next;
            t2 -> next = t;
        }
        return t2;
    }
};