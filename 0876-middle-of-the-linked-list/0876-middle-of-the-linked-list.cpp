class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            temp = temp->next;
            count++;
        }

        temp = head;
        int mid = (count / 2) + 1;

        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        return temp;
    }
};