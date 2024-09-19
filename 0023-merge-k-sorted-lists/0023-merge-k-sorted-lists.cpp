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
        priority_queue<int, vector<int> ,greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* mover=lists[i];
            while(mover){
                pq.push(mover->val);
                mover=mover->next;
            }}
        // vector<int> ans;
    ListNode* node=new ListNode(0);
    ListNode*mover=node;
        while(!pq.empty()){
            ListNode* ans=new ListNode(pq.top());
            mover->next=ans;
            mover=mover->next;  
            pq.pop();        
        }
        return node->next;
    }
};