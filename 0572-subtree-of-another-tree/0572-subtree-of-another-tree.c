/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool equals(struct TreeNode* s, struct TreeNode* t)
{
    if (s==NULL && t==NULL)
        return true;
    else if (s==NULL || t== NULL)
        return false;

    return (s->val == t->val) && equals(s->right,t->right) && equals(s->left,t->left);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if (s==NULL && t==NULL)
        return true;
    
    return s!= NULL && (equals(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t));
}
    
