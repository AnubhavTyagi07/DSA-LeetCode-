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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        // If there is only one node to reverse
        if (head == nullptr || left == right)
            return head;

        // Dummy node
        ListNode dummy(0);
        dummy.next = head;

        // Move prev to the node just before 'left'
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Reverse the required part
        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;

            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};