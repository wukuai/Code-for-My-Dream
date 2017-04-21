//用两个栈模拟队列
//https://leetcode.com/problems/implement-queue-using-stacks
//待改进版：
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stack1.empty()) return -1;
        int temp;
        while(!stack1.empty()){
            temp=stack1.top();
            stack1.pop();
            stack2.push(temp);
        }
        int top=stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            temp=stack2.top();
            stack2.pop();
            stack1.push(temp);
        }
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(stack1.empty()) return -1;
        int temp;
        while(!stack1.empty()) {
            temp=stack1.top();
            stack1.pop();
            stack2.push(temp);
        }
        int top=stack2.top();
        while(!stack2.empty()) {
            temp=stack2.top();
            stack2.pop();
            stack1.push(temp);
        }
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty()?true:false;
    }
private:
    stack<int>stack1;
    stack<int>stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
