// #include <iostream>
// using namespace std;
// int main(){
//         char vowels[5];
//         // for each
//         for (char &ele : vowels){
//             cin>>ele;
//         }
//         for (char ele:vowels){
//             cout<<ele<<" ";
//         }
//         cout<<endl<<endl;

//         int arr[]{1,2,3,4,5};
//         int length=sizeof(arr)/sizeof(arr[0]);
//         for (int idx=0;idx<length;idx++){
//             cout<<arr[idx]<<"";
//         }
//         cout<<endl;
        
// return 0;
// }

//QUESTION 1:-
// CALCULATE SUM OF ALL ELEMENTS IN ARRAY.
// #include <iostream>
// using namespace std;
// int main(){
//         int arr[]={1,2,3,4,5};
//         int length=sizeof(arr)/ sizeof(arr[0]);
//         int sum=0;
//         for (int i=0;i<length;i++){
//             sum+=arr[i];
//         }
//         cout<<sum<<endl;
// return 0;
// }

// QUESTION 2:-
// MAX. VALUE OUT OF ALL ELE.
    // ME:- wrong .
// #include <iostream>
// using namespace std;
// int main(){
//         int arr[]={222,35,6,111};
//         int length=sizeof(arr)/ sizeof(arr[0]);
//         int store=0;
//         for (int i=0;i<length-1;i++){
//             if (arr[i]<arr[i+1]){
//                 store=arr[i+1];
//                     // break;  isse first big element milega. 
//             }
//         }
//         cout<<store<<endl;
// return 0;
// }

// MAM:- correct.
// #include <iostream>
// using namespace std;
// int main(){
//         int arr[]={2,35,6,111};
//         int length=sizeof(arr)/ sizeof(arr[0]);
//         int max=2;
//         for (int i=1;i<length;i++){
//             if (arr[i]>max){
//                 max=arr[i];
//             }
//         }
//         cout<<max<<endl;
// return 0;
// }



// QUESTION 3:-
// LINEAR SEARCH:- ELEMENT INPUT AND INDEX RETURN.

//me:-

// #include <iostream>
// using namespace std;
// int main(){
//         int arr[]={ 1,32,4,6,8};
//         int k;
//         cin>>k;
//         int idx=0;
//         for (int i=0;i<5;i++){
//             if (k==arr[i]){
//                 idx=i;
//                 break;
//             }else idx=-1; // ya else aur break-> likhne ki bajaye idx ko uper hi -1 likho.
//         }
//         cout<<idx<<endl;
// return 0;
// }

//mam:-
// #include <iostream>
// using namespace std;
// int main(){
//         int arr[]={1,23,43,55,4,6};
//         int key=23;
//         int ans=-1;
//         for (int i=0;i<6;i++){
//             if (key==arr[i]){
//                 ans=i;
//                 // break;   // here optional to make time and space less.
//             }
//         }
//         cout<<ans<<endl;
// return 0;
// }

//4. FIND THE LAST OCCURANCE OF ELEMENT X IN AN ARRAY.
// #include <iostream>
// using namespace std;
// int main(){
//         int arr[]={1,2,3,2,1,3,1};
//         int length=sizeof(arr)/sizeof(arr[1]);
//         int x;
//         cin>>x;
//         int idx=-1;

//         for (int i=0;i<length;i++){
//             if (x==arr[i]){
//                 idx=i;
//             }
//         }

//         //aliter: back se first occurence to break
//         for (int i=length-1;i>=0;i--){
//             if (arr[i]==x){
//                 idx=i;
//                 break;
//             }
//         }

//         cout<<idx<<endl;
// return 0;
// }


// 5 . COUNT NUMBER OF OCCURENCE OF AN ELEMENT.
// #include <iostream>
// using namespace std;
// int main(){
//         int arr[]={1,2,3,3,2,4,3,2,4,1,1,3};
//         int x;
//         int length=sizeof(arr)/sizeof(arr[1]);

//         cin>>x;
//         int c=0;
//         for (int i=0;i<length;i++){
//                 if (x==arr[i]){
//                         c++;
//                 }
//         }cout<<c<<endl;
// return 0;
// }

//6.COUNT THE ELEMENTS STRICTLY GREATER THEN X.
// #include <iostream>
// using namespace std;

// int main(){
//         int arr[]={1,2,3,3,2,4,3,2,4,1,1,3};
//         int length=sizeof(arr)/sizeof(arr[1]);
//         int x;
//         cin>>x;
//         int c=0;
//         for (int i=0;i<length;i++){
//                 if (x<arr[i]){
//                         c++;
//                 }
//         }cout<<c<<endl;
// return 0;
// }

// // 7. SORTED OR NOT. MOSTLY ASCENDING
// #include <iostream>
// using namespace std;
// int main(){
//         int arr[]={1,2,3,4,5,6};
//         int length=sizeof(arr)/sizeof(arr[1]);
//         bool flag=true;
//         for (int i=1;i<length;i++){
//             if (arr[i]<=arr[i-1]){
//                 flag=false;
//             }
//         }cout<<flag<<endl;
// return 0;
// }

//8 . FIND DIFF BETN SUM OF ELE AT EVEN INDICES TO SUM OF ELE AT ODD INDICES.
#include <iostream>
using namespace std;
int main(){
        int arr[]={1,2,3,4,5,6,7,8,9};
        int length=sizeof(arr)/sizeof(arr[1]);

        // way 1 :-

        // int even=0;
        // int odd=0;
        // for(int i=0;i<length;i++){
        //     if (i%2==0){
        //         even+=arr[i];
        //     }else{
        //         odd+=arr[i];
        //     }
        // }
        // int diff=even-odd;
        // cout<<diff<<endl;

        // way2:-
        int sum=0;
        for (int i=0;i<length;i++){
            if (i%2==0){
                sum+=arr[i];
            }else{
                sum-=arr[i];
            }
        }cout<<sum<<endl;
return 0;
}