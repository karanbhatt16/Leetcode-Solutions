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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        if(count==0){
            return nullptr;
        }
        k=k%count;
        temp=head;
        ListNode* mover=head;
        while(k!=0){
            temp=temp->next;
            k--;
        }
        while(temp->next!=nullptr){
            mover=mover->next;
            temp=temp->next;
        }
        temp->next=head;
        head=mover->next;
        mover->next=nullptr;
        return head;
    }
};