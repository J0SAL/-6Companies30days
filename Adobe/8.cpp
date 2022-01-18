// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=7252f51d29bce619f88ddd6d5bb80ccb&pid=700386&user=josal
class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int number = 0;
        bool neg = 0;
        for(char c: str){
            if(c>='a' and c<='z') return -1;
            if(c=='-'){
                neg=1;   
                continue;
            }
            int num = c-'0';
            number = number*10+num;
        }
        if(neg) number*=-1;
        return number;
    }
};