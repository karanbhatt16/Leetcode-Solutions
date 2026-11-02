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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* newHead = root;
        for (int i = 1; i < left; i++) {
            root = root->next;
        }
        ListNode* node = root->next;
        ListNode* prev = NULL;
        ListNode* temp;
        for (int i = left; i <= right; i++) {
            temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        root->next->next = temp;
        root->next = prev;
        return newHead->next;
    }
};