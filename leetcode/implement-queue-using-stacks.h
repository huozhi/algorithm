/**

mplement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

*/

class Queue {
    stack<int> a;
    stack<int> b;
public:
    // Push element x to the back of queue.
    void push(int x) {
        a.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        b.pop();
    }

    // Get the front element.
    int peek(void) {
        if (b.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return a.empty() && b.empty();
    }
};