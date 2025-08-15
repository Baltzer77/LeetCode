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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        int i = 0;
        ListNode* current = head;
        ListNode* prev = NULL;

        while(i < k && current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;

            i++;
        } 
        
        if(i == k) {
            ListNode* rest = reverseKGroup(current, k);
            head->next = rest;
        }
        else {
            // we need to reverse the last part again
            current = prev;
            prev = NULL;
            while(current != NULL) {
                ListNode* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            } 
        }

        return prev; 
    }
};