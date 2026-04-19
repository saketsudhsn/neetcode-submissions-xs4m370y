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

    int res;

    void countGoodNodes(TreeNode* root, int prevGreatestVal)
    {
        if(!root)
        {
            return;
        }
        
        if(root->val >= prevGreatestVal)
        {
            res++;
            std::printf("root->val = %d, old greatest value = %d, res = %d\n", root->val, prevGreatestVal, res);
            prevGreatestVal = root->val;
        }

        countGoodNodes(root->left, prevGreatestVal);
        countGoodNodes(root->right, prevGreatestVal);
    }

    int goodNodes(TreeNode* root) 
    {
        if(!root)
            return 0;
        
        res = 0;
        countGoodNodes(root, -101);
        return res;     
    }
};
