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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr, *curr = nullptr;
        int s, c = 0;
        while (l1 || l2)
        {
            s = (l1 ? l1->val : 0) + (l2 ? l2 -> val : 0) + c;
            c = (s > 9) ? 1 : 0;
            s = s % 10;
            ListNode *temp = new ListNode(s);
            if (res == nullptr) res = temp;
            else curr -> next = temp;
            curr = temp;
            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }
        if (c)
        {
            ListNode *temp = new ListNode(c);
            curr -> next = temp, curr = temp;
        }
        return res;
    }
};