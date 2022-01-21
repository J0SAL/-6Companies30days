// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=9b80a1e93bae12e86b5de99fa36e4aa2&pid=700489&user=josal
/* You are required to complete this function
which return the required missing number
if present else return -1*/

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
        while(i<n and len--){
            curr+=str[i++];
        }
        
        prev_i = to_int(curr);
        curr = "";
        int j=i;
        while(j<n){
            curr+=str[j++];
            curr_i = to_int(curr);
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
        }
        if(cnt == 1) return miss_i;
    }
    return -1;
}