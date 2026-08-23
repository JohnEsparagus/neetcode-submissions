
struct Node{
    int val;
    int key;
    Node* left;
    Node* right;

    Node(int key, int val) : key(key), val(val), left(nullptr), right(nullptr) {}
};

class TreeMap {
private:
    Node* root;

    void inorder(Node* node, std::vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left, result);
        result.push_back(node->key);
        inorder(node->right, result);
    }
public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        Node* new_node = new Node(key, val);
        Node* curr = root;
        if (root == nullptr){
            root = new_node;
            return;
        }

        while (curr!=nullptr) {
            if (key > curr->key){
                if (curr->right == nullptr){
                    curr->right = new_node;
                    return;
                }
                curr = curr->right;
            }
            else if (key < curr->key){
                if (curr->left == nullptr){
                    curr->left = new_node;
                    return;
                }
                curr = curr->left;
            }
            else {
                curr->val = val;
                curr->key = key;
                delete new_node;
                return;
            }
        }
    }

    int get(int key) {
        Node* curr = root;

        while (curr!=nullptr) {
            if (key > curr->key){
                curr = curr->right;
            }
            else if (key < curr->key){
                curr = curr->left;
            }
            else {
                return curr->val;
            }
        }
        return -1;
    }

    int getMin() {
        if (root == nullptr){
            return -1;
        }
        Node* curr = root;
        while (curr && curr->left){
            curr = curr->left;
        }
        return curr->val;
    }

    int getMax() {
        if (root == nullptr){
            return -1;
        }
        Node* curr = root;
        while (curr && curr->right){
            curr = curr->right;
        }
        return curr->val;
    }

    void remove(int key) {
        Node* curr = root;
        Node* prev = nullptr;
        while (curr!=nullptr && curr->key != key) {
            prev = curr;
            if (key > curr->key){
                curr = curr->right;
            }
            else if (key < curr->key){
                curr = curr->left;
            }
        }
        if (curr == nullptr){
            return; //not found
        }

        // now  curr is at the to_delete point
        //prev is behind it..

        //case both exist
        if (curr->left !=nullptr && curr->right != nullptr){
            // now,  find right leftest
            Node* head_leftest = nullptr;
            Node* leftest = curr->right;
            
            while (leftest->left != nullptr){
                head_leftest = leftest;
                leftest = leftest->left;
            }

            curr->val = leftest->val;
            curr->key = leftest->key;

            if (head_leftest == nullptr){
                //erease curr->right
                curr->right = leftest->right;
            } else {             //if leftest has a right to be replaced
                head_leftest->left = leftest->right;
            }

            delete leftest;
            return;
        }

    //case  one or the other...

        //case 1 
        if (curr->left !=nullptr || curr->right != nullptr){
            Node* child = (curr->left != nullptr)
            ? curr->left
            : curr->right;

        if (prev == nullptr) {
            root = child;
        } else if (prev->left == curr) {
            prev->left = child;
        } else {
            prev->right = child;
        }

            delete curr;
            return;
        }

        else if (curr->left == nullptr && curr->right == nullptr){
            if (prev == nullptr) {
                delete curr;
                root = nullptr;
                return;
            }
            if (prev->left == curr) {
                prev->left = nullptr;
            } else {
                prev->right = nullptr;
            }

            delete curr;
            return;       
        }


    }

std::vector<int> getInorderKeys() {
    std::vector<int> result;
    inorder(root, result);
    return result;
}
};
