/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// skip node
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while (p) {
            ListNode *q = p->next;
            while (q && p->val == q->val) {
                ListNode *tmp = q;
                q = q->next;
                delete[] tmp;
            }
            p->next = q;
            p = p->next;
        }
        return head;
    }
};

// hashmap
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> hash;
        ListNode *p = head;
        ListNode *dummy = new ListNode(0), *q = dummy;
        while (p) {
            if (hash.count(p->val) == 0) {
                hash.emplace(p->val);
                ListNode *n = new ListNode(p->val);
                q->next = n;
                q = q->next;
            }
            p = p->next;
        }
        return dummy->next;
    }
};