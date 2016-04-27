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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *cur = dummy->next, *prev = dummy;
        while (cur) {
            if (cur->next && cur->next->val < cur->val) {
                prev = dummy;
                while (prev->next && prev->next->val < cur->next->val) 
                    prev = prev->next;
                ListNode *tmp = prev->next;
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = tmp;
            }
            else cur = cur->next;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};