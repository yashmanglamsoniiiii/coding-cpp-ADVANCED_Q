#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    bool visited;
    Node(int data){
        val=data;
        next=NULL;
        visited= false;
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

             // QUE 1 : EQUAL LL
             //   ME:- CORRECT:-
// void  equalLL(Node* &head1 , Node* &head2){
//     if (head1==NULL || head2==NULL){
//         cout<<"can't be compared."<<endl;
//     }
//     Node* temp1=head1;
//     Node* temp2=head2;
//     while(temp1!=NULL && temp2!=NULL && temp1->val==temp2->val){
//         temp1=temp1->next;
//         temp2=temp2->next;
//     }
//     if (temp1==NULL && temp2==NULL){  //equal length hai islye both null and equal value too.
//         cout<<"both linked lists are equal."<<endl;
//     }
//     else {  // ll. unequal ya not same val will come to this case.
//         cout<<" both  linked lists are unequal."<< endl;
//     }
// } 
                      // URVI MAM'S :
// bool equalLL(Node* head1, Node* head2){
//     Node* temp1=head1;
//     Node* temp2=head2;
//     while(temp1!=NULL && temp2!=NULL){
//         if (temp1->val!=temp2->val){
//             return false;
//         }
//         temp1=temp1->next;
//         temp2=temp2->next;
//     }
//     // either temp1=null / temp2=null / temp1=temp2=null
//     return (temp1==NULL && temp2==NULL);
// }


         //QUE 2: FIND INTERSECTION POINT OF TWO LL. 
// Node* interpt(Node* head1,Node* head2){
//     Node* temp1=head1;
//     Node* temp2=head2;
//     visited=false;
//     while(temp1!=NULL){
//         visited=true;
//         temp1=temp1->next;
//     }
//     while(temp2!=NULL){
//         if(visited==true){
//             return temp1;
//         }
//         temp2=temp2->next;
//     }
//     return NULL;
// }

        //mam:
int length(Node* head){
    Node* temp=head;
    int  count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

Node* moveHeadbyK(Node* head,int k){
    Node* temp=head;
    while(k--){
        temp=temp->next;
    }
    return temp;
}

Node* interpt(Node* &head1, Node* &head2){
    int l1=length(head1);
    int l2=length(head2);

    Node* t1; Node* t2;
    if (l1>l2){
        int k=l1-l2;
        t1=moveHeadbyK(head1,k);
        t2=head2;
    }else{
        int k=l2-l1;
        t2=moveHeadbyK(head2,k);
        t1=head1;
    }

    while(t1!=NULL && t2!=NULL && t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }

    // if (t1==NULL || t2==NULL){
    //     return NULL;
    // }

    // return t1;

    // OR 

    // if (t1==t2) return t1;

    // return NULL;

    while(t1){
        if (t1==t2){
            return t1;
        }
        t1=t1->next;
        t2=t2->next;
    }

    return NULL;
}



                 // QUE 3: REMOVE Kth node from last.

// int length(Node* head){    // length function 
//     Node* temp=head;
//     int l=0;
//     while(temp!=NULL){
//         temp=temp->next;
//         l++;
//     }
//     return l;
// }

// Node* removefrmLast(Node* &head,int lastpos){
//     Node* t=head;
//     int size=length(head);
//     int strtpos=size-lastpos;

//     // lastpos>size 

//     if (lastpos>size){
//         cout<<"invalid input, size se bada input"<<endl;
//         return head;
//     }
//     // if strtpos=0 ->del_head wla case:
//     if (strtpos==0){
//         head=head->next;
//         t->next=NULL;
//         delete t;
//         return head;
//     }

//     int currpos=0;
//     while(t!=NULL && currpos!=strtpos-1){
//         t=t->next;
//         currpos++;
//     }

//     // no. out of bounds.
//     if (t==NULL)  return head;  // this is not as required as last>size wala case checked above.
    
//     // normal case:
//     else{
//         Node* t1=t->next;
//         t->next=t1->next;
//         t1->next=NULL;
//         delete t1;
//         return head;
//     }
// }
       //URVI MAM:
// void removefrmLast(Node* &head,int k){
//     Node* p1=head;
//     Node* p2=head;
//     int count=k;
//     while(count--){
//         p2=p2->next;
//     }
//     //p2 null to firstnode delete 
//     if (p2==NULL){
//         Node* t=head;
//         head=head->next;
//         t->next=NULL;
//         delete t;
//         return;
//     }
//     while(p2->next!=NULL){
//         p1=p1->next;
//         p2=p2->next;
//     }
//     Node* temp=p1->next;
//     p1->next=p1->next->next;/     temp->next=NULL;
//     delete temp;
// }
            //QUE 4: MERGE 2 SORTED LL INTO ANOTHER SORTED SINGLE LL

         // me: approach 1: making new conn. and deleting old ones
// Node* mergeSortedLL(Node* &head1, Node* &head2){
//     Node* t1=head1;
//     Node* t2=head2;
//     Node* h=NULL;

//     //declaring head of NEW (CONNCECTED) LL.
//     if (t1->val<t2->val){
//         h=t1;
//         t1=t1->next;
//     }else{
//         h=t2;
//         t2=t2->next;
//     }
//     // sorting and connecting middle part
//     Node* a=h;
//     while(t1!=NULL && t2!=NULL){
//         if (t1->val<t2->val){
//             a->next=t1;
//             a=a->next;
//             t1=t1->next;
//         }
//         else{
//             a->next=t2;
//             a=a->next;
//             t2=t2->next;
//         }
//     }

//     // now either t1 reached to null or t2 reached to null
//     if (t1==NULL){
//         a->next=t2;
//     }else{
//         a->next=t1;
//     }
//     return h;
// }

        // me: approach 2: creating a new ll and copying "sorted" values

//     Node* mergeSortedLL(Node* &head1, Node* &head2){
//     Node* t1=head1;
//     Node* t2=head2;

//     Node* h=NULL;
//     // Node* a=NULL;
//     //declaring head of NEW (made) LL.
//     if (t1->val<t2->val){
//         Node* newNode=new Node(t1->val);
//         h=newNode;
//         // a=h;
//         t1=t1->next;
//     }else{
//         Node* newNode=new Node(t2->val);
//         h=newNode;
//         // a=h;
//         t2=t2->next;
//     }

//     // sorting and connecting middle part
//     Node* a=h;
//     while(t1!=NULL && t2!=NULL){
//         if (t1->val<t2->val){
//             Node* newNode1=new Node(t1->val);
//             a->next=newNode1;
//             a=a->next;
//             t1=t1->next;
//         }
//         else{
//             Node* newNode2=new Node(t2->val);
//             a->next=newNode2;
//             a=a->next;
//             t2=t2->next;
//         }
//     }

//     // now either t1 reached to null or t2 reached to null
//     if (t1==NULL){
//         while(t2!=NULL){
//             Node* N = new Node(t2->val);
//             a->next=N;
//             a=a->next;
//             t2=t2->next;
//         }
//     }else{
//         while(t1!=NULL){
//             Node* N=new Node(t1->val);
//             a->next=N;
//             a=a->next;
//             t1=t1->next;
//         }
//     }

//     return h;
// }

                        // WRONG APPROACH:-

// Node* mergeSortedLL(Node* &head1, Node* &head2){
//     Node* t1=head1;
//     Node* t2=head2;

//     Node* h=NULL;
//     // Node* a=NULL;
//     //declaring head of NEW (made) LL.
//     if (t1->val<t2->val){
//         Node* newNode=new Node(0);
//         newNode=t1;
//         h=newNode;
//         // a=h;
//         t1=t1->next;
//     }else{
//         Node* newNode=new Node(0);
//         newNode=t2;
//         h=newNode;
//         // a=h;
//         t2=t2->next;
//     }

//     // sorting and connecting middle part
//     Node* a=h;
//     while(t1!=NULL && t2!=NULL){
//         if (t1->val<t2->val){
//             Node* newNode1=new Node(0);
//             newNode1=t1;
//             a->next=newNode1;
//             a=a->next;
//             t1=t1->next;
//         }
//         else{
//             Node* newNode2=new Node(0);
//             newNode2=t2;
//             a->next=newNode2;
//             a=a->next;
//             t2=t2->next;
//         }
//     }

//     // now either t1 reached to null or t2 reached to null
//     if (t1==NULL){
//         while(t2!=NULL){
//             Node* N = new Node(0);
//             N=t1;
//             a->next=N;
//             a=a->next;
//             t2=t2->next;
//         }
//     }else{
//         while(t1!=NULL){
//             Node* N=new Node(t1->val);
//             N=t2;
//             a->next=N;
//             a=a->next;
//             t1=t1->next;
//         }
//     }

//     return h;
// }

           // URVI MAM's APPROACH:-
// Node* mergeSortedLL (Node* &head1,Node* &head2){
//     Node* dummyHeadNode=new Node(-1) ;
//     Node* ptr1=head1;
//     Node* ptr2=head2;
//     NOde* ptr3=dummyHeadNode;
//     while(ptr1 && ptr2){
//         if (ptr1->val<ptr2->val){
//             ptr3->next=ptr1;
//             ptr1=ptr1->next;
//         }else{
//             ptr3->next=ptr2;
//             ptr2=ptr2->next;
//         }
//         ptr3=ptr3->next;
//     }

//     if (ptr1){
//         ptr3->next=ptr1;
//     }else{
//         ptr3->next=ptr2;
//     }
//     return dummyHeadNode->next;
// }


                 //5 . SORTING MULTIPLE LINKED LISTS.

                 //wrong as infinite loop crazzy thing see notebook.
// Node* mergeMultipleLL(Node* head1, Node* head2,Node* head3){
//     // if (head1==NULL && head2==NULL){
//     //     return h;
//     // }  here h not defined.


//     Node* t1=head1;
//     Node* t2=head2;
//     Node* h=NULL;
    
//     //BASE CASE:
//     // if (head1==NULL && head2==NULL && head3==NULL){
//     //     return h;
//     // }  
//     if (head1==NULL && head2==NULL){
//         return h;
//     }

//     //declaring head of NEW (CONNCECTED) LL.
//     if (t1->val<t2->val){
//         h=t1;
//         t1=t1->next;
//     }else{
//         h=t2;
//         t2=t2->next;
//     }
//     // sorting and connecting middle part
//     Node* a=h;
//     while(t1!=NULL && t2!=NULL){
//         if (t1->val<t2->val){
//             a->next=t1;
//             a=a->next;
//             t1=t1->next;
//         }
//         else{
//             a->next=t2;
//             a=a->next;
//             t2=t2->next;
//         }
//     }

//     // now either t1 reached to null or t2 reached to null
//     if (t1==NULL){
//         a->next=t2;
//         // t2=t2->next;
//     }else{
//         a->next=t1;
//         // t1=t1->next;
//     }
//     // return h; // function se bahar.

//     // return mergeMultipleLL(h,head3,NULL); what i am returning not defined 

//     Node* newHead=mergeMultipleLL(h, head3, NULL);
//     return newHead;
// }

          // approach 2: RIGHT ONE
//     Node* mergeSortedLL (Node* head1,Node* head2){
//     Node* dummyHeadNode=new Node(-1) ;
//     Node* ptr1=head1;
//     Node* ptr2=head2;
//     Node* ptr3=dummyHeadNode;
//     while(ptr1 && ptr2){
//         if (ptr1->val<ptr2->val){
//             ptr3->next=ptr1;
//             ptr1=ptr1->next;
//         }else{
//             ptr3->next=ptr2;
//             ptr2=ptr2->next;
//         }
//         ptr3=ptr3->next;
//     }

//     if (ptr1){
//         ptr3->next=ptr1;
//     }else{
//         ptr3->next=ptr2;
//     }
//     return dummyHeadNode->next;
// }

// Node* mergeMultiple(Node* &head1, Node* &head2, Node* &head3){
//     return mergeSortedLL((mergeSortedLL(head1,head2)),head3);
// }

          // URVI MAM:-
// Node* mergeSortedLL (Node* head1,Node* head2){
//     Node* dummyHeadNode=new Node(-1) ;
//     Node* ptr1=head1;
//     Node* ptr2=head2;
//     Node* ptr3=dummyHeadNode;
//     while(ptr1 && ptr2){
//         if (ptr1->val<ptr2->val){
//             ptr3->next=ptr1;
//             ptr1=ptr1->next;
//         }else{
//             ptr3->next=ptr2;
//             ptr2=ptr2->next;
//         }
//         ptr3=ptr3->next;
//     }

//     if (ptr1){
//         ptr3->next=ptr1;
//     }else{
//         ptr3->next=ptr2;
//     }
//     return dummyHeadNode->next;
// }

// Node* mergeKLL(vector<Node*> &lists){
//     if (lists.size()==0){
//         return NULL;
//     }
//     while(lists.size()>1){
//         Node* merged=mergeSortedLL(lists[0],lists[1]);
//         lists.push_back(merged);
//         lists.erase(lists.begin());
//         lists.erase(lists.begin());
//     }

//     return lists[0];
// }


             //QUE 6:MIDDLE ELEMENT
             // approach 1:
// int length (Node*&head){
//     Node* temp=head;
//     int counter=0;
//     while(temp!=NULL){
//         temp=temp->next;
//         counter++;
//     }
//     return counter;
// }

// Node* middle(Node* &head){
//     Node* temp=head;

//     int l=length(head);
//     int even=l/2-1;
//     int odd=l/2;

//     int tick=0;
//     if (l%2!=0){
//         while(tick<odd){
//             temp=temp->next;
//             tick++;
//         }
//         return temp;
//     }else{
//         while(tick<even){
//             temp=temp->next;
//             tick++;
//         }
//         return temp;
//     }
// }

                   // approach 2:
// Node* middle(Node* &head){
//     if (head->next==NULL){
//         return head; //single node

//     }
//     Node* slow=head;
//     Node* fast= head;
//     // while(fast!=NULL && fast->next!=NULL)// for baad wala in even 
//     while(fast->next!=NULL && fast->next->next!=NULL){// for pehle wala in even 

//         slow =slow->next;
//         fast=fast->next->next;
//     }
//     return slow;
// }

            //7 . DETECTING CYCLE IN A LINKED LIST
            // way 1: NULL THEN CYCLE BLOCK
// bool detectCycle (Node* &head){
//     Node* temp=head;
//     while(temp!=NULL){
//     temp->visited =true;
    
//     if (temp->next==NULL){ 
//         return false;
//     }

//     if ( temp->next->visited == true){
//         return true;
//     }

//     temp=temp->next;
//     }
// }
           // way 2: if dont wanna change CYCLE and NULL blocks

bool detectCycle (Node* &head){
    Node* temp=head;
    while(temp!=NULL){
    temp->visited =true;
    

    if (temp->next!=NULL && temp->next->visited == true){
        return true;
    }

    if(temp->next==NULL){
        return false;
    }
    temp=temp->next;
    }
}

            // WAY 3: lil more optimized + remove cycle
// bool detectCycle(Node* &head){
//     Node* temp=head;
//     while(temp!=NULL){
//         temp->visited=true;
//         if (temp->next!=NULL && temp->next->visited==true){
            
//             return true;
//         }
//         temp=temp->next;
//     }
//     return false;
// }


           //way4: urvi mam
// bool detectCycle(Node* &head){
//     if (!head)return false;

//     Node* slow=head; Node* fast=head;
//     while(fast && fast->next){
//         slow=slow->next;
//         fast=fast->next;
//         if (slow=fast){
//             cout<<slow->val<<endl;
//             return true;
//         }
//     }
//     return false;
// }



                      //REMOVING THE CYCLE TOO.
                      //ME:

                      // bool detectCycle(Node* &head){
// void untick(Node* &head){
//     Node* temp=head;
//     while(temp!=NULL){
//     temp->visited=false;
//     temp=temp->next;
//     }
//     return;
// }
// bool detectCycle(Node*& head){
//     Node* temp=head;
//     while(temp!=NULL){
//         temp->visited=true;
//         if (temp->next!=NULL && temp->next->visited==true){
//             temp->next=NULL;
//             untick(head);
//             return true;
//         }
//         temp=temp->next;
//     }
//     return false;
// }


            //urvi mam:
// bool detectCycle(Node* &head){
//     if (!head) return false;
//     Node* slow=head; Node* fast=head;
//     while(fast && fast->next){
//         slow=slow->next;
//         fast=fast->next->next;
//         if(slow==fast){
//             cout<<slow->val<<endl;
//             return true;
//         }
//     }
//     return false;
// }
                     // FLOYD'S ALGORITHM:-
// void removeCycle(Node* & head){
//     Node* slow=head;
//     Node* fast=head;
//     do {
//         slow=slow->next;
//         fast=fast->next->next;
//     }while(slow!=fast);

//     fast=head;
//     while(slow->next!=fast->next){
//         slow=slow->next;
//         fast=fast->next;
//     }

//     slow->next=NULL;
    
// }

         // MY REMOVE FUNCTION :-
// void removeCycle(Node* &head){
//     Node* temp=head;
//     while(temp!=NULL){
//         temp->visited=true;

//         if(temp->next!=NULL && temp->next->visited==true){
//             temp->next=NULL;
//             Node* t=head;
//             while(t!=NULL){
//                 t->visited=false;
//                 t=t->next;
//             }
//             return;
//         }
//         temp=temp->next;
//     }
// }

     //QUE 8: CHECK FOR PALINDROMIC LINKEDLISTS.

           // me:
// int length(Node* &head){
//     int count=0;
//     Node* temp=head;
//     while(temp!=NULL){
//         temp=temp->next;
//         count++;
//     }
//     return count;
// }

// bool isPalindrome(Node* &head){
//     if (head==NULL || head->next==NULL){
//         return false;
//     }
//     Node* temp=head;
//     int size=length(head);
//     int l=size/2;
//     int c=0;

//     //temp ko strting of other half pe le jao.
//     while(c<l){
//         temp=temp->next;
//         c++;
//     }


//     // Node* slow = head;
//     // Node* fast = head;
//     // while (fast->next && fast->next->next) {
//     //     slow = slow->next;
//     //     fast = fast->next->next;
//     // }

//     //temp is at strting of that other half.Now reverse the other half.
//     Node* prev=NULL;
//     Node* curr=temp;
//     while(curr!=NULL){
//         Node* nxt=curr->next;
//         curr->next=prev;
//         // curr=nxt;
//         prev=curr;
//         curr=nxt;
//     }
//     Node* newHead=prev;
//     //checking for palindrome.
    
//     Node* t1=head; 
//     Node* t2=newHead;
//     // while(t2!=NULL && t1->val==t1->next->val && t1!=NULL && t1!=t2){
//     while(t2!=NULL){
//     if (t1->val!=t2->val){
//         return false;
//     }
//     t1=t1->next;
//     t2=t2->next;
//     }
//     return true;
// }

                  //urvi mam:
// bool isPalindrome(Node* head){
//     Node* slow=head;
//     Node* fast=head;
//     while(fast && fast->next){
//         slow=slow->next;
//         fast=fast->next->next;
//     }

//     Node* curr=slow->next;
//     Node* prev=slow;
//     slow->next=NULL;
//     while(curr!=NULL){
//         Node* next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }

//     Node* head1=head;
//     Node* head2=prev;
//     while(head2){
//         if (head1->val!=head2->val){
//             return false;
//         }
//         head1=head1->next;
//         head2=head2->next;
//     }
//     return true;
// }

         //9. rotating the linked list by k nodes.
// void rotateLLbyK(Node* &head, int k){
    
//     while(k!=0){
//         Node*  temp=head;
//         while(temp->next->next!=NULL){
//             temp=temp->next;
//         }
//         Node* t=temp->next;
//         t->next=head;
//         temp->next=NULL;
//         head=t;
//         k--;
//     }
//     return ;
// }
                     //URVI MAM:
// Node* rotateLLbyK(Node* &head, int k){
//     //1 . finding length
//     int n=0;
//     //2. finding tail node
//     Node* tail=head;
//     while(tail->next!=NULL){
//         n++;
//         tail=tail->next;
//     }

//     n++;   //for including the last node too.
//     k=k%n;
//     if (k==0){  // k is multiple of n so no change.
//         return head;
//     }
    
//     tail->next=head;//imp.
//     // traversing n-k nodes and declaring n-k+1 th node as newhead.
//     Node* temp=head;
//     for (int i=1;i<n-k;i++){
//         temp=temp->next;
//     }
//     Node* newHead=temp->next;
//     temp->next=NULL;
//     return newHead;
// }

               //10. grouping all nodes with even indices after odd indices.
// Node* mergeOEindexes(Node* head){
//     if (!head && !head->next) return head;
//     Node* Ohead=head;
//     Node* Ehead=head->next;

//     //pointers to traverse and link
//     Node* t1=Ohead;
//     Node* t2=Ehead;
    
//     do{
//         t1->next=t1->next->next;
//         t1=t1->next;
//         t2->next=t2->next->next;
//         t2=t2->next;
//     // }while(t1 && t1->next && t2 && t2->next)
//     }while( t1->next && t2->next);

//     t1->next=Ehead;
//     return Ohead;
// }


          // urvi mam:
// Node* mergeOEindexes(Node* &head){
//     if (!head && !head->next) return head;
//     Node* evenHead=head->next;
//     Node* oddptr=head;
//     Node* evenptr=evenHead;
//     while(evenptr && evenptr->next){
//         oddptr->next=oddptr->next->next;
//         oddptr=oddptr->next;
//         evenptr->next=evenptr->next->next;
//         evenptr=evenptr->next;
//     }
//     oddptr->next=evenHead;
//     return head;
// }

          //11. REORDERING A LL

          // me :wrong:
// Node* reorderLL(Node* head){
//     Node* slow=head;
//     Node* fast=head;
//     // finding middle element 
//     while(fast && fast->next){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     // reversing ll (other half)
//     Node* curr=slow;
//     Node* pre=NULL;
//     while(curr){
//         Node* nxt=curr->next;
//         curr->next=pre;
//         pre=curr;
//         curr=nxt;
//     }
    
//     Node* t2=pre;  //pre new head;
//     Node* t1=head;
//     Node* c=head; // can make point to null; then t1 pe point
//     Node* chead=head;
//     // while(t2){
//     //     c->next=t2;
//     //     c=c->next;
//     //     t2=t2->next;

//     //     // if (!t2->next) return chead;  wrong

//     //     t1=t1->next;// abhi head par hi tha. now moved.
//     //     c->next=t1;
//     //     c=c->next;

//     //     if (!t1->next) return chead;
        
//     // }



//     return chead;
// }
        // me+ chatgpt: correct:

// Node* reorderLL( Node* &head){
//     Node* slow=head;
//     Node* fast=head;
//     while(fast && fast->next){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     Node* curr=slow;
//     Node* pre=NULL;
//     while(curr){
//         Node* nxt=curr->next;
//         curr->next=pre;
//         pre=curr;
//         curr=nxt;
//     }

//     Node* t1=head;
//     Node* t2=pre;
    
//     Node* chead=head;
//     while(t1 && t2){
//         Node* n1=t1->next;
//         Node* n2=t2->next;

//         t1->next=t2;
//         // if (t1==NULL){ break;}
//         if (!n1->next) break;
//         t2->next=n1;

//         t1=n1;
//         t2=n2;
//     }
//     return chead;
// }

               // URVI MAM:

// Node* reorderLL( Node* & head){
//     if (!head || !head->next || !head->next->next ) return head;
//     Node* slow=head;
//     Node* fast=head;
//     while( fast && fast->next){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     Node* curr=slow->next;
//     slow->next=NULL;
//     Node* pre=slow;
//     while( curr){
//         Node* nxt= curr->next;
//         curr->next= pre;
//         pre=curr; 
//         curr=nxt;
//     }
//     Node* ptr1=head;
//     Node* ptr2=pre;
//     while(ptr1!=ptr2){
//         Node* temp=ptr1->next;
//         ptr1->next=ptr2;
//         ptr1=ptr2;
//         ptr2=temp;
//     }

//     return head;
// }

               //12. SWAP TWO ADJACENT NODES.
               // me : method 1
// Node* swapAdjacent(Node* &head){
//     Node* pre=NULL;
//     Node* curr=head;
//     int counter=0;

//     while(curr!=NULL &&  counter< 2){
//         Node* nxt=curr->next;
//         curr->next=pre;
//         pre=curr; 
//         curr=nxt;
//         counter++;
//     }
//     if (curr!=NULL){
//         Node* newHead=swapAdjacent(curr);
//         head->next=newHead;
//     }

//     return pre;
// }

        // me: method 2 : wrong:
// Node* swapAdjacent(Node* &head){
//     Node* t=head;
//     Node* t1=head->next;
//     Node* newhead=t1;
//     while(t){
//         t->next=t1->next;
//         t1->next=t;
//         t=t->next;// t aage badd gya
//         if (!t && !t->next) break ;
//         t1=t->next;
//     }

//     return  newhead;
// }

              // URVI MAM:
Node* swapAdjacent(Node* &head){
    if (head==NULL || head->next==NULL){
        return head; // NULL bhi ok 

    }
        //recursive function:
        Node* secondHead=head->next;
        head->next=swapAdjacent(secondHead->next);
        secondHead->next=head;
        return secondHead;
}



int main(){
    linkedlist ll1,ll2 ;
    // ll1.add_end(1);
    // // ll1.add_end(2);
    // // ll1.add_end(3);
    // // ll1.add_end(4);
    // // ll1.add_end(5);
    // // ll1.add_end(6);
    // ll1.display();
    // ll2.head=swapAdjacent(ll1.head);
    // ll2.display();

    //QUE 2:
    // ll1.add_end(1);
    // ll1.add_end(2);
    // ll1.add_end(3);
    // ll1.add_end(4);
    // ll1.add_end(5);
    
    // ll2.add_end(6);
    // ll2.add_end(7);
    // // ll2.head->next->next=ll1.head->next->next->next;
    // Node* ans=interpt(ll1.head, ll2.head);
    // cout<<ans<<endl;
    

        // QUE 1:
        // cout<<equalLL(ll1.head , ll2.head);

        // QUE 3:
        // ll.head=removefrmLast(ll1.head,6);  if Node* rem...(Node* head,int lstpos)
        // removefrmLast(ll1.head,6);   .. Node* &head,..

        //QUE 4:
        // ll1.head=mergeSortedLL(ll1.head,ll2.head);
        // ll1.display();

        //QUE 5:
        // linkedlist ll1, ll2;
        // // ll1.add_begin(1);
        // // ll1.add_end(7);
        // // ll1.add_end(8);
        // for (int i=0;i<3;i++){
        //     // cin>>add_end(val);
        //     int value;
        //     cin>>value;
        //     ll1.add_end(value);
        // }
        // ll1.display();

        // ll2.add_begin(2);
        // ll2.add_end(4);
        // ll2.add_end(5);
        // ll2.display();

        // linkedlist ll3,ll4;
        // ll3.add_end(3);
        // ll3.add_end(6);
        // ll3.display();

        // vector<Node*> lists;
        // lists.push_back(ll1.head);
        // lists.push_back(ll2.head);
        // lists.push_back(ll3.head);

        // linkedlist mergedhead;
        // mergedhead.head=mergeKLL(lists);
        // mergedhead.display();


        // // ll4.head=mergeMultiple(ll1.head, ll2.head,ll3.head);
        // // ll4.display();


        //que 6:
         // ll1.add_begin(1);
        // ll1.add_end(2);
        // ll1.add_end(3);
        // ll1.add_end(4);
        // ll1.add_end(5);
        // // ll1.add_end(6);
        // ll1.display();
        
        // Node* middleNode=middle(ll1.head);
        // cout<<middleNode->val<<endl;

        // //or 
        // // cout<<middle(ll1.head)-> val;

        // QUE 7:

        ll1.add_begin(1);
        ll1.add_end(2);
        ll1.add_end(3);
        ll1.add_end(4);
        ll1.add_end(5);
        ll1.head->next->next->next->next->next=ll1.head->next->next;
        
        // ll1.display();
        
        cout<<detectCycle(ll1.head)<<endl;
    //     removeCycle(ll1.head);
    //     cout<<detectCycle(ll1.head)<<endl;
        // ll1.display();
    //     // cout<<detectCycle(ll1.head)<<endl;

    //QUE 8:
    // cout<<isPalindrome(ll1.head);
    
    //QUE 10:
    // ll2.head= mergeOEindexes(ll1.head);
    // ll2.display();

    //QUE 11:
    //  ll2.head=reorderLL(ll1.head);
    // ll2.display();



return 0;
}