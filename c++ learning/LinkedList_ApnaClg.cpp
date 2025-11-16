// Linked List Implementation:


                                 //BASICS : IMP TO REVIEW MISTAKES.
// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int val;
//     Node* next;

//     Node(int data){// constructor -> to initialise value of that node.
//         val=data;
//         next=NULL; //if not written to error.
//     }
// };

// class List{   // for LinkedList Implementation -> to combine all Nodes formed.
//     Node* head;
//     Node* tail;
//     public:
//     List(){  // constructor -> to initialise value of pointers "head" &  "tail".
//         head=tail=NULL;
//     }

//     void push_front (int value){
//         Node* newNode=new Node(value);
//         if (head==NULL){
//             head=tail =newNode;
//             return;
//         }else{       // 'else'  keyword likhne ki not so much requirement 
//             newNode->next=head;
//             head=newNode;
//         }
//     }

//     void display(){
//         Node* temp=head;
//         if (head==NULL){
//             cout<<"-1"<<endl;
//             return;
//         }

//         while(temp!=NULL){
//             cout<<temp->val<<"->";
//             temp=temp->next;
//         }
//         cout<<"NULL"<<endl;
//     }

// };

// int main(){
//         //     // Node *n1(1); //constructor no here we need new nodes 
//         //    // Node *n2(2); //THESE WILL GIVE ERROR AS WE HAVEN'T CREATED NEW NODES

//          Node *n1=new Node(1);
//          Node *n2=new Node(2);
//          n1->next=n2; // these are pointers so * lagao.
//                       // abhi head not null if ye nhi to head null.


//          List ll;
//          ll.push_front(3);
//          ll.display();
                  // output:3->null

//              //You are not getting the output 3 -> 1 -> 2 -> NULL 
//              //because your List object (ll) is completely separate 
//              //from the nodes n1 and n2 that you created manually.
// return 0;
// }




// 1. Node* temp;

// This declares a pointer variable named temp that can point to a Node,
// but it does not point to any actual node yet (it is uninitialized until you assign it).
// Example: Node* temp = head; (now temp points to the head node).

//2. Node *n = new Node();

// This creates a new Node object on the heap using the constructor, 
//and n points to this new node.
// Memory is allocated for a new node, and you must delete it later to avoid memory leaks.



                            //MAIN:
// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int val;
//     Node* next;
//     Node (int data){
//         val=data;
//         next=NULL;
//     }
// };
//   // class list ko node mei hi merge kar sakte hain. but isse jada clear. as mam ne bataya.
// class List{
//     Node *head;
//     Node *tail;
//     public:
//     List(){
//         head=tail=NULL;
//     }
    
//     void push_front(int value){  //O(1)
//         Node *newNode=new Node(value);
//         if (head==NULL){
//             head=tail=newNode;
//             return;
//         }else{
//             newNode->next=head;
//             head=newNode;
//         }
//     }

//     void push_back(int value){//O(1)
//         Node *newNode= new Node(value);
//         Node *temp=head;
//         if (head==NULL){
//             tail=head=newNode;
//             return;
//         }else{
//             while(temp->next!=NULL){
//                 temp=temp->next;   // traversing a linked list.
//             }
//             temp->next=newNode;
//             tail=newNode;      // next ko humne by default null pe rakha hai in const. of Node class.
//         }
//     }

//     void pop_front(){//O(1)
//         Node *temp=head;
//         if (head==NULL){
//             cout<<"empty linkedlist."<<endl;
//             return;
//         }else{
//             //Node *temp=head;
//             head=temp->next;  //OR head=head->next;  // head to aage push;
//             temp->next=NULL;  // connection break;
//             delete temp;
//         }
//     }

//     void pop_back(){//O(n) worst case
//         if (head==NULL){
//             cout<<"-1"<<endl;
//             return;
//         }
//         Node *temp=head;
//         while(temp->next!=tail){// or temp->next->next!=NULL
//             temp=temp->next;
//         }
//         temp->next=NULL;
//         delete tail;
//         tail=temp;
//     }

//     void insert(int value, int pos){//O(n)
//         if (pos<0){
//             cout<<"-1"<<endl;
//             return;
//         }
//         if (pos==0){
//             push_front(value);
//             return;
//         }
//         Node *temp= head;
//         for (int i=0;i<pos-1;i++){     // OR  for(int i=0;i<pos-1 && temp!=NULL; i++)
//             if (temp==NULL){
//                 cout<<"invalid position\n";  // if position is greater than ll size
//                 return;
//             }
//             temp=temp->next;
//         }
//         Node *newNode=new Node(value);
//         newNode->next=temp->next; // aage wale sabhi nodes ka address preserve isse.
//         temp->next=newNode;
//     }
//     // HERE IN THE FOR LOOP:  (HAMARA TEMP PHELE HI POS -1 PE HAI)
//     // for (int i=0;i<=pos-1;i++){
//     //         temp=temp->next;
//     //     }                     
//     // OBSERVE THIS THAT OUR TEMP IS ALREADY AT HEAD NODE AND IT POINTS AT 1 ,
//     // IF I<=POS-1 => I=0 WHEN POS(4,1) TO (i=0;i<=0;i++)=> so loop runs once .
//     // temp moves to 2 now and  1-> 2-> 4-> 3->null 
    
