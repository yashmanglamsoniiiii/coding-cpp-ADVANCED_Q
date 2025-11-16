                  //#Implementation:
// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int val;
//     Node* next;

//     Node(int data){ // contructor.
//         val=data;
//         next=NULL;
//     }
// };

// int main(){
//         // Node* n=new Node(1);
//         // cout<<n->val<<" "<<n->next<<endl;    //-----> 1  0  (output)

//         // Node *n1=new Node(2);
//         // Node *n2=new Node(3);
//         // n1->next=n2;
//         // //cout<<n1<<"->"<<n1->next<<"->"<<n1->next->next<<endl;//addressess!!!
//         // cout<<n1->val<<"->"<<n1->next->val<<"->"<<n1->next->next<<endl;//perfectly right.
//         //                          // n1-> next->next->val is null so segmentation error 
//         //                          // no output.
// return 0;
// }




// #include <iostream>
// using namespace std;

// class listNode{
//     public:
//     int val;
//     listNode* next;

//     listNode(int data){
//         val=data;
//         next=NULL;
//     }
// };

// void add_begin(listNode* &head , int value){//listNode &head (head by ref.) -> wrong
//                                               // by ref. to a pointer 
//     listNode* newNode=new listNode(value);
//     if (head==NULL){ // if uper tail bhi liya to head=tail=newNode;
//         // head=tail=newNode;  // tail not declared.
//         head==newNode;
//         return;
//     }
//     newNode->next=head;
//     head=newNode;
// }
// // newNode = head;

// // This makes the pointer newNode point to the same node as head.
// // It does NOT change the linked list or the head pointer.
// // After this, newNode and head both point to the same node.

// // head = newNode;

// // This updates the head pointer to point to the new node. 
// //Now, the new node becomes the first node of the linked list.

// void display(listNode* &head){
//     listNode* temp=head;
//     while(temp!=NULL){
//         cout<<temp->val<<"->";
//         temp=temp->next;
//     }
//     cout<<"NULL" <<endl;
// }

// //void add_end(Node* head,Node* tail,int value){
// //     Node* temp;
// //     temp=new Node(value);

// //     if (head==null){
// //         head=tail=newNode;
// //     }else{
// //         tail->next=newNode;
// //         tail=newNode;
// //     }
// // }

// void add_end(listNode* &head, int value){ // pass head by ref.
//     listNode *newNode=new listNode(value);
//     if (head==NULL){                //O(1) if tail pointer is passed direct tail->next=newNode;
//         head=newNode;
//     }
//     else{
//         listNode *temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         temp->next=newNode;
//         temp=newNode;//optional;
//     }
// }


// void insert(listNode* &head, int value, int pos){
//     listNode *newNode=new listNode(value);
//     if(pos<0){
//         cout<<"-1"<<endl;
//         // return -1;
//     }
//     if (pos==0){
//         add_begin(head, value);
//         return;
//     }
//     listNode *temp=head;
//     int current_pos=0;
//     while(current_pos!=pos-1  && temp!=NULL){  // while(temp<pos-1)--->we can't compare  a pointer and integer ********.
//         temp=temp->next;
//         current_pos++;
//     }
//     if (temp==NULL){
//         cout<<"out of position!"<<endl;
//         return;
//         //if return nhi likha to:-

//         //if temp == NULL, you print the message, 
//         //but you still try to access temp->next,
//         //jo niche code likha hai vo bhi chalega,
//         // which will cause a segmentation fault (crash)
//         // because temp is NULL.

//         //Always return after handling the error to avoid
//         // dereferencing a null pointer.
//         //[Dereferencing means accessing the value or 
//         //member pointed to by a pointer.]

//     }
//     newNode->next=temp->next;
//     temp->next=newNode;
// }
// // 0 based indexing###

// void update(listNode* &head, int value, int pos){  //O(n) worst case
//     if(pos<0){
//         cout<<"-1"<<endl;
//         // return -1;
//     } 
//     //pos>=0:-
//     listNode* temp=head;
//     // int curr_pos=0;
//     // while(curr_pos!=pos){//&& temp!=NULL bhi likh sakte hain. bas usme vo NULL tak bhi reach.
//     //     temp=temp->next;
//     //     curr_pos++;
//     // }

//     //OR:-

//     for (int i=0;i<pos;i++){ // "<"as jese hi pos pe pohocha temp,loop break and temp pos pe hi.
//         temp=temp->next;
//     }
//     if (temp==NULL){
//         cout<<"out of ll!!!"<<endl;
//         return;
//     }
//     temp->val=value;
// }

// void del_beg(listNode* &head){
//     if (head==NULL){
//         return;
//     }
//     listNode* temp=head;
//     head=head->next; //OR head=temp->next;
//     temp->next=NULL;
//     delete temp;
//     // free(temp); // can also use.
// }

// void del_end(listNode* &head){
//     if (head==NULL){
//         return;
//     }
//     listNode*temp=head;   // temp=second_last and tail= last 
//     while(temp->next->next!=NULL){
//         temp=temp->next;
//     }
//     // temp->next=NULL;  // isse last block ka add. gya and del nhi kar paye.
//     listNode* tail=NULL;
//     // temp->next=tail; // means temp->next=null also
//     tail=temp->next;
//     temp->next=NULL;
//     delete tail;

//     // CAN ALSO DO:-

//     // listNode* tail=temp->next;// OR  listNode* tail; then 2 line mei tail=temp->next;
//     // temp->next=NULL;
//     // free(tail);
// }


// void del_arb(listNode* &head , int pos){// O(n) worst case.
//     if (head==NULL){
//         del_beg(head);
//         return;
//     }
//     listNode* temp=head;  // temp= pre  and t= temp mam->names
//     for (int i=0;i<pos-1;i++){ 
//         temp=temp->next;
//     }
//     // or 
//     // int curpos=0;
//     // while(curpos!=pos-1){
//     //     temp=temp->next;
//     //     curpos++;
//     // }
//     listNode* t=temp->next;
//     temp->next=temp->next->next; // direct ye to agle wale ke add. not preserve and gya 
//                                    // then hum use delete nhi kar payenge.
//     t->next=NULL;    // instead of last two lines -> free(t);
//     delete t;
// }

// int main(){
//     listNode *head=NULL;
//    // listNode *tail=NULL;  not using this pointer.
//         listNode *n1=new listNode(1);
//         listNode *n2=new listNode(2);
//         n1->next=n2;
//         head=n1;
//         //tail=n2;

//         display(head);
//         add_begin(head, 3);
//         display(head);

//         add_end(head, 7);
//         display(head);
//         insert(head, 8,1);
//         display(head);
//         update(head, 9,1);
//         display(head);
//         // del_beg(head);
//         // display(head);
//         // del_end(head);
//         // display(head);
//         del_arb(head, 1);
//         display(head);
        
// return 0;
// }


