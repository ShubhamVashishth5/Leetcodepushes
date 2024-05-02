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
        ListNode* mid = findMid(head);
        ListNode* second = reverseList(mid->next);
        mid->next=NULL;
        printList(head);
        printList(second);
        ListNode *start=head;
        ListNode *tail=head;
        head=head->next;
        while(second!=NULL && head!=NULL){
            tail->next = second;
            tail=tail->next;
            second=second->next;
            tail->next=head;
            tail=tail->next;
            head=head->next;
        }
        if(second!=NULL) tail->next=second;
        
        printList(start);
    }

    ListNode* findMid(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *tortoise = head;
    ListNode *hare = head->next;
    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    return tortoise;
}

     ListNode* reverseList(ListNode* head) {
        if(head==NULL|| head->next==NULL)return head;
        ListNode* head2=head->next;
        if(head->next->next!=NULL){
        head2 = reverseList(head->next);
        }
        head->next->next = head;
        head->next=NULL;
        return head2;
    }

    void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl; // Print a newline character at the end of the list printing
}

};