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
    ListNode* reverseList(ListNode* head) {
    // Base case: if the list is empty or has only one element, it's already reversed
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive call: reverse the rest of the list
    ListNode* newHead = reverseList(head->next);

    // Connect the current node's next node's next to the current node
    // This effectively places the current node at the end of the reversed portion
    head->next->next = head;

    // Since the current node is now the last node, its next should point to nullptr
    head->next = nullptr;

    // Return the new head of the reversed list
    return newHead;
}
};