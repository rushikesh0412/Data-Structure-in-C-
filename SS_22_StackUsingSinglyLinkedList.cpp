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
class Stack{
	public:
		Node *top;
		
	Stack()
	{
		top = NULL;
	}
	bool isEmpty()
	{
		if(top == NULL)
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
		Node *temp = top;
		bool exist = false;
		while(temp!=NULL)
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
	void push(Node *n)
	{
		if(top == NULL)
		{
			top = n;
		}
		else if(checkIfNodeExist(n))
		{
			cout<<"Node already exist with this key value. Please try with differet key value"<<endl;			
		}
		else
		{
			Node *temp = top;
			top = n;
			n->next = temp;
			cout<<"Node PUSHED!"<<endl;
		}
	}
	Node *pop()
	{
		Node *temp = NULL;
		if(isEmpty())
		{
			cout<<"Stack underflow"<<endl;
		}
		else
		{
			temp = top;
			top = top->next;	
		}
		return temp;
	}
	Node* peek()
	{
		
		if(isEmpty())
		{
			cout<<"Stack underflow"<<endl;
			return NULL;
		}
		else
		{
			return top;
		}
	}
	int count()
	{
		Node* temp = top;
		int count = 0;
		while(temp!=NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	void display()
	{
		cout<<"All value in the stack are: "<<endl;
		Node *temp = top;
		while(temp != NULL)
		{
			cout<<"("<<temp->key<<","<<temp->data<<")"<<endl;
			temp = temp->next;
		}
		
	}
	
};
int main()
{
	Stack s1;
	int option, data, key ;
	
	do{
		cout<<"\n\nWhat operation do you want to perform?"<<endl;
		cout<<"0. exit()"<<endl;
		cout<<"1. Push()"<<endl;
		cout<<"2. Pop()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. Peek()"<<endl;
		cout<<"5. count()"<<endl;
		cout<<"6. display()"<<endl;
		cout<<"7. Clear Screen"<<endl<<endl;
		cout<<"Select option number: ";
		cin>>option;
		
		Node *new_node = new Node();
		
		switch(option)
		{	
			case 0:
				break;
			case 1:
				cout<<"PUSH Operation: "<<endl;
				cout<<"Enter key:";
				cin>>key;
				cout<<"Enter data: ";
				cin>>data;
				new_node->key = key;
				new_node->data = data;
				s1.push(new_node);
				break;
			case 2:
				cout<<"Pop function called- Poped Value: "<<endl;
				new_node = s1.pop();
				cout<<"TOP of Stack is: ("<<new_node->key<<","<<new_node->data<<")"<<endl;
				delete new_node;
				break;
			case 3:
				if(s1.isEmpty())
				{
					cout<<"Stack is Empty"<<endl;
				}
				else
				{
					cout<<"Stack is not Empty"<<endl;
				}
				break;
			case 4:
				if(s1.isEmpty())
				{
					cout<<"Stack is Empty"<<endl;
				}
				else
				{
					cout<<"Peek function Called: "<<endl;
					new_node = s1.peek();
					cout<<"TOP of Stack is: ("<<new_node->key<<","<<new_node->data<<")"<<endl;
				}
				break;
			case 5:
				cout<<"Count Function called- Number of Items in the stack are: "<<s1.count()<<endl;
				break;
			case 6:
				cout<<"Display Function called- "<<endl;
				s1.display();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Enter Propper Option number "<<endl;
		}
		
		
	}while(option != 0);
	
	return 0;
}