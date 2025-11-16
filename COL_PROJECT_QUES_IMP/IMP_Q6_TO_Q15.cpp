//                    //QUES 6 VERY IMP.
//                         //100% correct.
// #include <iostream>
// using namespace std;
                
// class Node{
//     public:
//     int val;
//     Node* next;
//     Node(int value){
//         // value=val;//garbage or zero values(me garbage value)
//         val=value;
//         next=NULL;
//     }
// };

// class listNode{
//     public:
//     Node* head;

//     // public:
//     listNode(){
//         head=NULL;
//     }

//     void add_begin(int value){
//         Node* newNode=new Node(value);
//         if (head==NULL){
//             head=newNode;
//         }else{
//             newNode->next=head;
//             head=newNode;
//         }
//         return ;
//     }

//     void add_end(int value){
//         Node* newNode=new Node(value);
//         if (head==NULL){
//             head=newNode;
//         }else{
//             Node* temp=head;
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }
//             temp->next=newNode;
//         }
//         return;
//     }

//     void del_begin(){
//         if (head==NULL){
//             return;
//         }
//         if (head->next==NULL){
//             delete head;
//             return ;
//         }
//         else{
//             Node* temp=head;
//             head=head->next;
//             temp->next=NULL;
//             delete temp;
//         }
//         return;
//     }


//     void del_end(){
//         if (head==NULL){
//             return;
//         }
//         if(head->next==NULL){
//             delete head;
//         }else{
//             Node* temp=head;
//             while(temp->next->next!=NULL){
//                 temp=temp->next;
//             }
//             Node* t=temp->next;   // 2 ptrs :temp->next!=tail; then t=tail;then tail=temp;tail->next=null ;delete t;
//             temp->next=NULL;
//             delete t;
//         }
//         return;
//     }

//     void del_arbitrary(int pos){
//         if (pos==0){
//             del_begin(); return;
//         }
//         Node* temp=head;
//         int count=0;
//         while(temp!=NULL && count<pos-1 ){
//             temp=temp->next;
//             count++;
//         }
//         Node* temp2=temp->next;
//         temp->next=temp2->next;
//         temp2->next=NULL;
//         delete temp2;
//     }

//     void display(){
//         if (head==NULL){
//             return;
//         }else{
//         Node* temp=head;
//         while(temp!=NULL){
//             cout<<temp->val<<"->";
//             temp=temp->next;
//         }
//         cout<<"NULL"<<endl;
//         return;
//     }
// }
// };

//     void insertSorted(Node* &head, int value){
//         Node* newNode=new Node(value);
//         if (head==NULL){
//             head=newNode;
//             return;
//         }else{
//         Node* temp=head;
//         Node* tail=head;
//         while(tail->next!=NULL){
//             tail=tail->next;
//         }
//         // three cases :
//         // head ke aaage , tail ke peeche , kahin beech mei
//         if (newNode->val<=head->val){
//             newNode->next=head;
//             head=newNode;
//         }else if (tail->val<=newNode->val){
//             tail->next=newNode;
//             tail=newNode;
//         }else{
//         while(temp->next!=NULL){  // head and tail ke beech mei

//             //temp agar last node (tail par ) aaya to loop ke bahar no checking therefore no need for temp->next->next
//             // varna second last node will not checked.


//             //temp->next so if tail par temp to tail->next-val [crash code].
//             if  (temp->next->val>newNode->val && temp->val<=newNode->val){
//                 Node* temp2=temp->next;
//                 newNode->next=temp2;
//                 temp->next=newNode;
//                 break;
//             }
//             temp=temp->next;
//         }

//         }

//         }
//     }
//     // bugs:
//     // 1. most imp ->single node case.
//     // Your approach splits into 3 cases (before head, after tail, between). 
//     // That's OK. But the way you handle the between case depends on while(temp->next != NULL). 
//     // If the list is length 1 (so temp->next == NULL) 
//     // but the new node should be inserted between head and tail (which are the same node),
//     //  the loop is skipped and nothing happens.

//     //2.
//     // You used temp->next->val > newNode->val && temp->val <= newNode->val. 
//     // That condition is okay for many middle insertions but it assumes there is a '"temp->next."' 
//     // If temp->next is NULL, you never check insertion point.
// // temp = 1 (ok)
// // temp = 5 (ok)
// // temp = 10 (tail) → now temp->next == NULL, so loop stops immediately.
// // And since nothing was inserted, the function exits without adding the new node.


