class Stack {
public:
    int *arr;
    int tp=-1;
    int cap;
    Stack(int capacity) {
        arr = new int[capacity];
        this->cap = capacity;
    }

    void push(int num) {
        if (isFull()!=1){
            arr[++tp] = num;
        }
    }

    int pop() {
        if (isEmpty()!=1){
            int x = arr[tp];
            tp--;
            return x;
        }
        else{
            return -1;
        }
    }

    int top() {
        if (tp!=-1){
            return arr[tp];
        }
        return -1;
    }

    int isEmpty() {
        if (tp==-1){
            return 1;
        }
        return 0;
    }

    int isFull() {
        if (tp==cap-1){
            return 1;
        }
        return 0;
    }
};
