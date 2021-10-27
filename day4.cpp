<------ 1 ------!>

// 2 Sum problem
// https://leetcode.com/problems/two-sum/

// time -> O(n) // wrost could lead to O(n^2)
// space -> O(n)

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int,int> mp;        
    int n=nums.size();            

    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int t=target-nums[i];
        if(mp.count(t))
        {
            v.push_back(i);
            v.push_back(mp[t]);                    
            return v;
        }
        mp[nums[i]]=i;
    }
    return v;
}



<------ 2 ------!>

// 4 Sum problem
// https://leetcode.com/problems/4sum/

// time -> O(n^3)
// space -> O(n)


vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> vv;
    sort(nums.begin(), nums.end());
    int n=nums.size();        
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int l=j+1,r=n-1;
            
            while(l<r)
            {
                int sum=nums[i]+nums[j]+nums[l]+nums[r];
                
                if(sum>target)
                    r--;
                else if(sum<target)
                    l++;
                else
                {
                    vv.push_back(vector<int> {nums[i],nums[j],nums[l],nums[r]});
                    
                    while(l+1<n && nums[l]==nums[l+1])
                        l++;
                    
                    while(r-1>=0 && nums[r]==nums[r-1])
                        r--;
                    
                    l++;
                    r--;
                }
            }
            
            while(j+1<n && nums[j]==nums[j+1])
                j++;
        }
        while(i+1<n && nums[i]==nums[i+1])
                i++;
    }
    return vv;
}



<------ 3 ------!>

// Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

// main idea is to find if any number lower than curr is available or not;
// if not find number that are 1 more that curr and cnt;

// time -> O(nlogn)
// space -> O(n)

int longestConsecutive(vector<int>& nums)
{
    int n=nums.size();
    unordered_set<int> st(nums.begin(), nums.end()); // copy vector in set
    int max_cnt=0;
                    
    for(int i=0;i<n;i++)
    {
        if(st.find(nums[i]-1)==st.end())
        {
            int num=nums[i];
            int cnt=1;
            while(st.find(num+1)!=st.end())
            {
                num++;
                cnt++;
            }
            max_cnt = max(max_cnt, cnt);
        }
    }
    return max_cnt;
}



<------ 4 ------!>

// Largest Subarray with 0 sum
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// time -> O(nlogn)
// space -> O(n)

int maxLen(int A[], int n)
{
    unordered_map<int,int> mp;
    int sum=0, max_len=0;;
    mp[sum]=-1;
    
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(mp.find(sum) == mp.end())
            mp[sum]=i;
        else
        {
            max_len = max(max_len, i-mp[sum]);
        }
    }    
    return max_len;   
}



<------ 5 ------!>

// Count number of subarrays with given XOR
// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

// time -> O(nlogn)
// space -> O(n)

int getCount(vector<int> arr, int k)
{
    map<int,int> mp;
    int cnt=0;
    int cur_xor=0;
    mp[cur_xor]=1;

    for(int i=0;i<arr.size();i++)
    {
        cur_xor^=arr[i];

        if(mp.find(cur_xor ^ k) != mp.end())
            cnt+=mp[cur_xor ^ k];

        mp[cur_xor]++;
    }
    return cnt;
}



<------ 6 ------!>

// Longest substring without repeat
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// time -> O(2*n) (This can be more optimized)
// space -> O(n)

int lengthOfLongestSubstring(string s) {
    bool arr[257]={false};
    
    int cnt=0,cnt_final=0;
    int n=s.length();
    int l=0,r=0;
    for(int i=0;i<n;i++)
    {            
        while(arr[s[i]] && l<i)
        {
            arr[s[l]]=false;
            l++;  // inplace of changeing L by 1 store 
            	  // last index of char (in more optimal way)
            cnt--;
        }            
        if(i<n)
        {
            arr[s[i]]=true;
            cnt++;
        }
        cnt_final=max(cnt,cnt_final);
    }
    return cnt_final;
}