//            //   IMPLEMENTATION OF QUEUES USING LINKED LIST.
// #include <iostream>
// using namespace std;
// class Node{
//     public:
//     Node* next;
//     int val;
//     Node(int data){
//         val=data;
//         next=NULL;
//     }
// };

// class queue{
//     Node* head;
//     Node* tail;
//     int size;

//     public:

//     queue(){
//         this->head=this->tail=NULL;
//         this->size=0;
//     }

//     void enqueue(int value){
//         Node* newNode=new Node(value);
//         if (this->head==NULL){
//             this->head=this->tail=newNode;
//         }else{
//             this->tail->next=newNode;
//             this->tail=newNode;
//         }
//         this->size++;
//     }


//     void dequeue(){
//     if (this->head==NULL){
//         return;
//     }else{
//         Node* oldhead=this->head;
//         Node* newHead=this->head->next;
//         this->head=newHead;
//         if (this->head==NULL){      //* imp.imp.imp.
//             this->tail=NULL;
//         }
//         delete oldhead;
        //    size--;
//     }
//     // this->size--; here not 
//     }

//     bool isEmpty(){
//         return this->head==NULL;
//     }

//     int getsize(){
//         return this->size;
//     }
//     int front(){
//         if (this->head==NULL) return -1;
//         return this->head->val;
//     }

//     void display(){
//         Node* temp=this->head;
//         while(temp!=NULL){
//             cout<<temp->val<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// };

// int main(){
//     queue q;
//     q.enqueue(1);
//     q.enqueue(3);
//     q.enqueue(2);
//     q.display();
//     cout<<q.getsize()<<endl;
//     cout<<q.front()<<endl;
//     q.dequeue();
//     q.dequeue();
//     q.display();
//     q.dequeue();
//     cout<<q.isEmpty()<<endl;

// }



                  //queues using arrays

#include <iostream>
#include <vector>
using namespace std;

// class queue{
//     int *arr;
//     int capacity;
//     int size;
//     int front;
//     int back;
//     public:
//     queue(int cap){
//         arr=new int[cap];
//         capacity=cap;
//         size=0;
//         front=0;
//         back=capacity-1;
//     }
//     void enqueue(int value){
//         if (size==capacity){
//             cout<<"overflow"<<endl;
//             return ;
//         }
//         arr[size++]=value;
        
//     }

//     void dequeue(){
//         if (size==0){
//             cout<<"underflow"<<endl;
//             return;
//         }
//         front++;
//     }
//     bool isEmpty(){
//         return size==0;
//     }
//     bool isFull(){
//         return size==capacity;
//     }

//     int getsize(){
//         return size;
//     }
//     int peek(){
//         if (size<=0) return -1;
//         return arr[front];
//     }

//     void display(){
//         int i=front;
//         while(i<=size){
//             cout<<arr[i]<<" ";
//             i++;
//         }cout<<endl;
//     }

// };

                          //sir :

class queue{
    int front;
    int back;
    vector<int> v;
    public:
    queue(){
        this->front=-1;
        this->back=-1;
    }

    void enqueue(int value){
        this->v.push_back(value);
        this->back++;
        if (this->back==0 ) this->front=0;
    }

    void dequeue(){
        if (this->front==this->back){
            this->front=this->back=-1;
            v.clear();
        }else{
            this->front++;
        }
        cout<<"index :"<<this->front<<"\n";
    }

    bool isEmpty(){
        return this->front==-1;
    }

    int getFront(){
        if (this->front==-1) return -1;
        return v[this->front];
    }
    int getsize(){
        return (this->back-this->front)+1;
    }

    void display(){
        int i=this->front;
        while(i<=this->back){
            cout<<v[i]<<" ";
            i++;
        }cout<<endl;
    }
};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(2);
    q.display();
    cout<<q.getsize()<<endl;
    cout<<q.getFront()<<endl;
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    cout<<q.isEmpty()<<endl;




return 0;
}


