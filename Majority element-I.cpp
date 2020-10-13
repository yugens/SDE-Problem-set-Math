//Approach using hash map with time complexity o(nlogn) and space complexity o(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int cnt=0;
        int ele=0;
        for(auto it : mp)
        {
            if(it.second>cnt)
            {
                cnt=it.second;
                ele=it.first;
            }
        }
        return ele;
        
    }
};

//Optimal Approach commonly known as [MOORE'S VOTING ALGORITHM] with time complexity o(n) and space complexity o(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int ele=0;
        for(auto it : nums)
        {
            if(cnt==0)
                ele=it;
            if(ele==it)
                cnt+=1;
            else
                cnt-=1;
        }
        return ele;
        
    }
};
