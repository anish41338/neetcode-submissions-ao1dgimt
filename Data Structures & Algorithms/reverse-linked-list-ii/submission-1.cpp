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
    ListNode* reverseBetween(ListNode* head, int left, int right) {     
        ListNode* dummy=new ListNode(0,head);
        ListNode* p=dummy;
        for(int i=1;i<left;i++)p=p->next;
        ListNode* a=p->next;
        ListNode* b=a->next;
        for(int i=0;i<abs(left-right);i++){
            a->next=b->next;
            b->next=p->next;
            p->next=b;
            b=a->next;
        }
        return dummy->next;
        
    }
};