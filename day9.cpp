<------ 1 ------!>

// Subset Sums
// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

1. power set solution
// time -> O(2^n * n)
// space -> O(2^n)

vector<int> subsetSums(vector<int> nums, int N)
{
    int n=pow(2,N);
    
    vector<int> ans;
    
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<N;j++)
        {
            if((i & 1<<j) > 0)
                sum+=nums[j];
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

2. recursion
// time -> O(2^n)
// space -> O(2^n)

vector<int> ans;
void recursion(int indx, vector<int>& nums, int sum)
{
    if(indx==nums.size())
    {
        ans.push_back(sum);
        return;
    }
    recursion(indx+1, nums, sum+nums[indx]);
    recursion(indx+1, nums, sum);
}
vector<int> subsetSums(vector<int> nums, int N)
{
    recursion(0,nums,0);
    
    sort(ans.begin(), ans.end());
    return ans;
}



<------ 2 ------!>

// Subset-II
// https://leetcode.com/problems/subsets-ii/

// time -> O(2^n * m)
// space -> O(2^n)

vector<vector<int>> ans;
void recursion(int indx, vector<int>& nums, vector<int>& temp)
{
    ans.push_back(temp);
    for(int i=indx;i<nums.size();i++)
    {
        if(i!=indx && nums[i]==nums[i-1])
            continue;
        
        temp.push_back(nums[i]);
        recursion(i+1, nums, temp);
        temp.pop_back();                        
    }                
}    
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    vector<int> temp;
    sort(nums.begin(), nums.end());
    recursion(0, nums, temp);
    
    return ans;
}



<------ 3 ------!>

// Combination sum-1
// https://leetcode.com/problems/combination-sum/

// time -> O(2^t * k)
// space -> O(k * x)  // k=average lenght of data set , x combination

vector<vector<int>> vv;
int t;
void backtrack(vector<int>& nums, vector<int>& curr, int sum, int start)
{   
    if(start>=nums.size())
        return;
    
    if(sum==0)
    {               
        vv.push_back(curr);
        return;
    }
    if(sum<0)        
        return;
                
    backtrack(nums,curr,sum,start+1);
    
    curr.push_back(nums[start]);
    backtrack(nums,curr,sum-nums[start],start);
    curr.pop_back();    
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<int> curr;
    t=target;
    backtrack(candidates,curr,target,0);

    return vv;
}



<------ 4 ------!>

// Combination sum-2 
// https://leetcode.com/problems/combination-sum-ii/

// time -> O(2^n *k)
// space -> O(k * x) 

vector<vector<int>> vv;
int t;
void backtrack(vector<int>& nums, vector<int>& curr, int sum, int start)
{    
    if(sum>t)        // this condiction can be put even inside for loop
        return;
    if(sum==t)
    {               
        vv.push_back(curr);
        return;
    }
    for(int i=start;i<nums.size();i++)
    {
        if(i!=start && nums[i]==nums[i-1])
            continue;
        
        curr.push_back(nums[i]);
        sum+=nums[i];             // this can be changed be by reducing target
        backtrack(nums,curr, sum, i+1);
        sum-=nums[i];
        curr.pop_back();
    }    
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<int> curr;
    t=target;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates,curr,0,0);

    return vv;    
}



<------ 5 ------!>

// Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

// time -> O(2^n *k)
// space -> // as same to store all result

bool isPalin(string &s, int start, int end)
{
    while(start<=end)
    {
        if(s[start] != s[end])
            return false;
        start++;
        end--;            
    }
    return true;
}

void backtrack(string &s, int start, vector<string> &v, vector<vector<string>> &vv)
{
    if(start == s.length())   
    {
        vv.push_back(v);
        return;
    }
    for(int i=start; i<=s.size(); i++)
    {
        if(isPalin(s,start,i))
        {
            v.push_back(s.substr(start, i-start+1));
            backtrack(s,i+1,v,vv);
            v.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> vv;
    vector<string> v;
    
    backtrack(s,0,v,vv);
    
    return vv;
}



<------ 6 ------!>

// K-th permutation Sequence
// https://leetcode.com/problems/permutation-sequence/

// time -> O(n*n)
// space -> O(n)

string getPermutation(int n, int k)
{
    int fact=1;
    vector<int> nums;
    for(int i=1;i<=n;i++)
    {
        fact*=i;
        nums.push_back(i);
    }
    
    string ans="";
    k--;
    
    while(nums.size()>0)
    {            
        fact /= nums.size();
        ans+= to_string( nums[k/fact] );            
        nums.erase(nums.begin() + k/fact);
        k = k%fact;
    }
    return ans;
}