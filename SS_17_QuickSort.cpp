#include <iostream>
using namespace std;
//Quick Sort Sorting Algorithm


int n;		//Array size

int partition(int arr[], int s, int e)
{
	int pivot = arr[e];
	int pIndex = s;
	for(int i=s; i<e; i++)
	{
		if(arr[i] <= pivot)
		{
			int temp = arr[i];
			arr[i] = arr[pIndex];
			arr[pIndex] = temp;
			pIndex++;
		}
	}
	int temp = arr[e];
	arr[e] = arr[pIndex];
	arr[pIndex] = temp;
	
	return pIndex;
}
void quickSort(int arr[], int s, int e)
{
	if(s<e)
	{
		int  p= partition(arr, s,e);
		quickSort(arr, s, (p-1));		//recursive QS call for left pratition
		quickSort(arr, (p+1), e);		//recursive QS call for right partition
	}	
}
int main()
{
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
	
	quickSort(arr,0,n-1);	//Sorting actually happening
	
	cout<<"Sorted Array: "<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}