// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
        // vector<int> v;
        // cout<<"capacity : "<<v.capacity()<<endl;
        // cout<<"size : "<<v.size()<<endl;

        // v.push_back(1);
        // cout<<"capacity : "<<v.capacity()<<endl;
        // cout<<"size : "<<v.size()<<endl;

        // v.push_back(2);
        // cout<<"capacity : "<<v.capacity()<<endl;
        // cout<<"size : "<<v.size()<<endl;

        // v.push_back(3);
        // cout<<"capacity : "<<v.capacity()<<endl;
        // cout<<"size : "<<v.size()<<endl;

        // v.push_back(4);
        // cout<<"capacity : "<<v.capacity()<<endl;
        // cout<<"size : "<<v.size()<<endl;

        // v.push_back(5);
        // cout<<"capacity : "<<v.capacity()<<endl;
        // cout<<"size : "<<v.size()<<endl;

        // v.insert(v.begin()+2,10);
        // v.insert(v.end()-2,10);  //same as above.

        // v.resize(10);
        
        // cout<<"capacity : "<<v.capacity()<<endl;
        // cout<<"size : "<<v.size()<<endl;

        // v.pop_back();
        // v.pop_back();
        // cout<<"capacity : "<<v.capacity()<<endl;
        // cout<<"size : "<<v.size()<<endl;



        // vector <int> v;
        // for (int i=0;i<5;i++){
        //     int elements;
        //     cin>>elements;
        //     v.push_back(elements);
        // }

        //or to in:- IF SIZE IS DEFINED.
        // vector <int> v(5);
        // for (int i=0;i<5;i++){
        //     cin>>v[i];
        // }
        
        
        //for 
        // for (int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }cout<<endl;

        // v.insert(v.begin()+2, 100);
        //for each
        // for (int ele: v){
        //     cout<<ele<<" ";
        // }cout<<endl;


        // v.erase(v.end()-2);
        // while
//         int idx=0;
//         while (idx<v.size()){
//             cout<<v[idx++]<<" ";
//         }cout<<endl;

// return 0;
// }

                         // QUESTIONS
//1. FIND THE LAST OCCURANCE OF ELEMENT X IN AN ARRAY.
// #include <iostream>
// #include<vector>
// using namespace std;
// int main(){

//         vector<int> v;
//         v.push_back(1);
//         v.push_back(2);
//         v.push_back(3);v.push_back(2);v.push_back(1);v.push_back(3);
//         v.push_back(1);

//         int x;
//         cin>>x;
//         int idx =-1;


//         for (int i=0;i<v.size();i++){
//                 if (x==v[i]){
//                         idx=i;
//                 }
//         }

//         //aliter:back se first occurence to break
//         for (int i=v.size()-1;i>=0;i--){
//                 if (v[i]==x){
//                         idx=i;
//                         break;
//                 }
//         }

//         cout<<idx<<endl;
// return 0;
// }

//2. COUNT THE NUMBER OF OCCURENCES OF AN ELEMENT.
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//         vector <int> v(6);
//         for (int i=0;i<v.size();i++){
//                 cin>>v[i];
//         }
//         int x;
//         cin>>x;
//         int c=0;
//         for (int i=0;i<v.size();i++){
//                 if (x==v[i]){
//                         c++;
//                 }
//         }cout<<c<<endl;
// return 0;
// }

//3.COUNT THE ELEMENTS STRICTLY GREATER THEN X.
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//         vector <int> v(6);
//         for (int &ele:v){
//                 cin>>ele;
//         }
//         int x;
//         cin>>x;
//         int c=0;
//         for (int i=0;i<v.size();i++){
//                 if (x<v[i]){
//                         c++;
//                 }
//         }cout<<c<<endl;
// return 0;
// }

// 4. SORTED OR NOT. MOSTLY ASCENDING
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//         vector <int> v={1,2,3,4,5,6};
        
//         bool flag=true;
//         for (int i=1;i<v.size();i++){
//         if (v[i]<=v[i-1]){
//                 flag=false;
//         }
//         }cout<<flag<<endl;
// return 0;
// }

//8 . FIND DIFF BETN SUM OF ELE AT EVEN INDICES TO SUM OF ELE AT ODD INDICES.
#include <iostream>
#include <vector>
using namespace std;
int main(){
        vector <int> v={1,2,3,4,5,6,7,8,9};

        //way1 :-

        int even=0;
        int odd=0;
        for(int i=0;i<v.size();i++){
        if (i%2==0){
                even+=v[i];
        }else{
                odd+=v[i];
        }
        }
        int diff=even-odd;
        cout<<diff<<endl;

        //way 2:-

        // int sum=0;
        // for (int i=0;i<v.size();i++){
        //         if (i%2==0){
        //                 sum+=v[i];
        //         }else{
        //                 sum-=v[i];
        //         }
        // }
        // cout<<sum<<endl;
return 0;
}