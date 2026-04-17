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
    int helper(int a, int b) {
        while(b) {
            int tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next==nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        while (dummy->next && dummy->next->next) {
            dummy = dummy->next;
            int a = dummy->val;
            int b = dummy->next->val;
            int ret = helper(a,b);
            ListNode* end = dummy->next;
            ListNode* mid = new ListNode(ret);
            dummy->next = mid;
            mid->next = end;
            dummy = dummy->next;
        }
        return head;
    }
};