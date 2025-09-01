// CLASS -> fundamental unit of OOPS
//user defined data types.
//define some data/properties and methods / functions.

// OBJECTS are VARIABLES OF TYPE CLASS.

// #include <iostream>
// using namespace std;

// class fruit{
//     public:
//     string name;
//     string colour;
//     int price;
// };

// int main(){
//     // creation of OBJECTS
//     fruit f1, f3;
//     f1.name="apple";
//     f1.colour="red";
//     f1.price=12;
//     cout<<f1.name<<" - "<<f1.colour<<" - "<< f1.price<<endl;

//     //creation of POINTERS   --> another way of creating obj.(new keyword)
//     fruit* f2=new fruit();   // pointer variables
//     f2->name="banana";
//     f2->colour="yellow";
//     f2->price=10;
//     cout<<f2->name<<" - "<<f2->colour<<" - "<< f2->price<<endl;
        
// return 0;
// }



// CONSTRUCTORS       &      DESTRUCTORS
// #include <iostream>
// using namespace std;

// class arearect{
//     public:
//     int l;
//     int b;

//     arearect(){   // default const. ( WITH NO ARGUMENTS)
//         l=0;
//         b=0;
//     }
    
//     arearect(int x, int y){  // parameterized const.( WITH ARGUMENTS ) 
//         l=x;                  // if no arg is passed --> 0 0
//         b=y;
//     }

//     arearect(arearect& r){  // copy const. (initialising an obj with another existing obj.)
//         l=r.l;
//         b=r.b;
//     }

//     ~arearect(){   // destructor.
//         cout<<" destructor is called! "<<endl; 
//     }
      //deletes obj.s
// };
// int main(){

//         arearect *a =new arearect();  
//         cout<<a->l<<" "<<a->b<<endl;
//         delete a;       // pointer variables aise delete kar sakte hain.
//         // here pehle destructor called.

//         arearect r1;
//         cout<<r1.l<<" "<<r1.b<<endl;

//         arearect r2(2,3);
//         cout<<r2.l<<" "<<r2.b<<endl;

//         arearect r3=r2;     // same work like copy const. without creating it.
//         cout<<r3.l<<" "<<r3.b<<endl;

//         arearect r4=r2;    // with copy const.
//         cout<<r4.l<<" "<<r4.b<<endl;
//         // destructor is called automatically.

// return 0;
// }


// ENCAPSULATION
// #include <iostream>
// using namespace std;

// class trial{
//     int x;

//     public:
//     int set(int n){
//         x=n;
//     }
//     void get(){
//         cout<<x<<endl;
//     }
//     // aliter to get x
//     int getter(){
//         return x;
//     }
    
// };

// int main(){
//     // ABC f1=4;// can't access directly;
//     trial obj;
//     obj.set(4);          // set / put the value of x.
//     obj.get();          //get /cout the data of x.
//     cout<<obj.getter(); // aliter option to cout.
    
// return 0;
// }

// ACCESS MODIFIERS &   INHERITENCE:
// #include <iostream>
// using namespace std;

// class parent{
//     private:
//     int x;
//     public:
//     int y;
//     protected:
//     int z;

// };

// class child1 : public parent{ //inherited classes->normal classes with ek class ke var.in use
//     // here
//     // x -> inaccessible
//     // y-> public
//     //z-> protected
// };
// class child2 : protected parent{
//     //here
//     // x-> inaccessible
//     //y-> protected 
//     //z-> protected
// };
// class child3 : private parent{
//     //here
//     //x-> inaccessible
//     // y-> private
//     //z-> private
// }

// int main(){
//         parent p;
//         p.y;  //can't use x and z
// return 0;
// }

// SINGLE INHERITENCE:
// #include <iostream>
// using namespace std;

// class parent{   // parent class --> base class
//     public:
//     parent(){
//         cout<<"p"<<endl;
//     }
// };
// class child : public parent{
//     public:
//     child(){
//         cout<<"c"<<endl;
//     }
// };

// int main(){
//         child c1;
// return 0;
// }


// MULTI-LEVEL INHERITENCE:
//EX.1

// #include <iostream>
// using namespace std;

// class parent{
//     public:
//     parent(){
//         cout<<"p"<<endl;
//     }
// };

// class child : public parent{
//     public:   // if not written this to private..as said it is a normal class with inheritedness
//     child(){
//         cout<<"c"<<endl;
//     }
// };

// class grandchild : public child{  // here child is the parent class which inh. from 'parent'
//     public:                       // class.
//     grandchild(){
//         cout<<"gc"<<endl;
//     }
// };


