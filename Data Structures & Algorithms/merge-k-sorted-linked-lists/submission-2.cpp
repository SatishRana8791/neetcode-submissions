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

    

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return {};
        if(lists.size() == 1) return lists[0]; 

        auto cmp=[](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);


        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }

        ListNode* head=new ListNode(0);
        ListNode* tail=head;

        while(!pq.empty()){
            ListNode * top=pq.top();
            pq.pop();
            tail->next=top;
            tail=tail->next;
            if(top->next){
                pq.push(top->next);
            } 
        }
        tail->next=nullptr;
        return head->next;
    }
};
