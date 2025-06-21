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
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow;
        ListNode* curr = mid->next;
        mid->next = nullptr;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        ListNode* head2 = prev;
        ListNode* start=head;
        ListNode* t1=nullptr;
        ListNode* t2=nullptr;
        while(start && head2){
            t1=start->next;
            t2=head2->next;
            start->next=head2;
            head2->next=t1;
            start=t1;
            head2=t2;
        }
        

    }
};