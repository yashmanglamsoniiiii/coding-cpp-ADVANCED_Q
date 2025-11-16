#include <iostream>
#include<stack>
#include<queue>
using namespace std;
          //que : reversing elements of queue
int main(){
        queue<int> q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        // while(not q.empty()){
        //     cout<<q.front()<<" ";
        //     q.pop();
        // }
        // cout<<endl;

        stack<int> s;
        while(not q.empty()){
            s.push(q.front());
            q.pop();
        }

    while(not s.empty()){
        q.push(s.top());
        s.pop();
    }

    while(not q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
return 0;
}