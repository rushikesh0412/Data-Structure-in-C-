#include <iostream>
using namespace std;

//Algorithm 1
void sumOfNumbers1(double n)
{
	double sum = 0;
	for(int i=1; i<=n; i++)
	{
		sum = sum + i;
	}
	cout<<"Method 1: Sum of "<<n<<" numbers is: "<<sum<<endl;
}

//Algorithm 2
void sumOfNumbers2(double n)
{
	double sum = ((n*(n+1))/2);
	
	cout<<"Method 2: Sum of "<<n<<" numbers is: "<<sum<<endl;
}
int main()
{
	double num;
	cout<<"Enter no. till which you want to sum: ";
	cin>>num;
	//sumOfNumbers1(num);
	cout<<endl<<endl;
	sumOfNumbers2(num);
}