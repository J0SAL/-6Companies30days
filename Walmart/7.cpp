// submisison link: https://practice.geeksforgeeks.org/viewSol.php?subId=602e9dff197127d584d7b16d1880ac4d&pid=700357&user=josal

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        if(N<3) return {};
        vector<int> left(N);
        vector<int> right(N);
        
        left[0] = arr[0];
        right[N-1] = arr[N-1];
        
        for(int i=0; i<N-1; i++){
            left[i+1] = min(left[i], arr[i]);
        }
        for(int i=N-1; i>0; i--){
            right[i-1] = max(right[i], arr[i]);
        }
        
        for(int i=1; i<N-1; i++){
            if(arr[i]>left[i] and arr[i]<right[i]){
                return {left[i], arr[i], right[i]};
            }
        }
        
        return {};
    }
};