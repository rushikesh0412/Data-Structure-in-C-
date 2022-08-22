#include <iostream>
using namespace std;

int n;		//Array size

//Shell Sort
void shellSort(int arr[], int n)
{
	int total_passes = 0;
	for(int gap =n/2; gap>0; gap /= 2)
	{
		for(int j=gap; j<n; j+=1)
		{
			int temp = arr[j];
			int i=0;
			for(i=j; (i>=gap) && (arr[i-gap] > temp); i-=gap)
			{
				arr[i] = arr[i - gap]; 
				total_passes++;
			}
			arr[i] = temp;
			total_passes++;
		}
		total_passes++;
	}
	cout<<"Total Passes in Shell Sort: "<<total_passes<<endl;
}


void bubbleSort(int arr[], int n)
{
	int total_passes = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<(n-i-1); j++)
		{
			
			//For ASCENDING Order
			if(arr[j] > arr[j+1])
			{ 
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				total_passes++;
			}
			
			
			/*
			//For DESCENDING Order
			if(arr[j] < arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			*/
			total_passes++;
		}
		total_passes++;
	}
	cout<<"Total Passesin Bubble Sort: "<<total_passes<<endl;
}
int main()
{
	int range = 10;
	cout<<"How many element you want to enter: ";
	cin>>n;
	int arr[n], arr1[n];
	cout<<"Enter "<<n<<" no. of elements of array: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"arr["<<i<<"] = ";
		cin>>arr[i];
		arr1[i]= arr[i];
	}
	
	cout<<"Unsorted Array: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
	
	shellSort(arr,n);			//shell Sort called
	
	cout<<"Shell Sorted Array: "<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	
	cout<<endl<<endl;
	bubbleSort(arr1, n);
	cout<<"Bubble Sorted Array: "<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr1[i]<<" ";
	}
	return 0;
}