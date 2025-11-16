#include <iostream>
#include<vector>
#include <algorithm>
#include <cmath>
using namespace std;
             //que 1: fibonacci sires nth term
int fib(int n){
    //base case:
    if (n==0) return 0;
    if (n==1) return 1;
    // recursive fn.
    int ans =fib(n-1)+ fib(n-2);
    return ans;
}
         // factorial
int f1(int v){
    //base case:
    if (v==1){
        return 1;
    }

    int ans=v*f1(v-1);
    return ans;
}

        // que 3: sum of digits:

        //me:
// int sumOfdigits(int n){
//     if (n==0) return n;

//     int ans= n%10 + sumOfdigits(n/10);
//     return ans;
// }

       // sir:
int sumOfdigits(int n){
    if (n>=0 && n<=9) return n;
    return sumOfdigits(n/10) + (n%10);
}

     // que 4:p power q

// int power(int p ,int q){
//     if (q==0) return 1;
//     return power(p,q-1)*p;
// }

        // sir optimized solution :
int power(int p , int q){
    if (q==0 ) return 1;
    if (q%2==0){
        // q is even 
        int result=power(p,q/2);
        return result * result;
    }
    else{
        // q is odd
        int result=power(p,(q-1)/2);
        return p*result*result;
    }
}

        //que 6: printing all elements of array:
// void f(int arr[],int idx,int size){
//     if (idx==size){
//         return ;
//     }
//     cout<<arr[idx]<<" ";
//     f(arr,idx+1,size);
//     return;
// }

           //que 7 : max of elements

// int maxOfArr(int* arr, int idx,int size){
//     if (idx==size-1) return arr[idx];
    
//     int max=maxOfArr(arr,idx+1,size);
//     if (max<arr[idx]){
//         return arr[idx];
//     }else{
//         return max;
//     }

// }
           //sir
int maxOfArr(int *arr, int idx,int size){
    if (idx==size-1) return arr[idx];

    return max(arr[idx],maxOfArr(arr,idx+1,size));
}

          //que 8 : sum of elements:
int sumOfEle(int * arr, int idx,int size){
    if (idx==size-1) return arr[idx];

    int result = sumOfEle(arr,idx+1,size);
    return arr[idx]+ result;
}

          //que 9. : increasing sequence from 1 to n.
void incSeq(int n){
    if (n==1){
        cout<<n<<" ";
        return ;
    }

    incSeq(n-1);
    cout<<n<<" ";
    return ;
}
        //que 10: printing k multiples of n 
void kmultiplesOfn(int n,int k){
    if (k==1){
        cout<<n*k<<" ";
        return;
    }

    kmultiplesOfn(n,k-1);
    cout<<n*k<<" ";
    return;
}

   //11. printing sum of n natural numbers with alternate +/- sign
   //me:
// int altSum(int n){
//     if (n==1) return n;

//     int result=altSum(n-1);
//     if (n%2==0){
//         return result-n;
//     }else{
//         return result+n;
//     }
// }

  //sir:
int altSum(int n){
    if (n==0) return 0;
    return altSum(n-1)+ ((n%2==0) ? (-n):(n));
}


             //12. GCD
             //me :iterative wrong:
// int gcd(int x,int y){
//     int store1=0;
//     int store2=0;
//     for (int i=0;i<=x;i++){
//         if (x%i==0){
//             store1=i;
//         }
//     }
//     for (int i=0;i<=y;i++){
//         if (y%i==0){
//             store2=i;
//         }
//     }
    
//     if (store1==store2){
//         return store1;
//     }else{
//         return 1;
//     }
// }
     // me : perfect:
// int gcd(int a , int b){
//     if (b==0 ){
//         return a;
//     }
//     if (a>b){
//         return gcd(b,a%b);
//     }
//     else{
//         return gcd(a, b%a);
//     }
// }

     //sir :
