#include <iostream>
using namespace std;



/*
//Binary Search Algorithm
int binerySearch(int arr[], int left, int right, int x)
{
	int mid;
	while(left<=right)
	{
		//mid = left + ((right-left)/2);
		mid = (left + right)/2;
		
		if(arr[mid] == x)
		{
			return mid;
		}
		else if(arr[mid]<x)
		{
			left = mid+1;
		}
		else
		{
			right = mid-1;
		}
	}
	return -1;
}
int main()
{
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;
	int *arr = new int(n);
	
	cout<<"Enter the "<<n<<" elements in the arrya in ASCENDING order: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"arr["<<i+1<<"] = ";
		cin>>arr[i];
	}
	
	cout<<"Please enter an element to search: ";
	int num;
	cin>>num;
	
	int result = binerySearch(arr, 0, n-1, num);
	
	(result == -1)? cout<<"Element Not found" : cout<<"Element found at position "<<result+1<<endl;
	return 0;
}
*/



//Binary Search Algorithm using recursion
int binerySearch(int arr[], int left, int right, int x)
{
	if(left <= right)
	{
		//int mid = left + ((right-left)/2);
		int mid = (left + right)/2;
		
		if(arr[mid] == x)
		{
			return mid;
		}
		else if(arr[mid]<x)
		{
			return binerySearch(arr, mid+1, right, x);
		}
		else
		{
			return binerySearch(arr, left, mid-1, x);
		}
	}
	return -1;
}
int main()
{
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;
	int *arr = new int(n);
	
	cout<<"Enter the "<<n<<" elements in the arrya in ASCENDING order: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"arr["<<i+1<<"] = ";
		cin>>arr[i];
	}
	
	cout<<"Please enter an element to search: ";
	int num;
	cin>>num;
	
	int result = binerySearch(arr, 0, n-1, num);
	
	(result == -1)? cout<<"Element Not found" : cout<<"Element found at position "<<result+1<<endl;
	return 0;
}