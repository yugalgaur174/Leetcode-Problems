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
        // return head;
        if(head==nullptr) return nullptr;
        Node* mover=head;
        Node* m=new Node(0);
        Node* point=m;
        unordered_map<Node*,int> mpp1;
        unordered_map<int,Node*>mpp2;
        int i=0;
        while(mover){
            mpp1[mover]=i;
            i++;
            mover=mover->next;
        }
        i=0;
        unordered_map<int,int>mpp3;
        mover=head;
        while(mover){
            
            Node* y=new Node(mover->val);
            m->next=y;
            mpp2[i]=y;
            if (mover->random) {
                mpp3[i] = mpp1[mover->random];  
            } else {
                mpp3[i] = -1; 
            }
            mover=mover->next;
            m=m->next;
            i++;
        }
        m->next=nullptr;
        m=point->next;
        i=0;
        while(m){
           if (mpp3[i] != -1) {
                m->random = mpp2[mpp3[i]];  
            }
            m=m->next;
            i++;
        }
        return point->next;
    }
};