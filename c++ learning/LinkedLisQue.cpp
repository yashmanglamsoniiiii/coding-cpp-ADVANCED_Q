 // QUESTIONS FOR LL
                        
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

class linkedlist{
    public:
    Node* head;
    Node* tail;
    linkedlist(){
        head=tail=NULL;
    }


void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL" <<endl;
}

void add_begin( int value){                                              
    Node* newNode=new Node(value);
    if (head==NULL){
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}

void add_end( int value){ 
    Node *newNode=new Node(value);
    if (head==NULL){                
        head=newNode;
    }
    else{
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        temp=newNode;
    }
}
};

                        // 1. delete every alternate element
// trial: wrong:-
// void del_alternate(Node* &head){
//     Node *temp=head;
//     int idx=0;
    
//         while(temp!=NULL){
//             if (idx%2!=0){
//                 Node* t=temp->next;
//                 temp->next=temp->next->next;
//                 t->next=NULL;
//                 delete t;
//             }
//             temp=temp->next;
//             idx++;
//         }
    
// }

// void del_alternate(Node* &head){    // beech wala node hatake phir chalao (print);
//     Node* current=head;
//     while(current!=NULL && current->next!=NULL){ 

//         //even then odd ki condn.(otherwise segmentation error) => copy


//         Node* temp=current->next;   // this node is to be deleted.
//         current->next=current->next->next; // link change.
//         temp->next=NULL;
//         delete temp; // beech wla node delete;
//         current=current->next;// traversing ahead (aage bade)
    
//     }
// }


//2.DELETE EVERY DUPLICATE ELEMENT IN THE LINKED LIST SUCH THAT EACH ELEMENT APPEARS ONLY ONCE.
// ALSO SORT THE LINKEDLIST. (given linked list is sorted.)

// wrong:-
// void length(Node* &head){
//     Node* temp=head;
//     int count=0;
//     while(temp!=NULL){
//         count++;
//         temp=temp->next; //ya iske niche count++;
//     }
//     cout<<count<<endl;
// }

// void dupli_sort(Node* &head){
//     Node*t= head;
//     Node*t1=head;
//     int length=length(head);
//     for(int i=0;i<length;i++){   // for t

//         for (int j=i+1;j<length;j++){  // for t1
//             if (t->val==t1->val){
                                        //  complex copy dekho.
//             }
//             t1=t1->next;
//         }

//         t=t->next;
//     }
// }

// void del_duplicates(Node* &head){
//     Node* curr=head;
//     while(curr!=NULL){ // OR SIMPLY 'while(curr)'-> vahi mean cond false loop break.
//         // curr!=null  iterates over last node too 

//         // another option:-
//         // "curr!=null && curr->next!=null" isse last node pe no iteration*******
//         // baki optional.
//         // both handles last node safely.
//         while(curr->next!=NULL && curr->val==curr->next->val){ 
//                  // null ki value no (crash)no output. so currnext!=null*****
//             Node* temp=curr->next; 
//             curr->next=temp->next; // curr->Next->next ok
//             temp->next=NULL;
//             delete temp;
//         }
//         curr=curr->next;// traverse.
//     }
// }


//3. TRAVERSING LINKED LIST IN REVERSE ORDER  AND PRINTING LL.
// [NOTE CHANGE THE LINKED LIST :- DON'T REVERSE THE LL.]

// void prtreversell(Node* head){
//     Node *temp=head; // right.
//     // base condn
//     if (temp==NULL) return;

//     // recursive calls
//     prtreversell(temp->next);
//     cout<<temp->val<<"->";  // stacks bante hain to endl se har alag line mei.
//     // NULL bhi print to recursive calls in else part.
// }
              //output:3->3->2->2->1->

//aliter:
// void prtreversell(Node* head){
//     Node *temp=head;
//     if (temp==NULL){
//         return;
//     }else{
//         prtreversell(head->next);
//         cout<<head->val<<"->";
//     }
//     cout<<"NULL";
// }  
           // output:    3->NULL3->NULL2->NULL2->NULL1->NULL


//4. REVERSE A LINKED LIST.
                // ME:-wrong.
// void rev_ll(Node* &head){
//     if (head ->next==NULL){  // head is not at null head is at last node.
//         return;
//     }

//     rev_ll(head->next);
// }  // i am not reversing the links.

                              //METHOD 1;
// Node* rev_ll(Node* &head){
//     Node* pre=NULL;
//     Node* curr=head;
//     // Node* next;    // phir niche bass next=curr->next;

//     // here not Node* next=curr->next; phir niche bhi next=curr->next; do baar move.first time*
//     while(curr!=NULL){
//         Node* next=curr->next; // preserve the next node.
//         curr->next=pre; // next ki link break and pre link formed.
//         // move forward.
//         pre=curr;
//         curr=next; //or curr->next;
//         // next is moving forward sabse pehle .

//     }
//     head=pre;  
//     // or Node* newhead=pre;
//     return head;// or pre
// }                   //     ll.head=rev_ll(ll.head);  head define


                      //RECURSIVE WAY : METHOD 2:-

Node* rev_ll(Node* &head){
    Node* pre=NULL;
    if (head==NULL){
        head=pre;
        return head;
    }
    head->next=pre;
    pre=head;// pre ko aage badaya
    rev_ll(head->next); // head ko bhi aage badaya.
}
int main(){
    linkedlist ll;
        ll.add_begin(1);
        ll.add_end(2);
        ll.add_end(2);
        ll.add_end(3);
        ll.add_end(3);
        ll.display();

        // del_alternate(ll.head);
        // del_duplicates(ll.head);
        // ll.display();
        // prtreversell(ll.head);
        ll.head=rev_ll(ll.head);  
        ll.display();
return 0;
}


