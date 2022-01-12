// https://practice.geeksforgeeks.org/viewSol.php?subId=8a983fc954979a34ce6e9c71ee412189&pid=701199&user=josal

vector<string> maping = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void getCombinations(int a[], int i, int &N, string curr, vector<string> &res){
    if(i==N){
        res.push_back(curr);
        return;
    }
    for(char c: maping[a[i]]){
        curr+=c;
        getCombinations(a, i+1, N, curr, res);
        curr=curr.substr(0, curr.size()-1);
    }
}

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> res;
        
        getCombinations(a, 0, N, "", res);
        
        return res;
    }
};