#include<iostream>
using namespace std;

class Deque
{
 	  int *arr, front, back, max, count;;
 	  public:
	  		 void declare()
	  		 {
			  	  cout<<"\nEnter the maximum number of elements :: ";
			  	  cin>>max;
			  	  arr = new int[max];
			  	  count = 0;
			  	  front = -1;
			  	  back = -1;
			  	  for(int i=0;i<max;i++)
			  	  		  arr[i] = 0;
			 }
			 void display()
			 {
			  	  cout<<endl;
			  	  for(int i=0;i<max;i++)
			  	  {
				   		  if(i==front)
				   		  		cout<<"[";
			  	  		  cout<<"  "<<arr[i];
				   		  if(i==back)
				   		  		cout<<"]";
				  }
			  	  cout<<endl;
			 }
			 bool isEmpty()
			 {
			  	  return count==0?true:false;
			 }
			 bool isFull()
			 {
			  	  return count>=max?true:false;
			 }
			 void insertFront(int x)
			 {
			  	  if(isEmpty())
	  	  		  {
				   		front = 0;
				   		back = 0;
				   		arr[front] = x;
				   		count++;
				  }
				  else
				  {
				   	    if(!isFull())
							 	if(front==0)
							 	{
								 		for(int i=back; i>=0;i++)
								 				arr[i+1] = arr[i];
						 				back++;
						 				arr[front] = x;
								}
								else
								 		arr[--front] = x;
					 		    count++;
	 			 		else
	 			 		{
						 	cout<<"\nDeque Full.\n";
						}
				  }
			 }
			 void insertBack(int x)
			 {
			  	  if(isEmpty())
	  	  		  {
				   		front = 0;
				   		back = 0;
				   		arr[back] = x;
				   		count++;
				  }
				  else
				  {
				   	    if(!isFull())
							 	if(back<max-1)
							 	{
								 		arr[++back] = x;
								 		count++;
								}
								else
								{
								 		for(int i=front; i<max; i++)
										 		arr[i-1] = arr[i];
										arr[back] = x;
										count++;
								}
	 			 		else
						 	cout<<"\nDeque Full.\n";
				  }
		  	 }
			 void deleteFront()
			 {
			  	  arr[front++] = 0;
			  	  count--;
			  	  if(front>back)
	  	  		  {
				   		front = -1;
				   		back = -1;
				   		count = 0;
				  }
		  	 }
			 void deleteBack()
			 {
			  	  arr[back--] = 0;
			  	  count--;
			  	  if(front>back)
	  	  		  {
				   		front = -1;
				   		back = -1;
				   		count = 0;
				  }
		  	 }
		  	 int menu()
		  	 {
				  	 cout<<"\nDEQUE MENU DRIVEN PROGRAM:-";
				  	 cout<<"\n1.Insert Front";
				  	 cout<<"\n2.Insert Back";
				  	 cout<<"\n3.Delete Front";
				  	 cout<<"\n4.Delete Back";
				  	 cout<<"\n5.Display";
				  	 cout<<"\n6.Exit";
				  	 int ch;
				  	 cout<<"\nEnter your choice :: ";
				  	 cin>>ch;
				  	 return ch;
			 }
			 int execute()
			 {
			  	 	 declare();
			  	 	 display();
				  	 while(true)
				  	 {
						  	 int ch = menu();
						  	 switch(ch)
						  	 {
							  		   case 1:
									   		cout<<"\nEnter a number :: ";
									   		cin>>ch;
									   		insertFront(ch);
									   		display();
									   		break;
							  		   case 2:
									   		cout<<"\nEnter a number :: ";
									   		cin>>ch;
									   		insertBack(ch);
									   		display();
									   		break;
							  		   case 3:
									   		deleteFront();
									   		display();
									   		break;
							  		   case 4:
									   		deleteBack();
									   		display();
									   		break;
							  		   case 5:
									   		display();
									   		break;
							  		   case 6:
									   		return 0;
									   		break;
							  		   default:
									   		cout<<"\nInvalid Input.\n";
									   		break;
			  		   		 }
					 }
			 }
};

int main()
{
 	Deque *obj = new Deque;
 	obj -> execute();
}
