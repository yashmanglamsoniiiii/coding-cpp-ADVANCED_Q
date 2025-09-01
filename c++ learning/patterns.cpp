// 1.                            RECTANGLE PATTERN. of (n*m)

// #include <iostream>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n >>m;
//         for (int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){ // if for (int i...) to bhi same.
//                 cout<<"*"<<" ";
//             }
//             cout<<endl;// to change line.
//         }
// return 0;
// }
//2.                          NUMBER RECTANGLE (N*M)  OF SAME NUMBER.

                          //1 1 1 1 (N=4,M=4) |     //1 1 1 1 1 (n=3,m=5)
                          //2 2 2 2           |     //2 2 2 2 2
                          //3 3 3 3           |     //3 3 3 3 3
                          //4 4 4 4           |
// #include <iostream>
// using namespace std;
// int main(){
//         int n,m;
//         cin>>n >>m;
//         for (int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 cout<<i<<" ";
//             }
//             cout<<endl;
//         }
// return 0;
// }

//3 .                      NUMBER RECTANGLE (N*M) OF NUMBER IN SERIES.

                    //1 2 3 4            //  1 2 3 4 5
                    //1 2 3 4            //  1 2 3 4 5 
                    //1 2 3 4            //  1 2 3 4 5 
                    //1 2 3 4            
// #include <iostream>
// using namespace std;
// int main(){
//         int n,m;
//         cin>>n >>m;
//         for (int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
// return 0;
// }

//4.                         ALPHABET RECTANGLE(N*M) OF SAME NUMBER.
                  //A A A A (4*4)    //A A A A A(3*5)
                  //B B B B          //B B B B B
                  //C C C C          //C C C C C
                  //D D D D
// #include <iostream>
// using namespace std;
// int main(){
//         int n,m;
//         cin>>n >>m;
//         for (int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 cout<<char(64+i)<<" ";// don't think user will input=69 like i,j=65  
//             }
//             cout<<endl;
//         }
// return 0;
// }


//5.                     ALPHABET RECTANGLE (N*M) OF DIFF. NUMBER.

            //A B C D E (3*5)  //AAA(3*3)
            //A B C D E         //BBB
            //A B C D E          //CCC

// #include <iostream>
// using namespace std;
// int main(){
//         int n,m;
//         cin >>n >>m;
//         for (int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 cout<<char(64+j)<<" ";
//             }
//             cout<<endl;
//         }
// return 0;
// }

//6.                               STAR RECTANGLE.
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//         for (int i=1;i<=n;i++){
//             for (int j=1;j<=i;j++){
//                 cout<<"*"<<" "; 
//                                   //if   i -->1 22.. 333.
//                                  //if   j--> 1  12 ...123. 
//                                  //if  char(i) --> A  BB  CCC..
//                                  //if  char(j)--> A  AB   ABC..
                                
//             }
//             cout<<endl;
//         }
// return 0;
// }

