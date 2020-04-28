#include<iostream>
using namespace std;

class Node
{
 	  char desg;
 	  char name[30];
 	  int roll;
 	  Node *next;
 	  public:
	  		 friend class Club;
	  		 Node()
	  		 {
			  	   roll=-1;
			  	   next = NULL;
			  	   desg = 'n';
			 }
			 void accept()
			 {
			  	  cout<<"\nEnter the roll number :: ";
			  	  cin>>roll;
			  	  cout<<"\nEnter the name :: ";
			  	  cin>>name;
			  	  cout<<"\nEnter the designation [p,s,m] :: ";
			  	  cin>>desg;
			 }
			 void display()
			 {
			  	  cout<<"\t"<<roll<<"\t"<<name<<"\t"<<desg;
			 }
};

class Club
{
 	  Node *first;
 	  Node *last;
 	  public:
	  		 Club()
	  		 {
			  	   first=NULL;
			  	   last=NULL;
			 }
			 bool empty()
			 {
			  	   if (first == NULL && last == NULL)
			  	  	     return true;
  	  	  		   return false;
			 }
			 bool one_node()
			 {
			  	   if ( first == last )
			  	   	  	 return true;
	   	  	 	   return false;
			 }
			 void accept(Node arg)
			 {

				   if(empty())
		  		   {
					     first = &arg;
					     last = &arg;
		   		   }
		   		   else
		   		   {
						  	 if( arg->desg == 'p' )
						  	 {
			
					   			   first -> desg = 'm';
		 						   arg -> next = first;
								   first = arg;
							 }
							 if( arg->desg == 's')
							 {
								   last -> desg = 'm';
					   		 	   last -> next = arg;
					   		 	   last = arg;
							 }
							 if( arg->desg == 'm')
							 {
					   			   if(one_node())
					   			   {
						   				 first -> next = arg;
						   				 last = arg;
					   			   }
					   			   else
					   			   {
								   	     arg -> next = first -> next;
								   	     first -> next = arg;
								   }
							 }
					}
					first -> desg = 'p';
					last -> desg = 's';
			 }
			 void display()
			 {
				  	cout<<"\n\tRoll No\tName\tDesignation";
				  	cout<<"\n\t=======\t====\t===========";
				  	Node *curr;
				  	curr = first;
				  	while(curr != last)
	 	  			{
					  	 curr -> display();
					   	 curr = curr -> next;
					}
					curr -> display();
			 }
			 
};

int main()
{
 	Club *obj;
 	for(int i=0;i<10;i++)
	{
		Node *arg = new Node;
		arg -> accept();	 
		obj -> accept(arg);
 		obj -> display();
 	}
 	return 0;
}
