#include <iostream>
using namespace std;


//Insertion Sort Algorithm in C++ 
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for(i=1; i<n; i++)
	{
		key = arr[i];
		j = i-1;
		
		/*
		//ASCENDING order
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j = j - 1;
		}
		
		*/
		
		//DESCENDING order
		while(j>=0 && arr[j]<key)
		{
			arr[j+1] = arr[j];
			j = j - 1;
		}
		
		arr[j+1] = key;
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
	
	insertionSort(arr, n);	//Sorting actually happening
	
	
	cout<<"Sorted Array: "<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}