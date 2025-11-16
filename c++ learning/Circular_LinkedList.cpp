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

class cll{
    public:
    Node *head;
    public:
    cll(){
        head=NULL;
    }

    //display:-
    void display(){
        Node* temp=head;
        do{
            cout<<temp->val<<"->";
            temp=temp->next;
        }while(temp!=head);

        cout<<endl;
    }

    // insert at begin:
    void add_beg(int value){
        Node* newNode=new Node(value);
        if (head==NULL){
            head=newNode;
            newNode->next=head;
            return;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        newNode->next=head;
        tail->next=newNode;
        head=newNode;
    }

    // append(add at last):
    void append(int value){
        Node* newNode=new Node(value);
        if (head==NULL){
            head=newNode;
            newNode->next=head;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=newNode;
        newNode->next=head;
        tail=newNode;
    }

    // insert:-
    void insert (int value , int pos){
        Node* newNode=new Node(value);
        if(pos==0){
            add_beg(value);
            return;
        }
        if(pos<0){
            return;
        }
        int currpos=0;
        Node* temp=head;
        while(temp->next!=head && currpos<pos-1){ // currpos!=pos-1
            temp=temp->next;
            currpos++;
        }
        if (temp->next==head && currpos<pos-1){
            append(value);
            return;
        }
        else{
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }

    // update:- value position format:-
    //me:- wrong (2 bugs in copy)
    // void update (int newValue, int pos){
    //     if (pos<0) {
    //         cout<<"invalid pos";
    //         return;
    //     }
    //     if (!head){ //!head=> head==NULL
    //         cout<<"empty cll";
    //         return;
    //     }
    //     Node* temp=head;
    //     int curr=0;
    //     while(curr<pos){
    //         temp=temp->next; curr++;
    //     }
    //     if (curr==pos){
    //         temp->val=newValue;
    //     }else{
    //         cout<<"invalid position";
    //     }
    // }

    //right:-

    // VERSION - WHILE LOOP.
    void update1 (int newValue, int pos){
        if (pos<0) {
            cout<<"invalid pos";
            return;
        }
        if (!head){ //!head=> head==NULL
            cout<<"empty cll";
            return;
        }
        Node* temp=head;
        int curr=0;
        while(curr<pos){
            temp=temp->next;
            curr++;
            if (temp==head){
                cout<<"invalid position."<<endl;
                return;
            }
        }
        temp->val=newValue;
        cout<<"done";
    }
    
    //VERSION 2: DO WHILE LOOP:
    void update2(int newValue, int pos){
        if (pos<0) {
            cout<<"invalid pos";
            return;
        }
        if (!head){ //!head=> head==NULL
            cout<<"empty cll";
            return;
        }
        Node* temp=head;
        int curr=0;
        bool found=false;
        do{
            if (curr==pos){
                temp->val=newValue;
                found=true;
                break;
            }
            temp=temp->next;
            curr++;
        }while(temp!=head);
        
    if (found){// found==true;
            cout<<"successfully updated!!!"<<endl;
    }else{
        cout<<"not found"<<endl;
    }
}
 

//update by value
// see copy.

// search function:-give key(value) and take it's index.
void search(int key){
    Node* temp=head;
    int idx=0;
    do{
        if (temp->val==key){
            cout<<idx<<endl;
            return;
        }
        temp=temp->next;
        idx++;
    }while(temp!=head);
    // loops ends
    cout<<"not found key."<<endl;
}
//del_head;
void del_head(){
    if (head==NULL) return;
    if (head->next=head){
        delete head;
        head=NULL;
    }
    
    Node* temp=head;
    // find tail:-
    Node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    head=head->next;
    tail->next=head;
    temp->next=NULL;
    delete temp;
}

//del_tail;
void del_end(){
    if (head==NULL) return;
    if (head->next==head){
        delete head;
        head=NULL;
    }
    Node* temp=head;
    Node* tail=head;
    while(tail->next->next!=head){
        tail=tail->next;
    }
    tail->next->next=NULL;
    delete tail->next;
    tail->next=head;
}

// del_arb:-
// void del_arb(int pos){
//     if ( pos<0){           
//         return;
//     }
//     if (pos==0){
//         del_head();
//         return;
//     }
//     // creation of tail is optional:-
//     Node* tail=head;
//     while(tail->next!=head){
//         tail=tail->next;
//     }

//     // temp node ptr.
//     Node* temp=head;
//     int curr=0;
//     while(temp->next!=head && curr<pos-1){
//         temp=temp->next;
//         curr++;
//     }
//     if (temp->next==head && curr<pos-1){
//         // del_end();this is not required and use this condition to check valid position of temp. 
//         return;
//     }else{
//         Node* t=temp->next;
//         temp->next=t->next;
//         t->next=NULL;
//         delete t;
//     }

// }

void del_arb(int pos){
    if (!head || pos<0){
        return;
    }
    if (pos==0){
        del_head();
    }
    Node* temp=head;
    int curr=0;
    while(temp->next!=head && curr<pos-1){// condns can be switched,safer but ok .
        temp=temp->next;
        curr++;
    }
    if (temp->next==head){
        cout<<"invalid"<<endl;
        return;
    }
    Node* t=temp->next;
    temp->next=t->next;
    t->next=NULL; // t->next =NULL in cll is not good sometimes it can cause problems . 
                  // it is also not required  .
    delete t;
}
};

int main(){
        cll c;
        c.append(1);
        c.append(2);
        c.append(3);
        c.append(4);
        c.append(5);
        c.append(6);
        c.display();

        // c.update2(10, 2);
        // c.display();
        // c.search(5);
        // c.del_end();
        c.del_arb(5);
        c.display();
        // c.del_end();
        // c.display();

return 0;
}