// iterative
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode *p = head, *prev = NULL;
        while (p) {
            ListNode *t = p->next;
            p->next = prev;
            prev = p;
            p = t;
        }
        return prev;
    }
};


// recursion
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *reversed = reverseList(head->next);
        head->next = NULL;
        ListNode *cur = reversed;
        while (cur->next) cur = cur->next;
        cur->next = head;
        return reversed;
    }
};