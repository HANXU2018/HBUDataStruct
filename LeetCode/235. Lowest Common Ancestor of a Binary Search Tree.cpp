class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q
        ||(root!=NULL&&root->val>p->val&&root->val<q->val)
        ||(root!=NULL&&root->val<p->val&&root->val>q->val)){
            return root;
        }
        if(p->val<root->val&&q->val<root->val&&root!=NULL){
          return lowestCommonAncestor(root->left,p,q);
        }
        if(p->val>root->val&&q->val>root->val&&root!=NULL){
          return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};

作者：qing-ruo-xia-hua
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/di-gui-chu-li-by-qing-ruo-xia-hua/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。