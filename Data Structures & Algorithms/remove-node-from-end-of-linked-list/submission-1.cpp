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
        int k=0;
        ListNode* temp=head;
        while(temp){
            k++;
            temp=temp->next;
        }
        k=k-n+1;
        if(k==1)return head->next;
        ListNode* prev=nullptr;
        temp=head;
        int i=0;
        while(temp && i<k-1){
            i++;
            prev=temp;
            temp=temp->next;
        }
        if(temp){
        prev->next=temp->next;
        temp->next=nullptr;}
        else{
            prev=nullptr;
        }
        return head;
    }
};
