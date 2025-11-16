            
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
                  //que 1 : sort the given string
                  //method 1 :me
// void strSort(string &str){
//     for (int i=0;i<str.size();i++){
//         for (int j=i+1;j<str.size();j++){
//             //wrong:
//             // if (int(str[i])>int(str[j])){
//             //     int temp=int(str[i]);
//             //     int (str[i])=int(str[j]);
//             //     int (str[j])=temp;
//             // }

//             if ( (str[i])>int (str[j])){
//                 char t=str[i];
//                 str[i]=str[j];
//                 str[j]=t;
//             }

//         }
//     }

//     for (int i=0;i<str.size();i++ ){
//         cout<<str[i]<<" ";
//     }cout<<endl;
// }


         //method 2: mam:
string strSort(string str){
    vector<int> freq(26,0);
    //storing the frequency of each element of string
    for (int i=0;i<str.size();i++){
        int index=str[i]-'a';
        freq[index]++;
    }
    //sort the elements
    int j=0;
    for (int i=0;i<freq.size();i++){
        while(freq[i]--){
            str[j++]=i+'a';
        }
    }
    return str;
}
             // que 2: are following two strings s and t amagram.
// bool isAmagram(string s,string t){
//     vector<int> count1(26,0), count2(26,0);
//     for (int i=0;i<s.size();i++){
//         count1[s[i]-'a']++;
//     }
//     for(int i=0;i<t.size();i++){
//         count2[t[i]-'a']++;
//     }

//     for (int i=0;i<26;i++){
//         if (count1[i]!=count2[i]){
//             return false;
//         }
//     }

//     return true;
// } 
        //mam:
bool isAmagram(string s,string t){

    if (s.length()!=t.length()){
        return false;
    }
    vector<int> freq(26,0);
    for (int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if (freq[i]!=0){
            return false;
        }
    }
    return true;
}

       //que 3. check isomorphic:
       //me :  wrong:
// bool checkIsomorphic(string s,string t){
//     if (s.length()!=t.length()){
//         return false;
//     }
//     vector<int> freq1(26,0),freq2(26,0);
//     // since now both has same length of string  in one loop
//     for (int i=0;i<s.length();i++){
//         freq1[s[i]-'a']++;
//         freq2[t[i]-'a']++;
//     }

//     for (int i=0;i<s.size();i++){
//         if (freq1[s[i]-'a']!=freq2[t[i]-'a']){
//             return false;
//         }
//     }
//     return true;
// }

         //mam:
bool checkIsomorphic(string s,string t){
    vector<int> v1(128,-1),v2(128,-1);
    if (s.size()!=t.size()){
        return false;
    }

    for (int i=0;i< s.size();i++){
        if (v1[s[i]]!=v2[t[i]]){
            return false;
        }else{
            v1[s[i]]=v2[t[i]]=i;
        }
    }
    return true;
}

          //que 4: longes common prefix string
          //method 1:
string f(vector<string> &str){
    sort(str.begin(), str.end());
    string s1=str[0];
    string s2=str[str.size()-1];
    int i=0;int j=0;
    string ans="";
    while(i<s1.size() && j< s2.size()){
        if (s1[i]==s2[j]){
            ans+=s1[i];
            i++; j++;
        }else{
            break;
            // return ans;not that good
        }
    }
    return ans;
}
        //method 2:
string f2(vector<string> &str){
    string s1=str[0];
    int ans_length=s1.size();
    for(int i=1;i<str.size();i++){
    int j=0;
    while(j<s1.size() && j<str[i].size() && s1[j]==str[i][j]){
            j++;
            ans_length=min(ans_length,j);
        }
    }

    string ans=s1.substr(0,ans_length);
    return ans;
}

         //que 5: decode the code:

         //me: wrong:
// void encoding(vector<string> str){
//     int i=0;
//     int j=-1;
//     for (int a=0;a<str.size();a++){
//         if ('0'<= str[j] <='9' && str[i]=='['){
//             i++;j++;
//             continue;
//         }else{
//             int counter=j;
//             int k=i;
//             while(int(str[counter])--){
//                 cout<<str[k];
//                 if (str[k]==']'){
//                     continue;
//                 }
//                 if (k==str.size()){
//                     k=i;
//                 }
//             i++;j++;
//         }
//         }
//     }
// }

// void encoding1(string &s){
//     string result="";
//     for (int i=0;i<s.length();i++){
//         if (s[i]!=']'){
//             result+=s[i];

//         }else{

//             int j=result.size()-1;
//             string temp="";

//             while(j--){
//                 if (result[j]=='['){
//                     break;
//                 }
//                 temp+=result[j];
//                 result.pop_back();
//                 // j--;
//             }

//             reverse(temp.begin(),temp.end());
            
//             j--;//[->j.
//             result.pop_back();//[-> popped

//             string num="";
//             while(result[j]>='0'&& result[j]<='9'){
//                 num+=result[j];
//                 result.pop_back();
//                 j--;
//             }

