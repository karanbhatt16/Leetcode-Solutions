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
    ListNode* swapPairs(ListNode* head) {
        ListNode* mover = head;
        if (mover == NULL || mover->next == NULL) return head;
        head = head->next;
        
        while(mover->next->next != NULL && mover->next->next->next != NULL){
            ListNode* nextNode = mover->next->next;
            mover->next->next = mover;
            mover->next = nextNode->next;
            mover = nextNode;
        }
        if (mover->next->next == NULL) {
            mover->next->next = mover;
            mover->next = NULL;
            return head;
        }
        if (mover->next->next->next == NULL) {
            ListNode* nextNode = mover->next->next;
            mover->next->next = mover;
            mover->next = nextNode;
        }
        return head;
    }
};