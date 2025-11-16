#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1={1,2,3,4,5,6};

    //creating itr:-
    // list<int> ::iterator itr;
    // itr =l1.begin();

    //aliter:-
    auto itr=l1.begin();

    // auto itr2=l1.end();
    // cout<<*itr<<endl;
    // cout<<*itr2<<endl;//Dereferencing it (*itr2) is undefined behavior in C++.
                     //    For some runs, it might print 5.
                     //   For others, it might crash.
                     // Or it might print garbage.

    // itr2=l1.rbegin();// wrong use auto keyword.or explicitly define.
    // auto itr22 =l1.rbegin();
    // cout<<*itr22<<endl;

    // advance(itr22,3);
    // cout<<*itr22<<endl;

    for (auto itr=l1.begin();itr!=l1.end();itr++){
        cout<<*itr<<" ";
    }cout<<endl;

    // reverse
    // for (auto itr=l1.rbegin();itr!=l1.rend();itr++){
    //     cout<<*itr<<" ";
    // }cout<<endl;

    advance(itr,2);
    // l1.insert(itr,10);
    // l1.insert(itr, 2 , 10);

    //for section:-
    auto l=l1.begin();
    auto r=l1.begin();
    advance(r, 3);
    l1.insert(itr,l,r);

    for (auto itr=l1.begin();itr!=l1.end();itr++){
        cout<<*itr<<" ";
    }cout<<endl;

    
    // advance(l,2); create new mannn!!!
    auto s_itr=l1.begin();
    advance(s_itr,2);
    auto e_itr=l1.begin();
    advance(e_itr, 5);
    l1.erase(s_itr, e_itr);
    for (auto itr=l1.begin();itr!=l1.end();itr++){
        cout<<*itr<<" ";
    }cout<<endl;

    l1.erase(itr);
    for (auto itr=l1.begin();itr!=l1.end();itr++){
        cout<<*itr<<" ";
    }cout<<endl;

    return 0;
}