/* question: 
    Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. Find out which one is more recent? Strings can be empty also.
*/
#include <bits/stdc++.h>
using namespace std;

string getRecent(const string &s1, const string &s2){
    int n=s1.size(), m=s2.size();

    if(n==0 or m==0){ //for empty string
        if(n==0 and m==0) return "Invalid";
        else if(m==0) return s1;
        else return s2;
    }
    int i=0, j=0;
    while(i<n and j<m){
        if(s1[i] == s2[j]){
            i++; j++;
        }
        else if(s1[i]>s2[j]){
            return s1; 
        }else{
            return s2;
        }
    }
    if(i<n){
        return s1;
    }
    return s2;
}

int main(){
    cout<<getRecent("11.1.1.1","10.1.1.9")<<endl;
    cout<<getRecent("","")<<endl;    

    return 0;
}