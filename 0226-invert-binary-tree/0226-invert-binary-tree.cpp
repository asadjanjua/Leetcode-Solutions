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
      TreeNode* invertTree(TreeNode* root){
    //     if(root==NULL)
    //     return NULL;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty())
    //     {
    //         int size=q.size();
           
    //         for (int i=0;i<size;i++)
    //         {
    //             TreeNode* node=q.front();
    //             q.pop();
    //             swap(node->left,node->right);
    //             if(node->left)
    //             q.push(node->left);
    //             if(node->right)
    //             q.push(node->right);
    //         }
    //     }
    //     return root;

    if(root==NULL)
    return NULL;
    // swap(root->left,root->right);

    TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;

    }    
      
};