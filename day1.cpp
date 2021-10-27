<------ 1 ------!>

// Sort an array of 0’s 1’s 2’s without using extra space or sorting algo
// https://leetcode.com/problems/sort-colors/
( Dutch Nation Flag Algorith )

// time -> O(n)
// space -> O(1)

void sortColors(vector<int>& nums)
{
    int low=0;
    int mid=0;
    int high=nums.size()-1;
    
    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low], nums[mid]);
            mid++;
            low++;                
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}



<------ 2 ------!>

// Repeat and Missing Number
// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

1: take index array 
    // time -> O(n)
    // space -> O(n)    

2: 1+2+3...+n = (n)(n+1)/2 = s;
   1^2 + 2^2 + ... + n^2 = (n)(n+1)(2n+1)/6 = s^2;
   // calculate equation and solve

3: using xor
    // time -> O(n) 
    // space -> O(1)       
    // this don't tell which is missing need one more traversal for that

void getElements(vector<int> arr)
{
    int mis1=0,mis2=0;

    int xor1=0;
    for(int n:arr)
        xor1^=n;

    for(int i=1;i<=n;i++)
        xor1^=i;

    //check right most set bit;
    int set_bit = xor1 & ~(xor1 - 1);

    //devide element of array in two
    for(int n:arr)
    {
        if(n & setbit)
            mis1^=n;
        else
            mis2^=n;        
    }

    //devide all element in two
    for(int i=0;i<=n;i++)
    {
        if(i & setbit)
            mis1^=i;
        else
            mis2^=i;
    }

    return {mis1,mis2};
}



<------ 3 ------!>

// Merge two sorted Arrays without extra space
// https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
(GAP method)

// gap = ceil(n1+n2 / 2) 

// time -> O(nlogn) 
// space -> O(1)

void sort1(vector<int>& arr1, vector<int>& arr2)
{
    int n=arr1.size();
    int m=arr2.size();

    int gap = ceil((n+m) / 2.0);

    while(gap>0)
    {
        for(int i=0,j=gap; j<n+m ;i++,j++)
        {        
            if(j>=n) {
                j-=n;
                if(i>=n)
                {
                    i-=n;
                    if(arr2[i] > arr2[j])
                        swap(arr2[i], arr2[j]);                    
                    i+=n;
                }
                else
                {
                    if(arr1[i] > arr2[j])
                        swap(arr1[i], arr2[j]);                    
                }                                
                j+=n;
            }
            else
            {
                if(arr1[i] > arr1[j])
                    swap(arr1[i], arr1[j]);                
            }
        }
        if(gap==1)
            gap=0;
        else
            gap = (gap+1)/2;
    }
}



<------ 4 ------!>

// Maximum sum of subarray
// https://leetcode.com/problems/maximum-subarray/
( Kadane’s Algorithm )

// time -> O(n)
// space -> O(1)

int max_sum_subarray(vector<int> nums)
{
    int max_sum=INT_MAX;
    int curr_sum=0;

    for(int i=0;i<nums.size();i++)
    {
        curr_sum += nums[i];

        if(curr_sum > max_sum)
            max_sum = curr_sum;

        if(curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;
}



<------ 5 ------!>

// Merge Overlapping Subintervals
// https://leetcode.com/problems/merge-intervals/

// time -> O(nlogn) + O(n) (if sorting required)
// space -> O(n) (at worst due to return answer)

vector<vector<int>> merge(vector<vector<int>>& intervals)
{    
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    vector<int> temp = intervals[0];

    for(int i=1;i<intervals.size();i++)
    {           
        if(intervals[i][0] <= temp[1]) {
            temp[1] = max(intervals[i][1], temp[1]);
        }
        else {
            ans.push_back(temp);
            temp = intervals[i];
        }        
    }
    ans.push_back(temp);
    return ans;
}



<------ 6 ------!>

// Find the duplicate in an array of N+1 integers
// https://leetcode.com/problems/find-the-duplicate-number/

// time -> O(n)
// space -> O(1)

int findDuplicate(vector<int>& nums)
{        
    int slow = nums[0];
    int fast = nums[nums[0]];
    while(fast!=slow)        
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    
    fast = 0;
    
    while(fast!=slow)
    {
        slow=nums[slow];
        fast=nums[fast];
    }
    
    return fast;
}




