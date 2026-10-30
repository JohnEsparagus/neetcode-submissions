/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* curr_new = dummy;

        Node* curr_old = head;

        unordered_map<Node*,Node*> mp;

        mp[nullptr] = nullptr;
    

        while (curr_old != nullptr){
            Node* new_n = new Node(curr_old->val);
            curr_new->next = new_n;
            mp[curr_old] = new_n;

            curr_new = curr_new->next;
            curr_old = curr_old->next;
        }

        curr_old = head;
        Node* curr = dummy->next;
        while (curr_old != nullptr && curr!= nullptr){

            if (curr_old->random != nullptr) {
                curr->random = mp[curr_old->random];
            } else {
                curr->random = nullptr;
            }
            curr_old = curr_old->next;
            curr = curr->next;
        }
        //now the random
        //can we use a hashmap???
        //what do we need to recreate random...
        // store in 2 hashmaps? s.t they are the same and we can instantly assign the pointer of random
        //so 1st would contain node and where random points e.g which index?


        return dummy->next;


        
    }
};
