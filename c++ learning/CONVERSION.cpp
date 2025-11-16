//CONVERTING DECIMAL TO BINARY:-
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int dec=0;
//         int power=1;
//         while(n>0){
//             int ld=n%10;
//             dec=dec+(ld*power);
//             power*=2;
//             n=n/10; // last wala digit hatthe jayenge.
            
//             }
//             cout<<dec<<endl;
        
// return 0;
// }


// DECIMAL TO BINARY:   

// my way:  to get the parity digits and then reverse them --> binary number.

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cout<<"Enter any decimal number : "<<" ";
//         cin>>n;

//         // getting all binary digits (parity digits.)
//         int rem =0;
//         int store=0;
//         while(n>0){  // read all imp point under 'store' niche
//             rem=n%2;  
//             n=n/2;
//             //rem=n%2;    it is the error yahan to n change.
//             store=store*10;    // or direct st=rem+(st*10);
//             store=rem+store;   
//         }
//         // now store has all parity (binary digits) of that number.

//         // we need to reverse the order .
//         int revnum=0;
//         int ld=0;
//         while(store>0){    
//             //              1. store ==0 will only run when 0==0 
//             //              therefore not run
//             //              2. and store>=0 is infinite loop as at one point 
//             //              0>=0 is always true 
                
            
//             ld =store%10;
//             store/=10;
//             //ld=store%10; // error here to store change.
//             revnum=(revnum*10)+ld;
//         }
//         int binaryno=revnum;
//         cout<<"Your binary number is : "<<binaryno<<endl;
// return 0;
// }


// mam's way:     *** basically rev karne se bachne ke liye power ans ke baad increase.
//             understand and learn the algorithm isse direct no. mila rev ki no need.
//                  hum pehle hi 10 se mul.

// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//         int ans=0;
//         int power=1;
//         while(n>0){
//             int paritydigit=n%2;
//             ans+=paritydigit*power;
//             power*=10;
//             n/=2;
//         }
//         cout<<ans<<endl;
// return 0;
//}

