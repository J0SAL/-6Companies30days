// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=68db25540ec722e1e5bf29e2e75bfda4&pid=701966&user=josal

#define v vector
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        v<v<string>> ans;
        unordered_map<string, v<string>> mp;
        for(string s: string_list){
            string new_s = s;
            sort(new_s.begin(), new_s.end());
            mp[new_s].push_back(s);
        }
        
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};