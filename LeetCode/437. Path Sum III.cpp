/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> sums;
    int count = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        sums.resize(maxDepth(root) + 1, 0);
        travel(root, 1, sum);
        return count;
    }

    int maxDepth(TreeNode* t){  // 获取树的深度，用以确定sums数组的大小
        if (t == NULL) return 0;
        return max(maxDepth(t->left), maxDepth(t->right)) + 1;
    }

    void travel(TreeNode* node, int level, int sum){
        if (node == NULL) return ;
        sums[level] = sums[level-1] + node->val;
        for (int i = 0; i < level; i++) if (sums[level] - sums[i] == sum) count++;
        travel(node->left, level+1, sum);
        travel(node->right, level+1, sum);
    }
};