#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

             //1. pascal's triangle.
             //wrong:
//call fn f
// int f(int n){
    //     int row=n;
    // int col=2*n-1;
//         int pascal[row][col];
//         for (int i=0;i<row;i++){
//             for (int j=0;j<col;j++){

//                 //printing spaces:-
//                 // int k=n-i-1;
//                 // while(k--){
//                 //     cout<<" ";
//                 // }
//                 //printing 1:-
//                 if (j==n/2-i || j==n/2+i){
//                     cout<<1<<" ";
//                 }
//                 // mid values:-
//                 // int value=pascal[i][j];//no
//                 if (j<n/2-i && j>n/2+i){
//                 int value=pascal[i-1][n/2-1]+pascal[i-1][n/2+1];
//                 pascal[i][j]=value;
//                 cout<<pascal[i][j]<<" ";
//                 }

//             }
//             cout<<endl;
//         }

// }

                 //me:2
//call fn f
// int f(int n){
       //wrong:

// int row=n;
// int col=2*n-1;
// int pascal[row][col];
// for(int i=0;i<n;i++){
//     int a=(2*n-i-1)/2;
//     for (int j=0;j<a;j++){
//         cout<<"  ";
//     }
//     for(int k=a;k<col;k++){
//         if (k==n/2-i || k==n/2+i){
//             cout<<1<<" ";
//         }

//         int value=pascal[i-1][n/2-1]+pascal[i-1][n/2+1];
//         pascal[i][k]=value;
//         cout<<pascal[i][k]<<" ";
//     }cout<<endl;
// }


// }

          //mam: way 1:
          //CORRECT:
// vector<vector<int>> pascalTriangle(int &n){
//     vector<vector<int>> pascal(n);
//     for (int i=0;i<n;i++){
//         // vector<int> ith_vector=pascal[i];
//         // ith_vector.resize(i+1);
//         pascal[i].resize(i+1);
        
//         for (int j=0;j<i+1;j++){
//             if (j==0 || j==i){
//                 pascal[i][j]=1;
//             }else{
//                 pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
//             }
//         }
//     }

//     return pascal;
// }

        //mam :2
        //CORRECT:
// int fact(int n){
//     if (n==0 ||n==1) return 1;
//     return n*fact(n-1);
// }
// int combination(int i ,int j){
//     int k=fact(i)/(fact(j)*fact(i-j));
//     return k;
// }
// vector<vector<int>> pascalTriangle(int n){
//     vector<vector<int >> pascal (n);
//     for (int i=0;i<n;i++){
//         pascal[i].resize(i+1);
//         for (int j=0;j<i+1;j++){
//             if (j==0 || j==i) pascal[i][j] =1;
//             else{
//                 pascal[i][j]=combination(i,j);
//             }

//         }
//     }
//     return pascal;
// }

             // me:3 correct appraoch:
// vector<vector<int>> pascalTriangle(int n){
//     int m=2*n-1;
//     vector<vector<int>> pascal(n,vector<int>(m,0));

//     for (int i=0;i< n;i++){
//         for(int j=0;j<m;j++){
//             if (j==m/2-i || j==m/2+i){
//                 pascal[i][j]=1;
//             }
//             else if (j> m/2-i && j< m/2+i){  // isko if mei bhi likh sakte hain else ki no requirement
//                 pascal [i][j]=pascal[i-1][j-1]+pascal[i-1][j+1];
//             }else{
//                 pascal[i][j]=0;
//             }
//         }
//     }

//     return pascal;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> ans(n);
//     ans=pascalTriangle(n);
    
//     for (int i=0;i<ans.size();i++){
//     //     for(int k=0;k<n-i-1;k++){
//     //         cout<<"  ";
//     //     }
//         for (int j=0;j<ans[i].size();j++){

//             //eliminating zeroes in me3.
//             if (ans[i][j]==0){
//                 cout<<"  ";
//             }
//             else{
//             cout<<ans[i][j]<<" ";
//             }

//             // cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }

// return 0;
// }



            //QUE 2. row with max no. of 1's:
         //me:
// int maxOnes(vector<vector<int>> mat){
//     int count=-1;
//     // int c=0;
//     int row=-1;
//     for (int i=0;i<mat.size();i++){
//         int c=0;
//         for (int j=0;j<mat[i].size();j++){
//             if (mat[i][j]==1){
//                 c++;
//             }
//         }

//         if (count<c){
//             count=c;
//             row=i;
//         }

//     }
//     return row;
// }

          //mam:1
