<------ 1 ------!>

// Clone a Linked List with random and next pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/

// time -> O(n)
// space -> O(1)

Node* copyRandomList(Node* head)
{
    if(!head)
        return NULL;
    
    Node* start=head;
    
    while(start)
    {
        auto nd = new Node(start->val);            
        nd->next=start->next;
        start->next=nd;            
        start=nd->next;
    }
    start=head;
    while(start)
    {
        start->next->random = start->random ? start->random->next : NULL; 
        start=start->next->next;
    }
    Node s(0);
    s.next=head->next;
    
    start=head;
    Node* front=head;
    while(start)
    {
        front=start->next->next;
        start->next->next = front ? front->next : NULL;
        start->next = front;
        start = front;
    }
    
    return s.next;
}



<------ 2 ------!>

// 3 sum
// https://leetcode.com/problems/3sum/

// time -> O(nlogn)
// space -> O(m)

vector<vector<int>> threeSum(vector<int>& nums)
{        
    vector<vector<int>> vv;
        
    int n=nums.size();
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i]==nums[i-1])
            continue;
        
        int l=i+1,r=n-1;
        
        while(l<r)
        {
            int sum=nums[i]+nums[l]+nums[r];
            
            if(sum>0)
                r--;
            else if(sum<0)
                l++;
            else
            {
                vv.push_back(vector<int> {nums[i],nums[l],nums[r]});
                while(l+1<n && nums[l]==nums[l+1])
                    l++;
                while(r-1>=0 && nums[r]==nums[r-1])
                    r--;
                l++;
                r--;
            }
        }
        
    }           
    return vv;
}



<------ 3 ------!>

// Trapping rainwater
// https://leetcode.com/problems/trapping-rain-water/

// time -> O(n)
// space -> O(1)

int trap(vector<int>& height)
{
    int n=height.size();
    int l=0, r=n-1, r_max=0, l_max=0;
    int res=0;
    
    while(l<=r)
    {
        if(height[l]<=height[r])
        {
            if(height[l]>=l_max)
                l_max = height[l];
            else
              res+=(l_max-height[l]);
            l++;
        }
        else
        {
            if(height[r]>=r_max)
                r_max = height[r];
            else
                res+=(r_max-height[r]);
            r--;
        }
    }
    return res;
}



<------ 4 ------!>

// Remove Duplicate from Sorted array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// time -> O(n)
// space -> O(1)

int removeDuplicates(vector<int>& nums)
{        
    int cnt=0;                
    for(int i=1;i<nums.size();i++)   
    {
        if(nums[i]==nums[i-1])
            cnt++;
        else
        {
            nums[i-cnt]=nums[i];
        }
    }
    return nums.size()-cnt;
    
}



<------ 5 ------!>

// Max consecutive ones
// https://leetcode.com/problems/max-consecutive-ones/

// time -> O(n)
// space -> O(1)

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int cnt=0;
    int cnt_max=0;
    
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==1)
            cnt++;
        else
            cnt=0;
        cnt_max=max(cnt,cnt_max);
    }
    return cnt_max;
}