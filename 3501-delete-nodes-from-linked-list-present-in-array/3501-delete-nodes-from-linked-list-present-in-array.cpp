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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=1;
        }
        ListNode* mover=head;
        ListNode* prev=nullptr;
        while(mover){
            if(mpp[mover->val]==1){
                if(prev==nullptr){
                    mover=mover->next;
                    head=mover;
                }
                else {
                    prev->next=mover->next;
                    mover=mover->next;
                }
            }
            else{
                prev=mover;
                mover=mover->next;
            }
        }
        return head;
    }
};