//Doubly Linked List

#include <iostream>
using namespace std;

class Node{
	public: 
		int key;
		int data;
		Node *previous;
		Node *next;
		
		Node()
		{
			key  	 = 0;
			data 	 = 0;
			previous = NULL;
			next 	 = NULL;
		}
		Node(int k, int d)
		{
			key  	 = k;
			data 	 = d;
			previous = NULL;
			next 	 = NULL;
		}
};
class DoublyLinkedList{
	public:
		Node *head;
		
		DoublyLinkedList()
		{
			head = NULL;
		}
		DoublyLinkedList(Node *n)
		{
			head = n;
		}
		//1. Check of node exist using key value
		Node *nodeExists(int k)
		{
			Node *temp = NULL;
			Node *ptr = head;
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
					cout<<"Node Appended as Head Node"<<endl;
				}
				else
				{
					Node *ptr = head;
					while(ptr->next != NULL)
					{
						ptr = ptr->next;
					}
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
					cout<<"Node Prepended as Head Node"<<endl;
				}
				else{
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
			//check k is exist
			if(ptr == NULL)
			{
				cout<<"No node exist with key value: "<<k<<endl;
			}
			else
			{
				//check for the node already exist
				if(nodeExists(n->key) != NULL)
				{
					cout<<"Node Already exist with key value: "<<n->key<<endl;
					cout<<"Append another node with different key value"<<endl;
				}
				else	//if node is not exist
				{
					cout<<"INSERTIMG"<<endl;
					
					Node *nextNode = ptr->next;
					
					//appending at the end
					if(nextNode == NULL)
					{
						ptr->next = n;
						n->previous = ptr;
						cout<<"Node Inserted at the END"<<endl;
					}
					
					//appended in between
					else
					{
						n->next = nextNode;
						nextNode->previous = n;
						n->previous = ptr;
						ptr->next = n;
						
						cout<<"Node Inserted in between"<<endl;
					}
					
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
				//check for the node already exist
				if(nodeExists(n->key) != NULL)
				{
					cout<<"Node Already exist with key value: "<<n->key<<endl;
					cout<<"Append another node with different key value"<<endl;
				}
				else	//if node is not exist
				{
					cout<<"INSERTIMG"<<endl;
					
					Node *nextNode = ptr->next;
					if(ptr->key == head->key)
					{
						n->next = head;
						head->previous = n;
						head = n;
						cout<<"Node Inserted before head Node"<<endl;
					}
					//appended in between
					else
					{
						Node *prevNode = ptr->previous;
						
						n->next = ptr;
						ptr->previous = n;
						
						n->previous = prevNode;
						prevNode->next = n;
						
						cout<<"Node Inserted in between"<<endl;
					}
				}	
			}
		}
		void deleteNodeByKey(int k)
		{
			Node *ptr = nodeExists(k);
			if(ptr == NULL)
			{
				cout<<"No node exist with key value: "<<k<<endl;
			}
			else
			{
				if(head->key == k)
				{
					head = head->next;
					cout<<"Node UNLINKED with key value: "<<k<<endl;
				}
				else
				{
					Node *nextNode = ptr->next;
					Node *prevNode = ptr->previous;
					//deleting at end
					if(nextNode == NULL)
					{
						prevNode->next = NULL;
						cout<<"Node UNLINKED at the END"<<endl;
					}
					else	//Deleting in between
					{
						prevNode->next = nextNode;
						nextNode->previous = prevNode;
						cout<<"Node UNLINKED in Between"<<endl;
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
				cout<<"No Node in Doubly Linked List"<<endl;
			}
			else
			{
				cout<<endl<<"Doubly Linked List value: ";
				Node *ptr = head;
				while(ptr != NULL)
				{
					cout<<"("<<ptr->key<<","<<ptr->data<<") <--> ";
					ptr = ptr->next;
				}
			}
		}
};
int main()
{
	DoublyLinkedList s;
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