//Brute force solution which is recursive in nature with exponential time and space complexity 
class Solution {
public:
    int countpaths(int i, int j , int m , int n){
        if(i==n-1 and j==m-1)
            return 1;
        if(i>=n or j>=m)
            return 0;
        else
            return countpaths(i+1,j,m,n) + countpaths(i,j+1,m,n);
         
    }
    int uniquePaths(int m, int n) {
      return countpaths(0,0,m,n);
        
    }
};

//Better solution with time complexity o(n*m) and space complexity o(n*m)
class Solution {
public:
    int countpaths(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
       if(i==m-1 and j==n-1)
           return 1;
        if(i>=m or j>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        else
            return dp[i][j]=countpaths(i+1,j,m,n,dp)+countpaths(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        return countpaths(0,0,m,n,dp);
    }
};

//Optimal solution with time complexity o(m-1) and space complexity o(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++)
        {
            res=res * (N-r+i)/i;
        }
        return (int)res;
    }
};
