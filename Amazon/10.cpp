// submission link: https://practice.geeksforgeeks.org/viewSol.php?subId=a053df8100b7a14bcdf33fcbd2374f6c&pid=703024&user=josal
int getPriority(char c){
    switch(c){
        case '!': return 1;
        case '#': return 2;
        case '$': return 3;
        case '%': return 4;
        case '&': return 5;
        case '*': return 6;
        case '@': return 7;
    }
}

bool mysort(char a, char b){
    return getPriority(a)<=getPriority(b);
}
class Solution{
public:	
    
    
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    sort(nuts, nuts+n, mysort);
	    sort(bolts, bolts+n, mysort);
	}

};