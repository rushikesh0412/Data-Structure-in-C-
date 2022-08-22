#include <iostream>
using namespace std;

//Bubble Sort Algorithm
void bubbleSort(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<(n-i-1); j++)
		{
			/*
			//For ASCENDING Order
			if(arr[j] > arr[j+1])
			{ 
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			*/
			
			
			//For DESCENDING Order
			if(arr[j] < arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main()
{
	int n = 5;			//Array size
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
	
	bubbleSort(arr, n);	//Sorting actually happening
	
	
	cout<<"Sorted Array: "<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}