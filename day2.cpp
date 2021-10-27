<------ 1 ------!>

// Set Matrix Zeros
// https://leetcode.com/problems/set-matrix-zeroes/

// time -> O(n*m)
// space -> O(1)

void setZeroes(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    
    bool fr=false,fc=false;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                if(i==0) fr=true;
                if(j==0) fc=true;
                
                matrix[i][0]=matrix[0][j]=0;
            }
        }
    }    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {                                
            if(matrix[i][0]==0 || matrix[0][j]==0)
                matrix[i][j]=0;                               
        }            
    }    
    if(fr)
    {
        for(int i=0;i<m;i++)
            matrix[0][i]=0;
    }
    if(fc)
    {
        for(int i=0;i<n;i++)
            matrix[i][0]=0;
    }
}



<------ 2 ------!>

// Pascal Triangle
// https://leetcode.com/problems/pascals-triangle/

1: Given row collum index
// time -> O(n) 
// space -> O(1)
   formula = row-1 C col -1	(combination)
  

2: Print only entire row
// time -> O(n) 
// space -> O(n) 

n=row-1;
for(int i=0;i<row;i++)
{
	res *= (n-i);
	res /= (i+1);
}   
 

3: Entire pascal
// time -> O(n^2) 
// space -> O(n^2) 

vector<vector<int>> pascal(int numRows)
{        
    vector<vector<int>> v(numRows);
    
    for(int i=0;i<numRows;i++)
    {        
        v[i].resize(i+1);
        v[i][0]=v[i][i]=1;
        
        for(int j=1;j<i;j++)
        {
            v[i][j] = (v[i-1][j-1]+v[i-1][j]);
        }
    }
    return v;
}
 


<------ 3 ------!>

// Next Permutation
// https://leetcode.com/problems/next-permutation/

// time -> O(n) 
// space -> O(1) 

void nextPermutation(vector<int>& nums)
{
    int n=nums.size(),i,j;
	for(i=n-2; i>=0; i--)
	{
		if(nums[i] < nums[i+1])	
			break;
	}
	if(i<0)
		reverse(nums.begin(), nums.end());

	else
	{
		for(j=n-1; j>i; j--)
		{
			if(nums[j] > nums[i])
				break;
		}
		swap(nums[j], nums[i]);
		reverse(nums.begin()+i+1, nums.end());
	}    
}



<------ 4 ------!>

// Inversion of Array (Using Merge Sort) 
// https://www.geeksforgeeks.org/counting-inversions/

// time -> O(nlogn) 
// space -> O(n) 

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

int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right)
{
    int i=left;  //first subarray
    int j=mid;   //second subarray
    int k=left;  //temp subarray

    int cnt=0;

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
            cnt+=(mid-i); //all right elemnet need to swap
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



<------ 5 ------!>

// Stock Buy and Sell 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// time -> O(n) 
// space -> O(1) 

int maxProfit(vector<int>& prices)
{     
    int buy=prices[0];
    int profit=0;
    
    for(int i=1;i<prices.size();i++)
    {
        if(prices[i]<=buy)
            buy=prices[i];
        else
        {
            profit=max(prices[i]-buy,profit);
        }
    }
    return profit;
}



<------ 6 ------!>

// Rotate Matrix 
// https://leetcode.com/problems/rotate-image/

// transpose -> reverse every row

// time -> O(n^2) 
// space -> O(1)

void rotate(vector<vector<int>>& matrix)
{
	int n=matrix.size();

	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			swap(matrix[i][j], matrix[j][i]);

	for(int i=0;i<n;i++)
		reverse(matrix[i].begin(), matrix[i].end())
}	