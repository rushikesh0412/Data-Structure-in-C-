#include <iostream>
using namespace std;


//Circular Doubly Linked List
class Node{
	public:
		int key;
		int data;
		Node *previous;
		Node *next;
		
		Node()
		{
			key  = 0;
			data = 0;
			previous = NULL;
			next  = NULL;	
		}	
		Node(int k, int d)
		{ 
			key  = k;
			data = d;
			previous = NULL;
			next = NULL;
		}
};
class CircularDoublyLinkedList
{
	public:
		Node *head;
		
		CircularDoublyLinkedList()
		{
			head = NULL;
		}
		//1. Check of node exist using key value
		Node *nodeExists(int k)
		{
			Node *temp = NULL;
			Node *ptr = head;
			
			if(ptr == NULL)
			{
				return temp;
			}
			else
			{
				do
				{
					if(ptr->key == k)
					{
						temp = ptr;
					}
					ptr = ptr->next;
				}while(ptr != head);
				return temp;
			}
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
					n->next = head;
					//n->previous = head
					cout<<"Node Appended as Head Node"<<endl;
				}
				else
				{
					Node *ptr = head;
					while(ptr->next != head)
					{
						ptr = ptr->next;
					}
					n->next = ptr->next;
					head->previous = n;
					n->previous = ptr;
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
					n->next = head;
					//n->previous = head
					cout<<"Node Prepended"<<endl;
				}
				else
				{
					Node *ptr = head;
					while(ptr->next != head)
					{
						ptr = ptr->next;
					}
					n->previous = ptr;
					ptr->next = n;
					n->next = head;
					head->previous = n;
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
					if(ptr->next == head)
					{
						n->next = ptr->next;
						head->previous = n;
						n->previous = ptr;
						ptr->next = n;
						cout<<"Node Inserted After key at END"<<endl;
					}
					else
					{
						Node *nextptr = ptr->next;
						n->next = ptr->next;
						nextptr->previous = n;
						n->previous = ptr;
						ptr->next = n;
						cout<<"Node Inserted After key"<<endl;
					}	
				}
			}
		}
		//4. Insert a Node before key in the list
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
					if(ptr == head)
					{
						Node *ptr1 = head;
						while(ptr1->next != head)
						{
							ptr1 = ptr1->next; 
						}
						n->next = head;
						head->previous = n;
						head = n;
						ptr1->next = head;
						head->previous = ptr1;
						cout<<"Node Inserted Before key at END"<<endl;
					}
					else
					{
						Node *prevptr = ptr->previous;
						
						n->next = ptr;
						ptr->previous = n;
						n->previous = prevptr;
						prevptr->next = n;
						cout<<"Node Inserted Before key"<<endl;
					}	
				}
			}
		}
		//6. Delete node by unique key
		void deleteNodeByKey(int k)
		{
			Node *ptr = nodeExists(k);
			if(ptr == NULL)
			{
				cout<<"No node exist with key value of "<<k<<endl;
			}
			else
			{
				
				if(ptr == head)
				{
					if(head->next == head)
					{
						head = NULL;
						cout<<"Head Node UNLINKED... List Empty"<<endl;
					}
					else
					{
						Node *ptr1 = head;
						while(ptr1->next != head)
						{
							ptr1 = ptr1->next;
						}
						head = head->next;
						head->previous = ptr1;
						ptr1->next = head;
						cout<<"Node UNLINKED with key value "<<k<<endl;
					}
				}
				else
				{
					Node *nextptr = ptr->next;
					Node *ptr1 = head;
					while(ptr1->next != ptr)
					{
						ptr1 = ptr1->next;
					}
					ptr1->next = ptr->next;	
					nextptr->previous = ptr1;
					cout<<"Node UNLINKED with keys value: "<<k<<endl;
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
				cout<<"No Node in Circular Singly Linked List"<<endl;
			}
			else
			{
				cout<<endl<<"Circular Singly Linked List value: ";
				Node *ptr = head;
				do{
					cout<<"("<<ptr->key<<","<<ptr->data<<") <--> ";
					ptr = ptr->next;
				}while(ptr != head);
			}
		}
};
int main()
{
	CircularDoublyLinkedList c;
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
				c.appendNode(n1);
				break;
			case 2:
				cout<<"Prepend Node Operation- "<<endl;
				cout<<"Enter key: ";
				cin>>key1;
				cout<<"Enter data: ";
				cin>>data1;
				n1->key = key1;
				n1->data = data1;
				c.prependNode(n1);
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
				c.insertNodeAfter(k1,n1);
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
				c.insertNodeBefore(k1,n1);
				break;
			case 5:
				cout<<"Delete Node By Key- "<<endl;
				cout<<"Enter key of the node to be deleted: ";
				cin>>k1;
				c.deleteNodeByKey(k1);
				break;
			case 6:
				cout<<"Update Node By Key Operation- "<<endl;
				cout<<"Enter key: ";
				cin>>key1;
				cout<<"Enter New Data: ";
				cin>>data1;
				c.updateNodeByKey(key1, data1);
				break;
			case 7:
				c.printList();
				break;
			case 8:
				system("cls");
			default:
				cout<<"Enter Proper Option Number"<<endl;
		}
		
	}while(option !=0);
	return 0;
}