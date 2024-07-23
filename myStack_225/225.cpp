#include <queue>
using namespace std;
class MyStack {
public:
    queue<int> queue1, queue2;
    MyStack() {

    }
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        int size = queue1.size();
        size--;
        while(size--){
            queue2.push(queue1.front());
            queue1.pop();
        }

        int res = queue1.front();
        queue1.pop();
        queue1 = queue2;
        while (!queue2.empty()){
            queue2.pop();
        }
        return res;
    }
    
    int top() {
        return queue1.back();
    }
    
    bool empty() {
        return queue1.empty();
    }
};