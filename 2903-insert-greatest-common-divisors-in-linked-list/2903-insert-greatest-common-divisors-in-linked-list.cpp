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
int gcd(int a, int b) 
{
    int result = min(a, b); 
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    }
    return result; 
} 
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* mover1=head;
        ListNode* mover2=head->next;
        while(mover2){
            int a=gcd(mover1->val,mover2->val);
            ListNode* arr=new ListNode(a);
            mover1->next=arr;
            arr->next=mover2;
            mover1=mover2;
            mover2=mover2->next;
        }
        return head;
        
    }
};