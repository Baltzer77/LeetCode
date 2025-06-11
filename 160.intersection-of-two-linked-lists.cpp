/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> seen;

        ListNode* cur = headA;
        while(cur != NULL) {
            seen.insert(cur);
            cur = cur->next;
        }

        cur = headB;

        while(cur != NULL) {
            if(seen.contains(cur)) {
                return cur;
            }
            cur = cur->next;
        }
        
        return NULL;
    }
};
// @lc code=end

