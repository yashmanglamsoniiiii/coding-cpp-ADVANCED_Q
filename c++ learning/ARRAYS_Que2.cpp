#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

            //que 7.sort 0 and 1
            //me:
// void sort01(int *arr,int n){
//     for (int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){

//             if (arr[i]>arr[j]){ // or if arr[j]==0
//                 int temp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=temp;
//                 break;
//             }

//         }
//     }

//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
        
//     }
// }

          //mam:
// void sort01 (vector<int> &v){
//     int count=0;
//     for (int ele:v){
//         if (ele==0) count++;
//     }

//     for (int i=0;i<v.size();i++){
//         if (i<count) v[i]=0;
//         else v[i]=1;
//     }

//     for (int i=0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     }
// }

                  //que 2. even at begin and odd at last. (relative order doesnt matter)
void sorteo(vector<int> &v){
    int left_ptr=0;
    int right_ptr=v.size()-1;
    while(left_ptr<right_ptr){

        if (v[left_ptr]%2!=0 && v[right_ptr]%2==0){
            int temp=v[left_ptr];
            v[left_ptr++]=v[right_ptr];
            v[right_ptr--]=temp;
            // left_ptr++; right_ptr--;
            
        }
        if (v[left_ptr]%2==0)  left_ptr++;
        
        if (v[right_ptr]%2!=0) right_ptr--; 
    }
    return ;
}

              // method 2:
// void sorteo(vector<int> &v){
//     for (int i=0;i<v.size();i++){
//         for (int j=i+1;j< v.size();j++){
//             if (v[j]%2==0   ){
//                 swap(v[j],v[i]);
//                 break;
//             }
//         }
//     }
// }

                   //que 9. give array  where each element is squre of its but in sorted order
// void sort(vector<int> &v){
//     for (int i=0;i<v.size();i++){
//         for (int j=i+1;j<v.size();j++){
//             if (v[j]<v[i]){
//                 swap(v[i],v[j]);
//                 break;
//             }
//         }
//     }

// }
// void sqsort(vector<int> &v){
//     for (int i=0 ;i<v.size();i++){
//         v[i]=v[i]*v[i];
//     }
//     sort(v);
// }


          //mam:
void sqsort(vector<int> &v){
    int l=0;
    int r=v.size()-1;
    vector<int> ans;
    // for(int i=0;i<v.size();i++){
    while(l<=r){
        if (abs(v[l])>abs(v[r])){
            ans.push_back(v[l]*v[l]);
            l++;
        }else{
            ans.push_back(v[r]*v[r]);
            r--;
        }
    }
    reverse(ans.begin(),ans.end());

    for (int i=0 ;i<v.size();i++){
        cout<< ans[i]<<" ";
    }cout<<endl;
    return;
}


              //10. prefix sum:-
// int sum
void prefixSum(vector<int> &v){
    for (int i=0;i< v.size();i++){
        if (i==0)  v[i]=v[i]+0;
        else v[i]=v[i]+v[i-1];
    }
    for (int i=0;i<v.size();i++)
{
    cout<<v[i]<<" ";
}
}

// in new array:
int add(vector<int> &v,int strtpos,int endpos){
    int ans=0;
    for (int i=0;i<=endpos;i++){
        ans=ans +v[i];
    }
    return ans;
}

void pS(vector<int> &v){
    vector<int> newarr(v.size());
    // int j=0;
    for (int i=0;i<v.size();i++){
        newarr[i]=add(v,0,i); // new i se bhi as size to same

    }
    for (int i=0;i<newarr.size();i++){
        cout<<newarr[i]<<" ";
    }
}

           // que 11. partition array with equal sum just check.

           // me: wrong:
// bool parCheck(vector<int> &v){
//     int prefix=0;
//     int suffix=0;
//     int left=0;
//     int right=v.size()-1;
//     while(left<=right){
//         // pehle kuch dalo 
//         prefix+=v[left];
//         suffix+=v[right];
//         if (prefix>suffix) right--;
//         if (suffix>prefix) left++;
//         if (suffix==prefix ) return true;
//         // else {left++; right--;}
//     }
//     return false;
// }

           //me 2:
