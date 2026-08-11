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
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        while(second){
            ListNode* cur=second->next;
            second->next=prev;
            prev=second;
            second=cur;
        }
        second=prev;
        fast=head;
        while(second){
            ListNode* temp1=fast->next;
            ListNode* temp2=second->next;
            fast->next=second;
            second->next=temp1;
            fast=temp1;
            second=temp2;
        }
    }
};
