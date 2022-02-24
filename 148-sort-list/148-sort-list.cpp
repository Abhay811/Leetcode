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
    ListNode* sortList(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode *slow = head, *fast = head -> next;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *snd = slow -> next;
        slow -> next = nullptr;
        ListNode *l = sortList(head);
        ListNode *l2 = sortList(snd);
        return merge(l, l2);
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode *temp = nullptr;
        if (!left) return right;
        if (!right) return left;
        if (left -> val < right -> val) {
            temp = left;
            temp -> next = merge(left -> next, right);
        }
        else {
            temp = right;
            temp -> next = merge(left, right -> next);
        }
        return temp;
    }
};