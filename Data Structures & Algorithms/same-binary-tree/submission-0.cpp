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

    bool areTreesSame;
    void TraverseTrees(TreeNode* p, TreeNode* q)
    {
        if(!areTreesSame)
            return;
        
        if(p == nullptr && q == nullptr)
            return;
        
        if((p == nullptr && q != nullptr) 
            || (p != nullptr && q == nullptr)
            || (p->val != q->val))
        {
            areTreesSame = false;
            return;
        }
        
        TraverseTrees(p->left, q->left);
        TraverseTrees(p->right, q->right);
        return;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        areTreesSame = true;
        TraverseTrees(p, q);
        return areTreesSame;    
    }
};
