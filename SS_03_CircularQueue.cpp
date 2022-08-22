#include <iostream>
using namespace std;
class CircularQueue{
	private:
		int front;
		int rear;
		int arr[5];
		int size; 
		int itemCount;
	public:
		CircularQueue()
		{
			size = (sizeof(arr)/sizeof(arr[0]));
			itemCount = 0;
			front = -1;
			rear = -1;
			for(int i=0; i<5; i++)
			{
				arr[i] = 0;
			}
		}
		bool isEmpty()
		{
			if(front == -1 && rear == -1)
			{
				return true;
			}
			else
			{
				return false;
			}
			
		}
		bool isFull()
		{
			if((rear+1)%size == front)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void enqueue(int val)
		{
			if(isFull())
			{
				cout<<"Queue is Full"<<endl;
			}
			else if(isEmpty())
			{
				rear = front = 0;
				arr[rear] = val;
				itemCount++;
			}
			else
			{
				rear = (rear+1)%size;
				arr[rear] = val;
				itemCount++;
			}
		}
		int dequeue()
		{
			int x = 0;
			if(isEmpty())
			{
				cout<<"Queue is empty!"<<endl;
			}
			else if(front == rear)
			{
				x = arr[front];
				arr[front] = 0;
				rear = -1;
				front = -1;
				itemCount--;
			}
			else
			{
				x = arr[front];	
				arr[front] = 0;
				front = (front+1)%size;
				itemCount--;
			}
			return x;
		}
		int count()
		{
			return itemCount;
		}
		void display()
		{
			cout<<"All values in Queue are: "<<endl;
			for(int i=0; i<size; i++)
			{
				cout<<arr[i]<<" ";
			}
		}
};
int main()
{
	CircularQueue q1;
	int option, value;
	do{
		cout<<"\n\nWhat operation do you want to perform?"<<endl;
		cout<<"0. exit()"<<endl;
		cout<<"1. Enqueue()"<<endl;
		cout<<"2. Dequeue()"<<endl;
		cout<<"3. isFull()"<<endl;
		cout<<"4. isEmpty()"<<endl;
		cout<<"5. count()"<<endl;
		cout<<"6. display()"<<endl;
		cout<<"7. Clear Screen"<<endl<<endl;
		
		cout<<"Select option number: ";
		cin>>option;
		
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Enqueue Operation: \nEnter an item to Enqueue in the Queue: ";
				cin>>value;
				q1.enqueue(value);
				break;
			case 2:
				cout<<"Dequeue Operation: \nDequeue value: "<<q1.dequeue()<<endl;
				break;
			case 3:
				if(q1.isFull())
				{
					cout<<"Queue is Full"<<endl;
				}
				else
				{
					cout<<"Queue is not Full"<<endl;
				}
				
				break;
			case 4:
				if(q1.isEmpty())
				{
					cout<<"Queue is Empty"<<endl;
				}
				else
				{
					cout<<"Queue is not Empty"<<endl;
				}
				break;
			case 5:
				cout<<"Count operation called- \nCount of item in Queue: "<<q1.count()<<endl;
				break;
			case 6:
				cout<<"Display Function called- "<<endl;
				q1.display();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Enter Propper option number"<<endl;
				
		}
	}while(option !=0);
}