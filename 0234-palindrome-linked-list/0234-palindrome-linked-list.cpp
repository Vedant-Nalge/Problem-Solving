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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* last = NULL;
        ListNode* curr = slow;
        while (curr != NULL) {
            ListNode* after = curr->next;
            curr->next = last;
            last = curr;
            curr = after;
        }
        ListNode* start1 = head;
        while (last != NULL) {
            if (start1->val != last->val)
                return false;
            start1 = start1->next;
            last = last->next;
        }
        return true;
    }
};