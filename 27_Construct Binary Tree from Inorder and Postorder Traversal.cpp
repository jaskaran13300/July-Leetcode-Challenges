//Note: (As given in the problem description)
//You may assume that duplicates do not exist in the tree.

//Since we need not worry about the presence of duplicates in the tree, we can simply create an inorder key-value index map to store all values inside Hash Map and easily access the index of any particular node in the inorder traversal of the tree.

// Explanation:
// Inorder Traversal -> First visit the left subtree, followed by the root node, followed by the right subtree.
// Left -> Root -> Right
// Point of observation: The root node divides the inorder array into 2 halves, left subtree and right subtree.
// Postorder Traversal -> First visit left subtree, followed by the right subtree, followed bt the root node.
// Left -> Right -> Root
// Point of observation: The root node is available at the end the of the postorder array.

// So, as the first step, we can eaily obtain the value of the root node for the tree (or subtree) from the postorder array by accessessing the last element of the postorder array. Then, it can be observed that the root node divides the inorder array into two halves, the left and right subtree. So, for constructing the tree using postorder and inorder, we will find the find the index of root node in inorder array and then make recursive calls on the left and right subtrees.

class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* buildTreeUtil(vector<int>& post, int& idx, const int& si, const int& ei) {
        if (si>ei) return NULL;
        TreeNode* root = new TreeNode(post[idx]);
        int mid = mp[post[idx]];
        idx--;
        root->right = buildTreeUtil(post, idx, mid+1, ei);
        root->left = buildTreeUtil(post, idx, si, mid-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0; i<in.size(); i++) mp[in[i]]=i;
        int idx=post.size()-1;
        return buildTreeUtil(post, idx, 0, in.size()-1);
    }
};
