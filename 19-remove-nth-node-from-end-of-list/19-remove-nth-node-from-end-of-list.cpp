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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** slow = &head, *fast = head;
        int i = 1;
        while (i < n)
            fast = fast -> next, i++;
        cout << fast -> val;
        while (fast -> next)
            fast = fast -> next, slow = &(*slow) -> next;
        *slow = (*slow) -> next;
        return head;
    }
};