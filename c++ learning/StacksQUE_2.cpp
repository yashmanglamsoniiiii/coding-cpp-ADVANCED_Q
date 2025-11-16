#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> &s){
    while(!s.empty()){
        int curr=s.top();
        s.pop();
        cout<<curr<<endl;
    }
}
// 1.copy stack
//2.insert at any index
//me
void insertIdx(stack<int> &s,int idx,int val){
    //0 based indexing
    stack<int> r;
    int j=s.size();
    while(!s.empty()){
        if (j==idx){
            r.push(val);
        }
        int curr=s.top();
        s.pop();
        j--;
        r.push(curr);
    }
    while(!r.empty()){
        // if (j-2==idx) s.push(val);
        int curr=r.top();
        r.pop();
        // j--;
        s.push(curr);
    }
    // return s;
}

// sir:-
// void insertIdx(stack<int> &s,int idx,int val){
//     stack<int> r;
//     int n=s.size();
//     int count=0;
//     while(count<n-idx){
//         count++;
//         int curr=s.top();
//         s.pop();
//         r.push(curr);
//     }
//     s.push(val);
//     while(!r.empty()){
//         int curr=r.top();
//         r.pop();
//         s.push(curr);
//     }
// }
//me
void insertIdx(stack<int> &s,int idx,int val,int n){
    //if bottom position par add isliye s.empty() wala niche
    if (n==idx){
        s.push(val);
        return;
    }
    
    if (s.empty()){
        return;
    }
    int curr=s.top();
    s.pop();
    insertIdx(s,idx,val,n-1);
    s.push(curr);
}

//3. remove any index / bottom
void removeIdx(stack<int> &s,int idx){
    int count=0;
    stack<int> r;
    int n=s.size();
    while(count<(n-idx)-1){
        count++;
        int curr=s.top();
        s.pop();
        r.push(curr);
    }
    s.pop();
    while(!r.empty()){
        int curr=r.top();
        r.pop();
        s.push(curr);
    }
}

// recursion :-
void removeIdx(stack<int> &s,int idx,int n){
    if (n-1==idx){
        s.pop();
        return;
    }
    if (s.empty()) return;
    int curr=s.top();
    s.pop();
    removeIdx(s,idx,n-1);
    s.push(curr);
}
//4. reverse elements in same stack:-
void insertbottom(stack<int> &s,int x){
    stack<int> t;
    while(!s.empty()){
        int curr=s.top();
        s.pop();
        t.push(curr);
    }
    s.push(x);
    while(!t.empty()){
        int curr=t.top();
        t.pop();
        s.push(curr);
    }
}
void revele(stack<int> &s){
    if (s.empty()){
        return;
    }
    int curr=s.top();
    s.pop();
    revele(s);
    insertIdx(s,0,curr);
    // insertbottom(s,curr);
    
}

//5.bracket balance:-

bool bracketbalance(string &s){
    stack<char> t;
    int i=0;
    while(i<s.size()){  

        if (s[i]=='(' || s[i]=='['||s[i]=='{'){
            t.push(s[i]);
            i++;
        }
        
        if (s[i]==')' || s[i]==']'||s[i]=='}'){
            if ((t.top() == '(' &&s[i]==')') ||(t.top() == '{' &&s[i]=='}') ||
                (t.top() == '[' &&s[i]==']')){
                t.pop();
                i++;
            }
            else{
                return false;
            }
        }
        
    }
    return true;
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // display(s);
    // cout<<"new stack"<<endl;
    // stack<int> r=insertIdx(s,2,10);
    // insertIdx(s,2,19);
    // display(s);

    string str="([{}])[]";
    cout<<bracketbalance(str);
}