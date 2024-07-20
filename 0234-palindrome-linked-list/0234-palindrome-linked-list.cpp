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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* mover=head;
        while(mover){
            st.push(mover->val);
            mover=mover->next;
        }
        mover=head;
        while(mover){
            if(st.top()==mover->val){
                mover=mover->next;
                st.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};