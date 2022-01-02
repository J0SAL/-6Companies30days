//submission link- https://practice.geeksforgeeks.org/viewSol.php?subId=c1f9ed2c515a9bcb8481101d5e1885d9&pid=700243&user=josal
string encode(string src)
{     
    //Your code here 
    int n=src.size();
    int cnt=1;
    string new_s;
    new_s += src[0];
    for(int i=1; i<n; i++){
        if(src[i]==src[i-1]){
            cnt++;
        }
        else{
            new_s += to_string(cnt);
            new_s += src[i];
            cnt=1;
        }
    }
    new_s += to_string(cnt);
    return new_s;
} 