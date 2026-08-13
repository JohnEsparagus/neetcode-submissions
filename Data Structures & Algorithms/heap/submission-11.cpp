class MinHeap {
    void bubbleUp(int i){
        
        int parent = (i - 1) / 2 ;
        while (i > 0 && heap[i] < heap[parent]){
            swap(heap[i],heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
        
    }

    void bubbleDown(int i){
        int parent = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest  = parent; 

        while ( min(left,right) < heap.size() ){
            if (left < heap.size() && heap[smallest] > heap[left]){
                smallest = left;
            }

            if (right < heap.size() && heap[smallest] > heap[right]){
                smallest = right;
            }

            if (smallest != parent){
                swap(heap[smallest],heap[parent]);
                parent = smallest;
                left = 2*parent + 1;
                right = 2*parent + 2;
                smallest = parent;
            } else {break;}

        }
    }
    //a priority queue word have a vector?
    vector<int> heap{};

public:
    MinHeap() {
    }

    void push(int val) {
        //add val to the heap, 
        // insert at end of list and bubble up...
        heap.push_back(val);
        bubbleUp(heap.size() - 1);

    }

    int pop() {
        //push back and then swap 1st and last
        if (heap.empty()){
            return -1;
        }
        swap(heap[0], heap[heap.size() - 1]);
        //remove last node now
        int ans = heap[heap.size()-1];
        heap.pop_back();
        bubbleDown(0);

        return ans;

    }

    int top() {
        if (heap.empty()){
            return -1;
        }
        return heap[0];
    }

    void heapify(const vector<int>& arr) {
        if (arr.empty()){
            return ;
        }
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--){
            bubbleDown(i);
        }
        
    }
};
