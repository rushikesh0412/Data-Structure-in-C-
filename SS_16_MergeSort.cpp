#include <iostream>
using namespace std;

//Merge Sort Sorting Algorithm
int n;		//Array size
//mereg function
void merge(int arr[], int left, int mid, int right)
{
	int i = left;	//stating index of left subarray
	int j = mid+1;	//stating index for right subarray
	int k = left;	//starting index for temporary
	
	int temp[n];	//temporary
	
	while(i<=mid && j<=right)
	{
		if(arr[i]<=arr[j])			//arr[i] is smaller than arr[j]
		{
			temp[k] = arr[i];		 
			i++;
			k++;
		}
		else						//arr[j] is smaller than arr[i]
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid)					//remaingining element of the sorted left subarray
	{
		temp[k] = arr[i];			
		i++;
		k++;
	}
	while(j<=right)					//remaingining element of the sorted right subarray
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	
	for(int s=left; s<=right; s++)		//copy all element in arr from temp array
	{
		arr[s] = temp[s];
	}
}

//merge sort function
void mergeSort(int arr[], int left, int right)
{
	if(left < right)
	{
		int mid = (left+right)/2;
		
		mergeSort(arr, left, mid);			//divide left sub array
		mergeSort(arr, mid+1, right);		//divide right sub array
		merge(arr, left, mid, right);
	}
}
int main()
{
	//int arr[5] = {4,6,1,2,7};	
				
	cout<<"How many element you want to enter: ";
	cin>>n;
	int arr[n];
	cout<<"Enter "<<n<<" no. of elements of array: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"arr["<<i<<"] = ";
		cin>>arr[i];
	}
	
	cout<<"Unsorted Array: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
	
	mergeSort(arr,0,n-1);	//Sorting actually happening
	
	cout<<"Sorted Array: "<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