// int main(){
//         grandchild gc1;
// return 0;
// }
                                //output:
                                   //p
                                   //c
                                   //gc

// EX.2  --> my exp. learning

// #include <iostream>
// using namespace std;

// class Animal{ // base / parent class.
//     private:
//     string type;
//     public:
//     int price;
//     string setType(string a){
//         type=a;
//         return type;  // imp . return nhi to getType mei kuch hoga.
//     }


//                  // string getType(string x){
//                  //     x=type;                   // aise to to x dala vo aayega . 
//                  //     return x;
//                  //}


//     string getType(){
//         return type;
//     }
// };

// class dog : public Animal{
//     public: 
//     int setter(int n){   // not needed but aise hi.
//         price=n;
//     }
//     void getter(){
//         cout<<price<<endl;
//     }
// };
// int main(){
//         dog d1;

//         d1.setter(89000);
//         d1.getter();

//         // d1.type="cat";// here error comes as dog class cant access 'type' private.
//         d1.setType("cat");      
//         cout<<d1.getType()<<endl;

// return 0;
// }

//EX.3:

// #include <iostream>
// using namespace std;

// // Base class
// class Animal {
// public:
//     void eat() {
//         cout << "I can eat" << endl;
//     }
// };

// // Derived class 1
// class Dog : public Animal {
// public:
//     void bark() {
//         cout << "I can bark" << endl;
//     }
// };

// // Derived class 2
// class Puppy : public Dog {
// public:
//     void weep() {
//         cout << "I can weep" << endl;
//     }
// };

// int main() {
//     Puppy puppy;    // puppy can access all things from dog and animal as --> public.

//     puppy.eat();   // Inherited from Animal class
//     puppy.bark();  // Inherited from Dog class
//     puppy.weep();  // Defined in Puppy class

//     return 0;
// }


                                 // MULTIPLE INHERITENCE
//EX.1:
// #include <iostream>
// using namespace std;

// class parent1{
//     public:
//     parent1(){
//         cout<<"p1"<<endl;
//     }
// };

// class  parent2{
//     public:
//     parent2(){
//         cout<<"p2"<<endl;
//     }
// };

// class child: public parent1, public parent2{
//     public:
//     child(){
//         cout<<"child"<<endl;
//     }
// };

// int main(){
//         child bachcha;
// return 0;
// }

// EX .2
// #include <iostream>
// using namespace std;
// class country{
//     public:
//     void desh(){
//         cout<<"This is a country."<<endl;
//     }
// };
// class city{
//     public:
//     void shahar(){
//         cout<<"This is a city."<<endl;
//     }
// };

// class village : public country, public city{
//     public:
//     void gaon(){
//         cout<<"This is a village."<<endl;
//     }
// };

// int main(){
//         village v1;
//         v1.shahar();   // randomly in any order we can call.
//         v1.desh();
//         v1.gaon();

// return 0;
// }


// HIERARCHICAL INHERITENCE.
// #include <iostream>
// using namespace std;

// class parent1{
//     public:
//     parent1(){
//         cout<<"p1"<<endl;
//     }
// };

// class  child1 : public parent1{
//     public:
//     child1(){
//         cout<<"c1"<<endl;
//     }
// };

// class child2: public parent1{
//     public:
//     child2(){
//         cout<<"c2"<<endl;
//     }
// };

// int main(){
//         child1 bachcha1;
//         child2 bachcha2;
// return 0;
// }

// HYBRID INHERITENCE:
// #include <iostream>
// using namespace std;
// class a{   // base/parent class
//     public: 
//     a(){
//         cout<<"a"<<endl;
//     }
// };
// class b : public a{ // derived class
//     public: 
//     b(){
//         cout<<"b"<<endl;
//     }
// };
// class c : public a{ // derived class
//     public: 
//     c(){
//         cout<<"c"<<endl;
//     }
// };
// class d : public c{ // derived class2 with parent class c
//     public: 
//     d(){
//         cout<<"d"<<endl;
//     }
// };
// int main(){
        
// return 0;
// }

// DIAMOND PROBLEM:
// #include <iostream>
// using namespace std;

// class parent{
//     public:
//     parent(){
//         cout<<"p"<<endl;
//     }
// };
// class child1 : public parent{
//     public:
//     child1(){
//         cout<<"c1"<<endl;
//     }
// };
// class child2 : public parent{
//     public:
//     child2(){
//         cout<<"c2"<<endl;
//     }
// };
// class grandchild : public child1, public child2{
//     public:
//     grandchild(){
//         cout<<"gc"<<endl;
//     }
// };
// int main(){
//         grandchild gc1;
// return 0;
// }
                                 //output:
                                 //p
                                 //c1
                                 //p
                                 //c2
                                 //gc


                                   //POLYMORPHISM:
                                   // compile time:
                                   //function overloading:
