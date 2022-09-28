/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *d = new ListNode();
        d->next = head;
        auto p = d;
        auto q = d;
        
        for(int _=0;_<n;_++)
            q = q->next;
        while(q->next){
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return d->next;
    }
};