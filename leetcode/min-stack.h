/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Tags:
Stack, Data Structure

*/

class MinStack {
public:
    stack<int> assist;
    stack<int> normal;
    void push(int x) {
        if (x <= getMin()) {
            assist.push(x);
        }
        normal.push(x);
    }

    void pop() {
        if (normal.top() == getMin()) {
            assist.pop();
        }
        normal.pop();
    }

    int top() {
        return normal.top();
    }

    int getMin() {
        if (assist.empty())
            return INT_MAX;
        return assist.top();
    }
};