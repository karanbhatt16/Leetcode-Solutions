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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy=new ListNode(-1);
        ListNode* mover=dummy;
        while(left!=nullptr && right!=nullptr){
            if(left->val<=right->val){
                mover->next=left;
                left=left->next;
            }else{
                mover->next=right;
                right=right->next;
            }
            mover=mover->next;
        }
        if(left) mover->next=left;
        else mover->next=right;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* mid=findMiddle(head);
        ListNode* rightHead=mid->next;
        ListNode* leftHead=head;
        mid->next=nullptr;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);

        return merge(leftHead, rightHead);
    }
};