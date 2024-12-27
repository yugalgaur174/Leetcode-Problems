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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* dummy=new ListNode();
        ListNode* prev=dummy;

        while(list1 && list2){
            if(list1->val<=list2->val){
                prev->next=list1;
                list1=list1->next;
            }
            else{
                prev->next=list2;
                list2=list2->next;
            }
            prev=prev->next;
        }
        if(list1){
            prev->next=list1;
        }
        if(list2){
            prev->next=list2;
        }
        return dummy->next;
    }
};