class Solution 
{
    private:
    
    bool knows(vector<vector<int> >& M,int a,int b,int n)
    {
        if(M[a][b]==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int>s;
       
       for(int i=0;i<n;i++)
       {
           s.push(i);
       }
       while(s.size()>1)
       {
           int a=s.top();
           s.pop();
           
           int b=s.top();
           s.pop();
           
           if(knows(M,a,b,n))
           {
               s.push(b);
           }
           else
           {
               s.push(a);
            }
            
       }
       int ans=s.top();
       int zerocount=0;
       for(int i=0;i<n;i++)
       {
           if(M[ans][i]==0)
           
               zerocount++;
       }
       
           if(zerocount!=n)
           
               return -1;
           
       
       int onecount=0;
       for(int i=0;i<n;i++)
       {
           if(M[i][ans]==1)
           
               onecount++;
       }
           if(onecount!=n-1)
           
               return -1;
           
       return ans;
    }
};
