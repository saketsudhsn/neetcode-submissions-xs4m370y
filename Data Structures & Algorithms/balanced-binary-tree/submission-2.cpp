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

    bool isTreeBalanced;

    int calcHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int leftHeight = calcHeight(root->left);
        int rightHeight = calcHeight(root->right);

        if(abs(rightHeight - leftHeight) > 1)
        {
            isTreeBalanced = false;
        }

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) 
    {
        isTreeBalanced = true;
        calcHeight(root);
        return isTreeBalanced;
    }
};
