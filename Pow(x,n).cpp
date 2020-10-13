//Better Approach with time complexity o(n) and space complexity o(1)
class Solution {
public:
    double myPow(double x, long long int n) {
     double ans=1.0;
     for(long long int i=1;i<=abs(n);i++)
         ans=ans*x;
     double y= 1/ans;
     if(n>0)
         return ans;
     else if(n<0)
         return y;
     else
         return 1;
        
    }
};

//Optimal Approach with time complexity log2(n) and space complexity o(1)
class Solution {
public:
    double myPow(double x, long long int n) {
     double ans=1.0;
     long long int no =n;
        if(no<0)
            no=-1*no;
        while(no)
        {
            if(no%2==0)
            {
               x=x*x;
               no=no/2;
            }
            else
            {
                ans=ans*x;
                no=no-1;
            }
        }
        if(n<0)
        {
            ans=(double)(1.0)/(double)(ans) ;
        }
        return ans;
    }
};
