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
        ListNode* temp = nullptr, *stemp;
        while (head)
        {
            stemp = head -> next;
            head -> next = temp;
            temp = head;
            head = stemp;
        }
        return temp;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t = new ListNode();
        ListNode* temp = t;
        int c = 0;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        while (l1 || l2 || c)
        {
            int s = 0;
            if (l1)
            {
                s += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2)
            {
                s += l2 -> val;
                l2 = l2 -> next;
            }
            s += c;
            c = s / 10;
            ListNode *newNode = new ListNode(s % 10);
            temp -> next = newNode;
            temp = temp -> next;
        }
        t = reverseList(t -> next);
        return t;
    }
};