//     // THEREFORE WE (i=0;i<=pos-1;i++)=> here insert(4,1)=> i=0;i<0;i++
//     // so loop doesn't run and temp remains at head so we get
//     // 1->4->2-> 3-> null

//     // ANOTHER IMP POINT:
//     // "0"based indexing:-
//     // i=0;i<pos-1;i++  => so we give input like insert(4,1)

//     // for like a user => 
//     //we can also use normal indexing=> i=1;i<pos-1;i++ =>insert(4,2)
//     // THEN BAKI ki uper wali condn mei bhi pos<1 and pos==1 hoga.(TO MAKE IT ALIGN WITH THIS)
//     // OUTPUT SAME:1->4->2-> 3-> null
    
    
//     int search (int key){//O(n) worst case
//         Node *temp=head;
//         int idx=0;
//         while(temp!=NULL){
//             if (temp->val==key){
//                 return idx;
//             }
//             idx++;
//             temp=temp->next;
//         }
//         return -1; 
//         //OR:-
//         // if (temp==NULL){
//         //     return -1;
//         // }
//     }


//     // ALITER SEARCH:-


//     // void search (int key){//O(n)
//     //     Node *temp=head;
//     //     int idx=0;
//     //     while(temp!=NULL){
//     //         if (temp->val==key){
//     //             cout<<idx<<endl;
//     //             return ; // if yahan return nhi likha to loop idx print karne ke baad bhi 
//     //                      //chalega and -1 bhi print hoga.
//     //         }
//     //         idx++;
//     //         temp=temp->next;
//     //     }
//     //     cout<<"-1"<<endl;    // ye bhi sahi hai as if pura loop chala and nhi mila to ye hi 
//     //                          // print hoga.

//     //     //OR:-

//     //     // if (temp==NULL){   // if puri list chal li and temp =null to hai hi nhi key (value).
//     //     //     cout<<"-1"<<endl;
//     //     // }
//     // }


//     void display(){//O(n)
//         Node *temp=head;
//         if (head==NULL) {
//             cout<<"-1"<<endl;
//             return;
//         }
//         while(temp!=NULL){
//             cout<<temp->val<<"->";
//             temp=temp->next;// ye nhi to infi loop. as two nodes and temp never null
//         }
//         cout<<"NULL"<<endl;
//     }

// };
// int main(){
//         List ll;
//         // ll.push_front(2);
//         // ll.push_front(1);
//         // //ll.display();

//         // ll.push_back(3);
//         // //ll.display();

//         // ll.push_back(5);
//         // ll.push_back(6);
//         // ll.display();
//         // ll.pop_front();
//         // ll.display();
//         // ll.pop_back();
//         // ll.display();

//     // insert function:
//     // ll.push_front(3);
//     // ll.push_front(2);
//     // ll.push_front(1);
//     // ll.display();
    
//     // ll.insert(4,1);
//     // ll.display();

//     //search fun.
//     ll.push_back(1);
//     ll.push_back(2);
//     ll.push_back(3);
//     ll.push_back(4);

//     ll.display();
//     cout<<ll.search(5);
        
// return 0;
// }


                           // DOUBLY LINKED LIST
// #include <iostream>
// using namespace std;
// class Node {
//     public:
//     int val;
//     Node* next;
//     Node* pre;
//     Node(int data){
//         val=data;
//         next=pre=NULL;
//     }
// };

// class Doublyll{
//     Node* head;
//     Node* tail;
//     public:
//     Doublyll(){
//         head=tail=NULL;
//     }

//     void push_front(int value){
//         Node* newNode= new Node(value);
//         if (head==NULL){
//             head=tail=newNode;
//         }else{                // ye wala part in else only ya if mei return .
//                                  // as othw. ye part execute & head->pre= newNode(single)
//                                  //crash .
//         newNode->next=head;
//         head->pre=newNode;
//         head=newNode;
//         }
//     }

//     void display(){
//         Node* temp=head;
//         while(temp!=NULL){ // means last node pe bhi iterate to last node print 
//                             // but temp-> next !=NULL means last node pe not iterate (no print)
//             cout<<temp->val<<" <=> ";
//             temp=temp->next;
//         }
//         cout<<"NULL"<<endl;
//     }

//     void push_back(int value){
//         Node* newNode=new Node(value);
//         if (head==NULL)  head=tail=newNode;

//         //time complexity O(n)
//         Node* temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         temp->next=newNode;
//         newNode->pre=temp;
//         tail=newNode;

//         //aliter : TC=O(1)
//         // tail->next=newNode;
//         // newNode->pre=tail;
//         // tail=newNode;
        
