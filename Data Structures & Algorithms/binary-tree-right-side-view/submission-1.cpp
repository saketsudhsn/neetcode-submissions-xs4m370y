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
    vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> res;
        if(!root)
            return res;
            
        std::queue<TreeNode*> treeNodesQueue;
        treeNodesQueue.push(root);

        while(!treeNodesQueue.empty())
        {
            
            TreeNode* node = treeNodesQueue.back();
            res.push_back(node->val);

            int i = 0;
            size_t currQueueSize = treeNodesQueue.size();
            while(i < currQueueSize)
            {
                node = treeNodesQueue.front();

                if(node->left)
                    treeNodesQueue.push(node->left);
                if(node->right)
                    treeNodesQueue.push(node->right);

                treeNodesQueue.pop();
                i++;
            }                        
        }

        return res; 
    }
};
