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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;

        ListNode* ctr = head;
        while (ctr != nullptr) {
            st.push(ctr);
            ctr = ctr -> next;
        }

        ListNode* answer = new ListNode();
        ListNode* current = answer;
        while (!st.empty()) {
            ListNode* top_element = st.top();
            top_element -> next = nullptr;
            current -> next = top_element;
            st.pop();
            current = current -> next;
        }

        return answer -> next;
    }
};
