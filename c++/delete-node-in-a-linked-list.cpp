/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        int val = node->val;
        node->val = node->next->val;
        node->next->val = val;
        ListNode *t = node->next;
        node->next = node->next->next;
        delete[] t;
    }
    
};