// bool parCheck(vector<int> &v){
    
//     int left=0;
//     int right=v.size()-1;

//     int prefix=v[left];
//     int suffix=v[right];
//     while(left<=right){
        
//         if (prefix>suffix) {
//             right--;
//             suffix+=v[right];
//         }
//         if (suffix>prefix) {
//             left++;
//             prefix+=v[left];
//         }
//         if (suffix==prefix ) return true;
//         // else {left++; right--;}
//     }
//     return false;
// }

      //mam 1: 
// bool parCheck(vector<int> &v){
//     int prefix=0;
//     int suffix=0;
//     for (int i=0;i<v.size();i++){
//         prefix+=v[i];
//         suffix=0;
//         for (int j=i+1;j<v.size();j++){
//             suffix+=v[j];
//         }
//         if (prefix==suffix) return true;
//     }
//     return false;
// }

       //mam 2:
bool parCheck(vector<int> &v){
    int total=0;
    for (int i=0;i<v.size();i++){
        total+=v[i];
    }

    int prefix=0;
    for (int i=0;i<v.size();i++){
        prefix+=v[i];
        int suffix=total-prefix;
        if (suffix==prefix) return true;
    }
    return false; 
}
// int main(){
//     vector<int> v;
//     int n;cin>>n;
//     for (int i=0;i<n;i++){
//         int ele;cin>>ele;
//         v.push_back(ele);
//     }
//     cout<<parCheck(v);
//     // for (int i=0 ;i<v.size();i++){
//     //     cout<< v[i]<<" ";
//     // }cout<<endl;
//         // int arr[]= {1,1,0,1,0,};
//         // int n=sizeof(arr)/sizeof (arr[0]);
//         // sort01(arr, n);
// return 0;
// }



          // que12. q queries to calculate  defined sums

// int randomSum(vector<int> &v, int l ,int r){
//     int ans=0;
//     for(int i=l-1;i<=r-1;i++){
//     ans+=v[i];
//     }
//     return ans;
// }
// int main(){
//     vector<int> v;
//     int n;
//     cin>>n;
//     // for (int i=0;i<v.size();i++){
//     //     cin>>v[i];                       abhi kaise decide hoge pehle hi v.size mei kuch nhi hai
//     // }
//     for(int i=0;i<n;i++){
//         // cin>>v[i];
//         int ele;
//         cin>>ele;
//         v.push_back(ele);
//     }

//     int left;
//     int right;
//     int q;
//     cin>>q;
//     while(q--){
//     cin>>left;
//     cin>>right;
//     if (left > v.size() || right > v.size()) {
//         cout<<"invalid";
//         break;
//     }
//     cout<<"sum : "<<randomSum(v,left,right);

//     }
// }

           //mam:
// int main(){
//     int n; cin>>n;
//     vector<int> v(n+1,0);
//     for (int i=1;i<=n;i++){
//         cin>>v[i];
//     }

//     //making prefix sum:
//     for (int i=1;i<=n;i++){
//         v[i]=v[i]+v[i-1];
//     }

//     int q;cin>>q;
//     while(q--){
//         int l,r;
//         cin>>l>>r;
//         int ans=0;
//         ans=v[r]-v[l-1];
//         cout<<ans<<endl;
//     }
// }  

           //que 13. sorting two diff arrays.
