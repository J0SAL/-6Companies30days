// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=2e218cc89cefa14b7f6d41dc488309f4&pid=705602&user=josal
class Node{
    public:
    Node *next[26];
    bool end;
    Node(){
        end=0;
        for(int i=0; i<26; i++) next[i] = NULL;
    }
};
class Trie{
    public:
    Node *trie;
    Trie(){
        trie = new Node();
    }
    void insert(string s){
        int i=0;
        Node *it = trie;
        for(char c: s){
            if(!it->next[c-'a'])
                it->next[c-'a'] = new Node();
            it = it->next[c-'a'];
        }
        it->end = true;
    }
    vector<string> find(string s){
        Node *it = trie;
        for(auto c: s){
    		if(!it->next[c-'a']){
    			return {"0"};
    		}
    		it=it->next[c-'a'];
    	}
    	vector<string> res;
    	printAll(it, s, res, "");
    	for(int i=0; i<res.size(); i++){
    		res[i] = s+res[i];
        }
        if(res.size()==0) res.push_back("0");
        return res;
    }
    void printAll(Node *it, string &s, vector<string> &res, string curr){
        if(it==NULL) return;
        if(it->end){
            res.push_back(curr);  
        } 
        for(int i=0; i<26; i++){
            if(it->next[i])
                printAll(it->next[i], s, res, curr+char('a'+i));
        }
    }
    
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        // inserting contact[] to trie;
        vector<vector<string>> ans;
        Trie t;
        for(int i=0; i<n; i++){
            t.insert(contact[i]);
        }
        for(int i=1; i<=s.size(); i++){
            vector<string> temp = t.find(s.substr(0,i));
            ans.push_back(temp);
        }
        return ans;
    }
};