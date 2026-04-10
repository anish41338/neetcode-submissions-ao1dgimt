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
        int size=0;
        if(!head)return nullptr;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=head;
      
        while(temp){
            size++;
            temp=temp->next;
        }
        int target=size-n;
        temp=dummy;
        while(target--){
            temp=temp->next;
        }
        ListNode* del=temp->next;
        temp->next=temp->next->next;
        delete del;
        return dummy->next;
        
    }
};
