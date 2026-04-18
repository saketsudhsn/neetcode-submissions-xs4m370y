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

    int maxDiameter{};

    int calcTreeWidth(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int numOfLeftEdges = calcTreeWidth(root->left);
        int numOfRightEdges = calcTreeWidth(root->right);
        maxDiameter = max(maxDiameter, numOfLeftEdges + numOfRightEdges);
        return max(numOfLeftEdges, numOfRightEdges) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        maxDiameter = 0;
        calcTreeWidth(root);
        return maxDiameter;
    }
};
