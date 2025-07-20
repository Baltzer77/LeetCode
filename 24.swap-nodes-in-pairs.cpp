/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
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
    ListNode* swapPairs(ListNode* head) {        
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur != NULL && cur->next != NULL) {
            ListNode* next = cur->next;
            if(prev != NULL) prev->next = next;
            else head = next;

            cur->next = next->next;
            next->next = cur;

            prev = cur;
            cur = cur->next;
        }

        return head;
    }

};
// @lc code=end

