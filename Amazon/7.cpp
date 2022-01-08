// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=20e7bb2667a33cf64110b99edb9f0233&pid=705333&user=josal

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char, int> mp;
		    string ans;
		    deque<char> q; //manage unique chars
		    for(char c: A){
		        if(mp[c] == 0) q.push_back(c);
		        mp[c]++;
		        while(!q.empty() and mp[q.front()]>=2){
		            q.pop_front();
		        }
		        if(q.empty()) ans+='#';
		        else ans+=q.front();
		    }
		    return ans;
		}

};