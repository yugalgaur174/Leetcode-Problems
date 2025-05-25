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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        // int a=0;
        // while(slow){
        //     a++;
        //     slow=slow->next;
        // }
        slow=head;
        while(fast && fast->next ){
            
            fast=fast->next->next;
            slow=slow->next;
        }
        // if(a%2==0)return slow->next;
        return slow;
    }
};