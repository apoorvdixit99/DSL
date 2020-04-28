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

class Infix2Postfix
{
 	  char infix[50];
 	  char postfix[50];
 	  Stack *s;
 	  public:
	  		 Infix2Postfix()
	  		 {
			  	  s = new Stack;
 			 }
 			 void accept()
 			 {
			  	  cout<<"\nEnter the infix expression :: ";
			  	  cin>>infix;
			 }
			 void displayinfix()
			 {
			  	  cout<<infix;
			 }
			 void displaypostfix()
			 {
			  	  cout<<postfix;
			 }
			 bool parenthesis()
			 {
			  	  int i=0;
			  	  while( infix[i] != '\0' )
			  	  {
				   		 if( infix[i]=='(' || infix[i]=='{' || infix[i]=='[' ) 		
				   		 {
						  	 	s -> push( infix[i] );
						 }
						 else if( infix[i]==')' || infix[i]=='}' || infix[i]==']' )
						 {
						  	    if( infix[i]==')' && s->topval()!='(' )
						  	    	return false;
						  	    if( infix[i]=='}' && s->topval()!='{' )
						  	    	return false;
						  	    if( infix[i]==']' && s->topval()!='[' )
						  	    	return false;
						  	    s -> pop();
						 }
				   		 i++;
				  }
				  bool flag = s->empty();
  				  return flag;
			 }
			 int priority(char ch)
			 {
			  	 if(ch=='+' || ch=='-')
			  	 			return 1;
			  	 else if(ch=='*' || ch=='-')
			  	 			return 2;
			  	 else if(ch=='^')
			  	 			return 3;
			  	 else
			  	 	 		return 0;
			 }
			 void conversion()
			 {
			  	  if(!parenthesis())
			  	  		cout<<"\nIncorrectly Parenthesized.\n";
				  else
				  {
				   	    int i=0, p=0;
				   	    while(infix[i]!='\0')		//Traversing through characters of infix
				   	    {
						 		if( infix[i]>='a' && infix[i]<='z' )			//lowercase alphabets
						 				postfix[p++] = infix[i];
				 				else if( infix[i]>='A' && infix[i]<='Z' )		//uppercase alphabets
						 				postfix[p++] = infix[i];
						 		else if( infix[i]=='(' || infix[i]=='{' || infix[i]=='[' )		//left parenthesis
						 				s -> push( infix[i] );
						 		else if( infix[i]==')' || infix[i]=='}' || infix[i]==']' )		//right parenthesis
						 		{
								 		while( s->topval()!='(' || s->topval()!='{' || s->topval()!='[' )
								 		{
										 	   postfix[p++] = s->topval() ;
									 	   s->pop();
										}
								}
								else		//operators
								{
										int pi = priority(infix[i]), ps = priority(s->topval());
										while( pi <= ps )
										{
												postfix[p++] = s->topval();
												s->pop();
												ps = priority (s->topval());
										}
										s->push(infix[i]);
								}
								i++;
						}
						cout<<endl;
						for(i=0;i<p;i++)
								cout<<postfix[i];
				  }
			 }
			 void execute()
			 {
			  	  accept();
			  	  displayinfix();
			  	  conversion();
			 }
};

int main()
{
 	Infix2Postfix obj;
 	obj.execute();
 	int a;
 	cin>>a;
 	
 	return 0;
}
