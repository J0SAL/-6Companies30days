// submission link: https://leetcode.com/submissions/detail/630139436/

struct compare{
    bool operator()(string &a,string &b){
        int n=a.size();
        int m=b.size();
        if(n!=m){
            return n>m;
        }
        for(int i=0; i<n; i++){
            if(a[i]>b[i]){
                return 1;
            }
            if(a[i]<b[i]){
                return 0;
            }
        }
        return 0;
    }
};


class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
//         min heap
        priority_queue<string, vector<string>, compare> pq;
        
        for(auto s: nums){
            pq.push(s);
            while(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};