#include <iostream>
#include <stack>
using namespace std;

class queueusingstack{

    stack<int> s1,s2;
    public: 

    void enqueue(int n){
        while(!s1.empty()){
            int curr=s1.top();
            s1.pop();
            s2.push(curr);
        }
        s1.push(n);
        while(!s2.empty()){
            int curr=s2.top();
            s2.pop();
            s1.push(curr);
        }
    }

    void dequeue(){
        if (s1.empty() && s2.empty()) return;
        s1.pop();
    }


    void display(){
        if (s1.empty() && s2.empty()) return;
        stack<int> copy=s1;
        while(!copy.empty()){
            cout<<copy.top()<<" ";
            copy.pop();
        }
        cout<<endl;
    }

};

int main(){
    queueusingstack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();

    q.dequeue();
    q.dequeue();
    
    q.display();

    q.dequeue();
    q.display();


}