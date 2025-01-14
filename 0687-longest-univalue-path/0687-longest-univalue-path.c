/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    return a>b?a:b;
}
int traval(struct TreeNode *root,int *res){
    if(!root) return 0;
    int left_len=traval(root->left,res);
    int right_len=traval(root->right,res);
    int left=0,right=0;
    if(root->left!=NULL && root->val==root->left->val){
        left=left_len+1;
    }
    if(root->right!=NULL && root->val==root->right->val){
        right=right_len+1;
    }
    *res=max(*res,right+left);
    return max(right,left);
}

int longestUnivaluePath(struct TreeNode* root){
    int res=0;
    traval(root,&res);
    return res;
}
