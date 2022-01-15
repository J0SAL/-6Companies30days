// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=1b41fb5ab794321c2530bd173fd4f9d6&pid=704560&user=josal
class Solution{
public:
    int minSteps(int D){
        // code here
        int steps = 0;
        int summ = 0;
        while(1){
            summ+=steps;
            steps++;
            if(summ == D) {
                return steps-1;
            }
            if(summ>D and (summ-D)%2==0){
                return steps-1;
            }
        }
        
        return -1;
    }
};