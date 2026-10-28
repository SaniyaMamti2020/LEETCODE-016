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
        vector<int> vt;
        ListNode* temp=head;

        while(temp!=nullptr) {
            vt.push_back(temp->val);
            temp=temp->next;
        }

        int l=0;
        int r = vt.size()-1;
        while(l<r) {
            if(vt[l]!=vt[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};