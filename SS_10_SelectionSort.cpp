#include <iostream>
using namespace std;

//Selection Sort Algorithm
void selectionSort(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int min = i;
		for(int j = i+1; j<n; j++)
		{
			/*
			//for ASCENDING order
			if(arr[j]<arr[min])
			{
				min = j;
			}
			*/
			
			//for DESCENDING order
			if(arr[j]>arr[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
int main()
{
	int n = 5;
	int arr[n];
	cout<<"Enter 5 integers in random order: "<<endl;
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
	
	selectionSort(arr, n);	//Sorting actually happening
	
	
	cout<<"Sorted Array: "<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return -1; 
}