// #include <iostream>
// using namespace std;

// class add{ // class and function name shouldn't be same.
//     public :
//     void sum(int x,int y){
//         cout<<x+y<<endl;
//     }
//     void sum(float x , float y){
//         cout<<x+y<<endl;
//     }
// };
// int main(){
//         add s;
//         s.sum(2,3);
//         s.sum(float(4.5),float(4.3));  // when calling float explicitly or change datatype to 
// return 0;                        // double uper in class fn. aise likhna nhi padega double()
// }
                                    
                                    //operator overloading:
// #include <iostream>
// using namespace std;

// class complex{
//     int real;
//     int img;
//     public:
//     complex(int x, int y){
//         real=x;
//         img=y;
//     }
//     void print(){
//         cout<<real<<"+"<<img<<"i"<<endl;
//     }
    
//     complex operator+ (complex &c){   // operator is the keyword. simple 
//         complex ans(0,0);       // unary.
//         ans.real=real+c.real;
//         ans.img=img+c.img;
//         return ans;

                      // treat  -> 'opertor.'  like this:
                      //then c1.c2 -> c1 is object , 
                      //'.' is the operator which works on c1.
                      // c2 is passed as an argument.

//     }
// };
// int main(){
//         complex c1(1,2), c2(2,3);  
//         //khali contr. chodd  diya. -->co. c1, c2 then nxt line c1(1,2)  ->no .
//         // if i write directly c1+c2 then it doesn't know anything to add complex no.
        
//         complex c4=c1+c2;
//         c4.print();
// here we have real and img in public so print ki no need .

// return 0;
// }

                   // PART 2:
// #include <iostream>
// using namespace std;

// class complex {
//     private:
//     int real; 
//     int  img;
//     public:

//     complex (){
//         real=0;
//         img=0;
//     }
//     complex(int x,int y){
//         real=x;
//         img=y;
//     }
//     void print(){
//         cout<<real<<"+"<<img<<"i"<<endl;
//     }

//     complex operator + (complex c){  // SYNTAX
//         complex ans(0,0);
//         ans.real =real+c.real;
//         ans.img=img+c.img;
//         return ans;
//         }

// };
// int main(){
//         complex c1(4,5),c2(8,0),c3(3,5);
//         complex c4;
//         c4=c1+c2+c3; // firstly c2 + c3 then c1 + (answer of c2+c3).
//         c4.print();
// return 0;
// }


                                //IMPORTANT:
                      //complex operator+(complex c)

// The parameter c is passed by value.
// This means a copy of the argument is made when the function is called.
// Any changes to c inside the function do not affect the original object.

                     // complex operator+(complex &c)

// The parameter c is passed by reference.
// No copy is made; the function works with the original object.
// This is more efficient (especially for large objects) and avoids unnecessary copying.


               // RUN TIME POLYMORPHISM:
               // BY OVERRIDING:

// POINTER TO DERIVED CLASS= concept:
// #include <iostream>
// using namespace std;
// class baseclass{
//    public: 
//    int var_base;
//    void display(){
//       cout<<"1. Displaying base class var_base "<<var_base<<endl;
//    }
// };

// class derivedclass : public baseclass{
//    public :
//    int var_der;
//    void display(){
//       cout<<"2. Displaying base class var_base "<<var_base<<endl;
//       cout<<"2. Displaying derived class var_der "<< var_der<<endl;
//    }
// };

// int main(){
//    baseclass *base_class_pointer;
//       baseclass base_class_obj;
//       derivedclass der_class_obj;

//       base_class_pointer= &der_class_obj;//'->' nope
//       // pointer of base class (pointed to der. class obj)

//       base_class_pointer-> var_base=23; 
//      // base_class_pointer-> var_der=32;// ERROR  
//       // AS DERIVED CLASS ACCESS TO BASE CLASS NOT ULTA.

//       base_class_pointer->display();   
//       // IT WILL SHOW BASE CLASS DISPLAY AS IT IS 'LATE BINDING' -> JIS CLASS KA POINTER
//       // USI CLASS KA FUNC. RUN.

//       cout<<endl;

//       derivedclass *der_class_pointer;

