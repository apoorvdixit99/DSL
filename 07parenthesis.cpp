#include<iostream>
using namespace std;

class Node
{
 	  public:
 	  		 char val;
 	 		 Node *next;
 	 		 Node(){val='\0';next=NULL;}
	  		 friend class Stack;
};

class Stack
{
 	  Node *top;
	  bool one(){ return (top -> next == NULL )?true:false;  }
 	  public:
	  bool empty(){ return (top==NULL)?true:false; }
	  		 Stack(){ top = NULL ;}
	  		 void push(int c)
	  		 {
			  	  Node *temp = new Node;
			  	  temp -> val = c;
			  	  if(empty())
			  	  			 top = temp;
			  	  else
 		  	  	  {
				   	  		 temp -> next = top;
				   	  		 top = temp;
				  }
			 }
			 void pop()
			 {
			  	  if(empty())
			  	  			 cout<<"\nStack Empty.";
			  	  else if(one())
			  	  {
				   	  		 Node *del;
				   	  		 del = top;
				   	  		 top = NULL;
				   	  		 del -> next = NULL;
				   	  		 delete del;
				  }
			  	  else
  	  		 	  {
				   	  		 Node *del;
				   	  		 del = top;
				   	  		 top = top -> next;
				   	  		 del -> next = NULL;
				   	  		 delete del;
			  	  }		 
			 }
			 char topval()
			 {
			  	  if(!empty())
			  	  			  return (top->val);
	  			  else
	  			  	  		  return '&';	  
			 }
			 void display()
			 {
			  	  cout<<"\n=====\nStack\n=====";
			  	  Node *curr;
			  	  curr = top;
			  	  while( curr != NULL )
			  	  {
				   		 cout<<endl<<curr->val;
				   		 curr = curr->next;
				  }
				  cout<<"\n=====\n";
			 }
};

class Parenthesis
{
 	  char exp[50];
 	  Stack *s;
 	  public:
	  		 Parenthesis()
	  		 {
			  	  s = new Stack;
 			 }
 			 void accept()
 			 {
			  	  cout<<"\nEnter the expression :: ";
			  	  cin>>exp;
			 }
			 void display()
			 {
			  	  cout<<exp;
			 }
			 bool evaluate()
			 {
			  	  int i=0;
			  	  while( exp[i] != '\0' )
			  	  {
				   		 if( exp[i]=='(' || exp[i]=='{' || exp[i]=='[' )
				   		 {
						  	 	s -> push( exp[i] );
						 }
						 else if( exp[i]==')' || exp[i]=='}' || exp[i]==']' )
						 {
						  	    if( exp[i]==')' && s->topval()!='(' )
						  	    	return false;
						  	    if( exp[i]=='}' && s->topval()!='{' )
						  	    	return false;
						  	    if( exp[i]==']' && s->topval()!='[' )
						  	    	return false;
						  	    s -> pop();
						 }
				   		 i++;
				  }
				  bool flag = s->empty();
  				  	   return flag;
			 }
			 void execute()
			 {
			  	  accept();
			  	  display();
					bool flag = evaluate();
				 	if(flag==true)
					 	cout<<"\nCorrect";
					else 
						cout<<"\nIncorrect";
			  	  
			 }
};

int main()
{
 	return 0;
}