int gcd(int a ,int b){
    if (b>a) gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

      //13. armstrong number
    
      //sir:
int Armstrong(int n,int d){
    if (n==0) return 0;
    return power(n%10, d)+ Armstrong(n/10,d);
}

       //me: wrong
// int Armstrong(int n,int d){
//     if (n==0) return 0;
//     int store=n%10;
//     Armstrong(n/10,d);

//     int result=0;
//     result=result+power(store,d);
//     return result;
// }

           //que 14: frog jump problem

           //me: wrong:
// int sub(int a ,int b){
//     if (a>b){
//         return a-b;
//     }else{
//         return b-a;
//     }
// }

// int frogJump(int *arr,int i,int n){
//     if (i==n-1) return arr[i];
//     if (i+1!=n-1){
//     int value1=sub(arr[i],arr[frogJump(arr,i+1,n)]);
//         if (i+2!=n-1){
//             // int value1=sub(arr[i],arr[frogJump(arr,i+1,n)]);
//             int value2=sub(arr[i],arr[frogJump(arr,i+2,n)]);
//             if (value1<value2){
//                 return value1;
//             }else{
//                 return value2;
//             }
//         }
//     }
// }

        //sir:
int frogJump(int *arr,int i,int n){
    if (i==n-1) return 0;
    if (i==n-2) return frogJump(arr,i+1,n)+abs(arr[i]-arr[i+1]);

    return min(frogJump(arr,i+1,n) + abs(arr[i]-arr[i+1]) , frogJump(arr,i+2,n) + abs(arr[i]-arr[i+2]));
}

          // que 15: target value x exist in array or not.
// bool inArray(int *arr, int i, int n,int x,bool a){  //bool a=false
//     if (x==arr[i]) {
//         a=true;
//         return a;
//     }
//     if (i==n-1) return  a;

//     // if (x==arr[i]) return true; // no
//     inArray(arr, i+1, n,x,a);
//     return a;
// }

         //sir :
bool inArray(int *arr,int i,int n, int x){
    if (i==n) return false;

    return (arr[i]==x)|| inArray(arr,i+1,n,x);
}
           // que 16. subsets ka sum
// void subsetsSum(int *arr,int n,int i){
//     if (i<0) {
//         cout<<0<<" ";
//         return;
//     }

//     subsetsSum(arr,n,i-1);
//     cout<<arr[i]+0<<" ";
//     for(int j=i+1;j<n;j++){
//         // cout<<arr[i]+0<<" ";
//         cout<<arr[i]+arr[j]<<" ";
//     }

// }

       //sir : correct
void subsetsSum(int * arr, int n,int i,int sum, vector<int> &result){
    if (i==n) {
        result.push_back(sum);
        return;
    }

    subsetsSum(arr,n,i+1,sum+arr[i],result);
    subsetsSum(arr,n,i+1,sum,result);
}

      //que 17.
// int allPaths(int arr[][m],int n,int m, int  i ,int j,int count){
//     // if (i==n && j==m){
//     //     count++;
//     //     return count;
//     // }
//     if (i==n-1 && j==m-1){
//         count++;
//         i=0;j=0;
//         return count;
//     }
//     if (i==n){
//         j++;
//         return count;
//     }
//     if (j==m){
//         i++;
//         return count;
//     }

//     allPaths(arr,n,m,i+1,j,count);
//     allPaths(arr,n,m,i,j+1,count);
//     return count;
// }

          //que 18: string subsequences>
void strSubseq(string &s,int i,string &empstr){
    //base case:
    if (i==s.size() || s.size()==1 || s.empty()==true){
        return ;
    }
    // cout<<empstr<<endl;
    strSubseq(s,i+1,empstr+=s[i]);
    // cout<<empstr<<endl;
    strSubseq(s,i+1,empstr);
    cout<<empstr<<endl;
}


int main(){
    // que  18
    string s="abc";
    string empstr="";
    strSubseq(s,0,empstr);



    // que 17.
    // int n=2,m=3;
    // int arr[2][3];
    // cout<<allPaths(arr,n,m,0,0,0);
    //que 16
    // int n=2;
    // int arr[]={2,3};
    // vector<int> result;
    // subsetsSum(arr,n,0,0,result);
    // for (int a: result){
    //     cout<<a<<" ";
    // }


    //que 15.
    // bool a=false;
    // cout<<inArray(arr,0,n,8,a);wrong
    // cout<<inArray(arr,0,n,8); //correct
    //que 13.
        // int n;
        // cin>>n;
        // int temp=n;
        // int d=0;
        // while(temp!=0){
        //     temp=temp/10;
        //     d++;
        // }
        // int result=Armstrong(n,d);
        // if (result==n) cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;

return 0;
}