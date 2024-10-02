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
    // Function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        // Step 1: Reverse the list
        ListNode* revHead = reverseList(head);
        
        // Step 2: Traverse the reversed list and keep track of the maximum value
        ListNode* curr = revHead;
        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;
        int maxValue = INT_MIN;

        while (curr) {
            if (curr->val >= maxValue) {
                // This node has a value >= maxValue, so we keep it
                maxValue = curr->val;
                if (!newHead) {
                    newHead = curr; // Initialize new head
                    newTail = curr; // Initialize new tail
                } else {
                    newTail->next = curr;
                    newTail = newTail->next;
                }
            }
            curr = curr->next;
        }

        // Terminate the new list
        if (newTail) {
            newTail->next = nullptr;
        }

        // Step 3: Reverse the list back to the original order
        return reverseList(newHead);
    }
};