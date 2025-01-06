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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return nullptr;
        ListNode* curr=head;
        ListNode* pointer=head->next;
        while(curr && pointer){
            while(pointer && curr->val==pointer->val){
                pointer=pointer->next;
            }
            curr->next=pointer;
            curr=curr->next;
            if(pointer){
                pointer=pointer->next;
            }
        }
        return head;
    }
};