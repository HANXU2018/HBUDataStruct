TreeNode* invertTree(TreeNode* root) {//先序优先遍历
        if(root==NULL) return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
   TreeNode* invertTree(TreeNode* root) {//后序优先遍历
         if(root==NULL) return root;
         invertTree(root->left);
         invertTree(root->right);
         TreeNode* temp = root->left;
         root->left = root->right;
         root->right = temp;
         return root;
    }
   TreeNode* invertTree(TreeNode* root) {//中序优先遍历
         if(root==NULL) return root;
         invertTree(root->left);
         TreeNode* temp = root->left;
         root->left = root->right;
         root->right = temp;
         invertTree(root->left);
         return root;
    }

作者：vailing
链接：https://leetcode-cn.com/problems/invert-binary-tree/solution/qian-zhong-hou-bian-li-by-vailing/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。