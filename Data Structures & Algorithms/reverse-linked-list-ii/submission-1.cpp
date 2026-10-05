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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //lets take the list out, seperate it and put it back together after
        ListNode dummy(0);
        dummy.next = head;        
        ListNode* left_p = &dummy;
        ListNode* left_n = head;


        for (int i = 1; i < left; i++){
            left_p = left_n;
            left_n = left_n->next;
        }

        ListNode* right_p = left_n;

        for (int i = 0; i < right - left; i++){
            right_p = right_p->next;
        }
        ListNode* right_c = right_p->next;
        right_p->next = nullptr;

        // now subarr
        ListNode* new_head = reverseList(left_n);

        left_p->next = new_head;
        left_n->next = right_c;


        return dummy.next;

    }


private:    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr){
            ListNode* temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        return prev;
    }
};