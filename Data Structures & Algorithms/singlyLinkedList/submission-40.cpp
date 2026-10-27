struct Node{
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}

};

class LinkedList {
    Node* dummy;
    Node* tail;
public:
    LinkedList() {
        dummy =  new Node(-1);
        dummy->next = nullptr;
        tail = dummy;
    }

    int get(int index) {
        Node* curr = dummy->next;
        int i = 0;
        while (curr != nullptr && i < index){
            curr = curr->next;
            i++;
        }

        return (curr != nullptr) ? curr->val : -1;
    }

    void insertHead(int val) {
        Node* new_node = new Node(val);

        new_node->next = dummy->next;
        dummy->next = new_node;

        if (dummy == tail){
            tail = new_node;
        }
    }
    
    void insertTail(int val) {
        Node* new_node = new Node(val);

        tail->next = new_node;
        tail = new_node;

    }

    bool remove(int index) {
        Node* curr = dummy->next;
        Node* prev = dummy;

        int i = 0;
        while (curr != nullptr && i < index){
            prev = curr;
            curr = curr->next;
            i++;
        }

        if (curr == nullptr) {
            return false;
        }

        prev->next = curr->next;

        if (curr == tail){
            tail = prev;
        }
        delete curr;
        return true;
    }

    vector<int> getValues() {
        Node* curr = dummy;

        vector<int> values;
        while (curr!=nullptr && curr->next!=nullptr){
            curr = curr->next;
            values.push_back(curr->val);

        }

        return values;
    }
};