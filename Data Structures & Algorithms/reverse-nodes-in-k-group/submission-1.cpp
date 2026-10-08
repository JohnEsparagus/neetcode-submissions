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
        ListNode dummy(0);
        dummy.next = head;

        ListNode* group_prev = &dummy;
        while (true){
            ListNode* kth = group_prev;
            for (int i = 0; i < k && kth; i++) kth = kth->next;
            if (!kth){
                break;
            }

            ListNode* groupNext = kth->next;
            ListNode* oldFirst = group_prev->next; 


            ListNode* newHead = helper(oldFirst, k);

            group_prev->next = newHead;
            oldFirst->next = groupNext;
            group_prev = oldFirst;

        }
        //perhaps there is a seperation in the list.

        return dummy.next;
    }

    ListNode* helper(ListNode* curr, int k){
        ListNode* prev = nullptr;
        ListNode* node = curr;
        for (int i = 0; i < k && node; i++) {
            ListNode* nxt = node->next;
            node->next = prev;
            prev = node;
            node = nxt;
        }
        return prev;
    }
};
