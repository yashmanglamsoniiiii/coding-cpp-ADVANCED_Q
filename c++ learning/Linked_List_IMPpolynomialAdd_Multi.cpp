//             my thought:-[SEE AT LAST]
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

//           
//         ll.display();
        
//similarly aisa ek aur linked list banao then temp->next-val=temp2-next-val to 
//           // temp-val+temp2-val ek naye ll mei store
 
// }



#include<iostream>
using namespace std;

class Node{
    public:
    int coeff;
    int powX;
    int powY;
    Node* next;
    Node(int c,int x,int y){
        coeff=c;
        powX=x;
        powY=y;
        next=NULL;
    }
};

class list{
    public:
    Node* head;
    list(){
        head=NULL;
    }

     


                 //THIS IS NOT ORDERNG PROPERLY 
                //  REASON: EQUALS TO BLOCK IS TOO DEEP INSIDE ****
    void insertTerm(int c,int x ,int y){
        Node* newNode=new Node(c,x,y);
        
        if (head==NULL || (head->powX+head->powY)<(x+y) ||
        ( ((head->powX+head->powY)==(x+y))  &&  (head->powX<x)) ){
            newNode->next= head;
            head=newNode;
            return;
        }

        // if head wali value= c
    if( head->powX==x && head->powY==y){
        head->coeff+=c;
        delete newNode;
        return;
    }



        // all terms in descending order.(power)
        Node* temp=head;
        while(temp->next!=NULL){
            // int total_power=x+y;
            if ((newNode->powX+newNode->powY)>(temp->next->powX+temp->next->powY)){
                //total power is greater than the next one.
            newNode->next=temp->next;
            temp->next=newNode;
            return;
            }
            else if ((newNode->powX+newNode->powY)==(temp->next->powX+temp->next->powY)){
                if (newNode->powX>temp->next->powX){//y<temp->next->y [= no warna else if no]
                    newNode->next=temp->next;
                    temp->next=newNode;
                    return;
                }

                // y ki power ko cater kiya niche:-

                if((newNode->powX<temp->next->powX) && (newNode->powY>temp->next->powY)){
                    // or simple else if ()  use without else.

                // OR =>"if (newNode->powY>temp->next->powY){ ""=> HAVE ALREADY CHECKED
                //  X WITH TEMP->NEXT->POWX VALUE SO IT IS SMALLER ONLY (X) SO JUST CHECK X.



    // if all barabar then coeff add.****
   //**  we have to add in newNode in value =>(NO)temp->coeff+=c;//or  newNode->coeff.
   //**  newNode->coeff+=temp->coeff;// why we are adding a new node just alter that value in node.

                    newNode->next=temp->next;
                    temp->next=newNode;
                    return;
                }//no else case

                if ((newNode->powX==temp->next->powX) && (newNode->powY==temp->next->powY))
                {
                    temp->next->coeff+=newNode->coeff ; // or c just
                    delete newNode;//prevent memory leak
                    return;
                }
            }

            else{
                    temp=temp->next;
            }
        }

        //iske bahar then we reached last node  and we have compared temp->next node 
        // therefore isko last mei lagana hai.
        newNode->next=temp->next;
        temp->next=newNode;
    }


     

   

};

  //BETTER ARRANGES PROPERLY AND PERFECTLY ADDING.

    void insertTerm_2(Node* & head,int c,int x,int y){  
        // if (head==NULL || (head->powX<x)  )
// no this is wrong  :-
// head -> 3x¹y²   (total power = 3)
// insert: 4x²y⁰   (total power = 2)--> my code insert this before head as 2>
    
    // before head 
    Node* n=new Node(c,x,y);
    if (head==NULL || ((x+y)>head->powX+head->powY) || 
    (( (x+y)==(head->powX+head->powY) && (head->powX<x) ))) {
        n->next=head;
        head=n;
        return;
    }

    // if head wali value= c
    if( head->powX==x && head->powY==y){
        head->coeff+=c;
        delete n;
        return;
    }

    //middle
    Node* temp =head;
    while(temp->next!=NULL){
        //comparing like terms:


        // if (((temp->powX==x) && (temp->powy==y)))=> wrong why
//         ex:5x^3 + 2x^2
//         [5,3]->[2,2]->null
//         That would compare 5x^3 (current node) with 3x^2 —
//         They’re not equal, so we would move forward and might miss the merging step.
//        therefore at alst it will add a new node as in code we are adding.

    if ((temp->next->powX==x)&& (temp->next->powY==y)){
        temp->next->coeff+=c;
        delete n;
        return;
    }

    //inserting terms in descending order:
    if ( (temp->next->powX+temp->next->powY)<(x+y)  ||
        ((temp->next->powX+temp->next->powY)==(x+y) && (x>temp->next->powX))){
            n->next=temp->next;
            temp->next=n;
            return;
        }
    temp=temp->next;
    }

    //insert at end:
    n->next=temp->next;    // higher order y power bhi last mei lag rhe.
    temp->next=n;
}

