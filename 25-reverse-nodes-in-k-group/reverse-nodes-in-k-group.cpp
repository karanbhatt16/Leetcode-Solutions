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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* findKnode(ListNode* head, int k){
        while(k!=1){
            if(head->next==nullptr) return nullptr;
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=nullptr;
        while(temp){
            ListNode* kthNode=findKnode(temp,k);
            if(kthNode==nullptr){
                prevNode->next=temp;
                break;
            }
            ListNode* start=kthNode->next;
            kthNode->next=nullptr;
            ListNode* newhead=reverse(temp);
            if(temp==head){
                head=newhead;
            }else{
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=start;
        }
        return head;
    }

};