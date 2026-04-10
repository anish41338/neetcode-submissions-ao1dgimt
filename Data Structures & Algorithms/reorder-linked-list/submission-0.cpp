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
    void reorderList(ListNode* head) {
        if(!head || !head->next)return ;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *cur=slow->next;
        slow->next=NULL;
        ListNode* prev= NULL;
        while(cur){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        ListNode* first=head;
        cur=prev;
        while(cur){
            ListNode* t1=first->next;
            ListNode* t2=cur->next;
            first->next=cur;
            cur->next=t1;
            first=t1;
            cur=t2;
        }
        
    }
};
