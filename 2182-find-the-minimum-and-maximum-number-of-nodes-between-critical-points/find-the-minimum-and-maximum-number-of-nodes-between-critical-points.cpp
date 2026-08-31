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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        ListNode* node = head->next;
        ListNode* prev = head;
        int i = 1;
        while (node->next != NULL) {
            if (node->val < node->next->val && node->val < prev->val) {
                critical.push_back(i);
            }
            if (node->val > node->next->val && node->val > prev->val) {
                critical.push_back(i);
            }
            prev = node;
            node = node->next;
            i++;
        }

        int n = critical.size();
        if (n <= 1) {
            return {-1, -1};
        }

        int mn = i + 1;
        int mx = critical[n - 1] - critical[0];

        for (int i = 1; i < n; i++) {
            mn = min(mn, critical[i] - critical[i - 1]);
        }
        
        return {mn, mx};
    }
};