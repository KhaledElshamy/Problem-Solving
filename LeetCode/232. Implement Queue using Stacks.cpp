class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue* top = NULL;
    MyQueue* head = NULL;
    MyQueue* next = NULL;
    
    int data;
    MyQueue() {
        next = NULL;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        MyQueue* node = new MyQueue();
        node->data = x;
        if(top == NULL) top = node;
        if(head == NULL)head = node;
        else {
            head->next = node;
            head = node;
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(top==NULL)return NULL;
        int data = top->data;
        top = top->next;
        return data;
    }
    
    /** Get the front element. */
    int peek() {
        return top->data;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return top == NULL;
    }
};
