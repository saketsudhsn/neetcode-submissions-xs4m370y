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

    std::vector<int> kElemsVec;
    void getKthSmallest(TreeNode* root)
    {
        if(!root)
            return;
        
        getKthSmallest(root->left);
        kElemsVec.emplace_back(root->val);
        if(kElemsVec.size() == kElemsVec.capacity())
            return;
        
        getKthSmallest(root->right);

        return;
    }


    int kthSmallest(TreeNode* root, int k) 
    {
        kElemsVec.reserve(k);
        getKthSmallest(root);
        for(auto elem : kElemsVec)
        {
            std::cout << elem << "\n";
        }

        return kElemsVec[k-1];        
    }
};
