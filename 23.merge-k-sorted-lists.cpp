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
private:
    class Compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        priority_queue<ListNode*, vector<ListNode*>, Compare> heap;
        
        for(const auto& node : lists) {
            if(node != NULL)
                heap.push(node);
        }

        if(heap.size() == 0) return NULL;

        ListNode* head = heap.top(); heap.pop();
        ListNode* cur = head;
        if(head->next != NULL) heap.push(head->next);

        while(heap.size() > 0) {
            ListNode* top = heap.top(); heap.pop();
            cur->next = top;
            cur = top;

            if(top->next != NULL) {
                heap.push(top->next);
            }
        }

        return head;
    }
};