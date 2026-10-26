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
        ListNode* p = nullptr;
        ListNode* c = nullptr;
        ListNode* n = head;

        while(n!=nullptr) {
            c = n;
            n = n->next;
            c->next = p;
            p = c;
        }

        return c;
    }
};