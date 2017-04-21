//用两个栈模拟队列
//关键点在于：.top() or .pop() 时只需考虑stack2的顶部元素（它一定是最先进来的）,如果stack2为空，则倒腾一遍
//.push()时只需push到stack1中即可，不用管stack2
//则：常规情况下，push只管stack1   top/pop只管stack2
//这就避免了每次倒腾过来又倒腾过去了
//https://leetcode.com/problems/implement-queue-using-stacks
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
        if(stack1.empty()&&stack2.empty()) return -1;
        if(stack2.empty()){
            int temp;
            while(!stack1.empty()){
                temp=stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        int top=stack2.top();
        stack2.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(empty()) return -1;
        if(stack2.empty()){
            int temp;
            while(!stack1.empty()){
                temp=stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        return stack2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty()&&stack2.empty();
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
