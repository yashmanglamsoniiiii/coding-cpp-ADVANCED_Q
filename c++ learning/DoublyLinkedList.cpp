                    //#Implementation.
#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* pre;
    Node(int data){
        val=data;
        next=pre=NULL;
    }
};

class Doublyll{
    Node* head;  // Node* head, tail; --> error.
    Node* tail;
    public:
    Doublyll(){
        head=tail=NULL;
    }

    void add_begin(int value){
        Node* newNode=new Node(value);
        if (head==NULL){
            head=tail=newNode;
            return ;
        }
        newNode->next=head;
        head->pre=newNode;
        head=newNode;  // or head->pre;
    }

    void append(int value){
        Node* newNode=new Node(value);
        if (head==NULL){
            head=tail=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->pre=temp;
        tail=newNode;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    // void insert(int value, int pos){  // for 1 based indexing simply 0 ko 1 kardo baki sab same.
    //     Node* newNode=new Node (value);
    //     if (pos<0){
    //         cout<<"-1/n";
    //         return;
    //     }
    //     if (pos==0){
    //         add_begin(value);
    //         return;
    //     }

    //     Node* temp=head;
    //     for (int i=0;i<pos-1;i++){  //(int i=0;i<pos-1 && temp!=NULL;i++)
    //         temp=temp->next;
    //     }
    //     //temp is at pos-1
    //     if (temp==NULL){                //this can be inside for loop firstly too.
    //         cout<<"enter valid position./n";
    //         return;
    //     }



    //     // Node* t=temp->next;

    //     // temp->next=newNode;
    //     // newNode->pre=temp;

    //     // newNode->next=t;
    //     // if (t!=NULL){             // as when insert at last so t=null 
    //     // t->pre=newNode;          // and null->pre =newnode (access memory violation.)
    //     // }



    //     // ALITER: 
    //     newNode->next=temp->next; // we are not creating new pointer node.
    //     temp->next=newNode;

    //     newNode->pre=temp;
    //     if (newNode->next!=NULL){
    //     newNode->next->pre=newNode;
    //     }


    //     // SET TAIL :
    //     Node* a=head;
    //     while(a->next!=NULL){
    //         a=a->next;
    //     }
    //     tail=a;
    // }
    

                          // URVI MAM'S VERSION:
    // void insert( int value , int pos){
    //     Node* temp=head;
    //     int curr=1;
    //     while(curr< pos-1){
    //         temp=temp->next;
    //         curr++;
    //     }
    //     Node* newNode= new Node( value);
    //     newNode->next=temp->next;
    //     temp->next=newNode;

    //     newNode->pre=temp;
    //     if (newNode->next!=NULL){
    //         newNode->next->pre=newNode;
    //     }

    // }

    void del_begin(){
        if (head==NULL){
            cout<<"empty/n";
        }
        Node* temp=head;
        head=head->next;
        if (head!=NULL){
            head->pre=NULL;
        }
        temp->next=NULL;
        delete temp;
        
    }

    // void del_end(){
    //     if (tail==NULL){
    //         cout<<"empty/n";
    //         return;
    //     }
    //     Node* temp=head;

    //     if (temp->next==NULL){  // single node.
    //         delete temp;
    //         return;
    //     }
    //     // traversing:
    //     while(temp->next!=NULL && temp->next->next!=NULL){// ab 1 condn ki no need done single n.
    //         // first condn imp as single node mei  second cond code crash.
    //         temp=temp->next;
    //     }
    //     // WRONG:
    //     // if (temp!=NULL){     // this is wrong as temp null hoga bhi nhi .we aren't shifting
    //     //     temp->next->next=NULL;
    //     // }

    //     Node* t=temp->next;
    //     if ( temp->next!=NULL){  // ab to iski no need as single node kar diya.
    //         temp->next->pre=NULL;   // isse mene last node ka acces kho diya ****
    //         // temp->next=NULL; ye niche 
    //     }

    //     temp->next=NULL;
    //     delete t;
    //     tail =temp;
    // }

                               //Urvi mam style:
    void del_end(){
        if (head==NULL){
            return;
        }
        Node* temp=tail;
        tail=tail->pre;
        if (tail==NULL){  // shraddha mam ke code mei head ko null nhi banaya.
            head==NULL;
        }else{
            temp->pre=NULL;
        }
        tail->next=NULL;
        delete temp;
        return;
    }

    // me : del_arb
    // void del_arb(int pos){
    //     Node* temp=head;

    //     if (pos==0){
    //         del_begin();
    //     }
    //     int curr=0;
    //     while(curr!=pos-1){ // or < ok
    //         temp=temp->next;
    //         curr++;
    //     }

    // if (temp==NULL){  // iss par no output.
    //     cout<<"invalid/n";
    //     return;
    // }
    //     Node* t=temp->next;
    //     temp->next=t->next;

    //     if (t->next!=NULL){ // if last node delete to t->next NULL and NULL->pre = no outp. err.
    //         t->next->pre=temp;
    //     }
    //     delete t;
    // }
                             // urvi  mam style :
    void del_arb(int pos){    // we can plot all other condns
        Node* temp=head;
        int curr=1;
        while(curr<pos){
            temp=temp->next;
            curr++;
        }
        temp->next->pre=temp->pre; // ye if mei aayegi if (temp->next!=NULL)
        temp->pre->next=temp->next;
        delete temp;
    }
};

int main(){

    Doublyll dll;
    dll.add_begin(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.display();
    // dll.insert(10,5);
    dll.del_arb(2);
    dll.display();

    return 0;
}
