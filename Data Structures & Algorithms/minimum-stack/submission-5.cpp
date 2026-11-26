class MinStack {
public:
    std::stack <int> mainStack, minStack;

    MinStack() {
    }
    
    void push(int val) {
        mainStack.push(val);
        val = std::min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
