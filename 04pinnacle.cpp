#include <iostream>

using namespace std;


class LinkList;

class Node				//DOUBLY LINKED LIST
{
		string name;
		int prn;
		string desg;
		Node *next; 
		public:
		Node()
		{
				next = NULL;                
		}
		friend class LinkList;
};

class LinkList
{
		Node *start;
		Node *last;
		public : 
		LinkList()
		{
				start = NULL;
				last = NULL;
		}
		void create()
		{
				Node *new1;
				new1 = new Node;
				
				cout<<"Enter the PRN Number : " ;
				cin>>new1->prn;
				
				cin.ignore();
				cout<<"Enter the Designation : ";
				getline(cin ,new1->desg);
				
				cout<<"Enter the Name : ";
				getline(cin ,new1->name);
				
				if(start == NULL)
				{
						start = new1;
						last = new1;
				}
				
				else if(start->next == NULL)
				{
						start->next = new1;
						last = new1;
						last->next = NULL;
				}
				
				else
				{
						new1->next = start->next;
						start->next = new1;
				}
		}        
		void display()
		{
				Node *new1;
				new1 = start;
				int count = 0;
				while(new1!=NULL)
				{
						cout<<"Name : "<< new1->name << endl ;
						cout<<"PRN Number : "<< new1->prn <<endl;
						cout<<"Designation : "<< new1->desg << endl ;
						new1 = new1->next;
						count++; 
				}
				cout<<"\nTotal Number of Members are : "<<count<<endl;
		}
		Node *retstart()
		{
				Node *new1;
				new1 = start;
				return new1;	
		}
		void remove()
		{
				char per;
				cout<<"\nWho do you want to remove ? (P/S/M) : "<<endl;
				cin>>per;
				cout<<endl; 
				if(per == 'P')
				{
						Node *curr;
						curr = start;
						start = start->next;
						curr->next = NULL;
						delete curr;
						start->desg = "P";
				}
				else if(per == 'S')
				{
						Node *curr;
						curr = start;
						while(curr->next != last)
								curr = curr->next;
						last = curr;
						last->next = NULL;
						delete curr->next;
						curr->next = NULL;
						last->desg = "S";
				}
				else
				{
						int data;
						cout<<"\nEnter the PRN Number of the Student to be deleted : ";
						cin>>data;
						Node *curr;
						Node *prev;
						curr = start;
						prev = NULL;
						while((curr!=NULL) && (curr->prn!=data))
						{
								prev = curr;        		
								curr = curr->next;
						}
						prev->next = curr->next;
						delete curr;
						curr = NULL;
				}      
		}
		void revdisplay(Node *head)
		{
				if(head!=NULL)
				{
						revdisplay(head->next); 
						cout<<"Name : "<< head->name << endl ;
						cout<<"PRN Number : "<< head->prn <<endl;
						cout<<"Designation : "<< head->desg << endl ;
				}
		}
		LinkList concatenate(LinkList A ,LinkList B)
		{
				LinkList temp;		
				Node *i = A.start;
				Node *j = B.start;
				while(i != NULL && j != NULL)
				{
						Node *new1 = new Node;	
						if(temp.start = NULL)
						{
								temp.start = new1;
								temp.last = new1;		
						}
						else if (i->prn > j->prn)
						{
								new1->prn = i->prn;
								new1->name = i->name;
								new1->desg = i->desg;
								i = i->next;
								temp.last->next = new1;
								temp.last = new1;
						}
						else if (j->prn > i->prn)
						{		
								new1->prn = j->prn;
								new1->name = j->name;
								new1->desg = j->desg;
								j = j->next;
								temp.last->next = new1;
								temp.last = new1;				
						}
				}												
				return temp;
		}
};	


int main()
{
		LinkList A;
		LinkList B;		
		LinkList C;
		while(true)
		{
		 		int opn;
		 		char usr_ip = 'y';
				cout<<"\n1.Create/Add to Linked List\n2.Remove Node\n3.Display\n4.Display in Reverse\n5.Create and Concatenate\n6.Exit\nEnter Option : ";	
				cin>>opn;
				cout<<endl;
				switch(opn)
				{
						case 1:
								do
								{
										A.create();
										cout<<"Do you want to continue (y/n) : ";
										cin>>usr_ip;
								}
								while(usr_ip == 'y');
								cout<<endl;
								break;
						case 2:
								A.remove();
								break;
						case 3:
								A.display();
								break;
						case 4:
								Node *c;
								c = A.retstart();	
								A.revdisplay(c);
								break;
						case 5:
								do{
								B.create();
								cout<<"Do you want to continue (y/n) : ";
								cin>>usr_ip;
								}
								while(usr_ip == 'y');
								C = C.concatenate(A,B);
								C.display();
								break;
						case 6:
							    return 0;
						default:
								cout<<"Invalid Input\n";
				}		
		}
}
