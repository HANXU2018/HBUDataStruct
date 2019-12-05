class Solution {
public:
    bool judje(TreeNode* lf,TreeNode*ri){
        return (lf==NULL&&ri==NULL)||(lf->val==ri->lf&&judje(lf->left,ri->right)&&judje(lf->right,ri->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root){
            return judje(root->left,root->right);
        }return false;
    }
};