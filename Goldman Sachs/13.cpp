// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=2c849f197a902767d73e11fe8eb11477&pid=705287&user=josal
class Solution{
public:
    string getString(int &i, string &s){
        string ans="";
        int times = 0;
        while(i<s.size()){
            if(s[i] == '['){
                i++;
                string temp = getString(i, s);
                while(times--) ans += temp;
                times = 0;
            }
            else if(s[i] == ']'){
                return ans;
            }
            else if(s[i]>='0' and s[i]<='9'){
                times = times*10+(s[i] - '0');
            }
            else{
                ans += s[i];
            }
            i++;
        }
        
        return ans;
    }
    
    string decodedString(string s){
        // code here
        int i=0;//as I'm referring to this variable
        return getString(i, s);
    }
}