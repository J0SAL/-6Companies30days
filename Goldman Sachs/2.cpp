//submittion link: https://practice.geeksforgeeks.org/viewSol.php?subId=3a6fdc9c30d29648fc98b85544386eec&pid=705474&user=josal

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here - check if it is right-left-up-down..if not overlaps
        if(L2[0]>R1[0]) return 0; //on right
        
        if(R2[0]<L1[0]) return 0; //on left
        
        if(R2[1]>L1[1]) return 0; //above
        
        if(L2[1]<R1[1]) return 0; //below
        
        return 1; 
    }
};