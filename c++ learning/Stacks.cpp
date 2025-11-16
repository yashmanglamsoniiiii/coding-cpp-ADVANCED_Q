//                        //STACKS USING ARRAY:-

#include <iostream>
using namespace std;

class stacks{
    int capacity;
    int *arr;
    int top;
    public:
    stacks(int c){
        int capacity=c;
        arr=new int[c];
        top=-1;
    }

    //push 
    void push(int data){
        if (top>=capacity-1){
            cout<<"stack is full"<<endl;
            return;
        }
        arr[++top]=data;
    }

    // pop   

            // me : wrong 
    // void pop(){
    //     if (top==-1){
    //         cout<<"stack is already empty."<<endl;return;
    //     }
    //     int k;
    //     arr[k]=arr[top];
    //     top--;
    //     delete arr[k];
    // }

             // correct:
    void pop(){
        if (top==-1){
            cout<<"stack is already empty."<<endl; return;
        }
        top--;
    }

    // isEmpty
    // bool isEmpty(){
    // if (top==-1){
    //     return true;
    // }
    // return false; // optional
    // }

    //better:
    bool isEmpty(){
        return (top==-1);
    }

    //isFull
    // bool isFull(){
    //     if (top==capacity-1){
    //         return true;
    //     }
    //     return false;// optional
    // }

    //better :
    bool isFull(){
        return (top==capacity-1);
    }

    // top
    // int topidx(){
    //     if (top>capacity){
    //         return -2;
    //     }
    // // return arr[top];
    // return top;
    // }

    //better:
    int topidx(){
        return top;
    }

    // peek:
    int peek(){
        if (top==-1){
            return -1;
        }
        return arr[top];
    }

    //size
    // int size(){
    //     if (top==-1){
    //         return -1;
    //     }
    //     if(top>capacity) return -2;
        
    //     return (top+1);
    // }


    // better :
    int size(){
        return top+1;
    }

    //display
    void display(){
        if (top==-1){
            return;
        }
        cout<<"top -> ";
        for (int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
        }
        cout<<"<- last"<<endl;
    }
};
int main(){
        stacks s(5);
        s.push(114);
        s.push(23);
        s.push(39);
        s.push(100);
        s.display();
        
        cout<<s.isEmpty();
        cout<<endl;
        cout<<s.isFull()<<endl;

        // s.isEmpty();
        // s.isFull();

        cout<<s.topidx();
        cout<<endl;
        cout<<s.size()<<endl;
        
        cout<<s.peek();
        cout<<endl;
        // s.display();
        
        s.pop();
        s.display();
    
return 0;
}

                        // STACKS USING LINKED LIST:-
#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=NULL;
    }
};

class stacks{
    int capacity;
    int top;
    int currsize;
    Node* head;
    // Node* top;// to return top node;--- > head hai uske liye.

    public:
    stacks(int size){
        capacity=size;
        head=NULL;
        currsize=0;
    }
       // wrong push function ------> tail pe not add head pe add.
//     void push(int value){

//         if (currsize==capacity) {  // NOPE currsize==n-1 and then push to overflow 
//             cout<<"overflow"<<endl;
//             return;
//         }
//         Node* newNode=new Node(value);
//         if (head==NULL){
//             newNode=head;
//             top=newNode;
//             currsize++;
//         }else{

//         Node* tail=head;
//         while(tail->next!=NULL){
//             tail=tail->next;
//         }
//         tail->next=newNode;
//         top=newNode;
//         currsize++;
//     }
// }

    void push (int value){
        if (currsize==capacity) {
            cout<<"overflow"<<endl;
            return;
        }
        Node* newNode= new Node(value);
        if (head==NULL) {
            head=newNode;
            currsize++;
        } else{
            newNode->next=head;
            head=newNode;
            currsize++;
        }
    }

    void pop(){
        if (currsize==0){   // NOPE 0 based index agar 0 se kam hua to underflow. but phir uper currsize by default -1
            cout<<"underflow"<<endl;  //head NULL hai.
            return;
        }
        if (head->next==NULL){
            delete head;
            currsize--;
        }
        else{
            Node *temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            currsize--;
        }
    }

    bool isFull(){
        return (currsize==capacity);
    }

    bool isEmpty()
    {
        return (currsize==0);
    }

    int topEle(){//peek
        return head->val;
    }
    
    int currentSize(){
        return currsize;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
        stacks st(5) ;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(6);
        // cout<<st.currentSize();  // since vo -1 pe to 2 dikha rha hai size 0 pe hi sahi  as we are using  
                                   // currsize as for indexing too (o based)
        st.display();
        cout<<st.currentSize()<<endl;
        cout<<st.isFull()<<endl;

        // st.pop();
        // st.pop();
        // st.pop();
        // cout<<st.isEmpty();
return 0;
}