void sortTwo(vector<int> &arr1,vector<int> &arr2, int m,int n){
    vector<int> arr(m+n);
    int i=0;
    int j=0;
    int index=0;
    while(i!=m || j!=n){
        if (arr1[i]<arr2[j]){
            arr[index]=arr1[i];
            i++;
        }else{
            arr[index]=arr2[j];
            j++;
        }
        index++;
    }

    if (i==m){
        while(j!=n){
            arr[index]=arr2[j];
            index++;j++;
        }
    // }else{
    //     while(i!=m){
    //         arr[index]=arr[i];
    //         index++;i++;
    //     }
    // }
    if(j==n){
        while(i!=m){
            arr[index]=arr1[i];
            index++;i++;
        }
    }

    for (int i=0;i<m+n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
}

//que 14. find pair equals to target sum.
// void targetPair(vector<int> &v,int target){
//     for (int i=0;i<v.size();i++){
//         for (int j=0;j<v.size();j++){
//             if (v[i]+v[j]==target){
//                 cout<<"yes"<<endl;
//                 // break; 
//                 return ;
//             }
//         }
//     }

//     cout<<"no"<<endl;
// }

        //sir
bool targetPair(vector<int> &v,int x){
    int i=0;
    int j=v.size()-1;
    bool found=false;
    while(i<j){
        if (v[i]+v[j]==x){
            found=true;
        }
        else if(v[i]+v[j]<x){
            i++;
        }else{
            j--;
        }
    }
    return found;
}

            //15. targetdiff
bool targetDiff(vector<int> &v, int x){
    // int i=0;int j=v.size()-1;
    // bool found=false;
    // while(i<j){
    //     if (abs(v[i]-v[j])==x){
    //         found=true;
    //     }
    //     else if(abs(v[i]-v[j])<x)
    // }

    int i=0;
    int j=1;
    bool found=false;
    while(i<v.size() && j<v.size()){
        if (abs(v[i]-v[j]==x)){
            found =true;
            break;
        }
        else if (abs(v[i]-v[j])<x){
            j++;
        }else{
            i++;
        }
    }
    return found;
}
      //que 16: sorted square array.
void sqsortedArray(vector<int> &v){
    vector<int> ans(v.size());
    int i=0 ;
    int j=v.size()-1;
    int k=ans.size()-1;
    while(i<=j && k>=0){
        if (abs(v[i])>abs(v[j])){
            ans[k]=v[i]*v[i];
            k--;
            i++;
        }else{
            ans[k]=v[j]*v[j];
            k--;
            j--;
        }
    }

    for (int i=0;i<v.size();i++){
        cout<<ans[i]<<" ";
    }
}

       //que 17. unique pairs' sum=target
void uniquePairs(vector<int> &v, int x){
    int count=0;
    for (int i=0;i<v.size();i++)
    {
        if (v[i]==-2){
            continue; // break se loop se bahar.
        }
        for (int j=i+1;j<v.size();j++){

            if (v[j]==-2) continue;

            if (v[i]+v[j]==x){
                cout<<v[i]<<" , "<<v[j]<<endl;
                count++;
                // break;
            
            //array manipulation se jo aagya hai vo numbers change to -2;
            for (int k=0;k<v.size();k++){
                if (v[k]==v[i]|| v[k]==v[j]){
                    v[k]=-2;
                }

            }

            break;
            }
        }
    }

    cout<<count<<endl;
}

 //18 . count unique triplets
void tripletsUniq(vector<int> v, int x){
    int c=0;
    // int i=0;int j=v.size()-1;
    int k=1;
    while(k<v.size()){

        if (v[k]==v[k-1] ) k++;
        
        int y=x-v[k];
        int i=0; int j=v.size()-1;

        // v[k]==v[k-1]  not here as phir y ki value update.
        while(i<j){

            if (i==k) i++;
            if (j==k) j--;

            if (v[i]+v[j]==y){
                cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
                i++;
                j--;
                c++;
            }else if (v[i]+v[j]<y){
                i++;
            }else{
                j--;
            }
            // k++;
        }
        k++;
    }
    cout<<c;
}


int main(){
vector<int> v={-4,-1,-1,0,1,2};
tripletsUniq(v,0);
//     int m,n; 
//     cin>>m>>n;

//     vector<int> arr1(m);
//     for (int i=0;i<m;i++){
//         cin>>arr1[i];
//     }

//     vector<int> arr2(n);
//     for (int i=0;i<n;i++){
//         cin>>arr2[i];
//     }
    
//     sortTwo(arr1,arr2,m,n);
}


