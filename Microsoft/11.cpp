// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=3fee9a0f5ed784793da43b3ce26da081&pid=701347&user=josal
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	for(int i=1; i<=N; i++){
	    string s="";
	    int num = i;
	    while(num){
	        int rem = num%2;
	        s = to_string(rem) + s;
	        num/=2;
	    }
	    ans.push_back(s);
	}
	return ans;
}