void display(Node* &head){
        if (!head){
            cout<<"0"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->coeff<<"x^"<<temp->powX<<"y^"<<temp->powY;
            if (temp->next!=NULL && temp->next->coeff>0){
                cout<<" + ";
            }
            temp=temp->next;
        }
        cout<<endl;
    }


Node* Add(Node* p1,Node* p2){
    Node* result=NULL;
    Node* t1=p1;
    
    while(t1!=NULL){
        insertTerm_2(result,t1->coeff,t1->powX,t1->powY);
        t1=t1->next;
    }

    Node* t2=p2;
    while(t2!=NULL){
        insertTerm_2(result,t2->coeff,t2->powX,t2->powY);
        t2=t2->next;
    }

    return result;
}

Node* mul(Node* &p1,Node* &p2){
    Node* result=NULL;
    Node* t1=p1;
    // Node* t2=p2;
    while(t1!=NULL){
        
        Node* t2=p2;
        while(t2!=NULL){
            int newC=t1->coeff*t2->coeff;
            int newX=t1->powX+t2->powX;
            int newY=t1->powY+t2->powY;
            insertTerm_2(result,newC,newX,newY);
            t2=t2->next;
        }
        //t2 is at null so nhi chalega therefore  t2 ko outer while loop ke ander.***
        t1=t1->next;
    }

    return result;
}

//another version of "mul"
Node* mul2(Node* &p1,Node* &p2){
    Node* result=NULL;
    for (Node* t1=p1;t1!=NULL;t1=t1->next){
        for(Node* t2=p2;t1!=NULL;t2=t2->next){
            int newC=t1->coeff*t2->coeff;
            int newX=t1->powX+t2->powX;
            int newY=t1->powY+t2->powY;
            insertTerm_2(result,newC,newX,newY);
            t2=t2->next;
        }
    }

    return result;
}



int main(){
    list p , pp;
    insertTerm_2(p.head,2,3,2);
    insertTerm_2(p.head,3,2,1);
    // insertTerm_2(p.head,5,0,2);
    // insertTerm_2(p.head,4,0,3);
    // insertTerm_2(p.head,6,0,0);
    display(p.head);

    insertTerm_2(pp.head,2,3,2);
    insertTerm_2(pp.head,3,1,2);
    insertTerm_2(pp.head,4,2,1);
    // insertTerm_2(pp.head,3,3,4);
    // insertTerm_2(pp.head,4,1,2);
    display(pp.head);

    list s,m;

    s.head=Add(p.head,pp.head);
    display(s.head);

    m.head=mul(p.head,pp.head);
    display(m.head);
    // Node* sum=Add(p,pp);


    // wrong:
    // s.head=Add(p,pp);
    // s.display();
    // correct:
    // two ways if display is in class list
    // 1. Node* Add(p,pp);
    //    fn mei bhi p.head, pp.head 
    // 2. ya class wala hi .
}