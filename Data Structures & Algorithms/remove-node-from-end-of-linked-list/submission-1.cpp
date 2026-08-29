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
        //brute force 
        if(!head->next && n == 1) return NULL;
        ListNode* head1=head;
        int count=0;
        ListNode* curr=head1;
        while(curr){
            count++;
            curr=curr->next;
        }
        if(n > count){
            return head1;
        }
        else if(n==count){
            return head->next;
        }
        else{
            int step=count-n-1;
            curr=head1;
            while(step--){
                curr=curr->next;
            }
            curr->next=curr->next->next;
            return head1;
        }
        
    }
};


