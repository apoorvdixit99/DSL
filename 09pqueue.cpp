#include<iostream>
using namespace std;

class Node
{
 	  int pri;
 	  Node *next;
 	  public:
	  		 friend class Pqueue;
	  		 Node()
	  		 {
			  	   pri=-1;
			 }
};

class Pqueue
{
 	  Node *front;
 	  Node *rear;
 	  public:
	  		 friend class Node;
	  		 Pqueue()
	  		 {
			  		 front=NULL;
			  		 rear=NULL;
			 }
			 bool Empty()
			 {
			  	  	 return (front==NULL && rear==NULL )?true:false;
			 }
			 bool One()
			 {
			  	  	 return (front==rear)?true:false;
			 }
			 void add(int p)
			 {
			  	     Node *curr = new Node;
			  	     curr -> pri = p;
			  	     if(Empty())
			  	     {
					  		front = curr;
					  		rear = curr;
					 }
			  	     else
			  	     {
					  		if( curr->pri <= front->pri )
					  		{
							 		curr->next = front;
							 		front = curr;
							}
							else if( curr->pri >= rear->pri )
							{
							 		rear->next = curr;
							 		rear = curr;
							}
							else
							{
							 		Node *trav;
							 		trav = front;
							 		while(trav->next != rear)
							 		{
									 		if( ( trav->pri <= curr->pri ) && ( curr->pri <= (trav->next)->pri ) )
						 			  		{
											 	  	curr->next = trav->next;
											 	  	trav->next = curr;
											 	  	break;
									   		}
									   		trav = trav->next;
				 				 	}
							}
					 }    
			 }
			 void remove()
			 {
			  	  	if(Empty())
			  	  			   cout<<"\nPriority Queue Empty.";
	  			    else if(One())
	  			    {
					 		   Node *temp;
					 		   temp = front;
					 		   front = NULL;
					 		   rear = NULL;
					 		   delete temp;
					}
	  			    else
	  			    {
	 				 		   Node *trav, *temp;
							   trav = front;
							   temp = rear;
		 					   while(trav->next != rear)
		   					   {
							   			trav = trav -> next;
							   }
							   trav -> next = NULL;
							   delete temp;
							   rear = trav;
					}
			 }
			 void display()
			 {
			  	  	if(Empty())
			  	  			   cout<<"\nPriority Queue Empty.";
	  			    else
	  			    {
	 				 		   Node *trav;
							   trav = front;
		 					   while(trav != rear)
		   					   {
							   			cout<<endl<<trav->pri;
							   			trav = trav -> next;
							   }
							   cout<<endl<<trav->pri;
					}
			 }
			 int menu()
			 {
				  	 cout<<"\nPriority Queue Menu Program:-";
				  	 cout<<"\n1.Add Priority";
				  	 cout<<"\n2.Delete Priority";
				  	 cout<<"\n3.Display Priority Queue";
				  	 cout<<"\n4.Exit";
					 cout<<"\nEnter Your Choice :: ";
					 int ch;
					 cin>>ch;
					 return ch;
			 }
			 int execute()
			 {
			  	     while(true)
  	     			 {
					  		int ch = menu(), x;
					  		switch(ch)
					  		{
							 	   case 1:
								   		cout<<"\nEnter Priority :: ";
								   		cin>>x;
								   		add(x);
								   		break;
								   case 2:
								   		remove();
								   		break;
								   case 3:
								   		display();
								   		break;
								   case 4:
								   		return 0;
								   		break;
								   default:
								   		cout<<"\nInvalid Choice";
			 				}
					 }
			 }
			 
};

int main()
{
 	Pqueue obj;
 	obj.execute();
 	
 	return 0;
}
