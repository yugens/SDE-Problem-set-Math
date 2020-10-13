//Brute force approach with time complexity o(n^2) and space complexity o(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        set<int> s;
        for(auto it: nums)
        {
            s.insert(it);
        }
        vector<int> v;
        for(auto it: s)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(it==nums[i])
                    cnt++;
            }
        if(cnt>floor(n/3))
            v.push_back(it);
        cnt=0;
        }
        return v;
        
        
    }
};

//Better Approach with time complexity o(nlogn) and space complexity o(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        vector<int> v;
         for(auto it: mp)
            {
                if(it.second>floor(n/3))
                    v.push_back(it.first);
                    
         }
        return v;
        
        
    }
};

//Optimal approach commonly known as [BOYER MOORE VOTING ALGORITHM] with time complexity o(n) and space complexity o(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int n1=-1,n2=-1,c1=0,c2=0,x=0,y=0;
        for(auto ele:nums)
        {
            if(ele==n1)
                c1++;
            else if(ele==n2)
                c2++;
            else if(c1==0)
            {
                n1=ele;
                c1=1;
            }
            else if(c2==0)
            {
                n2=ele;
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        vector<int> v;
        for(auto it:nums)
        {
            if(it==n1)
                x++;
            else if(it==n2)
                y++;
        }
        if(x>floor(n/3))
        v.push_back(n1);
        if(y>floor(n/3))
        v.push_back(n2);
        return v;
        
        
    }
};
