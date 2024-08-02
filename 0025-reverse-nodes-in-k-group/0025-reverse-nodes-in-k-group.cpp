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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> a;
        ListNode* mover=head;
        while(mover){
            a.push_back(mover->val);
            mover=mover->next;
        }
        for(int i=0;i<k*(a.size()/k);i=i+k){
            reverse(a.begin() + i, a.begin() + i + k);
        }
        int z=0;
        mover=head;
        while(mover){
            mover->val=a[z];
            z++;
            mover=mover->next;
        }
        return head;
    }
};