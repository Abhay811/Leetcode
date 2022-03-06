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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        
        if (head == nullptr)
            return 0;
        vector<int> arr;
        while (temp!= nullptr)
        {
            arr.emplace_back(temp->val);
            temp = temp->next;
        }
        reverse(arr.begin(), arr.end());
        int res = 0, n = arr.size();
        for (int i = 0; i < n; i++)
            res += (arr[i] << i);
        return res;
    }
};