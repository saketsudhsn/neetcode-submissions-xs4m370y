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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.size() == 0 && inorder.size() == 0)
            return nullptr;
        
        int val = preorder.front();
        
        int inorderIndex = -1;
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == val)
            {
                inorderIndex = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(val);

        std::vector<int> leftPreOrderArray(preorder.begin()+1, preorder.end());
        std::vector<int> leftInOrderArray(inorder.begin(), inorder.begin()+inorderIndex);
        if(leftPreOrderArray.size() && leftInOrderArray.size())
            root->left = build(leftPreOrderArray, leftInOrderArray);

        int leftSize = inorderIndex;
        std::vector<int> rightPreOrderArray(preorder.begin()+1+leftSize, preorder.end());
        std::vector<int> rightInOrderArray(inorder.begin()+inorderIndex+1, inorder.end());
        if(rightPreOrderArray.size() && rightInOrderArray.size())
            root->right = build(rightPreOrderArray, rightInOrderArray);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return build(preorder, inorder);
    }
};
