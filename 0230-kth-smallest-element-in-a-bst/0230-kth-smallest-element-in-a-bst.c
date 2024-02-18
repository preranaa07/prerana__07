/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void inOrderTraversal(struct TreeNode* root, int *k, int *result) {
         if (root == NULL || *k == 0) {
                 return;
                     }

                         inOrderTraversal(root->left, k, result);

                             (*k)--;
                                 if (*k == 0) {
                                         *result = root->val;
                                                 return;
                                                     }

                                                         inOrderTraversal(root->right, k, result);
                                                         }
 
int kthSmallest(struct TreeNode* root, int k) {
    int result = 0;
        inOrderTraversal(root, &k, &result);
            return result;
}