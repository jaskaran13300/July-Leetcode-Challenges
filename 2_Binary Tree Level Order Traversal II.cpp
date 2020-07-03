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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        vector<int>v;
        // v.push_back(root->val);
        // ans.push_back(v);
        // v.clear();
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current==NULL && q.size()>0){
                q.push(NULL);
                ans.push_back(v);
                v.clear();
            }
            else if(current!=NULL){
                v.push_back(current->val);
            }
            if(current && current->left){
                q.push(current->left);
            }
            if(current && current->right){
                q.push(current->right);
            }
        }
        if(v.size()){
            ans.push_back(v);        
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