//      // der_class_pointer = &base_class_obj; 
//      //ERROR AS :
//       // BASE CLASS POINTER CAN HAVE ADD. OF DER. CLASS OBJ.   
//       // BUT DER. CLASS POINTER CAN'T HAVE ADD. OF BASE CLASS OBJ.
            // add.(address )  or referencing.


//       der_class_pointer= &der_class_obj;
//      der_class_pointer->var_base=44; //der class can access base class variables and its also.
//       der_class_pointer->var_der=55;
//       der_class_pointer-> display();

//       cout<<endl;

//    //base class ka pointer storing add. of base class obj. but here var_base ki value nhi hai 
//       // it is treating it like a new obj means' block khali' .
//       base_class_pointer= &base_class_obj;
//       base_class_pointer-> display();  // here not address(in output). 
                                          // it will give garbage value.

// return 0;
// }


                        // in ordered format with no explanation.
// #include <iostream>
// using namespace std;

// class  baseclass{
//    public:
//    int var_base;
//    void display(){
//       cout<<"1 display the base class var_base : "<<var_base<<endl;
//    }
// };

// class derivedclass : public baseclass{
//    public:
//    int var_der;
//    void display(){
//       cout<<"2 display the derived class var_base : "<<var_base<<endl;
//       cout<<"2 display the derived class var_der : "<<var_der<<endl;
//    }
// };

// int main(){
//       baseclass base_class_obj;
//       derivedclass der_class_obj;
//       baseclass *base_class_pointer;
//       derivedclass *der_class_pointer;

//       base_class_pointer= &der_class_obj;
//       base_class_pointer->var_base=23;
//       //base_class_pointer->var_der=34;//error
//       base_class_pointer->display();
      
//       cout<<endl;

//       //der_class_pointer=&base_class_obj;//error

//       der_class_pointer=&der_class_obj;
//       der_class_pointer->var_der=45;
//       der_class_pointer->var_base=66;
//       der_class_pointer->display();

//       cout<<endl;
   
//       base_class_pointer=&base_class_obj;
//       base_class_pointer->display();

// return 0;
// }


//  # VIRTUAL FUNCTIONS:
// #include <iostream>
// using namespace std;

// class  baseclass{
//    public:
//    int var_base;
//    virtual void display(){
//       cout<<"1 display the base class var_base : "<<var_base<<endl;
//    }
// };

// class derivedclass : public baseclass{
//    public:
//    int var_der;
//    void display(){
//       cout<<"2 display the derived class var_base : "<<var_base<<endl;
//       cout<<"2 display the derived class var_der : "<<var_der<<endl;
//    }
// };

// int main(){
//       baseclass base_class_obj;
//       derivedclass der_class_obj;
//       baseclass *base_class_pointer;
      

//       base_class_pointer= &der_class_obj;
//       base_class_pointer->var_base=23;

//       der_class_obj.var_der=44; // varna garbage value.
//                                  // compiler runtime pe decide 
//       base_class_pointer->display();
// return 0;
// }


            // MAIN CONCEPT :  pointers and virtual fun. se overriding :-


// #include <iostream>
// using namespace std;

// class parent{
//    public:
//    virtual void display(){
//       cout<<"1.1 parent"<<endl;
//    }
//    void show(){
//       cout<<"1.2 parent"<<endl;
//    }
// };

// class child : public parent{
//    public:
//    void display(){
//       cout<<"2.1 child"<<endl;
// }
//    void show(){
//       cout<<"2.2 child"<<endl;
//    }
// };
// int main(){
//       parent *p;
//       child cobj;
//       p=&cobj;
//       p->display(); // child class ka print.
//       p->show();// kar sakte hain . paglu.
//                // show mei parent class ka print.
// return 0;
// }

                           // friend functions:
// #include <iostream>
// using namespace std;
// class A {
//    int x;
//    public:
//    A (int y){
//       x=y;
//    }
//    friend void print(A &obj);
//    // print (A &obj) --> prints value of x for given obj .(obj)
//    //A &obj means "reference to an object", not the address.
// };

// void print(A &obj){ // this fn . is outside the class but can access private members 
                      //of class as it is friend to the class
//    cout<< obj.x<<endl;
// }
                   // ye friend fn . kisi aur class ka bhi ho sakta hai. which can access 
                   //A class  ka data members . 
                   // like parent and child class
                  
                   // OR it can be an independent function also.
                  

// int main(){
//       A object(5);
//       //object.x=5// error.
          // cout<<object.x=5;//error.
//       //object.print(object);// ye function class ke bahar
                                // hai kya kar rhe ho.
//       print(object);
// return 0;
// }