//     }



//                              //ME:  my code handles one node case
//     // void pop_front(){
//     //     if (head==NULL){
//     //         cout<<"empty/n";
//     //         return;
//     //     }
//     //     if (head->next==NULL){
//     //         delete head;                   // if only one node
//     //         tail =NULL ; // chatgpt sugg.
//     //     return;
//     //     }

//     //     else{
//     //         Node* temp=head;
//     //         head=head->next;
//     //         head->pre = temp->next = NULL;
//     //         delete temp;
//     //     }
//     // }

//                          //shraddha mam : one node case handling with style.
//     void pop_front (){
//         if (head==NULL){
//             cout<<"empty/n";
//             return;         
//         }
//         Node* temp=head;
//         head=head->next;
//         if (head!=NULL){
//             head->pre=NULL;
//         }
//         temp->next=NULL;
//         delete temp;
//     }

//                              //ME : 
// // void pop_back(){
// //     if (head==NULL){
// //         cout<<"empty/n";
// //         return;
// //     }
// //     if (head->next==NULL){
// //         delete head;
// //         return;
// //     }
// //     Node* temp=tail;
// //     tail=tail->pre;
// //     tail->next= temp->pre=NULL;
// //     delete temp;
// // }
                    
//                             //SHRADDHA MAM STYLE:
// void pop_back(){
//     if (head==NULL){
//         cout<<"empty/n";
//         return;
//     }
//     Node* temp=tail;
//     tail=tail->pre;
//     if (tail!=NULL){
//         tail->next=NULL;
//     }
//     temp->pre=NULL;
//     delete temp;
// }
// };


// int main(){
//         Doublyll dll;
//         dll.push_front(3);
//         dll.push_front(2);
//         dll.push_front(1);
//         dll.push_back(4);
//         dll.display();
//         // dll.pop_front();
//         dll.pop_back();
//         dll.display();
// return 0;
// }


                       //CIRCULAR LINKED LIST:-
#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node(int data){
    val=data;
    next=NULL;
    }
};

class circularll{
    Node* head;
    Node* tail;
    public:
    circularll(){
        head=tail=NULL;
    }
    void add_begin(int value){
        Node* newNode=new Node(value);
        if (head==NULL){
            head=tail=newNode;
            tail->next=head;  // else likhne ki jagah yahan return bhi likh sakte hain.
        }
        else{
            newNode->next =head;
            head=newNode;
            tail->next=head;// newNode(or)
            // if  head is not given:-
            //newNode->next=tail->next;
            // tail->next=newNode;
            // tail->next=head; // not req.
        }
    }

    // void display(){
    //     Node* temp=head;
    //     while(temp->next!=head){
    //         cout<<temp->val<<"->";
    //         temp=temp->next;
    //     }
    //     cout<<temp->val<<"->"<<"head"<<endl;
    // }

    // SHRADDHA MAM:-
    void display(){
        if (head==NULL) return;

        cout<<head->val<<"->";
        Node* temp=head->next;
        while(temp!=head){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<temp->val<<endl;
    }

    void append(int value){
        Node* newNode=new Node(value);
        if (tail==NULL){
            head=tail=newNode;
            tail->next=head;
        }
        else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }

                // me:-
//     void del_head(){
//         if (head==NULL){
//             cout<< "empty cll"<<endl;
//             return;
//         }
//         if (head->next==head){
//             delete head;
//             return;
//         }
//         Node* t=head->next;
//         head->next=NULL;
//         tail->next=t;
//         // head->next=NULL;
//         delete head;
//         head=t;
//     }



         // mam:-
void del_head(){
    if (head==NULL){
        return ;
    }
    if (head==tail){
        delete head;
        head=tail=NULL;
        return ;
    }
    Node* temp=head;
    head=head->next;
    tail->next=head;
    temp->next=NULL;
    delete temp;
}

                // me:-
// void delete_tail(){
//     if (head==NULL){
//         return; 
//     }
//     else if (head==tail){
//         delete head;
//         head=tail=NULL;
//     }
//     else{
//         Node* t=head;
//         while(t->next!=tail){
//             t=t->next;
//         }
//         t->next=head;
//         tail->next=NULL;
//         delete tail;
//         tail=t;
//     }
// }

               //mam:-
void delete_tail(){
    if (head==NULL){
        return;
    }
    else if(head==tail){
        delete head;
        head=tail=NULL;
    }
    else{
        Node* temp=tail;
        Node* pre=head;
        while(pre->next!=tail){
            pre=pre->next;
        }
        tail=pre;
        tail->next=head;
        temp->next=NULL;
        delete temp;
    }
}


};
int main(){
        circularll cll;
        cll.add_begin(3);
        cll.add_begin(2);
        cll.add_begin(1);
        cll.append(4);
        cll.append(5);
        cll.display();

        cll.delete_tail();
        cll.display();
return 0;
}