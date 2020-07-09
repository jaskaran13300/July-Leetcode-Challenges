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
typedef unsigned long long int ll;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode *,ll>> q;
        q.push({root,0});
        ll maxWidth=0;
        while(!q.empty()){
            ll size=q.size();
            pair<TreeNode *,ll> first=q.front();
            pair<TreeNode *,ll> cur={NULL,0};
            while((size--) > 0){
                cur=q.front();
                q.pop();
                if((cur.first)->left){
                    q.push({(cur.first)->left,(cur.second)*2});
                }
                if((cur.first)->right){
                    q.push({(cur.first)->right,((cur.second)*2)+1});
                }
            }
            maxWidth=max(maxWidth,(cur.second) - (first.second)+1);
            
        }
        return maxWidth;
    }
};
