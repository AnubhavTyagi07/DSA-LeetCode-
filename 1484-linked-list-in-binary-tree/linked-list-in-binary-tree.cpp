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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // Check whether the linked list matches
    // a downward path starting from this tree node
    bool checkPath(ListNode* head, TreeNode* root) {

        // Linked list completely matched
        if (head == nullptr)
            return true;

        // Tree ended before linked list
        if (root == nullptr)
            return false;

        // Values don't match
        if (head->val != root->val)
            return false;

        // Continue down either left or right
        return checkPath(head->next, root->left) ||
               checkPath(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {

        // Empty tree
        if (root == nullptr)
            return false;

        // Try starting the linked list from this tree node
        if (checkPath(head, root))
            return true;

        // Try every other tree node
        return isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};