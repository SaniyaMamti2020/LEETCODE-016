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
        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            temp = temp->next;
            count++;
        }
        int pfl = count - n + 1;
        temp = head;

        for(int i = 1; i < pfl - 1; i++) {
            temp = temp->next;
        }

        if(count == n){
            return head->next;
        } else {
            temp->next = temp->next->next;
        }
        return head;
    }
};