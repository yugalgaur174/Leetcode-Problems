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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL ) return 0;
        if(head->next==NULL) return head;
        vector<int> a;
        ListNode* mover=head;
        while(mover!=NULL && mover->next!=NULL){
            a.push_back(mover->val);
            mover=mover->next->next;
        }
        if(mover) a.push_back(mover->val);
        mover=head->next;
        while(mover!=NULL && mover->next!=NULL){
            a.push_back(mover->val);
            mover=mover->next->next;
        }
        if(mover ) a.push_back(mover->val);
        int i=0;
        mover=head;
        while(mover){
            mover->val=a[i];
            i++;
            mover=mover->next;
        }
        return head;

    }
};