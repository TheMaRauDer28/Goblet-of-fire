<------ 1 ------!>

// Search in a 2D matrix

1. // https://leetcode.com/problems/search-a-2d-matrix/
 (last of row 1 < first of row 2)

// time -> O(log(n*m))
// space -> O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target)
{	
	int n=matrix.size();
	int m=matrix[0].size();

	int l=0, h=(n*m)-1;

	while(l<=h)
	{
		int mid = (l + (h-l)/2);
		
		if(matrix[mid/m][mid%m] == target)
			return true;
		if(matrix[mid/m][mid%m] < target)
			l = mid+1;
		else
			r = mid-1;
	}
	return false;
}

2. // https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
 (row is sorted and col is sorted)

// time -> O(n)
// space -> O(1)

bool find(vector<vector<int>>& matrix, int target)
{
 	int n=matrix.size();
	int m=matrix[0].size();

	int i=0, j=m-1;

	while(i<n && j>=0)
	{
		if(matrix[i][j] == target)
			return true;

		if(matrix[i][j] > target)
			j--;
		else
			i++;
	}
    return false;
}



<------ 2 ------!>

// Pow(X,n)
// https://leetcode.com/problems/powx-n/

// time -> O(logn)
// space -> O(1)

double myPow(double x, int m)
{
	double ans=1.0;
	long n=m;

	if(m<0)
		n = (-1)*n;

	while(n>0)
	{
		if(n%2==1)
		{
			ans = ans*x;
			n--;
		}
		else
		{
			x*=x;
			n/=2;
		}
	}
	if(m<0)
		ans = (double)(1.0) / (double)(ans);
	return ans;
}



<------ 3 ------!>

// Majority Element (>N/2 times)
// https://leetcode.com/problems/majority-element/
(Boyer Moore Voting Algorithm)

// time -> O(n)
// space -> O(1)

int majorityElement(vector<int>& nums)
{
    int ele=0;
    int cnt=0;
    
    for(int i=0;i<nums.size();i++)
    {
        if(cnt==0)
            ele = nums[i];
        
        if(nums[i]==ele)
            cnt++;
        else
            cnt--;
    }
    return ele;
}



<------ 4 ------!>

// Majority Element (>N/3 times) 
// https://leetcode.com/problems/majority-element-ii/
(Boyer Moore Voting Algorithm)
// we can have at max 2 majority element (bcz 3*(n/3) > n ---- !think)

// time -> O(n)
// space -> O(1)

vector<int> majorityElement(vector<int>& nums)
{
    int n=nums.size();
    int num1, num2;
    int cnt1=0, cnt2=0;
    
    vector<int> ans;
    
    for(int i=0;i<n;i++)
    {
        if(cnt1!=0 && nums[i] == num1)
            cnt1++;
        else if(cnt2!=0 && nums[i] == num2)
            cnt2++;
        else if(cnt1==0)
        {
            num1=nums[i];
            cnt1=1;                
        }
        else if(cnt2==0)
        {
            num2=nums[i];
            cnt2=1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int c1=0,c2=0; // checking if majority elemnent is more than n/3 or not
    for(int i=0;i<n;i++)
    {
        if(cnt1>0 && nums[i]==num1)
            c1++;
        else if(cnt2>0 && nums[i]==num2)
            c2++;
    }
    
    if(c1>(n/3))
        ans.push_back(num1);
    if(c2>(n/3))
        ans.push_back(num2);
    
    return ans;
}



<------ 5 ------!>

// Grid Unique Paths
// https://leetcode.com/problems/unique-paths/

1. DP (Recursion) 
// first tell about recursion and then improve it to DP.

// time -> O(n*m)
// space -> O(n*m)

int recursion(int m, int n, int x, int y)
{
    if(x>m || y>n)
        return 0;
    
    if(x==m && y==n)
        return 1;
    
    if(t[x][y]!=-1) // checking in DP table (needs to be created global)
        return t[x][y];
    
    return t[x][y] = (recursion(m,n,x+1,y) + recursion(m,n,x,y+1));
}

2. using math
// for n row and m col 
// total number of direction d = (m+n-2)
// you can choose either from (m-1) col or (n-1) row

ans = (m+n-2 C m-1) or (m+n-2 C n-1)

// time -> O(m-1) or O(n-1) // depending on formula
// space -> O(1)

int uniquePath(int row, int col)
{
	int n=row+col-2;
	int r= min(col-1,row-1);
	double res=1;

	for(int i=1;i<=r;i++)
		res = (res*(n-r+i))/i;

	return (int)res;
}



<------ 6 ------!>

// Reverse Pairs
// https://leetcode.com/problems/reverse-pairs/

// time -> O(nlogn)+O(n)+O(n)
// space -> O(n)

int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right)
{
    int j=mid; //second subarray
    int cnt=0;
    
    // this loop is for calculating 
    for(int i=left;i<mid;i++)
    {
        while(j<=right && arr[i] > 2LL*arr[j])
            j++;
        cnt+=(j - mid);
    }

    //simple merge operation
    int i=left;  //first subarray        
    j=mid;       //second seubarray
    int k=left;  //temp subarray

    while(i<=mid-1 && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            k++,i++;
        }
        else
        {
            temp[k]=arr[j];
            k++,j++;                
        }
    }
    while(i<=mid-1)
        temp[k++] = arr[i++];

    while(j<=right)
        temp[k++] = arr[j++];

    for (i=left;i<=right;i++)
        arr[i] = temp[i];

    return cnt;
}

int mergeSort(vector<int>& arr, vector<int>& temp, int left, int right)
{
    int mid, cnt=0;
    if(right > left)
    {
        mid = (left+right)/2;

        cnt+=mergeSort(arr, temp, left, mid);
        cnt+=mergeSort(arr, temp, mid+1, right);

        cnt+=merge(arr, temp, left, mid+1, right);
    }
    return cnt;
}