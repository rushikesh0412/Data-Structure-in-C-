#include <iostream>
using namespace std;

int n;		//Array size

//Counting Sort Sorting Algorithm
void countingSort(int input_array[], int size, int range)
{
	int output_array[size];
	int count_array[range];
	
	//initialize all element to 0 count array
	for(int i=0; i<range; i++)
	{
		count_array[i] = 0;
	}
	//to take a count of all elements in the input array
	for(int i=0; i<size; i++)
	{
		++count_array[input_array[i]];
	}
	//cummulative count of count array to get the position of elements
	//to b store in the output array 
	for(int i=1; i<range; i++)
	{
		count_array[i] = count_array[i] + count_array[i-1];
	}
	//placing input aray elemens into output array in proper positions
	//such that the result is a sorted array in ASC order
	for(int i=0; i<size; i++)
	{
		output_array[--count_array[input_array[i]]] = input_array[i];
	}
	
	for(int i=0; i<size; i++)
	{
		input_array[i] =output_array[i];
	}
}
int main()
{
	int range = 10;
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
	
	countingSort(arr,n,range);			//Counting Sort called
	
	cout<<"Sorted Array: "<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}