class Solution {
private:
    stack<int> mainStack, minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) return;
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int peek() {
        return mainStack.empty() ? -1 : mainStack.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};