//             reverse(num.begin(),num.end());

//             int num1=stoi(num);

//             while(num1--){
//                 result+=temp;
//             }

//         }

//     }
//     for (int i=0;i< result.size();i++){
//         cout<<result[i];
//     }
// }


   //last mei thoda galti:-
// void encoding2(string &v){
//     int i=0;

//     while(i<v.size()){

//         if (v[i]==']'){
//             v.pop_back();
//             i--;

//             string temp="";
//             while(v[i]>='a'&& v[i]<='z'){
//                 temp+=v[i];
//                 v.pop_back();
//                 i--;
//             }

//             v.pop_back();
//             i--;//pointing to number.
//             reverse(temp.begin(),temp.end());//temp wali string is reversed.

//             string STnum="";
//             while(v[i]>='1' && v[i]<='9'){
//                 STnum+=v[i];
//                 v.pop_back();
//                 i--;
//             }
//             reverse(STnum.begin(),STnum.end());//that string number is now reversed.

//             int INTnum=stoi(STnum);
//             string temp2="";
//             while(INTnum--){
//                 temp2+=temp;//temp2 has caca.
//             }

//             string resultString="";
//             for (int j=1;j<=i;j++){
//                 resultString+=v[j];
//             }
//             resultString+=temp2;//3[bcaca
//             v=resultString;// but ']' ye part gayab

//             //abhi humara i pointer is pointing to b 
//             // and usske baad ka sab popped except last ']'
//             // b ke baad temp2 add karo.

//             // int pointerShift=temp2.length();
//             // v[i]+=temp2;//wrong as char +=string.
//             // while(pointerShift--){
//             //     i++;
//             // }
//         }
//         i++;
//     }

//     //now my string v is having the decoded code.
//     for (int i=0;i<v.size();i++){
//         cout<<v[i];
//     }cout<<endl;
// }


            // ME 3
void encoding3(string &s){
    string result="";
    for (int i=0;i<s.size();i++){
        if (s[i]!=']'){
            result+=s[i];
        }else{
            int j=result.size()-1;
            string temp="";
            while(!result.empty() && result[j]!='['){
                temp+=result[j];
                j--;
                result.pop_back();
            }

            reverse(temp.begin(),temp.end());

            j--;
            result.pop_back();

            string stnum="";
            while(!result.empty() &&(result[j]>='0' && result[j]<='9')){
                stnum+=result[j];
                result.pop_back();
                j--;
            }

            reverse(stnum.begin(),stnum.end());

            int num=stoi(stnum);
            while(num--){
                result+=temp;
            }
        }
    }

    for (int i=0;i<result.size();i++){
        cout<<result[i];
    }
}


            //que 6. max ones longest substr
            //my soln  -> 99 % correct.
            //wrong:-
// int length(int i,int j){
//     int c=0;
//     for (int s=i;s<=j;s++){
//         c++;
//     }
//     return c;
// }

// void maxonesSubstr(string &str ,int k){
//     int i=0,j=str.length()-1;
//     int length_of_longsubstr_1=0;
//     int length_of_longsubstr_2=0;
//     int len_final=0;
//     int strting_index=0;
//     int ending_index=0;
//     while(i<=j){
//         int count=0;
        
//         for (int t=i;t<=j;t++){
//             if (str[t]=='0'){
//                 count++;
//             }
//         }
//         if(count<=k){
//         length_of_longsubstr_1=length(i,j);
//         strting_index=i;
//         ending_index=j;
//         break;
//         }
//         i++;
//     }

//     //i==j or break;
//     i=0,j=str.length()-1;
//     while(i<=j){
//         int count2=0;
//         for (int s=i;s<=j;s++){
//             if (str[s]=='0'){
//                 count2++;
//             }
//         }
//         if (count2<=k){
//             length_of_longsubstr_2=length(i,j);
//             if (length_of_longsubstr_1<length_of_longsubstr_2){
//                 len_final=length_of_longsubstr_2;
//                 strting_index=i;
//                 ending_index=j;
//             }else{
//                 len_final=length_of_longsubstr_1;
//             }
//             break;
//         }
//         j--;
//     }
//     //now we have length of longest string and starting and ending index.
//     string ans=str.substr(strting_index,len_final);
//     for (int b=0;b<ans.size();b++){
//         if (ans[b]=='0'){
//             cout<<'1';
//         }else{
//         cout<<ans[b];
//         }
//     }cout<<endl;
// }

             //mam: sliding window technique:
int maxonesSubstr(string str,int k){
    int strt=0;
    int end=0;
    int max_length=0;
    int zero_count=0;
    for (;end<str.length();end++){
        if (str[end]=='0'){
            zero_count++;
        }
        while(zero_count>k){
            if (str[strt]=='0'){
                zero_count--;
            }
            strt++;
        }

        max_length=max(max_length,end-strt+1);
    }
    return max_length;
}
int main(){
    // vector<string> code;
    string code="1000101110001";
    cout<<maxonesSubstr(code,1);
    return 0;
}