// int maxOnes(vector<vector<int>> &v){
//     int max=-1;
//     int maxRow=-1;
//     int columns=v[0].size();
//     for (int i=0;i<v.size();i++){
//         for (int j=0;j<v[i].size();j++){
//             if (v[i][j]==1){
//                 int noOfones=columns-j;
//                 if (max<noOfones){
//                     max=noOfones;
//                     maxRow=i;
//                 }
//                 break;
//                 }
//         }
//     }
//     return maxRow;
// }


      //mam:2
// int maxOnes(vector<vector<int>> &v){
//     int leftmostones=-1;
//     int maxrows=-1;
//     // int j=v.size()-1;
//     int j=v[0].size()-1;
//     while(j>=0){
//         if (v[0][j]==1){
//         leftmostones=j;
//         maxrows=0;
//         }
//         j--;
//     }

//     for (int i=1;i<v.size();i++){
//         j=v[i].size()-1;
//         while(j>=0 ){
//             if (v[i][j]==1 && leftmostones>j){
//             leftmostones=j;
//             maxrows=i;
//             }
//             j--;
//         }
//     }
//     return maxrows;

// }
// int main(){
    
//     // vector<vector<int>> mat(5,4);// initialization mat filled with zeroes.
//     vector<vector<int>> mat;
//     mat={{0,0,1,1},{0,0,0,1},{0,1,1,1},{0,0,0,0},{0,0,0,1}};

//     int ans=maxOnes(mat);
//     cout<<ans<<endl;
// }


             //3. rotation of a square matrix
     //me: using extra space.
// vector<vector<int>> rotateby90(vector<vector<int>> &v){
//     vector<vector<int>> a(v.size(),vector<int>(v.size()));
//     int m=v.size()-1;
//     for (int i=0;i<v.size();i++){
//         for(int j=0;j<v[i].size();j++){
//             // a[i][j]=v[j][m-i];//270 
//             a[j][m-i]=v[i][j];//90
//         }
//     }

//     return a;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> v(n,vector<int>(n));
//     for (int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>v[i][j];
//         }
//     }
//     vector<vector<int>> ans =rotateby90(v);
//     for (int i=0;i<n;i++){
//         for (int j=0;j<n;j++){
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }

// }


            //mam: no extra space.
// void rotate(vector<vector<int>> &v){
//     int n=v.size();
//     for (int i=0;i<n;i++){
//         for(int j=0;j<i;j++){
//             swap(v[i][j],v[j][i]);
//         }
//     }

//     for (int i=0;i<n;i++){
//         reverse(v[i].begin(),v[i].end());
//     }

//     return;
// }

//     int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> v(n,vector<int>(n));
//     for (int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>v[i][j];
//         }
//     }
//     rotate(v);
//     for (int i=0;i<n;i++){
//         for (int j=0;j<n;j++){
//             cout<<v[i][j]<<" ";
//         }cout<<endl;
//     }

// }


       //4. traversing matrix of N*M in spiral order.
       //me:

// void spiralTraverse(vector<vector<int>> &v){
//     int i=0;
//     int j=0;
//     int n=v.size();
//     int m=v[0].size();
//     int a=0;
//     while(){
//         while(j<m){
//             cout<<v[i][j]<<" ";
//             j++;
//         }
//         while(i<n){
//             cout<<v[i][j]<<" ";
//             i++;
//         }
//         while(j>=0){
//             cout<<v[i][j]<<" ";
//         }

//         while(i>a){
//             cout<<v[i][j]<<" ";
//         }
//     }
// }

                //mam:
// void spiralTraverse(vector<vector<int>> &v){
//     int top=0;
//     int bottom=v.size()-1;
//     int front=0;
//     int back=v[0].size()-1;
//     int direction = 0;;
//     while(top<=bottom && front <=back){
//         if (direction==0){
//             int i=top;// for loop ke ander to bhi same.
//             for (int j=front;j<=back;j++){
//                 // int i=top;
//                 cout<<v[i][j]<<" ";
//             }
//             top++;
//         }else if (direction==1){
//             int j=back;
//             for (int i=top;i<=bottom;i++){
//                 // int j=back;
//                 cout<<v[i][j]<<" ";
//             }
//             back--;
//         }else if (direction==2){
//             int i=bottom;
//             for (int j=back;j>=front;j--){
//                 // int i=bottom;
//                 cout<<v[i][j]<<" ";
//             }
//             bottom--;
//         }
//         else{
//             int j=front;
//             for (int i=bottom ;i>=top;i--){
//                 // int j=front;
//                 cout<<v[i][j]<<" ";
//             }
//             front++;
//         }

