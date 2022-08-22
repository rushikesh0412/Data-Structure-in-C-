#include <iostream>
using namespace std;

/*
//Linear Search Algorithm
void LinearSearch(int arr[], int n, int s)
{
	int temp = -1;
	
	
	for(int i=0; i<s; i++)
	{
		if(arr[i] == n)
		{
			cout<<"Element found at position "<<i+1<<endl;
			temp = 0;
		}
	}
	
	if(temp == -1)
	{
		cout<<"No element found"<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;
	int arr[n];
	
	for(int i=0; i<n; i++)
	{
		cout<<"arr["<<i+1<<"] = ";
		cin>>arr[i];
	}
	
	cout<<"Please enter an element to search: ";
	int num;
	cin>>num;
	
	LinearSearch(arr, num, n);
	
	return 0;
}
*/


//Linear Search Algorithm
int LinearSearch(int arr[], int n, int s)
{
	for(int i=0; i<s; i++)
	{
		if(arr[i] == n)
		{
			return (i+1);
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
	
	for(int i=0; i<n; i++)
	{
		cout<<"arr["<<i+1<<"] = ";
		cin>>arr[i];
	}
	
	cout<<"Please enter an element to search: ";
	int num;
	cin>>num;
	
	int result = LinearSearch(arr, num, n);
	
	(result == -1)? cout<<"Element not found" : cout<<"Element found at position "<<result<<endl;
	return 0;
}





