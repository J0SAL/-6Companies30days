// solution: https://practice.geeksforgeeks.org/viewSol.php?subId=778fb32620b96ffe5062661f0b2f3060&pid=703607&user=josal
string printMinNumberForPattern(string S){
    // code here 
    string ans="";
    int n=S.size();
    int maxx = 1;
    stack<int> st;
    for(char i: S){
        if(i == 'D'){
            st.push(maxx++);
        }
        else{
            st.push(maxx++);
            while(!st.empty()){ 
                // cout<<"1: "<<st.top()<<endl;
                ans+=to_string(st.top()); 
                st.pop();
            }
        }
    }
    st.push(maxx); //if string  -> D
    while(!st.empty()){
        // cout<<"2: "<<st.top()<<endl;
        ans+=to_string(st.top());
        st.pop();
    }
    return ans;
}