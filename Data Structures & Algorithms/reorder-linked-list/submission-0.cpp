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
        //edge cases
        if(!head || !head->next) return;
        ListNode* head1=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* curr2=slow->next;
        slow->next=NULL;
        ListNode* prev=nullptr;
        while(curr2){
            ListNode* fut=curr2->next;
            curr2->next=prev;
            prev=curr2;
            curr2=fut;
        }
        ListNode* head2=prev;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(head1 && head2 ){
            temp->next=head1;
            temp=temp->next;
            head1=head1->next;
            temp->next=NULL;
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
            temp->next=NULL;
        }
        while(head1){
            temp->next=head1;
            temp=temp->next;
            head1=head1->next;
        }
        while(head2){
            temp->next=head2;
            temp=temp->next;
            head2=head2->next;
        }
        head=dummy->next;
    }
};
