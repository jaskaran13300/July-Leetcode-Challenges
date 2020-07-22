class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return {};
        queue<TreeNode*>Q;
        Q.push(root);
        bool f = true;
        while(!Q.empty()){
            Q.push(nullptr);
            vector<int>vec;
            while(Q.front()){
                TreeNode* temp = Q.front();
                Q.pop();
                vec.push_back(temp->val);
                if(temp->left)Q.push(temp->left);
                if(temp->right)Q.push(temp->right);
            }
            f =!f;
            Q.pop();
            if(f)reverse(begin(vec),end(vec));
            ans.push_back(vec);
            if(Q.empty())break;
        }
        return ans;
    }
};
