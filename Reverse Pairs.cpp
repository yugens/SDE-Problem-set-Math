//Brute force solution having time complexity o(n^2) and space complexity o(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((i < j) and (nums[i] > 2*nums[j]))
                    ans++;
            }
        }
        return ans;
        
    }
};

//Better solution having time compleity o(nlogn)+o(n)+o(n) and space complexity o(n)
class Solution {
public:
     int merge(vector<int>& nums,int temp[],int l,int mid,int r)
        {
            int cnt=0;
            int right=mid;
            for(int k=l;k<mid;k++)
            {
                while(right<=r and nums[k]>2LL*nums[right])
                {
                right++;
                }
                cnt+=(right-(mid));
            }
         
            int i=l;
            int j=mid;
            int k=l;
            while((i<=mid-1)and(j<=r))
            {
                if(nums[i]<=nums[j])
                {
                    temp[k]=nums[i];
                    k++;i++;
                }
                else
                {
                    temp[k]=nums[j];
                    k++;j++;
                }
            }
            while(i<=mid-1)
                temp[k++]=nums[i++];
            while(j<=r)
                temp[k++]=nums[j++];
            for(i=l;i<=r;i++)
                nums[i]=temp[i];
            return cnt;    
        }
    
  int mergesort(vector<int>& nums,int temp[],int l,int r)
        {
            if(l>=r)
                return 0;
            
               int mid=(r+l)/2;
               int inv= mergesort(nums,temp,l,mid);
               inv+= mergesort(nums,temp,mid+1,r);
               inv+= merge(nums,temp,l,mid+1,r);
               return inv;
        }
    
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int temp[n];
        return mergesort(nums,temp,0,n-1); 
    }
   
};
