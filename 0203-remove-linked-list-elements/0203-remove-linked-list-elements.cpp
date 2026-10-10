class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        int count = 0;
        ListNode* temp = head;

        // Step 1: Count the nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: Traverse the list
        temp = head;
        ListNode* prev = NULL;

        while (count > 0 && temp != NULL) {

            if (temp->val == val) {

                if (prev == NULL) {
                    // Remove the head node
                    head = temp->next;
                    temp = head;
                }
                else {
                    // Remove the current node
                    prev->next = temp->next;
                    temp = temp->next;
                }

            }
            else {
                // Keep the current node
                prev = temp;
                temp = temp->next;
            }

            count--;
        }

        return head;
    }
};