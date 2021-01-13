#define MIN INT_MAX

class MinStack {
public:
    /** initialize your data structure here. */
    int data;
    MinStack* Top = NULL;
    MinStack* next = NULL;
    
    int minimum = MIN;
    MinStack() {
        
    }
    
    void push(int x) {
        MinStack* node = new MinStack();
        node->data = x;
        if(Top!=NULL){
            node->minimum = min(Top->minimum,x);
            node->next = Top;
            Top = node;
        }else {
            node->minimum = x;
            Top = node;
        }
        
    }
    
    void pop() {
        if(Top == NULL)return ;
        Top = Top->next;
    }
    
    int top() {
        return Top->data;
    }
    
    int getMin() {
        return Top->minimum;
    }
};
