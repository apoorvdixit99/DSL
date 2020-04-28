#include<iostream>
using namespace std;

int i=0,j=0;

class node			//DOUBLY CIRCULAR LINKED LIST
{
 	    bool info;
		node()
		{
				info = false;
		}
		node *next,*prev;
		friend class linklist;
};


class linklist
{
		node *start[10];
		public:
		linklist()
		{
				for(int i=0; i<10; i++)
						start[i]=NULL;
		}
		     
		void create()
		{
				for(int i=0; i<10; i++)				//cout<<"\nEach row";
				{
						for(int j=0; j<7; j++)		//cout<<"Each column";
						{
								node* new1 = new node;
								if(start[i]==NULL)			//adding the first element of the row
								{
										start[i]=new1;
										new1->next=start[i];
										new1->prev=start[i];
								}
								else						//adding the subsequent elements
								{
										node *temp=start[i];
										while( temp->next != start[i] )			//Reaching the last element
												temp = temp->next;
										temp->next = new1;						//Adding a new one
										new1->prev = temp;
										new1->next = start[i];
										start[i]->prev = new1;
								}
						}
				}
		}
		
		
		void display()
		{ 
				for(int i=0; i<10; i++)
				{
						node *temp = start[i], *p = start[i]->prev;
						while(temp!=p)
						{
								cout<< temp->info << " " ;
								temp = temp->next;
						}
						cout<<p->info;  
						cout<<"\n";
				}
		}
		 
		void book()
		{
				int n;
				cout<<"\n Enter how many seats to book ? ";
				cin>>n;
				int row[n],col[n];
				for(i=0; i<n; i++) 
				{
						cout<<"\n Enter the row among 10 :  ";
						cin>>row[i];
						--row[i];
						cout<<"\n Enter the columns among 7 :  ";
						cin>>col[i]; 
						--col[i];
				}
				for(i=0; i<n; i++) 
				{ 
						node *temp = start[row[i]];  
						for(j=0; j<col[i]; j++)
								temp=temp->next;
						if( temp->info  == true )
								cout<<"\nThis seat is already booked";
						else
								temp->info = true;
				}
		}
		      
		void cancel()
		{
				int n;
				cout<<"\n Enter how many seats to cancel ?";
				cin>>n;
				int row[n],col[n];
				for(i=0; i<n; i++) 
				{
						cout<<"\n Enter the row among 10 :  ";
						cin>>row[i];
						--row[i];
						cout<<"\n Enter the columns among 7 :  ";
						cin>>col[i];
						--col[i];
				}
				for(i=0; i<n; i++) 
				{ 
						node * temp=start[row[i]];    
						for(j=0; j<col[i]; j++)
								temp = temp->next;
						if(temp->info == false)
								cout<<"This seat is not booked at all";
						else
								temp->info = false;
				}
		}
};


int main()
{
      int ch;
      linklist obj;
      obj.create();
      while(true)
      {
		      cout<<"\nCinemax Menu Driven Program";
			  cout<<"\n1. Display";
			  cout<<"\n2. Book";
			  cout<<"\n3. Cancel";
			  cout<<"\n4. Exit";
			  cout<<"\nEnter Your Choice :: ";
		      cin>>ch;
		     
		      switch(ch)
		      {
			        case 1: obj.display();
			                break;
			        case 2: obj.book();
			                break;
			        case 3: obj.cancel();
			                break;
           			case 4:
           					return 0;
			        default:
							cout<<"Wrong choice";
		      }  
      }
}
