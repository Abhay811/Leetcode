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
    void check(ListNode *&root, ListNode *&temp, bool &res)
    {
        if (!root || !temp || !res) return;
        check(root, temp -> next, res);
        int a = root -> val, b = temp -> val;
        if (a != b)
        {
            res = false;
            return;
        }
        root = root -> next;
    }
    bool isPalindrome(ListNode* head) {
        bool res = true;
        check(head, head, res);
        return res;
    }
};