class DynamicArray {
private:
    int capacity;
    int size;
    int* arr;
    
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->size = 0;
        
    }

    ~DynamicArray(){
        delete[] this->arr;
        this->size = 0;
        this->capacity = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i]=n;
        
    }

    void pushback(int n) {
        if (size >= capacity){
            resize();
        }
        arr[size]=n;
        size++;
    }

    int popback() {
        int popped = arr[size-1];
        size--; //silent delete?
        return popped;
    }

    void resize() {
        int new_cap = capacity*2;
        int* new_arr = new int[new_cap];


        for (int i = 0; i < capacity; i++){
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_cap;
        
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
