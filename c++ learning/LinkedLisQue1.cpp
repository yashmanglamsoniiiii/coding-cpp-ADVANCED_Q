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


                      //wrong:
// Node* rev_ll(Node* &head){
//     Node* pre=NULL;
//     if (head==NULL){
//         head=pre;
//         return head;
//     }
//     head->next=pre;
//     pre=head;// pre ko aage badaya
//     rev_ll(head->next); // head ko bhi aage badaya.
// }

                 // right: urvi mam:
// Node* revllrecur( Node* &head){

//     // base case: 
//     if (head==NULL || head->next==NULL){ // empty or single node ll also last case cater.
//         return head;
//     }
//     //recursive call:
//     Node* new_head= revllrecur(head->next);// reverse rest of ll
//     head->next->next=head; // make next node point to current head node (made a pre pointer)
//     head->next=NULL;    // disconnect curr. node from rest next wla ( next poi. toda )
//     return new_head;
// }

// 5. REVERSING K NODES IN A LINKED LIST *****
                      //URVI MAM:-
Node* reversekLL(Node* &head,int k){
    Node* pre=NULL;
    Node* curr=head;
    int counter=0; 
    while(curr!=NULL && counter <k ){
        Node* next=curr->next;
        curr->next=pre;

        // aage badao
        pre=curr;
        curr=next;
        counter++;
    }
    if (curr!=NULL){
        Node* new_head=reversekLL(curr, k);
        head->next=new_head;
    }
    return pre;
}

             //QUES 6 VERY IMP.-> Write a program to implement linked list which has an insert function. 
                    // Insert function should place the node at sorted position in the linked list.  
                        //100% correct.
    void insertSorted(Node* &head, int value){
        Node* newNode=new Node(value);
        if (head==NULL){
            head=newNode;
            return;
        }else{
        Node* temp=head;
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        // three cases :
        // head ke aaage , tail ke peeche , kahin beech mei
        if (newNode->val<=head->val){
            newNode->next=head;
            head=newNode;
        }else if (tail->val<=newNode->val){
            tail->next=newNode;
            tail=newNode;
        }else{
        while(temp->next!=NULL){  // head and tail ke beech mei

            //temp agar last node (tail par ) aaya to loop ke bahar no checking therefore no need for temp->next->next
            // varna second last node will not checked.


            //temp->next so if tail par temp to tail->next-val [crash code].
            if  (temp->next->val>newNode->val && temp->val<=newNode->val){
                Node* temp2=temp->next;
                newNode->next=temp2;
                temp->next=newNode;
                break;
            }
            temp=temp->next;
        }

        }

        }
    }
    // bugs:
    // 1. most imp ->single node case.
    // Your approach splits into 3 cases (before head, after tail, between). 
    // That's OK. But the way you handle the between case depends on while(temp->next != NULL). 
    // If the list is length 1 (so temp->next == NULL) 
    // but the new node should be inserted between head and tail (which are the same node),
    //  the loop is skipped and nothing happens.

    //2.
    // You used temp->next->val > newNode->val && temp->val <= newNode->val. 
    // That condition is okay for many middle insertions but it assumes there is a '"temp->next."' 
    // If temp->next is NULL, you never check insertion point.
// temp = 1 (ok)
// temp = 5 (ok)
// temp = 10 (tail) → now temp->next == NULL, so loop stops immediately.
// And since nothing was inserted, the function exits without adding the new node.



            //another version of this question's answer.[OPTIMIZED]

    void insertSorted_2(Node* &head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL || value < head->val) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->val < value) {//equals to wala case bhi handled
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}



int main(){
    linkedlist ll,ll1;
        ll.add_begin(1);
        ll.add_end(2);
        ll.add_end(2);
        ll.add_end(3);
        ll.add_end(3);
        ll.display();
   
        // que 6
         insertSorted(ll1.head,5);
        // insertSorted(ll1.head,3);
        // insertSorted(ll1.head,10);
        // insertSorted(ll1.head,1);
        // insertSorted(ll1.head,2);
        // insertSorted(ll1.head,3);

    //     ll1.display();

    //<--------------->

        // del_alternate(ll.head);
        // del_duplicates(ll.head);
        // ll.display();
        // prtreversell(ll.head);
        // ll.head=rev_ll(ll.head); 
        //ll.head=revllrecur(ll.head);// aisa islye as revllrecur only gives newhead
                                    // to if => revllrecur(ll.head) then display 
                                    // output 1-> head. (here head still 1 only)
                                    // ll.head=revllrecur(ll.head) then display
                                    // output REVERSED LL. (head updated)
        ll.head=reversekLL(ll.head, 2);
        ll.display();
return 0;
}


