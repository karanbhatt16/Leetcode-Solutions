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
    int pairSum(ListNode* head) {
        ListNode* node = head;
        ListNode* head2 = head;
        int n = 0;
        while (node) {
            node = node->next->next;
            head2 = head2->next;
            n++;
        }

        vector<int> sum(n);
        node = head;

        for (int i = 0; i < n; i++) {
            sum[i] += node->val;
            sum[n - i - 1] += head2->val;
            node = node->next;
            head2 = head2->next;
        }

        return *max_element(sum.begin(), sum.end());
    }
};