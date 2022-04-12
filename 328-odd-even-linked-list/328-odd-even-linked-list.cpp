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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode *temp = head;
        ListNode *stemp = head -> next;
        ListNode *ttemp = stemp;
        while (ttemp && ttemp -> next)
        {
            temp -> next = temp -> next -> next;
            ttemp -> next = ttemp -> next -> next;
            temp = temp -> next;
            ttemp = ttemp -> next;
        }
        temp -> next = stemp;
        return head;
    }
};