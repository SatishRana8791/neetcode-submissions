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
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;

        while(head1 && head2){
            if(head1->val <= head2->val){
                tail->next=head1;
                tail=tail->next;
                head1=head1->next;
            }
            else{
                tail->next=head2;
                tail=tail->next;
                head2=head2->next;
            }
        }
        if(head1) tail->next=head1;
        if(head2) tail->next=head2;

        tail=dummy;
        tail=tail->next;
        delete dummy ;
        return tail;
    }

    ListNode* mergesort(vector<ListNode*>& lists, int left, int right ){
        if(left == right){
            return lists[left];
        }
        int mid=left+(right-left)/2;
        
        ListNode* leftPart= mergesort(lists,left,mid);
        ListNode* rightPart= mergesort(lists,mid+1,right);

        return merge(leftPart,rightPart);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return {};
        if(lists.size() == 1) return lists[0]; 

        ListNode* head = mergesort(lists,0,lists.size()-1);
        return head;
    }
};
