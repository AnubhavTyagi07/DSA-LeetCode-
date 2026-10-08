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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        // Find the node just before index a
        ListNode* beforeA = list1;

        for (int i = 0; i < a - 1; i++) {
            beforeA = beforeA->next;
        }

        // Find the node at index b
        ListNode* atB = list1;

        for (int i = 0; i < b; i++) {
            atB = atB->next;
        }

        // Connect beforeA to the beginning of list2
        beforeA->next = list2;

        // Find the last node of list2
        ListNode* last2 = list2;

        while (last2->next != nullptr) {
            last2 = last2->next;
        }

        // Connect last node of list2 to node after b
        last2->next = atB->next;

        return list1;
    }
};