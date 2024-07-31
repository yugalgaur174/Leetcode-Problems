/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *traverse(ListNode* h1, ListNode * h2, int a){
        while(a>0){
            h1=h1->next;
            a--;
        }
        while(h1){
            if(h1==h2){
                return h1;
            }
            h1=h1->next;
            h2=h2->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0;
        int n2=0;
        ListNode* mover1=headA;
        ListNode* mover2=headB;
        if(mover1==mover2){
            return mover1;
        }
        while(mover1){
            n1++;
            mover1=mover1->next;
        }
        while(mover2){
            n2++;
            mover2=mover2->next;
        }
        if(n1>=n2){
        ListNode* ans=traverse(headA,headB,n1-n2);
        return ans;
        }
        else{
            ListNode* ans=traverse(headB,headA,n2-n1);
            return ans;
        }
        return 0;
    }
};