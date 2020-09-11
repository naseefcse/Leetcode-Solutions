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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* head = l;
        
        int v1 = 0, v2 = 0, c = 0, d = 0;
        
        while(l1 || l2 || c) {
            v1 = (l1) ? l1->val : 0;
            v2 = (l2) ? l2->val : 0;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            
            d = (v1 + v2 + c) % 10;
            c = (v1 + v2 + c) / 10;
            head->next = (new ListNode(d));
            head = head->next;
        }
        
        return l->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return merge(l1, l2);
    }
};
