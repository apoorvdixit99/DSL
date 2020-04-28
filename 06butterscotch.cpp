#include <iostream>
using namespace std;

class Node{
	public:
	Node *next;
	int roll;
	Node(){
		next = NULL;
		roll = 0;
	}
	void createNode(){
		cout<<"\nEnter roll number :: ";
		cin>>roll;
	}
};

class LL{
	public:
	Node *start, *last;
	LL(){
		start = NULL;
	}
	
	void displayList(){
		Node *current;// = new Node;
		current = start;
		while(current != NULL)
		{
			cout<<current->roll;
			current = current->next;
		}
	}
	void insertElement(int rollno){
		Node *new1 = new Node;
		new1 -> roll = rollno;
		if(start == NULL){
			start = new1;
			last = new1;
		}
		else{
			last -> next = new1;
			last = new1;
		}
	}
	void AUB(LL *list1, LL *list2)
	{
		Node *current1;
		Node *current2;
		current1 = list1 -> start;
		current2 = list2 -> start;
		while(current1 != NULL)
		{
			current2 = list2 -> start;
			while(current2 != NULL)
			{
				if(current1->roll == current2->roll)
					cout<<current1->roll;
				current2 = current2 -> next;
			}
			current1 = current1 -> next;
		}
	}
	void AMB(LL *list1, LL *list2)
	{
		Node *current1;
		Node *current2;
		current1 = list1 -> start;
		current2 = list2 -> start;
		while(current1 != NULL)
		{
			bool unique = true;
			current2 = list2 -> start;
			while(current2 != NULL)
			{
				if(current1->roll == current2->roll)
				{
					unique = false;
					break;
				}	
				current2 = current2 -> next;
			}
			if(unique == true)
				cout<<current1->roll;
			current1 = current1 -> next;
		}
	}
};

int main()
{
	LL *listB = new LL;
	LL *listV = new LL;
	LL *listN = new LL;
	int ch;
	cout<<"\nButter Scotch Vanilla Menu Driven Program :-\n";
	cout<<"\n\t1. Add Student Preference";
	cout<<"\n\t2. Display Butterscotch Gang";
	cout<<"\n\t3. Display Vanilla Gang";
	cout<<"\n\t4. Display Double Agents";
	cout<<"\n\t5. Display Free Agents";
	cout<<"\n\t6. Display Butterscotch Loyalist";
	cout<<"\n\t7. Display Vanilla Loyalist";
	cout<<"\n\t8. Display Butterscotch Vanilla Merger";
	cout<<"\n\t9. Exit";
	while(true)
	{
		cout<<"\n\nEnter your choice :: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				char ch1, ch2;
				int i;
	
				cout<<"\nEnter Roll No :: ";
				cin>>i;
	
				cout<<"\nButterscotch [Y/N]? :: ";
				cin>>ch1;
				if(ch1 == 'Y' || ch1 == 'y')
					listB -> insertElement(i);
		
				cout<<"Vanilla [Y/N]? :: ";
				cin>>ch2;
				if(ch2 == 'Y' || ch2 == 'y')
					listV -> insertElement(i);
								
				if( (ch1 == 'n' || ch1 == 'N') && (ch2 == 'n' || ch2 == 'N') ) //EXTRA
					listN -> insertElement(i); //EXTRA
				break;
			}
			case 2:
				listB->displayList();
				break;
			case 3:
				listV->displayList();
				break;
			case 4:
				listB->AUB(listB, listV);
				break;				
			case 5:
				listN->displayList(); //EXTRA
				break;
			case 6:
				listB->AMB(listB, listV);
				break;
			case 7:
				listV->AMB(listV, listB);
				break;
			case 8:
				listV->AMB(listV, listB);
				listB->AMB(listB, listV);
				listB->AUB(listB, listV);
				break;
			case 9:
				return 0;
				break;
		}
	cout<<"\n\n";
	}
}
