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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* mover=head;
        ListNode* mid=head;
        if(head->next==nullptr){
            return nullptr;
        }
        if(head->next->next==nullptr){
            ListNode* temp=head->next;
            head->next=nullptr;
            delete temp;
            return head;
        }
        int i=1;
        while(mover){
            if(i%2==0){
                mid=mid->next;
            }
            i++;
            mover=mover->next;
        }
        mid->val=mid->next->val;
        ListNode* temp=mid->next;
        mid->next=mid->next->next;
        delete temp;
        return head;
    }
};