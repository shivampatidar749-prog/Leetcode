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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // If there is only one node to reverse
        if (left == right)
            return head;

        // Dummy node before head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // prev will reach the node just before 'left'
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr is the first node that needs to be reversed
        ListNode* curr = prev->next;

        // Reverse the nodes from left to right
        for (int i = 0; i < right - left; i++) {

            ListNode* temp = curr->next;

            curr->next = temp->next;

            temp->next = prev->next;

            prev->next = temp;
        }

        return dummy->next;
    }
};