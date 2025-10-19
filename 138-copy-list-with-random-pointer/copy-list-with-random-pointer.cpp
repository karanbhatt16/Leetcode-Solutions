/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* mover=head;
        while(mover){
            Node* front=mover->next;
            mover->next=new Node(mover->val);
            mover=mover->next;
            mover->next=front;
            mover=mover->next;
        }
        Node* dummy=new Node(-1);
        Node* newHead=dummy;
        mover=head;
        while(mover){
            if(mover->random==nullptr){
                mover->next->random=nullptr;
            }else{
                mover->next->random=mover->random->next;
            }
            mover=mover->next->next;
        }
        mover=head;
        while(mover){
            dummy->next=mover->next;
            mover->next=mover->next->next;
            mover=mover->next;
            dummy=dummy->next;
        }
        return newHead->next;
    }
};