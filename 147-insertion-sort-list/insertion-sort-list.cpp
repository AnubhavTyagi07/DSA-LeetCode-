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
    ListNode* insertionSortList(ListNode* head) {
        
        // Dummy node for the sorted list
        ListNode dummy(0);
        
        ListNode* curr = head;

        while (curr != nullptr) {
            
            // Save the next node
            ListNode* next = curr->next;

            // Find where curr should be inserted
            ListNode* prev = &dummy;

            while (prev->next != nullptr &&
                   prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr into sorted part
            curr->next = prev->next;
            prev->next = curr;

            // Move to next unsorted node
            curr = next;
        }

        return dummy.next;
    }
};