//         direction++;
//         direction=direction%4;
//     }
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> v(n,vector<int> (m));
//     for (int i=0;i<n;i++){
//         for (int j=0;j<m;j++){
//             cin>>v[i][j];
//         }
//     }

//     spiralTraverse(v);
// }

      // que 5 >> spiral order filling

// void spiralFill(vector<vector<int>>&v){
//     int direction=0;
//     int top=0;
//     int bottom=v.size()-1;
//     int left=0;
//     int right=v[0].size()-1;
//     int count=1;
//     while(left<=right && top<=bottom){
//         if (direction==0){
//             for (int col=left;col<=right;col++){
//                 v[top][col]=count;
//                 count++;
//             }
//             top++;
//         }else if (direction==1){
//             for(int row=top;row<=bottom;row++){
//                 v[row][right]=count;
//                 count++;
//             }
//             right--;
//         }else if (direction ==2){
//             for (int col=right;col>=left;col--){
//                 v[bottom][col]=count;
//                 count++;
//             }
//             bottom--;
//         }else{
//             for (int row=bottom;row>=top;row--){
//                 v[row][left]=count;
//                 count++;
//             }
//             left++;
//         }
//         direction=(direction+1)%4;
//     }

//     for (int i=0;i<v.size();i++){
//         for (int j=0;j<v[i].size();j++){
//             cout<<v[i][j]<<" ";
//         }cout<<endl;
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> v(n, vector<int>(n));
//     spiralFill(v);
// }

                //que 6 : rectangle sum:
               //me : brute force method.
// int rectSum(vector<vector<int>> &v,int l1,int r1,int l2,int r2){
//     int top=l1;
//     int bottom=l2;
//     int left=r1;
//     int right=r2;
//     int ans=0;
//     for (int i=top;i<=bottom;i++){
//         for (int j=left; j<=right;j++){
//             ans+=v[i][j];
//         }
//     }

//     return ans;
// }

        // method 2:row wise prefix sum:
// int rectSum(vector<vector<int>> &v,int l1,int r1,int l2,int r2){
//     int sum=0;

//     //prefix sum array row - wise:-
//     for (int i=0;i<v.size();i++){
//         for (int j=1;j<v[0].size();j++){
//             v[i][j]+=v[i][j-1];
//         }
//     }
    
//     //print 2d array
//     for (int i=0;i<v.size();i++){
//         for (int j=0;j<v[0].size();j++){
//             cout<<v[i][j]<<"  ";
//         }cout<<endl;
//     }

//     for (int i=l1;i<=l2;i++){
//         if (r1!=0){
//             sum+=v[i][r2]-v[i][r1-1];
//         }
//     }

//     return sum;

// }
          //method 3: row col sum
// int rectSum(vector<vector<int>> &v,int l1,int r1,int l2,int r2){
//     int sum=0;
//     //prefix sum array  row wise
//     for (int i=0;i<v.size();i++){
//         for (int j=1;j<v[0].size();j++){
//             v[i][j]+=v[i][j-1];
//         }
//     }

//     //prefix sum array col wise
//     for (int i=1;i<v.size();i++){
//         for (int j=0;j<v[0].size();j++){
//             v[i][j]+=v[i-1][j];
//         }
//     }
//     //printing 2d array:-
//     for (int i=0;i<v.size();i++){
//         for (int j=0;j<v[0].size();j++){
//             cout<<v[i][j]<<"  ";
//         }cout<<endl;
//     }
    
//     int topSum=0,leftSum=0,topLeftSum=0;
//     if (l1!=0) topSum=v[l1-1][r2];
//     if (r1!=0) leftSum=v[l2][r1-1];
//     if (l1!=0 && r1!=0) topLeftSum=v[l1-1][r1-1];

//     sum=v[l2][r2]-topSum-leftSum+topLeftSum;
//     return sum;
// }

// int main(){
//     int n, m;
//     cin>>n>>m;
//     vector<vector<int>> v(n,vector<int>(m));
//     for (int i=0;i<v.size();i++){
//         for (int j=0;j<v[i].size();j++){
//             cin>> v[i][j];
//         }
//     }

//     for (int i=0;i<v.size();i++){
//         for (int j=0;j<v[0].size();j++){
//             cout<<v[i][j]<<"  ";
//         }cout<<endl;
//     }

//     int l1,r1,l2,r2;
//     cin>>l1>>r1>>l2>>r2;

//     cout<<rectSum(v,l1,r1,l2,r2);

// }



