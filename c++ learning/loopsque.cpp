// 1. printing even numbers from  1 to 100.

// #include <iostream>
// using namespace std;
// int main(){
// for (int i=0;i<=100; i++){
//     if (i%2 ==0) cout<< i<< " ";
// }
// }

                                     // optimized code:
// #include <iostream>
// using namespace std;
// int main(){
//     for (int i=2; i<=100;i=i+2){
//         cout<<i<<" ";
//     }
// }

//2 printing odd numbers from 1 to 100.

// #include <iostream>
// using namespace std;
// int main(){
//     for (int i=0;i<=100;i++){
//         if (i%2 !=0)cout<<i<<" ";
//     }
// }

                                     // optimized code:
// #include <iostream>
// using namespace std;
// int main(){
//     for (int i=1;i<=100;i=i+2){
//         cout<<i<<" ";
//     }
// }

//3. printing table of 19.

// #include <iostream>
// using namespace std;
// int main(){
//     for (int i=1; i<=10 ;i++){
//      cout<<19*i<<" "; // aliter  loop -> from 19 to 190 then -> if ( i%19 ==0) cout<< i;    
    
//     }
// }

// 4. print 1,3,5, ...

// #include <iostream>
// using namespace std;
// int main(){
//     int n; 
//     cin>> n;
//     for (int i=1;i<=(2*n)-1;i+=2){ // general term method.
//     cout << i<<" ";}
// }

// 5. 4,7, 10, 13,16, .....

                                      // method 1: general term method.
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>> n;
//     for (int i=4;i<=(3*n)+1;i+=3){
//         cout<<i<<" ";
//     }
// }
         // method 2: using extra variable k and using i for no. of rounds.
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a=4;
//     for (int i=1;i<=n;i++){
//         cout<<a<<" ";
//         a+=3; // a=a+3;
//     }
// }

