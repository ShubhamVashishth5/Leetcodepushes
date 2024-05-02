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
        if(head->next==NULL)return NULL;
        ListNode *ite= head;
        ListNode *it2= head;
        while(it2!=NULL && n>0){
            n--;
            it2=it2->next;
        }
        if(it2==NULL)return head->next;
        while(it2!=NULL && it2->next!=NULL){
            ite=ite->next;
            it2=it2->next;
        }
        if(ite->next!=NULL)ite->next=ite->next->next;
        return head;
    }
};