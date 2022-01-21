// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=28ba59cc26fcffc825a021a5a39c456d&pid=700489&user=josal
int to_int(string s){
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}

int missingNumber(const string& str)
{
    // Code here
    int n=str.size();
    
    
    for(int l=1; l<=6; l++){
        
        string curr;
        int curr_i, prev_i, miss_i;
        
        int len = l;
        int i=0;
        int cnt = 0;
        bool invalid = 0;
        while(i<n and len--){
            curr+=str[i++];
            // cout<<"ch: "<<len<<endl;
        }
        // cout<<"l: "<<l<<endl;
        
        prev_i = to_int(curr);
        curr = "";
        int j=i;
        // cout<<"prev: "<<prev_i<<endl;
        while(j<n){
            curr+=str[j++];
            curr_i = to_int(curr);
            // cout<<"gen: "<<curr_i<<endl;
            if(prev_i+1 == curr_i){
                prev_i=curr_i;
                curr="";
            }
            else if(prev_i+2 == curr_i){
                miss_i = prev_i+1;
                cnt++;
                curr="";
                prev_i = curr_i;
            }
            else if(prev_i<curr_i){
                invalid=1;
            }
            // else{
            //     break;
            // }
        }
        if(cnt == 1 and !invalid) return miss_i;
    }
    return -1;
}