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
private:
    int solve(ListNode* head, ListNode* node, ListNode* &head2) {
        if (node == NULL) return 0;
        head2 = head->next;
        int x = solve(head->next, node->next->next, head2);
        int ans = max(x, head->val + head2->val);
        head2 = head2->next;
        return ans;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* node = head;
        ListNode* head2 = head;
        return solve(head, head2, head2);

    }
};