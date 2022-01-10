// solution link: https://practice.geeksforgeeks.org/viewSol.php?subId=648240cbb07f96146aebfa0ae48df9bc&pid=700021&user=josal
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here
        Node *temp = head;
        Node *prev = NULL;
        int n=N, m=M;
        while(temp){
            if(m==0 and n>0){
                Node *del = temp;
                prev->next = del->next;
                temp=del->next;
                free(del);
                n--;
            }else{
                prev = temp;
                temp = temp->next;
                m--;
            }
            if(n==0){
                m=M;
                n=N;
            }
        }
    }
};
