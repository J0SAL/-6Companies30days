// submission link: https://leetcode.com/submissions/detail/631068041/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0;
        bool cneg = 0;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
            cneg = 1;
        }
        long long divid = abs(dividend);
        long long divis = abs(divisor);
        if((dividend == INT_MAX && divisor==1) ||(dividend == INT_MIN && divisor==-1)){
            return INT_MAX;
        }
        if((dividend == INT_MIN && divisor == 1) || (dividend == INT_MAX && divisor==-1)){
            return INT_MIN;
        }
        int cnt = 1;
        if(divid-divis<0){
            return 0;
        }
        divid-=divis;
        ans = 1;
        while(divid-divis >= 0){
            divid-=divis;
            divis = divis<<1;
            ans+=cnt;
            cnt = cnt<<1;
        }
        divisor = abs(divisor);
        while(divid-divisor>=0){
            ans++;
            divid-=divisor;
            
        }
        return cneg ? (-1*ans) : ans;
        
        
    }
};