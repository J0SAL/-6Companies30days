// submission link: https://leetcode.com/submissions/detail/628326802/
class Solution {
public:
    bool winnerOfGame(string colors) {
        int a_cnt(0), b_cnt(0);
        
        int n = colors.size();
        if(n<3) return 0;
        for(int i=1; i<n-1; i++){
            if(colors[i] == 'A' and colors[i-1] == 'A' and colors[i+1] == 'A') a_cnt++;
            if(colors[i] == 'B' and colors[i-1] == 'B' and colors[i+1] == 'B') b_cnt++;
        }
        
        return a_cnt>b_cnt;
    }
};