#include <iostream>
using namespace std;

class Node{
	public:
		int key;
		int data;
		Node *next;
		
	Node()
	{
		key = 0;
		data = 0;
		next = NULL;
	}
	Node(int k, int d)
	{
		key = k;
		data = d;
		next = NULL;
	}
};
class Queue{
	public:
		Node *front;
		Node *rear;
		
	Queue()
	{
		front = NULL;
		rear  = NULL;
	}
	bool isEmpty()
	{
		if(front == NULL && rear == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool checkIfNodeExist(Node *n)
	{
		Node *temp = front;
		bool exist = false;
		while(temp != NULL)
		{
			if(temp->key == n->key)
			{
				exist = true;
				break;
			}
			temp = temp->next;
		}
		return exist;
	}
	void enqueue(Node *n)
	{
		if(isEmpty())
		{
			front = n;
			rear = n;
			cout<<"Node ENQUEUED Successfully"<<endl;
		}
		else if(checkIfNodeExist(n))
		{
			cout<<"Node already exist with this key value. Please try with different key value"<<endl;
		}
		else
		{
			rear->next = n;
			rear = n;
			cout<<"Node ENQUEUED Successfully"<<endl;
		}
	}
	Node* dequeue()
	{
		Node *temp = NULL;
		if(isEmpty())
		{
			cout<<"Stack Underflow"<<endl;
		}
		else
		{
			if(front == rear)
			{
				temp = front;
				front = NULL;
				rear = NULL;
			}
			else{
				temp = front;
				front = front->next;
			}
		}
		return temp;
	}
	int count()
	{
		Node *temp = front;
		int count = 0;
		while(temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	void display()
	{
		Node *temp = front;
		if(isEmpty())
		{
			cout<<"Stack Underflow"<<endl;
		}
		else
		{
			while(temp != NULL)
			{
				cout<<"("<<temp->key<<","<<temp->data<<") -->";
				temp = temp->next;
			}
		}
		
	} 
	
};
int main()
{
	Queue q;
	int option, key, data;
	
	do{
		cout<<"\n\nWhat operation do you want to perform?"<<endl;
		cout<<"0. exit()"<<endl;
		cout<<"1. Enqueue()"<<endl;
		cout<<"2. Dequeue()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. count()"<<endl;
		cout<<"5. display()"<<endl;
		cout<<"6. Clear Screan"<<endl<<endl;
		
		cout<<"Select option number: ";
		cin>>option;
		Node *new_node = new Node();
		switch(option)
		{
			case 0:
				
				break;
			case 1:
				cout<<"Enqueue Function Called- "<<endl;
				cout<<"Enter key: ";
				cin>>key;
				cout<<"Enter data: ";
				cin>>data;
				new_node->key = key;
				new_node->data = data;
				
				q.enqueue(new_node);
				break;
			case 2:
				cout<<"DEQUEUE Function Called- "<<endl;
				new_node = q.dequeue();
				cout<<"Dequeue Value is: ("<<new_node->key<<","<<new_node->data<<")"<<endl;
				delete new_node;
				break;
			case 3:
				cout<<"isEmpty Function Called- "<<endl;
				if(q.isEmpty())
				{
					cout<<"Queue is Empty"<<endl;
				}
				else
				{
					cout<<"Queue is NOT Empty"<<endl;
				}
				break;
			case 4:
				cout<<"Count Function Called- "<<endl;
				cout<<"No. of node in the Queue: "<<q.count()<<endl;
				break;
			case 5:
				cout<<"Display Function Called- "<<endl;
				q.display();
				break;
			case 6:
				system("cls");
				break;
			default:
				cout<<"Oops Invalid option! Please enter proper option number."<<endl;
		}
		
	}while(option != 0);
	
	return 0;
}
