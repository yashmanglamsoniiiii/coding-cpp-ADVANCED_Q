#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
         // que 1 : pairs whose sum = x
         //me:

int pairSum(int* arr, int n , int x){
    int count=0;

    for(int i=0 ;i<n;i++){
        int s=x-arr[i];
        for(int j=0;j<n;j++){
            if (arr[j]==s){
                count++;
            }
        }
    }
    return count/2;
}

                  // que 2: no .of triplets of target sum.
int tripSum(int *arr,int l,int x){
    int triplets=0;
    for (int i=0;i<l;i++){
        for (int j=i+1;j<l;j++){
            for (int k=j+1;k<l;k++){
                if (arr[i]+arr[j]+arr[k]==x){
                    triplets++;
                }
            }
        }
    }
    return triplets;
}

                    //que 3. unique no. in an array
                  //me: wrong
// int UniqNo(int* arr, int n){
//     for(int i=0;i<n;i++){
//         int count=0;
//         for (int j=i+1;j<n;j++){
//             if (arr[i]==arr[j]){
//                 count++;
//             }
//         }
//         if (count==0){
//             return arr[i];
//         }
//     }
//     return -1;
// }

       //mam:
// int UniqNo(int* arr,int n){
//     for (int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){
//             if (arr[i]==arr[j]){
//                 arr[i]=arr[j]=-1;
//             }
//         }
//     }
//     int unique=0;
//     for (int i=0 ;i<n;i++){
//         if (arr[i]>0){
//             unique=arr[i];
//         }
//     }
//     return unique;
// }

           // my version: 
int UniqNo(int *arr, int n){
    
    for(int i=0;i<n;i++){
        int count=0;
        if (arr[i]==-1) continue;
        for (int j=i+1;j<n;j++){
            if (arr[j]==-1) continue;
            if (arr[i]==arr[j]){
                arr[i]=arr[j]=-1;
                count++;
            }
        }
        if (count==0 && arr[i]>0 ){ // count 0  usi ka
            return arr[i];
        }

    }
    return -1;
}


            //que 4. second_LARGEST element
            //me: 3 loops
// int sec_larg(int *arr, int n){
//     int max=-1;
//     for (int i=0;i<n;i++){
//         if (arr[i]>max){
//             max=arr[i];
//         }
//     }
//     for(int i=0;i<n;i++){
//         if (arr[i]==max){
//             arr[i]=-1;
//         }
//     }
//     int sec_l=-2;
//     for (int i=0;i<n;i++)
//     {
//         if (arr[i]>sec_l && arr[i]<max){
//             sec_l=arr[i];
//         }
//     }

//     return sec_l;
// }

            //me: two loops 
int sec_larg(int *arr, int n){
    int max=-1;
    for (int i=0;i<n;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }

    int sec_l=-1;
    for (int i=0;i<n;i++)
    {
        if (arr[i]>sec_l && arr[i]<max){
            sec_l=arr[i];
        }
    }

    return sec_l;
}

          // 5. rotate by k ->array
// void rotatebyK(int* arr,int n,int k){
//     // int last=-1;  // all -1 mie converted
//     while(k--){
        
//         // arr[0]=arr[n-1]; here too like jo niche bola .
//         // arr[n-1]=last;wrong >> all-1
//         int last=arr[n-1]; // >>15555
//         for(int i=1;i<=n-1;i++){
//             arr[i]=arr[i-1];
//         }
//         // arr[n-1 ]  mei arr [n-2 ] ki value means lost 
//         // therefore store it before for loop .
//         arr[0]=last;
//     }

//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// void rotatebyK (int* arr, int n, int k){
//     while(k--){
//         for (int i=0;i<n;i++){
//             if (n==0) i=n-1;
//             i=i-1;
//         }
//     }

//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

       //mam:
// void rotatebyK(int* arr,int n,int k){
//     k=k%n;
//     int ans[n];
//     int j=0;
//     for (int i=n-k;i<n;i++){
//         ans[j++]=arr[i];
//     }
//     for(int i=0;i<=n-k-1;i++){// mam ka thoda sa galat i<=k kuch ke liye sahi kuch ke liye galat.
//         ans[j++]=arr[i];
//     }

//     for(int i=0;i<n;i++){
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
// }
void rotatebyK(vector<int> v, int k){
    k=k%v.size();
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    for(int a:v){
        cout<<a<<" ";
    }cout<<endl;
}
          //que 6: check query
          //me attempt 1: wrong.
// void checkQuery(int *arr,int *query,int n1,int n2){
//     for (int i=0;i<n2;i++){
//         for (int j=0;j<n1;j++){
//             if (query[i]==arr[j]){
//                 cout<<"yes"<<endl;
//                 break;
//             }
//             else {
//                 cout<<"no"<<endl;
//                 break;
//         }
//     }
//     }
// }
              // attempt 2:

void checkQuery(int *arr,int *query,int n1,int n2){
    // bool flag=false;

    for (int i=0;i<n2;i++){
        bool flag=false;
        for (int j=0;j<n1;j++){
            if (query[i]==arr[j]){
                cout<<"yes"<<endl;
                flag=true;
                break;
            }
    }

    if (flag==false) cout<<"no"<<endl;
    }
}

              // attempt 3:
// void checking(int *&arr,int n1 , int &queryNo){
//     for (int i=0;i<n1;i++){
//         if (queryNo==arr[i]){ // har baar each element ko compare if hai to yes agar nhi to
//             cout<<"YES"<<endl; 
//             return;
//         }
//     }
//     cout<<"NO"<<endl;// agar nhi to no from loop ke bahar. varna each comparison pe yes no .....
// }
// void checkQuery(int* arr,int* query , int n1 , int n2){
//     for (int i=0;i<n2;i++){
//         checking(arr, n1, query[i]);
//     }
// }



// int main(){
//     //que 6
//     int arr[]={2,3,5,6,7,8};
//     int na=sizeof(arr)/sizeof(arr[0]);
//     int nq;
//     cin>>nq;
//     int query[nq];
//     for (int &a: query){
//         cin>>a;
//     }
//     checkQuery(arr,query,na,nq);
//     //que 5
//         // vector<int> v= {1,2,3,4,5,6,7};
//         // // int length=sizeof (arr)/sizeof (arr[0]);
//         // rotatebyK(v,4);
// return 0;
// }



              //que 6 :mam:
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    const int N=1e5+10;
    vector<int> freq(N,0);

    for (int i=0 ;i<n;i++){
        freq[v[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        int queryEle;
        cin>>queryEle;
        cout<<freq[queryEle]<<endl;
    }
}
