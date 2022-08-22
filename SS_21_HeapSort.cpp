#include <iostream>
using namespace std;

/*function to implement the heap sort*/
void heapSort(int arr[], int n)
{
	
}

/* Function to print the array elements*/
void printArray(int arr[], int n);
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cout<<"arr["<<i<<"] = ";
		cin>>arr[i];
	}
	cout<<"Before sorting array elements are- \n";
	printArray(arr, n);
	
	heapSort(arr, n);
	
	cout<<"After sorting array elements are- \n";
	printArray(arr, n);
	
	return 0;
}