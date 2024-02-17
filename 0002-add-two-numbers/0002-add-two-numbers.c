/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getValueAndMoveNext(struct ListNode **l) {
    int x = 0;
    if (*l != NULL) {
        x = (*l)->val;
        *l = (*l)->next;
    }
    return x;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int x = 0, y = 0, carry = 0, sum = 0;
    struct ListNode *h = NULL, **t = &h;
    
    while (l1 != NULL || l2 != NULL) {
        x = getValueAndMoveNext(&l1);
        y = getValueAndMoveNext(&l2);
        
        sum = carry + x + y;
        
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        
        *t = node;
        t = &((*t)->next);
        
        carry = sum / 10;
    }
    
    if (carry > 0) {
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = carry % 10;
        node->next = NULL;
        *t = node;
    }
    
    return h;
}
