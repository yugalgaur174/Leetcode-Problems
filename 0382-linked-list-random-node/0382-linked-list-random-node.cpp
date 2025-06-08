#include <random>

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
    ListNode* n = nullptr;
    int num = 0;

    Solution(ListNode* head) {
        n = head;
        ListNode* t = head;
        while (t) {
            num++;
            t = t->next;
        }
    }

    int getRandom() {
        std::random_device r;
        std::mt19937 g(r());
        std::uniform_int_distribution<> d(0, num - 1);
        int nn = d(g);
        ListNode* t = n;
        int a = 0;
        while (a < nn) {
            t = t->next;
            a++;
        }
        return t->val;
    }
};
