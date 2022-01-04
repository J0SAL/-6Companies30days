// Find max 10 numbers in a list having 10M entries
// time complexity: O(N log(10))
// space complexity: O(10);
#include<bits/stdc++.h>
using namespace std;

#define v vector
#define M 10e7

v<int> get10MaxNumbers(v<int> &list){
	int n = list.size();
	priority_queue<int, v<int>, greater<int>> pq;
	pq.push(list[0]);
	for(int i=1; i<list.size(); i++){
		if(list[i]>pq.top()){
			pq.push(list[i]);
		}
		if(pq.size()>10) pq.pop();
	}

	v<int> ans;
	while(pq.size()!=0){
		ans.push_back(pq.top()); pq.pop();
	}
	return ans;
}

int main(){
	v<int> list;
    for(int i=0; i<M; i++){
        list.push_back(i);
    }
	v<int> res = get10MaxNumbers(list);
	for(int i: res) cout<<i<<" ";
	return 0;
}