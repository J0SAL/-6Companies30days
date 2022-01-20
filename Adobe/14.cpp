// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=2e406fd5b689f5f22a047e740acf8893&pid=700497&user=josal

#define v vector
#define pii pair<int,int>

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
         //code here
        v<pii> v;
        pii ans;
        for(int i=0; i<k; i++){
            for(int j=0; j<n; j++){
                v.push_back({KSortedArray[i][j], i});
            }
        }
        sort(v.begin(), v.end()); //(n+k)log(n+k)
        
        unordered_map<int, int> mp; //to check the end of an arr
        int i(0), j(0), sz=v.size();
        int mn = INT_MAX;
        while(j<sz){
            pii curr=v[j];
            int val = curr.first;
            int id = curr.second;
            
            mp[id]++;
            if(mp.size()<k) j++;
            else if(mp.size() == k){
                while(mp.size() == k){
                    if(v[j].first - v[i].first < mn){
                        mn = v[j].first - v[i].first;
                        ans = {v[i].first, v[j].first};
                    }
                    
                    mp[v[i].second]--;
                    if(mp[v[i].second] == 0)
                        mp.erase(v[i].second);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};