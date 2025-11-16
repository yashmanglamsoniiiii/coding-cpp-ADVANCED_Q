#include <iostream>
using namespace std;

             //que 1 : matrix multiplication
// int main(){
//     int r1,c1;
//     cin>>r1>>c1;
//     int A[r1][c1];
//     for (int i=0;i<r1;i++){
//         for (int j=0;j<c1;j++){
//             cin>>A[i][j];
//         }
//     }

//     int r2,c2;
//     cin>> r2>>c2;
//     int B[r2][c2];
//     for (int i=0;i<r2;i++){
//         for (int j=0;j<c2;j++){
//             cin>>B[i][j];
//         }
//     }

//     int C[r1][c2];
//     for (int i=0;i<r1;i++){
//         for (int j=0;j< c2;j++){
//             int value=0;
//             for(int k=0;k<r2;k++){
//                 value+=A[i][k]*B[k][j];
//             }
//             C[i][j]=value;
//         }
//     }

//     for (int i=0;i<r1;i++){
//         for (int j=0;j< c2;j++){
//             cout<<C[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// return 0;
// }

           // que 2: transpose of a matrix.
  //me: wrong:
// int main(){
//     int r ,c;
//     cin>>r>>c;
//     int mat[r][c];
//     for (int i=0;i<r;i++){
//         for (int j=0;j<c;j++){
//             cin>>mat[i][j];
//         }
//     }

//     //displaying transpose:
//     for (int i=0;i<r;i++){
//         for (int j=0;j<c;j++){
//             cout<<mat[j][i]<<" ";
//         }cout<<endl;
//     }
// }
  //mam:
int main()
{
    int r,c;cin>>r>>c;
    int mat[r][c];
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }

    int tmat[c][r];
    for(int i=0;i<c;i++){
        for (int j=0;j<r;j++){
            tmat[i][j]=mat[j][i];
        }
    }

    for (int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout<<tmat[i][j] <<" ";
        }cout<<endl;
        }
}