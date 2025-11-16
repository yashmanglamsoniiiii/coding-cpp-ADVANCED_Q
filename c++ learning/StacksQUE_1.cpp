               //QUE 1. EVALUATE POSTFIX EXPRESSION.
               //ME:

// #include <iostream>
// #include <stack>

// using namespace std;
// int pow(int a,int b){
//     if (b==0){
//         return 1;
//     }
//     if (b%2==0){
//         int result= pow(a,b/2);
//         return result*result;
//     }else{
//         int result= pow(a,(b-2)/2);
//         return a*result*result;
//     }
    
// }


// int ops(int a,int b,char ch){
//     if (ch == '+'){
//         return a+b;
//     }else if (ch == '-'){
//         return a-b;
//     }else if (ch=='*'){
//         return a*b;
//     }
//     else if(ch=='/'){
//         return a/b;
//     }else if (ch=='%'){
//         return a%b;
//     }else if (ch=='^'){
//         return pow(a,b);
//     }
//     else{
//         return -1;
//     }
// }

// int main(){

//     stack<int> s;

//         // int a=231*+9-;
//         char arr[]={'2','3','1','*','+','9','-'};
//         int l=sizeof(arr)/sizeof (arr[0]);
//         int ans=0;

//         for (int i=0 ;i<l;i++){
//             //if numbers to push in stack
//             if (arr[i]>='0' && arr[i]<='9'){
//                 s.push(arr[i]-'0');
//             }
//             else {
//                 int upper_one=s.top();
//                 s.pop();
//                 int lower_one=s.top();
//                 s.pop();
//                 ans=ops(lower_one,upper_one,arr[i]);
//                 s.push(ans);
//             }
//         }

//         cout<<s.top()<<endl;
// return 0;
// }

                     // SIR :
// #include <iostream>
// #include <math.h>
// #include<stack>
// using namespace std;

// int calc(int a, int b,char ch){
//     if (ch=='+') return a+b;
//     if (ch=='-') return a-b;
//     if (ch== '*') return a*b;
//     if (ch== '/') return a/b;
//     if (ch=='^') return pow(a,b);
//     if (ch== '%' ) return a%b;
// }

// int eval(string &str){
//     stack<int> st;
//     for (int i=0;i<str.size();i++){
//         char ch=str[i];
//         if (isdigit(ch)){
//             st.push(ch-'0');
//         }else{
//             int v2=st.top();
//             st.pop();
//             int v1=st.top();
//             st.pop();

//             st.push(calc(v1,v2,ch));
//         }
//     }
//     return st.top();
// }


// int main(){
//         string str="231*+9-";
//         cout<<eval(str)<<endl;
// return 0;
// }

                    //QUE 2. EVAL PREFIX EXPRESSION
// #include <iostream>
// #include <math.h>
// #include<stack>
// using namespace std;

// int ops(int a, int b,char ch){
//     if (ch=='+') return a+b;
//     if (ch=='-') return a-b;
//     if (ch== '*') return a*b;
//     if (ch== '/') return a/b;
//     if (ch=='^') return pow(a,b);
//     if (ch== '%' ) return a%b;
// }

// int eval(string &str){
//     stack<int> st;
//     for (int i=str.size()-1;i>=0;i--){
//         char ch=str[i];
//         if (isdigit(ch)){
//             st.push(ch-'0');
//         }else{
//             int v2=st.top();
//             st.pop();
//             int v1=st.top();
//             st.pop();
//             st.push(ops(v1,v2,ch));
//         }
//     }
//     return st.top();
// }
// int main(){
//         string str="-9+*531";
//         cout<<eval(str)<<endl;
// return 0;
// }

            //QUE 3. EVAL OF INFIX EXPRESSION
            // me : crash code  check tomorrow.
#include <iostream>
#include<math.h>
#include<stack>
using namespace std;

int ops(int a, int b,char ch){
    if (ch=='+') return a+b;
    if (ch=='-') return a-b;
    if (ch== '*') return a*b;
    if (ch== '/') return a/b;
    if (ch=='^') return pow(a,b);
    if (ch== '%' ) return a%b;
}

int eval(char* exp ,int l){
    stack<int> st;
    for (int i=0;i<l;i++ ){
        st.push(exp[i]-'0');

        // ')' aaya to '(' iske aane tak pop.
        if (exp[i]==')'){
            // while(exp[i]!='('){   
           //     int x=st.top();
           //     st.pop();
           //     i--; // operation karne mei dikkat.
           // } 

            // aise likhne ke liye "while" loop ki no requirement.
                st.pop();  // ) hataya
                i--;
                int v2=st.top();
                st.pop();
                i--;
                char ch=st.top();  //implicitely int to char mei 
                i--;
                int v1=st.top();
                st.pop();
                i--;
                st.pop();  //  ( hataya
                i--;
            // }
            st.push(ops(v1,v2,ch));
        }else{
            int x2=st.top();
            st.pop();
            i--;

            char ch=st.top();
            st.pop();
            i--;

            int x1=st.top();
            st.pop();
            i--;

            st.push(ops(x1,x2,ch));
        }

    }
    return st.top();
}

int main(){
        char exp[]={'2','(','5','*','(','3','+','6',')',')','+','1','-','2'};
        int length=sizeof(exp)/sizeof(exp[0]);
        cout<<eval(exp,length);
return 0;
}