//7.          ALPHA-NUMERIC TRIANGLE.
                              // 1
                              // A B
                              // 1 2 3
                              // A B C D
                              // 1 2 3 4 5 

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             for(int j=1;j<=i;j++){
//                     if (i%2!=0){       // pehle 1 aayega so odd ki condn.
//                         cout<<j<<" "; // all other combn , just i j or eve-odd condn switch.
//                     }else{
//                         cout<<char(64+j)<<" ";
//                     }
//             }
//             cout<<endl;
//         }
// return 0;
// }                             


//8.                          STAR TRIANGLE ULTA.
// logic:-
             // JAB i=1 tab j=4 ,i=2 j=3 -->
             //--> so i+j=n+1 ****
             // therefore j=n-i+1.
                
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){                  //int i=n;i>=1;i--
//             for (int j=1;j<=n-i+1;j++){          //int j=i;j>=1;j--   ALSO CORRECT.
//                 cout<<"*"<<" ";
//             }
//             cout<<endl;
//         }
// return 0;
// } 


                     //cout<< :-
//        if  i-->  same no. 
//        if  j--> diff no. 
//        if  char(i)--> same alpha.
//        if  char (j)--> diff alpha.


//note:-
//for (int i=1;i<=n;i++){                  //int i=n;i>=1;i--
//for (int j=1;j<=n-i+1;j++){              //int j=i;j>=1;j--  

// here we can have :-                     // here we can have:-
// 1111      1234                                    4444        4321 for this ( i-->n to 1 )                                
// 222       123                                     333         321           (j-->i to 1)                           
// 33        12                                      22          21                             
// 4         1                                       1           1           
            // here aage wala no. fix                            //here last no. fix.
                   
// so have a note what pattern to print.    OR  DO THAT TO PRINT LIKE 1 TO N AND WE 
//                                           NEED N TO 1 SO COUT<<J=N-I+1  AND J=N-I AND SO ON..

// 9.                    // NICE QUESTION OF VARIATION.
//4
//4 3
//4 3 2 
//4 3 2 1 

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=n;i>=1;i--){
//             for (int j=n;j>=i;j--){ //not initialize from j=i nhi to nxt line mei 3 se strt.
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
// return 0;
// }

                             // aliter 

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             for (int j=n;j>=n-i+1;j--){ 
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
// return 0;
// }

//10 . print:-
//A B C D 
//A B C 
//A B
//A

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             for (int j=1;j<=n-i+1;j++){
//                 cout<<char(j+64)<<" ";
//             }
//             cout<<endl;
//         }
// return 0;
// }

//11. Odd number triangle.

// 1 
// 1 3
// 1 3 5
// 1 3 5 7

// MY APPROACH:- ( BUT NO BODY WILL LIKE PRINT ODD NUMBERS FOR PRINTING PATTERN ).

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n; 
//         if (n%2==0) cout<<"enter odd number.";
//         else {
//             for (int i=1;i<=n;i=i+2){
//                 for (int j=1;j<=i;j+=2){
//                     cout<<j<<" ";
//                 }
//                 cout<<endl;
//             }
//         }
// return 0;
// }

                               // SIMPLE ALITER:
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             for(int j=1;j<=i;j++){
//                 cout<<(2*j)-1<<" ";   // isko aise dekho like 2 colum mei 3 print 
//             }                          // and 3 column mei 5 print so 2n-1 type.
//             cout<<endl;
//         }
// return 0;
// }

      // NOT RECOMMENDED BY SIR AS WE ARE CHANGING OUR STRUCTURE OF TRIANGLE.

        // for (int i=1;i<=n;i++){
        //     for(int j=1;j<=2*i-1;j++){
        //         cout<<j<<" ";    
            
        //another interesting way:
// 1 
// 1 3
// 1 3 5
// 1 3 5 7

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             int a=1;
//             for (int j=1;j<=i;j++){
//                 cout<<a<<" ";
//                 a+=2;
//             }
//             cout<<endl;
//         }
// return 0;
// }

//12. ODD NUMBER TRIANGLE OF SUCCESSIVE NUMBERS. 
                        // FLOYD'S TRIANGLE OF ODD NUMBERS.
// 1 
// 3 5
// 7 9 11
// 13 15 17 19

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int a=1;
//         for (int i=1;i<=n;i++){
//             for (int j=1;j<=i;j++){
//                 cout<<a<<" ";
//                 a+=2;
//             }
//             cout<<endl;
//         }
// return 0;
// }

// 13. FLOYD'S TRIANGLE
// 1 
// 2 3
// 4 5 6
// 7 8 9 10

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int a=1;
//         for (int i=1;i<=n;i++){
//             for (int j=1;j<=i;j++){
//                 cout<<a<<" ";  // or directly cout<<a++ 
//                 a=a+1;
//             }
//             cout<<endl;
//         }
// return 0;
// }

//14. 0 and 1 TRIANGLE.  

// jab kuch samjh nhi aaye to think about i and j combn.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             for (int j=1;j<=i;j++){ // basically jitni i utni baar loop chale.
//                     if ((i+j)%2==0) cout<<1<<" ";
//                     else cout<<0<<" ";
//             }
//             cout<<endl;
//         }
// return 0;
// }


//15. STAR PLUS.


// specifically for n=5.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             for (int j=1;j<=n;j++){
//                 if ((i*j)%3==0) cout<<"*"<<" ";
//                 else cout<<" "<<" ";// << " " only --> to only one character space. so unequal.
//             }
//             cout<<endl;
//         }
// return 0;
// }



                             // MORE GENERALIZED AND GOOD APPROACH:
                             // only odd numbers to be entered;
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int a= n/2 +1;  // no matter i khin bhi likho.
//         if (n%2==0) cout<< " not odd number";
//         else{
//             //int a= n/2 +1;
//         for(int i=1;i<=n;i++){
//            // int a= n/2 +1;
//             for(int j=1;j<=n;j++){
//                 if (i==a || j==a){
//                     cout<<"*"<<" ";
//                 }else{
//                     cout<<" "<<" ";
//                 }
//             }
//             cout<<endl;
//         }
//     }
// return 0;
// }

// agar vo for loop wala else part not printed to spaces nhi hai:-
// * 
// *
// * * * * *
// *
// *


// 16. HOLLOW RECTANGLE.

// #include <iostream>
// using namespace std;
// int main(){
//         int n,m;
//         cin>>n>>m;
//         for (int i=1;i<=n;i++){
//             for (int j=1;j<=m;j++){
//                 if (i==1 || i==n || j==1||j==m) {
//                     cout<< "*"<<" ";
//                 }else{
//                     cout<<"  ";
//                 }
//             }
//             cout<<endl;
//         }
// return 0;
// }

//17. STAR CROSS. (n=odd). like star plus.
// just like printing diagonals of square.

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for(int i=1;i<=n;i++){
//             for (int j=1;j<=n;j++){
//                 if (i==j || (i+j)==n+1) {
//                     cout<<"*"<<" ";
//                 }else{
//                     cout<<"  ";
//                 }
//             }
//             cout<<endl;
//         }
// return 0;
// }



                                //ADVANCED PATTERNS:
//18. STAR TRIANGLE REVERSE.
//         * 
//       * *
//     * * *
//   * * * *
// * * * * *

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
        
//         for (int i=1;i<=n;i++){
//             //spaces
//             for (int j=1;j<=n-i;j++){
//                 cout<<"  ";
//             }
//             // stars
//             for(int k=1;k<=i;k++){
//                 cout<<"* ";
//             }
//             cout<<endl;
//         }
        // // stars  aise to alag print hoga  so ek hi for loop ke andar.
        // for (int i=1;i<=n;i++){
        //     for (int j=1;j<=i;j++){
        //         cout<<"*"<<" ";
        //     }
        //     cout<<endl;
        // }
// return 0;
// }

//IF 
//           * 
//         * *
//       * * *
//     * * * *
//   * * * * *  yahan bhi ek space extra print.


// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             //spaces
//             for (int j=1;j<=n-i+1;j++){
//                 cout<<"  ";
//             }
//             // stars
//             for(int k=1;k<=i;k++){
//                 cout<<"* ";
//             }
//             cout<<endl;
//         }
//         return 0;
//     }


//19. NUMBER TRIANGLE REVERSE.

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             //spaces
//             for (int j=1;j<=n-i;j++){
//                 cout<<"  ";
//             }
//             // stars
//             for(int k=1;k<=i;k++){
//                 cout<<k<<" ";   //char(j+64)  to reverse alphabet triangle.
//             }
//             cout<<endl;
//         }
//         return 0;
//     }

//20. RHOMBUS.

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             //spaces
//             for (int j=1;j<=n-i;j++){
//                 cout<<"  ";
//             }
//             // stars
//             for(int k=1;k<=n;k++){
//                 cout<<"* ";
//             }
//             cout<<endl;
//         }
//         return 0;
//     }

//21. STAR PYRAMID
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//             for(int j=1;j<=n-i;j++){
//                 cout<<"  ";
//             }
//             for (int j=1;j<=2*i-1;j++){
//                 cout<<"*"<<" ";
//             }
//             cout<<endl;
//         }
// return 0;
// }

                                //aliter way:
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int nst=1;
//         // int nsp=3;
//         for (int i=1;i<=n;i++){
//             //int nst=1; //this will update the value of nst every time one therefore single star.
//             for(int j=1;j<=n-i;j++){// j<=nsp;
//                 cout<<"  ";
//             }
//             //nsp=nsp-1;  // this nsp is for specific pyramid.
//             for (int k=1;k<=nst;k++){
//                 cout<<"*"<<" ";
//             }
//             nst+=2;
//             cout<<endl;
//         }
// return 0;
// }



//ERROR:

// for (int j=1;j<=nst;j++){
//                 cout<<"*"<<" ";
//                 nst+=2;
//             }

// First iteration:

// Print * 
// Now, nst = nst + 2 → nst = 3
// j increments to 2 due to j++
// Second iteration:

// Check: j = 2, j <= nst (2 <= 3) → true
// Print * 
// nst = nst + 2 → nst = 5
// j increments to 3 due to j++
// Third iteration:

// Check: j = 3, j <= nst (3 <= 5) → true
// Print * 
// nst = nst + 2 → nst = 7
// j increments to 4 due to j++

// Because nst keeps increasing inside the loop,
// j will always be less than or equal to nst, 
//so the condition j <= nst is always true after the first iteration.

// Conclusion:
// This causes an infinite loop and prints *  forever.
// Fix: Move nst += 2; outside the inner loop so 
//it only increases once per row, not for every star.

//22. NUMBER PYRAMID.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//                 for (int j=1;j<=n-i;j++){
//                 cout<<"  ";
//                 }
//                 for (int k=1;k<=2*i-1;k++){
//                 cout<<k<<" "; // here if char(k+64) to alphabet pyramid.
//                 }
//                 cout<<endl;
//         }
// return 0;
// }

//23. NUMBER PYRAMID MAST.
//       1 
//     1 2 1 
//   1 2 3 2 1 
// 1 2 3 4 3 2 1
// think about the extra variable.

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//                 int a=i-1;             // wapis ghoom par aaya then update 'a'.
//
//                 for(int j=1;j<=n-i;j++){    //or j<=nsp and loop ke bahar nsp--;
//                         cout<<"  ";         // uper declare nsp=n-1
//                 }
//                 for(int k=1;k<=i;k++){
//                         cout<<k<<" ";
//                 }
//                 for(int k=1;k<=i-1;k++){  //loop ek kam baar chalna hai 
//                         cout<<a<<" ";
//                         a--;
//                 }
//                 cout<<endl;
//         }
// return 0;
// }

//24. NUMBER PYRAMID MAST 2.0.

//       1 1 
//     1 2 2 1
//   1 2 3 3 2 1 
// 1 2 3 4 4 3 2 1


                                        // way no.1
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//                 int a=i;             
//                 for(int j=1;j<=n-i;j++){
//                         cout<<"  ";
//                 }
//                 for(int k=1;k<=i;k++){
//                         cout<<k<<" ";
//                 }
//                 for(int k=1;k<=i;k++){   // don't think to print k with same format.
//                         cout<<a<<" ";
//                         a--;
//                 }
//                 cout<<endl;
//         }
// return 0;
// }


                                // way no. 2
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){             
//                 for(int j=1;j<=n-i;j++){
//                         cout<<"  ";
//                 }
//                 for(int k=1;k<=i;k++){
//                         cout<<k<<" ";
//                 }
//                 for(int k=i;k>=1;k--){  
//                         cout<<k<<" ";
//                 }
//                 cout<<endl;
//         }
// return 0;
// }


//25. ALPHABET PYRAMID MAST.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for(int i=1;i<=n;i++){
//                 int a=i-1;
//                 for (int j=1;j<=n-i;j++){
//                         cout<<"  ";
//                 }
//                 for (int k=1;k<=i;k++){
//                         cout<<char(k+64)<<" ";
//                 }
//          // for (int m=1;m<=a;m++){ this is wrong as if i=3to m=1 se 2  then print a, a--;
//                         for (int m=1;m<=a;m++){ // then m++ se m=2 to 1 tak wrong as m++ and a--
//                         cout<<char(a+64)<<" ";
//                         a--;
//                 }
//                 cout<<endl;
//         }
// return 0;
// }

//26. DIAMOND.                              n=sides.


// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         //int a=1;
//         for (int i=1;i<=n;i++){     
//                 for(int j=1;j<=n-i;j++){
//                         cout<<"  ";
//                 }
//                 for (int k=1;k<=2*i-1;k++){  //k<=a;     //aliter way is commented.
//                         cout<<"* ";
//                 }
//                 //a+=2;
//                 cout<<endl;
//         }

//         int b=2*(n-1)-1;
//         for(int i=1;i<=n-1;i++){
//                 for (int k=1;k<=i;k++){
//                         cout<<"  ";
//                 }
//                 for (int m=1;m<=b;m++){    // or m=2*(n-1)-2;m>=1;m--   will not work.
//                         cout<<"*"<<" ";    // as har bar 5 se 1 tak 
//                 }                       // n ki jagah i then thoda code mei changes to right.
//                 b-=2;
//                 cout<<endl;
//         }
// return 0;
// }

                               //if n=no . of lines.  (odd)
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int midl=n/2 +1;
//         int nsp=n/2;
//         int nst=1;
        
//         for (int i=1;i<=n;i++){
//         if (i<midl){        // reason for it is down " ALITER "
//                 for (int j=1;j<=nsp;j++){ // j=1 pe ek _ then 2 pe _ then 3 pe_ .
//                         cout<<"  ";
//                 }
//                 for (int k=1;k<=nst;k++){
//                         cout<<"* ";
//                 }
//                 nsp--;
//                 nst+=2;
//                 cout<<endl;
//         }else{                              // at the end of first loop nsp=0 ;nst=n***
//                 nsp++;
//                 nst-=2;
//                 for (int j=1;j<=nsp;j++){
//                         cout<<"  ";
//                 }
//                 for (int k=1;k<=nst;k++){
//                         cout<<"* ";
//                 }
//                 // nsp++;
//                 // nst-=2;   // koi farak nhi padeaga as vo zero ho gya hai.
//                 cout<<endl;
//         }
//         }
// return 0;
// }            // DON'T KNOW WHAT'S THE ERROR.



                                  // OPTIMIZED:
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n ;
//         int midl=n/2+1;
//         int nsp=n/2;
//         int nst=1;
//         for(int i=1;i<=n;i++){
//                 for(int j=1;j<=nsp;j++){
//                         cout<<"  ";
//                 }
//                 for (int k=1;k<=nst;k++){
//                         cout<<"* ";
//                 }
//                 if (i<midl){   // key note: nsp & nst ke dec/inc baad mei ****
//                         nsp--;  // therefore i=3 ke baad dec chahiye.
//                         nst+=2; // so i=2 pe to if wala part then uper jayega for i=3  
//                 }else{           // and middle row aaram se print then i=3 pe else wala part shuru.
//                         nsp++;    // for more clearity do dry run.
//                         nst-=2;
//                 }
//                 cout<<endl;
//         }
// return 0;
// }

//27. STAR TABLE .(trial to that)

// * * * * * * * * 
// * * *     * * * 
// * *         * * 
// *             * 

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//                 // for first part:
//                 for(int j=1;j<=n-i+1;j++){
//                         cout<<"* ";
//                 }
//                 for (int k=1;k<=i-1;k++){      **
//                         cout<<"  ";
//                 }
//                 // for second part:
//                 for (int m=1;m<=i-1;m++){     **
//                         cout<<"  ";
//                 }
//                 for (int j=1;j<=n-i+1;j++){
//                         cout<<"* ";
//                 }
//                 cout<<endl;
//         }
// return 0;
// }

// 26. NUMBER TABLE.      (imp)**********
                            //SEE COPY / DIARY TO SEE 4 BREAK PARTS.
// * * * * * * *            // stars+ sp+sp2+ stars2
// * * *   * * *
// * *       * *
// *           *


// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//                 // first set of stars:
//                 for (int j=1;j<=n-i+1;j++){
//                         cout<<"* ";
//                 }
//                 // first set of spaces:
//                 for (int k=1;k<=i-1;k++){
//                         cout<<"  ";
//                 }
//                 // second set of spaces:
//                 for(int j=1;j<=i-2;j++){
//                         cout<<"  ";
//                 }
//                 // second set of stars:
//                 if (i==1){
//                         for (int j=1;j<=n-i;j++){// n-1 same as i==1 ke liye sirf .
//                                 cout<<"* ";
//                         }
//                 }else{
//                         for (int j=1;j<=n-i+1;j++){//aise if else se i=1, 2 mei same no of stars
//                                 cout<<"* ";
//                         }
//                 }
//                 cout<<endl;
//         }
// return 0;
// }


// ALITER:

                   //here we BREAK INTO 2 PARTS: FIRST LINE + LOWER PART.
// #include <iostream>
// using namespace std;
// int main(){
//         int n; 
//         cin>>n;      // IF ELSE (NOT REQ. SOMUCH) AS N=1 PEHLA WALA AND N=2... ELSE AISE OK ..

//         for (int i=1;i<=2*n-1;i++){
//                 cout<<"* ";
//                 //cout<<endl; har alag alag line mei print.
//         }
//         cout<<endl;

//         int nsp=1;
//         int nst=n-1;
//         for (int i=1;i<=n-1;i++){
//                 for (int j=1;j<=nst;j++){   // OR UPER INT A=1 THEN AFTER SP WALA LOOP A+=2.
//                         cout<<"* ";          // STARS -->J<= N-I
//                 }
//                 for (int k=1;k<=nsp;k++){
//                         cout<<"  ";
//                 }
//                 for (int j=1;j<=nst;j++){
//                         cout<<"* ";
//                 }
//                 nsp+=2;
//                 nst--;
//                 cout<<endl;
//         }
// return 0;
// }


//AGAR DONO LOOPS i WALE UPTO N TO IF N=4 AND 2*N+1 TAK TO FIRST LINE MEI 9 STARS AND THEN 
// SECOND MEI 4 -4 STARS WITH ONE BEECH MEI SPACE ........
// BASICALLY N=4 KE LIYE 5 LINES.


// 27. NUMBER TABLE .

//1 2 3 4 5 6 7 
//1 2 3   5 6 7
//1 2       6 7
//1           7


                         //TRIALS:-
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//                 //numbers1
//                 for (int j=1;j<=n-i+1;j++){
//                         cout<<j<<" ";
//                 }
//                 //spaces1
//                 for (int k=1;k<=i-1;k++){
//                         cout<<"  ";
//                 }
//                 //spaces2
//                 for (int j=1;j<=i-2;j++){
//                         cout<<"  ";
//                 }
//                 //numbers2


                                                
//                         // if (i==1){
//                         //    for (int k=1;k<=n-i;k++){
//                         //                 cout<<k+4<<" ";
//                         //         }
//                         // }else{
//                         //    for (int k=1;k<=n-i+1;k++){  // need to change.
//                         //                 cout<<k+4<<" ";  // if k ko i se strt.--no
//                         //         }
//                         // }

//                         // 1 2 3 4 5 6 7 
//                         // 1 2 3   5 6 7
//                         // 1 2       5 6
//                         // 1           5

//         if (i==1){
//                 for (int k=1;k<=n-i;k++){
//                         cout<<k+4<<" ";
//                 }
//         }else{
//                 // for (int k=1;k<=n-i+1;k++){  
//                         // concept of max from number zoom.
//                         // int max=i;
//                         // if (k>i) max=k;
//                         // else  max=i;
//                         // THIS IS ACTUALLY WRONG AS K=1 TO 4 ,1 TO 3 ..
//                 cout<<max<<" ";
//                 }
//         }



//         cout<<endl;
//         }
// return 0;
// }
                                
                                // MAIN ME:-  [specific for n=4]
// #include <iostream>
// using namespace std;
// int main(){
//         int n; 
//         cin>>n;
//         for (int i=1;i<=n;i++){
//                 //no.s1
//                 for (int j=1;j<=n-i+1;j++){
//                         cout<<j<<" ";
//                 }
//                 //sp1
//                 for (int k=1;k<=i-1;k++){
//                         cout<<"  ";
//                 }
//                 //sp2
//                 for (int j=1;j<=i-2;j++){
//                         cout<<"  ";
//                 }
//                 //no.2
//                 if (i==1){
//                         for (int k=1;k<=n-i;k++){
//                                 cout<<k+4<<" ";
//                         }
//                 }else{
//                         for (int k = i+3; k <= 2*n-1; k++) {   // k=7-i to 7 forn=4
//                                 cout << k << " ";           //n+1 to 2n-1
//                         }
//                 }
//                 cout<<endl;
//         }
// return 0;
// }
  


                                  // SIR :- MAIN NOW
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=2*n-1;i++){
//                 cout<<i<<" ";
//         }
//         cout<<endl;
//         for (int i=1;i<=n-1;i++){
//                 int a=1;
//                 //no.s1
//                 for (int j=1;j<=n-i;j++){
//                         cout<<a<<" ";
//                         a++;
//                 }
//                 //sp 
//                 for (int k=1;k<=2*i-1;k++){
//                         cout<<"  ";
//                         a++;     // key to solve ...***********
//                 }
//                 //no.s2
//                 for (int m=1;m<=n-i;m++){
//                         cout<<a<<" ";
//                         a++;  // if comment to 555 then 66 then 7 
//                 }
//                 cout<<endl;
//         }
// return 0;
// }

//28. ALPHABET TABLE.
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=2*n-1;i++){
//                 cout<<char(i+64)<<" ";
//         }
//         cout<<endl;
//         int nst=n-1;
//         int nsp=1;
//         for (int i=1;i<=n-1;i++){
//                 int a=1;
//                 for (int j=1;j<=nst;j++){
//                         cout<<char(a+64)<<" ";
//                         a++;
//                 }
//                 for (int k=1;k<=nsp;k++){
//                         cout<<"  ";
//                         a++;              // key to solve ... ******
//                 }
//                 for (int m=1;m<=nst;m++){
//                         cout<<char(a+64)<<" ";
//                 }
//                 nst--;
//                 nsp+=2;
//                 cout<<endl;
//         }
// return 0;
// }



//29. NUMBER ZOOM:
                       // SPECIFIC FOR N=4;


// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=2*n-1;i++){
//                 for (int j=1;j<=2*n-1;j++){
//                         if (i==1||j==1||i==2*n-1||j==2*n-1){
//                                 cout<<n<<" ";
//                         }else if( i==2||j==2||j==2*n-2||i==2*n-2){
//                                 cout<<n-1<<" ";
//                         }else if( i==3||j==3||j==2*n-3||i==2*n-3){
//                                 cout<<n-2<<" ";
//                                else{// i==j
//                                        cout<<n-3<<" ";
//                                 }


                        // TRIAL:- (NOPE)
                        // }else if(i==j){ // i==j
                        //         cout<<n-3<<" ";
                        // }else {
                        //         cout<<"  ";


//                         }
//                 }
//                 cout<<endl;
//         }
// return 0;
// }

//                        BEST WAY:-
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=2*n-1;i++){
//                 for (int j=1;j<=2*n-1;j++){
//                         if (i==1||j==1||i==2*n-i||j==2*n-j){
//                                 cout<<n-i+1<<" ";
//                         }
                        
//                 }
//                 cout<<endl;
//         }
// return 0;
// }


// this is wrong as when we code i=2n-1 to it means i=7 and 2n-1 =7 to 7=7
// and i=2n-i --> very specific points pe equal .


                        // CORRECT CODE:-
                        // FIRST WE BREAK IT AND MAKE IT SIMPLE BY 
                        // REVERSING IT.

// 1 1 1 1 
// 1 2 2 2
// 1 2 3 3
// 1 2 3 4 

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int min=0;
//         for (int i=1;i<=n;i++){
//                 for (int j=1;j<=n;j++){        
//                         if (i<j) min=i;  // for min.
//                         else min=j;
                        
//                         cout<<min<<" ";
//                 }
//                 cout<<endl;
//         }
// return 0;
// } 


                                       //part 2:

// 1 1 1 1 1 1 1 
// 1 2 2 2 2 2 1
// 1 2 3 3 3 2 1
// 1 2 3 4 3 2 1
// 1 2 3 3 3 2 1
// 1 2 2 2 2 2 1
// 1 1 1 1 1 1 1

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int a,b;
//         int min=0;
//         for (int i=1;i<=2*n-1;i++){
//                 for (int j=1;j<=2*n-1;j++){
//                         a=i;                  // if int a=i and int b=j in loop to bhi sahi.
//                         if (a>n) a=2*n-i;    // if i>n to bhi sahi.
//                         b=j;
//                         if (b>n) b=2*n-j;  // if j>n to bhi sahi
                        
//                         if (a<b) min=a;  // for min.
//                         else min=b;  // if here a then 1111. then 2222..till 7777. 
                        
//                         cout<<min<<" ";
//                 }
//                 cout<<endl;
//         }
// return 0;
// }

                                // part 3: main :-

// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4
// 4 3 2 2 2 3 4
// 4 3 2 1 2 3 4
// 4 3 2 2 2 3 4
// 4 3 3 3 3 3 4
// 4 4 4 4 4 4 4

// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         int min=0;
//         for (int i=1;i<=2*n-1;i++){
//                 for (int j=1;j<=2*n-1;j++){
//                         int a=i;
//                         if (a>n) a=2*n-i;   
//                         int b=j;
//                         if (b>n) b=2*n-j;  
                        
//                         if (a<b) min=a;  
//                         else min=b;          // this min is current min .we have above
                        
//                         int newmin=n-min+1;  // this is new min. we need 
//                         cout<<newmin<<" ";  // or direct n+1-min.
//                 }
//                 cout<<endl;
//         }
// return 0;
// }


//30 . NUMBER TALBE MAST.

                                // TWO PARTS
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;

//         for (int i=1;i<=2*n-1;i++){
//                 if (i<=n){
//                         cout<<i<<" ";
//                 }else{
//                         cout<<2*n-i<<" ";
//                 }
//         }
//         cout<<endl;
//         for (int i=1;i<=n-1;i++){
//                 for (int j=1;j<=n-i;j++){
//                         cout<<j<<" ";
//                 }
//                 for (int k=1;k<=2*i-1;k++){
//                         cout<<"  ";
//                 }
//                 for (int m=n-i;m>=1;m--){
//                         cout<<m<<" ";
//                 }
//                 cout<<endl;
//         }
        
// return 0;
// }


//                          USE OF EXTRA VARIABLE: TWO PARTS
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;

//         for (int i=1;i<=2*n-1;i++){
//                 if (i<=n){
//                         cout<<i<<" ";
//                 }else{
//                         cout<<2*n-i<<" ";
//                 }
//         }
//         cout<<endl;
//         for (int i=1;i<=n-1;i++){
//                 int a=1;
//                 for (int j=1;j<=n-i;j++){
//                         cout<<a<<" ";
//                         a++;
//                 }
//                 for (int k=1;k<=2*i-1;k++){
//                         cout<<"  ";
//                         a++;
//                 }
//                 for (int m=1;m<=n-i;m++){   // from 1 to n-i m++ also right.
//                         cout<<2*n-a<<" ";  // for first time here a=5 we need 3 so...
//                         a++;
//                 }
//                 cout<<endl;
//         }
        
// return 0;
// }


//               my technique: TO BREAK IN 4 PARTS 
// #include <iostream>
// using namespace std;
// int main(){
//         int n;
//         cin>>n;
//         for (int i=1;i<=n;i++){
//                 for (int j=1;j<=n-i+1;j++){
//                         cout<<j<<" ";
//                 }
//                 for (int k=1;k<=i-1;k++){
//                         cout<<"  ";
//                 }
//                 for (int k=1;k<=i-2;k++){
//                         cout<<"  ";
//                 }
//                 if (i==1){
//                 for (int m=1;m<=n-i;m++){ // or n-i to 1 and cout m;
//                         cout<<n-m<<" ";    // as we need 3 but we have 1 so..
//                 }
//                 }else{
//                 for (int m=1;m<=n-i+1;m++){  //or n-i+1 to 1 and cout m;
//                         cout<<n-m<<" ";    // as we need 3 but we have 1 so..
//                 }
//                 }
//                 cout<<endl;
//         }

// return 0;
// }