//             //another version of this question.[optimized]
//     void insertSorted_2(Node* &head,int value){
//         Node* newNode=new Node(value);
//         if (head==NULL || value<head->val){
//             newNode->next=head;
//             head=newNode;
//             return;
//         }
//         Node* temp=head;
//         while(temp->next!=NULL && temp->next->val<newNode->val){//equals to wala case bhi handled
//             temp=temp->next;
//         }

//         newNode->next=temp->next;
//         temp->next=newNode;
//     }

// int main(){
//         listNode ll1;

//         insertSorted_2(ll1.head,5);
//         insertSorted_2(ll1.head,3);
//         insertSorted_2(ll1.head,10);
//         insertSorted_2(ll1.head,1);
//         insertSorted_2(ll1.head,2);
//         insertSorted_2(ll1.head,3);

//         ll1.display();
// }




//                    //QUES 6 VERY IMP.
//                         //100% correct.
// #include <iostream>
// using namespace std;
                
// class Node{
//     public:
//     char val;
//     Node* next;
//     Node(char value){
//         // value=val;//garbage or zero values(me garbage value)
//         val=value;
//         next=NULL;
//     }
// };

// class listNode{
//     public:
//     Node* head;

//     // public:
//     listNode(){
//         head=NULL;
//     }

//     void add_begin(char value){
//         Node* newNode=new Node(value);
//         if (head==NULL){
//             head=newNode;
//         }else{
//             newNode->next=head;
//             head=newNode;
//         }
//         return ;
//     }

//     void add_end(char value){
//         Node* newNode=new Node(value);
//         if (head==NULL){
//             head=newNode;
//         }else{
//             Node* temp=head;
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }
//             temp->next=newNode;
//         }
//         return;
//     }

//     void del_begin(){
//         if (head==NULL){
//             return;
//         }
//         if (head->next==NULL){
//             delete head;
//             return ;
//         }
//         else{
//             Node* temp=head;
//             head=head->next;
//             temp->next=NULL;
//             delete temp;
//         }
//         return;
//     }


//     void del_end(){
//         if (head==NULL){
//             return;
//         }
//         if(head->next==NULL){
//             delete head;
//         }else{
//             Node* temp=head;
//             while(temp->next->next!=NULL){
//                 temp=temp->next;
//             }
//             Node* t=temp->next;   // 2 ptrs :temp->next!=tail; then t=tail;then tail=temp;tail->next=null ;delete t;
//             temp->next=NULL;
//             delete t;
//         }
//         return;
//     }

//     void del_arbitrary(int pos){
//         if (pos==0){
//             del_begin(); return;
//         }
//         Node* temp=head;
//         int count=0;
//         while(temp!=NULL && count<pos-1 ){
//             temp=temp->next;
//             count++;
//         }
//         Node* temp2=temp->next;
//         temp->next=temp2->next;
//         temp2->next=NULL;
//         delete temp2;
//     }

//     void display(){
//         if (head==NULL){
//             return;
//         }else{
//         Node* temp=head;
//         while(temp!=NULL){
//             cout<<temp->val;
//             temp=temp->next;
//         }
//         cout<<endl;
//         return;
//     }
// }
// };


// int main(){
//         listNode ll;
//         ll.add_end('3');
//         ll.add_end('x');
//         ll.add_end('+');
//         ll.add_end('4');
//         ll.add_end('y');
//          ll.add_end('+');
//           ll.add_end('5'); 
//           //similarly aisa ek aur linked list banao then temp->next-val=temp2-next-val to 
//           // temp-val+temp2-val ek naye ll mei store 
//         ll.display();
       

        
// }


//Q11.Write a program 
// to display a linked list in reverse order 
// (last node to first node) using a stack.


#include <iostream>
#include <stack>    // for std::stack
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert a node at the end
void insert(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display linked list normally
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to display linked list in reverse using a stack
void displayReverse(Node* head) {
    stack<int> st;
    Node* temp = head;

    // Push all node data into stack
    while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Pop and print
    cout << "Reversed List: ";
    while (!st.empty()) {
        cout << st.top() << " -> ";
        st.pop();
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Original List: ";
    display(head);

    displayReverse(head);

    return 0;
}
