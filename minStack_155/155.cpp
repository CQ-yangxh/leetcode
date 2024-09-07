#include <stack>
using namespace std;
class MinStack {
public:
    stack<int> assit;
    stack<int> data;
    MinStack() {

    }
    
    void push(int val) {
        if(data.empty()){
            data.push(val);
            assit.push(val);
        }
        else{
            if(val < assit.top()) assit.push(val);
            else assit.push(assit.top());
            data.push(val);
        }
    }
    
    void pop() {
        assit.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return assit.top();
    }
};

int main(){
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-1);
    int nm = ms.getMin();
    int top = ms.top();
    ms.pop();
    int nm2 = ms.getMin();
}