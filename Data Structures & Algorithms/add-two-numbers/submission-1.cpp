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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        ListNode* head1=l1;
        ListNode* head2=l2;
        while(head1 && head2){
            sum=head1->val + head2->val + carry;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            carry=sum/10;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1){
            sum=head1->val + carry;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            carry=sum/10;
            head1=head1->next;
        }
        while(head2){
            sum=head2->val + carry;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            carry=sum/10;
            head2=head2->next;
        }
        if(carry){
            temp->next=new ListNode(carry);
        }
        return dummy->next;
    }
};
