//Brute Approach with time complexity o(n*m) and space complexity o(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
        return false;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//Better Approach with time complexity o(n*logm) and space complexity o(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
        return false;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            if(binary_search(matrix[i].begin(),matrix[i].end(),target))
                return true;
        }
        return false;
        
    }
};

//Another Better Approach with time complexity o(n+m) and space complexity o(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
        return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0, j=n-1;
        while(i<m and j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]>target)
                j--;
            else
                i++;
        }
            return false;
        
    }
};

//Optimal solution with log(m*n) and space complexity o(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
        return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,r=m*n;
        while(l<r)
        {
            int mid=(l+r)/2;
            int row=mid/n,col=mid%n;
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                r= mid;
            else
                l= mid+1;
                
        }
            return false;
        
    }
};