//6. 2,4,8,16, 32,.....

        // method 1: directly in loop.( but will not be clear ki kitne terms aayenge)
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     for(int i=2;i<=n;i=i*2){
//         cout<<i<<" ";
//     }
// }

   // method 2: using third variable and using i for just no. of terms (rounds).>> more clear.
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int k=2;
//     for(int i=1;i<=n;i++){
//         cout<<k<<" ";
//         k*=2;
//     }
// }

// 7. Highest factor of number n (other than itself).
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin >> n;
//         int a=1;
//         for (int i=1;i<n;i++){   // <n  taki vo no. na aaye.
//                 if (n%i==0) a=i; // if to print all factors then don't create a simply cout<<i;
//         }
//         cout<< a <<endl;
//         return 0;
// }

// more optimized code: less space  runtime same.
// #include <iostream>
// using namespace std;
// int main(){
//         int n; 
//         cin>> n;
//         int a=0;
//         for (int i=1;i<=n/2;i++){  // highest factor like i*1 then second highest i*2.. (i is number which is changing from 1 to n/2).
//                 if (n%i==0) a=i;
//         }
//         cout<<a<<endl;
//         return 0;
// }

// ultra optimized : space less and runtime less. (fatest to give output.)
// #include <iostream>
// using namespace std;
// int main(){
//         int n; 
//         cin>> n;
//        // int a=0;
//         for (int i=n/2;i>=1;i--){  
//                 if (n%i==0)
//                  //a=i; //  we can also store value in a then put break and after that outside loop print a.
//                  cout<<i<<endl; // pehla wala milne ke baad put break .
//                  break;
//         }
//         return 0;
// }

// 8. finding whether a no. is composite or not.
// wrong code as it checks only divisibility by 2 and then break;( directly else wale part mei ghus jayega).

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=2;i<n;i++){
//                 if (n%i==0){ 
//                         cout<<"Number is composite.";
//                         break;
//                 }
//                 else {
//                         cout<< "Number is prime.";
//                         break;
//                 }
//         }
//         return 0;
// }

// right code. 
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=2;i<n;i++){ //  2 to n/2 more optimized.
//                 if (n%i==0){
//                         cout<<"composite";
//                         break;
//                 }
//         }
// }

//9. distinguish betn prime and composite.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         bool flag;
//         for (int i=2;i<n/2;i++){ 
//                 if (n%i==0){    // else wala part no as phir vhi mistake two ka divisibility check .
//                         flag=false;
//                      // break; // jada koi farak nhi same.  
//                 }
//                 break;
//         }
//         if (n==0 || n==1) cout<< "neither prime nor composite";
//         else if (flag==true){
//                 cout<<"prime";
//         }else{
//                 cout<<"composite";
//         }
//         return 0;
// }

//10. count digits of a number.

// wrong -->

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int a;
//         for (int i=1;;i++){    // n.length or n.size --> wrong .
//                 int a=i;      
//         }
//         cout<<a<<endl;
//         return 0;
// }

// integer division.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin >> n;
//         int count=0;
//         while(n>0){ // i wala loop --> mei ke saath condn . and do while or while mei ye bhi and koi other condn bhi ok.
//                 n=n/10;     //N!=0;  thik hai.
//                 int n;
//                 count++;   
//         }
//         cout<<count<<endl;
// return 0;
// }

//11. sum of digits of a number.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int sum=0;
//         int a;
//         while(n!=0){
//                 a=n%10;
//                 sum+=a;
//                 n=n/10;
//         }
//         cout<<sum;
// return 0;
// }

//12. print of product of digits.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int product=1;
//         int ld;
//         while(n>0){
//                 ld=n%10;
//                 n/=10;
//                 product*=ld;
//         }
//         cout<<product;
// return 0;
// }

//13. print sum of all even digits of a given number.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int ld;
//         int sumeven=0;
//         while(n>0){
//                 ld=n%10;
//                 n/=10;
//                 if (ld%2==0){  // for odd digits summ. ld%2 != 0;
//                         sumeven+=ld;
//                 }
//         }
//         cout<<sumeven<<endl;
// return 0;
// }

// 14. print reverse of a given number.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         //int mul=10;//multiplier.  --> not required as * 10 directly.
//         int ld;
//         int rev=0;
//         while(n>0){
//                 rev=rev*10;
//                 ld=n%10;
//                 n/=10;
//                // rev=(rev*10)+ld; //or ld=ld*10 -> rev=rev+ld  (no)
//                // rev=rev+ld;--> rev=rev*10; issue>>1234 --43210
//                 rev=rev+ld; 
//         }
//         cout<<rev;

// return 0;
// }   

//aliter algorithm:-
// ld=n%10
//n/=10
//rev*=10
//rev=rev+ld     or directly --> rev=(rev*10)+ ld   instead of two  steps only one. 

                                // NEW WAY OF REVERSING A NUMBER.
// for like 3 numbers.
// #include <iostream>
// using namespace std;
// int main(){
//         int x,y,z,l,num,pal;
//         cin>>num;
//         x=num%10;//212 -->2
//         y=num/10;// 21
//         z=y%10;// will get 1
//         l=y/10;//21/10=2(quotient)
//         pal=(x*100)+(z*10)+(l*1);
// return 0;
// }

//15. print the sum of given no. and its reverse . 

                                       //don't do:-
//ld=n%10;
//n/=10;
//sum=sum+ld;
//cout<<sum*2;  

                                        // do :-
// 1234    +     4321      =       5555
// jab rev nikalte hain then our n becomes 0 : IMP POINT.!!!!



// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int num=n;  // store the value of n in num to get n reserved.
//         int ld;
//         int rev=0;
//         int sum=0;
//         while(n!=0){
//                 ld=n%10;
//                 rev=(rev*10)+ld;
//                 n/=10;
//         }   // now n is zero!!!!!    
//             // don't do rev ka rev2 nikal leta hoon :-
//             // that will give  n again but then rev =0.
//         cout<<num+rev<<endl;
// return 0;
// }


// 16 . print sum of digits of a given no. and its rev.

                                    // what we need:-
                          // 1+2+3+4    +    4+3+2+1     =  20
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n; 
//         int num= n; //store the value of n
//         int sum1=0, sum2=0, rev=0;
//         int ld1,ld2,ld3;
//         //getting n's digit summ.
//         while(n!=0){
//                 ld1=n%10;
//                 n=n/10;
//                 sum1=sum1+ld1;
//         }            // now n is zero  


//         // getting reverse of number.
//         while(num>0){
//                 ld2=num%10;
//                 num/=10;
//                 rev=(rev*10)+ld2; //or rev=rev*10 ;   ----> rev=rev+ ld;
//         }


//         // getting rev no.'s digits  summ.
//         while(rev!=0){
//                 ld3=rev%10;
//                 rev/=10;
//                 sum2=sum2+ld3;  
//         }

//         cout<<sum1+sum2<<endl;
// return 0;
// }

//17 . printing factorial of a number.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int fact=1;
//         for (int i=n;i>=1;i--){   // or for(int i=1;i<=n;i++)
//                 fact=fact*i;
//         }
//         cout<<fact<<endl;
// return 0;
// }

//18. print factorial of first n numbers.

//wrong:-

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int fact=1;
//         for(int i=1;i<=n;i++){
//                 for (int j=1;j<=i;j++){
//                         fact=fact*j;

//                         //cout<<"factorial of"<<i<<fact<<endl;// write this after this (j) loop varna 
//                                   // 2 ka fact =1 
//                                   // 2 ka fact=2 .....same with 3 (three times).

//                 }
//                 cout<<"factorial of "<< i<<"="<<" "<< fact<<endl; 
        
//                 // wrong as when fact of 3 to 3*2*1 =6 but usme 2 pehle se stored it will also be multiplied.
//         }
// return 0;
// }

// right :-     (DON'T OVERTHINK JUST HAR MOMENT PAR PRINT.)
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int fact=1;
//         for (int i=1;i<=n;i++){
//                 fact=fact*i;
//                 cout<<"factorial of "<<i<<"="<<" "<<fact<<endl;
//         }
// return 0;
// }

//19. print all the ASCII values with their equi. charac.
//while loop:-
// #include <iostream>
// using namespace std;
// int main(){
//         int a=65;
//         char v;
//         while(a<=90){
//                 v=char(a);
//                 cout<<char(a)<< " "<< a<<endl;
//                 a++;
//         }
// return 0;
// }

//20. print the prime numbers series.

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=2;i<n;i++){
//                 if (i%i==0){   // 1 se everyone is div.i%1==0 && i%i==0 same.
                        
//                 }       
//         }
// return 0;
// }


#include <iostream>
using namespace std;
int main(){
        int n,i,k;
        cin>>n;
        for ( i=2;i<=n;i++){
                for ( k=2;k<i;k++){
                        if (i%k==0){
                                cout<<"";
                                break;
                        }
                }
                if (i==k){
                        cout<<k<<" ";
                        }
        }
return 0;
}


                                // SQRT WAY:
// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     for (int i = 2; i <= n; i++) { // declare i here
//         bool isPrime = true;
//         for (int k = 2; k * k <= i; k++) { // declare k here
//             if (i % k == 0) {
//                 isPrime = false;
//                 break;
//             }
//         }
//         if (isPrime) {
//             cout << i << " ";
//         }
//     }
//     cout << endl;
//     return 0;
// }


//20. print fibonacci series.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int c;
//         int a=0;
//         int b=1;
//         cout<<a <<" "<<b<<" ";
//         for (int i=3;i<=n;i++){
//                 c=a+b;
//                 cout<<c<<" ";
//                 a=b;
//                 b=c;
//         }
// return 0;
// }

//21. check if a no. is palindrome.
                                     // MY LOGIC :
                                // REVERSE = ACTUAL NO. (TRUE)---> PALINDROME 
                        // 22==22;(YES)  121==121;(YES)  2344322==2234432(NO);

// #include <iostream>
// using namespace std;
// int main(){
//         int n,ld,rev=0;
//         cin>>n;
//         int num=n;
//         while(n>0){
//                 ld=n%10;
//                 n=n/10;
//                 rev=rev*10;
//                 rev=rev+ld;
//         }
//         if (rev==num) cout<<num<<" "<<"is a palindrome!!!";
//         else cout<<num<<" "<<"is NOT a palindrome!!!";
// return 0;
// }