#include <iostream>
using namespace std;
int n;		//Array size

void countingSort(int arr[], int size, int div)
{
	int output_array[size];
	int range = 10;
	int count_array[range];
	
	for(int i=0; i<range; i++)
	{
		count_array[i] = 0;
	}
	for(int i=0; i<size; i++)
	{
		count_array[(arr[i]/div)%10]++;
	}
	for(int i=1; i<range; i++)
	{
		count_array[i] += count_array[i-1];
	}
	for(int i =(size-1); i>=0; i--)
	{
		output_array[count_array[(arr[i]/div)%10] - 1] = arr[i];
		count_array[(arr[i]/div)%10]--;
	}
	for(int i=0; i<size; i++)
	{
		arr[i] = output_array[i];
	}
}

int getMax(int arr[], int size)
{
	int max = arr[0];
	
	for(int i=1; i<size; i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}
void radixSort(int arr[], int size)
{
	int max = getMax(arr, size);
	
	for(int div=1; max/div>0; div*=10)
	{
		countingSort(arr, size, div);
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
	
	radixSort(arr,n);			//Radix Sort called
	
	cout<<"Sorted Array: "<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}