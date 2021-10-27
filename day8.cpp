<------ 1 ------!>

// N meeting in one room
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// time -> O(nlogn)
// space -> O(n)

int maxMeetings(int start[], int end[], int n)
{    
    vector<pair<int,int>> meet(n);

    for(int i=0;i<n;i++)
        meet[i]={end[i],start[i]};
        
    sort(meet.begin(), meet.end());
    
    int last_end=-1,cnt=0;
    
    
    for(int i=0;i<n;i++)
    {
        if(meet[i].second > last_end )
        {
            cnt++;
            last_end=meet[i].first;
        }
    }
    return cnt;
}



<------ 2 ------!>

// Minimum number of platforms required for a railway
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// time -> O(nlogn)
// space -> O(1)

int findPlatform(int arr[], int dep[], int n)
{
	sort(arr, arr+n);
	sort(dep, dep+n);
	
	int cnt=1,max_cnt=1;
	int i=1,j=0;
	
	while(i<n && j<n)
	{
	    if(arr[i] <= dep[j])
	    {
	        cnt++;
	        i++;
	    }
	    else
	    {
	        cnt--;
	        j++;
	    }
	    max_cnt=max(cnt,max_cnt);
	}
	return max_cnt;
}


<------ 3 ------!>

// Job sequencing Problem
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// time -> O(nlogn) + O(n*m)
// space -> O(m)   --> m=maximum deadline

static bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr, arr+n, comp);
    
    int max_dead = INT_MIN;
    for(int i=0;i<n;i++)
        max_dead = max(max_dead, arr[i].dead);
        
    vector<int> res (max_dead+1, -1);
    int cnt=0, profit=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].dead; j>0; j--)
        {
            if(res[j]==-1)
            {
                cnt++;
                profit+=arr[i].profit;
                res[j]=i;
                break;
            }
        }
    }
    return vector<int> {cnt,profit};
}



<------ 4 ------!>

// Fractional Knapsack Problem
// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// time -> O(nlogn)
// space -> O(1) 

static bool comp(Item a, Item b)
{
    double ta = ((double)a.value/(double)a.weight);
    double tb = ((double)b.value/(double)b.weight);
    return (ta>tb);
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr+n, comp);
    double profit=0;
    for(int i=0;i<n;i++)
    {       
        if(arr[i].weight<=W)
        {
            profit+=arr[i].value;
            W-=arr[i].weight;
        }
        else
        {
            profit+=((double)(W*arr[i].value)/(double)arr[i].weight);
            break;
        }
    }
    return profit;
}



<------ 5 ------!>

// Greedy algorithm to find minimum number of coins
// https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/

// time -> O(amount) // in worst
// space -> O(1) 

void findMin(int V)
{
	int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	int n=9;
	vector<int> ans;

	for(int i=n-1;i>=0;i--)
	{
		while(V >= arr[i])
		{
			V-=arr[i];
			ans.push_back(arr[i]);
		}		
	}
	for(int a:ans)
		cout<<ans[i]<<" ";
}



<------ 6 ------!>

// Activity Selection
// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

(It is as same as N meeting in one room)