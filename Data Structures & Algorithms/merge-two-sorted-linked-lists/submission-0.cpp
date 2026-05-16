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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy =new ListNode(0);
        ListNode* curr=dummy;
        ListNode* head1=list1;
        ListNode* head2=list2;
        while(head1 && head2){
            if(head1->val <= head2->val){
                curr->next=head1;
                head1=head1->next;
                curr=curr->next;
            }
            else{
                curr->next=head2;
                head2=head2->next;
                curr=curr->next;
            }
        }
        while(head1){
            curr->next=head1;
            head1=head1->next;
            curr=curr->next;
        }
        while(head2){
            curr->next=head2;
            head2=head2->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};
