//Singly Linked List
/* 
1. Understanding of what is Linked List & Singly Linked List
2. C++ Objects & Classes
3. Pointer in C++
4. Dynamic Memory aloocation

	disclaimer: There are different ways to implement Linked List (& pretty much all other DS) so this is the way we will go ahead
	Singly Linked List Operations:
	1. appendNode()
	2. prependNode()
	3. insertNodeAfter()
	4. deleteNodeByKey()
	5. updateNodeByKey()
	6. print()
	
*/

#include <iostream>
using namespace std;


class Node{
	public:
		int key;
		int data;
		Node *next;
		Node()
		{
			key  = 0;
			data = 0;
			next = NULL;
		}
		Node(int k, int d)
		{
			key  = k;
			data = d;
			next = NULL;
		}
		
};
class SinglyLinkedList{
	public:
		Node *head;
		
		SinglyLinkedList()
		{
			head = NULL;
		}
		SinglyLinkedList(Node *n)
		{
			head = n;
		}
		
		//1. Check of node exist using key value
		Node *nodeExists(int k)
		{
			Node *temp = NULL;
			Node *ptr  = head;
			while(ptr != NULL)
			{
				if(ptr->key == k)
				{
					temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}
		//2. Append a node to the list
		void appendNode(Node *n)
		{
			if(nodeExists(n->key) != NULL)
			{
				cout<<"Node Already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
			}
			else
			{
				if(head == NULL)
				{
					head = n;
					cout<<"Node Appended"<<endl;
				}
				else
				{
					Node *ptr = head;
					while(ptr->next != NULL)
					{
						ptr = ptr->next;
					}
					ptr->next = n;
					cout<<"Node Appended"<<endl;
				}
			}
		}
		//3. Prepend Node - Attach a node at the start
		void prependNode(Node *n)
		{
			if(nodeExists(n->key) != NULL)
			{
				cout<<"Node Already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
			}
			else
			{
				if(head == NULL)
				{
					head = n;
					cout<<"Node Prepended"<<endl;
				}
				else
				{
					n->next = head;
					head = n;
					cout<<"Node prepended"<<endl;
				}
				
			}
		}
		
		//4. Insert a Node after a particular node in the list
		void insertNodeAfter(int k, Node *n)
		{
			Node *ptr = nodeExists(k);
			if(ptr == NULL)
			{
				cout<<"No node exist with key value: "<<k<<endl;
			}
			else
			{
				if(nodeExists(n->key) != NULL)
				{
				cout<<"Node Already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
				}
				else
				{
					n->next = ptr->next;
					ptr->next = n;
					cout<<"Node Inserted After key"<<endl;
				}
			}
		}
		//5. Insert node before key
		void insertNodeBefore(int k, Node *n)
		{
			Node *ptr = nodeExists(k);
			
			if(ptr == NULL)
			{
				cout<<"No node exist with key value: "<<k<<endl;
			}
			else
			{
				if(nodeExists(n->key) != NULL)
				{
				cout<<"Node Already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
				}
				else
				{
					if(head->key == k)
					{
						n->next = head;
						head = n;
						cout<<"Node Inserted Before key"<<endl;
					}
					else
					{
						Node *prevptr = head;
						Node *currentptr = head->next;
						while(currentptr != NULL)
						{
							if(currentptr->key == k)
							{
								n->next = prevptr->next;
								prevptr->next = n;
								currentptr = NULL;
								cout<<"Node Inserted Before key"<<endl;
							} 
							else
							{
								prevptr    = prevptr->next;
								currentptr = currentptr->next;
							}			
						}
					}
				}
			}
		}
		//6. Delete node by unique key
		void deleteNodeByKey(int k)
		{
			if(head == NULL)
			{
				cout<<"Singly Linked List already Empty. cant delete"<<endl;
			}
			else if(head != NULL)
			{
				if(head->key == k)
				{
					head = head->next;
					cout<<"Node Unlinked with key value: "<<k<<endl;
				}
				else
				{
					Node *temp = NULL;
					Node *prevptr = head;
					Node *currentptr = head->next;
					
					while(currentptr != NULL)
					{
						if(currentptr->key == k)
						{
							temp = currentptr;
							currentptr = NULL;
						}
						else
						{
							prevptr = prevptr->next;
							currentptr = currentptr->next;
						}
					}
					if(temp != NULL)
					{
						prevptr->next = temp->next;
						cout<<"Node Unlinked with key value: "<<k<<endl;
					}
					else
					{
						cout<<"Node Doesn't exist with key value: "<<k<<endl;
					}
				}
			}
		}
		//7. Update node
		void updateNodeByKey(int k, int d)
		{
			Node *ptr = nodeExists(k);
			if(ptr != NULL)
			{
				ptr->data = d;
				cout<<"Node Data Updataed Successfully"<<endl;
			}
			else
			{
				cout<<"Node Doesn't exist with key value: "<<k<<endl;
			}
		}
		//8. print linked List
		void printList()
		{
			if(head == NULL)
			{
				cout<<"No Node in Singly Linked List"<<endl;
			}
			else
			{
				cout<<endl<<"Singly Linked List value: ";
				Node *ptr = head;
				while(ptr != NULL)
				{
					cout<<"("<<ptr->key<<","<<ptr->data<<") --> ";
					ptr = ptr->next;
				}
			}
		}
};

int main()
{
	SinglyLinkedList s;
	int option;
	int key1, k1, data1;
	
	do{
		cout<<"\n\nWhat operation do you want to perform?"<<endl;
		cout<<"0. exit()"<<endl;
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insertNodeAfter()"<<endl;
		cout<<"4. insertNodeBefore()"<<endl;
		cout<<"5. deleteNodeByKey()"<<endl;
		cout<<"6. updateNodeByKey()"<<endl;
		cout<<"7. printList()"<<endl;
		cout<<"8. Clear Screen"<<endl<<endl;
		
		cout<<"Select Option Number: ";
		cin>>option;
		Node* n1 = new Node();
		
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Append Node Operation- "<<endl;
				cout<<"Enter key: ";
				cin>>key1;
				cout<<"Enter data: ";
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				s.appendNode(n1);
				break;
			case 2:
				cout<<"Prepend Node Operation- "<<endl;
				cout<<"Enter key: ";
				cin>>key1;
				cout<<"Enter data: ";
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				s.prependNode(n1);
				break;
			case 3:
				cout<<"Insert Node After Operation- "<<endl;
				cout<<"Enter key of existing Node after which you want to Insert this new Node: ";
				cin>>k1;
				cout<<"Enter key: ";
				cin>>key1;
				cout<<"Enter data: ";
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				s.insertNodeAfter(k1,n1);
				break;
			case 4:
				cout<<"Insert Node Before Operation- "<<endl;
				cout<<"Enter key of existing Node Before which you want to Insert this new Node: ";
				cin>>k1;
				cout<<"Enter key: ";
				cin>>key1;
				cout<<"Enter data: ";
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				s.insertNodeBefore(k1,n1);
				break;
			case 5:
				cout<<"Delete Node By Key- "<<endl;
				cout<<"Enter key of the node to be deleted: ";
				cin>>k1;
				s.deleteNodeByKey(k1);
				break;
			case 6:
				cout<<"Update Node By Key Operation- "<<endl;
				cout<<"Enter key: ";
				cin>>key1;
				cout<<"Enter New Data: ";
				cin>>data1;
				s.updateNodeByKey(key1, data1);
				break;
			case 7:
				s.printList();
				break;
			case 8:
				system("cls");
			default:
				cout<<"Enter Proper Option Number"<<endl;
		}
		
	}while(option !=0);
	
	return 0;
}