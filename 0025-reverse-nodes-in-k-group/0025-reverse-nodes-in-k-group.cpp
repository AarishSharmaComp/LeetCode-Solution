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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1)
            return head;

        // Dummy node to handle edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // Check if there's a complete group of size k
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; ++i)
                kth = kth->next;
            if (!kth)
                break; // Not enough nodes for a complete group

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            // Reverse the group
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Connect the reversed group
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};