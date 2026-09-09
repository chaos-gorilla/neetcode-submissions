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
        if (lists.empty()) {
            return nullptr;
        }

        auto node_comparator = [](const ListNode* a, const ListNode* b) {
            return a -> val >= b -> val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(node_comparator)> pq;

        for (auto linked_list : lists) {
            if (linked_list) {
                pq.push(linked_list);
            }
        }

        // now we have the first nodes of all the lists.
        ListNode* result = new ListNode();
        ListNode* ptr = result;
        while (!pq.empty()) {
            auto top_element = pq.top();
            pq.pop();
            ptr -> next = top_element;
            ptr = ptr -> next;
            if (top_element -> next) {
                pq.push(top_element -> next);
            }
        }

        return result -> next;
    }
};
