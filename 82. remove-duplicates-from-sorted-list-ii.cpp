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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummyhead = new ListNode(101), *cur, *pre;
        ListNode *tmp;
        dummyhead->next = head;

        if (!head) return head;
        cur = head;
        pre = dummyhead;
        while(cur->next) {
            if (cur->next->val == cur->val) {
                tmp = cur->next;
                while(tmp && tmp->val == cur->val) tmp=tmp->next;
                cur = tmp;
                pre->next = cur;
                if (!cur) break;

            }
            else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return dummyhead->next;
    }
};
