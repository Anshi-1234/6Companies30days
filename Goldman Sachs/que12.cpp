class Solution {
public:
void preorder(TreeNode *root,vector<int>&res)
{
    if(root==NULL)
    return;
    res.push_back(root->val);
    preorder(root->left,res);
    preorder(root->right,res);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;
        if(root1)
        preorder(root1,res);
        if(root2)
        preorder(root2,res);
        sort(res.begin(),res.end());
        return res;
    }
};
