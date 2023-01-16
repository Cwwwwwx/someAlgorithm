#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> que1;

    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        size--;
        while (size--)
        {
            que1.push(que1.front());
            que1.pop();
        }

        int result = que1.front();
        que1.pop();
        return result;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};