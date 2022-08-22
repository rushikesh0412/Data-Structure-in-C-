#include <iostream>
using namespace std;

//Iterative
int factorial1(int n)
{
	int fact = 1;
	for(int i=1; i<=n; i++)
	{
		fact *= i;
	}
	return fact;+-
}
//Recursive
int factorial2(int n)
{
	if(n<=1)
	{
		return 1;
	}
	else
	{
		return (n * factorial2(n-1));
	}
	
}
int main()
{
	char i;
	
	do{
		int num;
		cout<<"Enter number: ";
		cin>>num;
		cout<<endl;
		int fact1 = factorial1(num); 
		cout<<"Factorial1 of "<<num<<" is "<<fact1<<endl;
		int fact2 = factorial2(num);
		cout<<"Factorial2 of "<<num<<" is "<<fact2<<endl;
		cout<<endl<<endl;
		
		cout<<"Do you want to continue(y/n) : ";
		cin>>i;
	}while(i!='n');
	
	
	return 0;
}