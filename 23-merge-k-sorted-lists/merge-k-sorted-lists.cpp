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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=lists[0];
        ListNode* head=dummy;
        for(int i=1;i<lists.size();i++){
            ListNode* t1=dummy->next;
            ListNode* t2=lists[i];
            while(t1 && t2){
                if(t1->val<=t2->val){
                    dummy->next=t1;
                    t1=t1->next;
                }else{
                    dummy->next=t2;
                    t2=t2->next;
                }
                dummy=dummy->next;
            }
            if(t1!=nullptr) dummy->next=t1;
            else dummy->next=t2;
            dummy=head;
        }
        return head->next;
    }
};