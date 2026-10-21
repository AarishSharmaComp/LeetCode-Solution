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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if (left != nullptr) {
            tail->next = left;
        } else {
            tail->next = right;
        }

        return dummy.next;
    }
};