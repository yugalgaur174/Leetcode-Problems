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
     ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Min-heap (priority queue) of ListNode pointers
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // Custom comparator for ListNode based on value
        };
        
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> pq(compare);

        // Initialize the priority queue with the head of each non-empty list
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        // Create a dummy node to act as the starting point for the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Merge the lists
        while (!pq.empty()) {
            // Get the node with the smallest value
            ListNode* smallest = pq.top();
            pq.pop();

            // Add the smallest node to the merged list
            current->next = smallest;
            current = current->next;

            // If there are more nodes in the list of the extracted node, push the next node into the queue
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        // Return the merged list (skipping the dummy node)
        return dummy->next;
    }
};