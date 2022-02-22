/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        int s = 0, t = 0;
        ListNode *res = nullptr;
        while (s != 2)
        {
            if (a == b)
            {
                res = a; break;
            }
            if (a) a = a -> next;
            else a = headB, s++;
            if (b) b = b -> next;
            else b = headA;
        }
        return res;
        
    }
};