#include <iostream>

using namespace std;

class LinkList;

class Node{

	bool a ;

	Node *prev;
	Node *next;

	public:
	Node(){
	
	prev = NULL;
	next = NULL;
	
	}
	
friend class LinkList;
	
};

class LinkList{

	Node *start;
	Node *last;
	
	public :
	LinkList(){
	
	start = NULL;
	last = NULL;
	
	}
	
	void insert(bool rem){
	
		Node *new1 ;
		new1 = new Node;
	
		new1->a = rem;
	
		if(start == NULL){
		
			start = new1;
			last = new1;	
		
		}
	
		else{
	
			new1->next = start;
			start->prev = new1;
			start = new1;
	
		}
	
	}
	
	void create(){
	
		int num;
		cout<<"Enter the Decimal Number : ";
		cin>>num;
		cout<<endl;
		
		bool r;
		
		while(num != 0){
		
			r = num % 2;
			num = num/2;
			
			insert(r);
		
		}		
	
	}
	
	void display(){
	
		Node *curr;
		
		curr = start;
		
		while(curr != NULL){
		
			cout<< curr->a;
			curr = curr->next;
		
		}
	
	}
	
	LinkList onescomp(){
		
		LinkList temp;
	
		Node *curr;
		
		curr = last;
		
		while(curr != NULL){
			if(curr->a == 0){
			
				temp.insert(1);	
			
			}
		
			else if(curr->a == 1){
			
				temp.insert(0);	
			
			}
			
			curr = curr -> prev;
		}
		
	return temp;	
	}
	
	
	LinkList addBin(LinkList A, LinkList B){
		
		LinkList C;
		
		Node *i; Node *j;
		
		i = A.last;
		j = B.last;
		
		bool carr = 0;
		
		while((i != NULL) && (j != NULL)){
		
			if(i->a + j->a + carr == 3){
		
				C.insert(1);
				carr = 1;
				i = i->prev;
				j = j->prev;
			
			}
		
			else if(i->a + j->a + carr == 2){
		
				C.insert(0);
				carr = 1;
				i = i->prev;
				j = j->prev;
			
			}
		
			else if(i->a + j->a + carr == 1){
		
				C.insert(1);
				carr = 0;
				i = i->prev;
				j = j->prev;
			
			}
		
			else if(i->a + j->a + carr == 0){
		
				C.insert(0);
				carr = 0;
				i = i->prev;
				j = j->prev;
			
			}
		}
		
		while(i != NULL){
		
			if(i->a + carr == 2){
		
				C.insert(0);
				carr = 1;
				i = i->prev;
			
			}
		
			else if(i->a + carr == 1){
		
				C.insert(1);
				carr = 0;
				i = i->prev;
			
			}
		
			else if(i->a + carr == 0){
		
				C.insert(0);
				carr = 0;
				i = i->prev;
			
			}
			
		}
		
		while(j != NULL){
		
			if(j->a + carr == 2){
		
				C.insert(0);
				carr = 1;
				j = j->prev;
			
			}
		
			else if(j->a + carr == 1){
		
				C.insert(1);
				carr = 0;
				j = j->prev;
			
			}
		
			else if(i->a + carr == 0){
		
				C.insert(0);
				carr = 0;
				j = j->prev;
			
			}
			
		}
		
		if(carr == 1){
		C.insert(1);
		}
				
	return C;	
	}
		
	LinkList twoscomp(LinkList OC){
	
		LinkList TC;
		LinkList One;
		
		One.insert(1);
		
		TC = TC.addBin(OC, One);
		
		return TC;
		
	}


};

int main(){

	LinkList A;
	LinkList B;
	LinkList O;
	LinkList T;
	
	A.create();
	cout<<"Binary Number is : ";
	A.display();
	cout<<endl;
	
	O = A.onescomp();
	cout<<"1's Complement of given number is : ";
	O.display();
	cout<<endl;
	
	T = A.twoscomp(O);
	cout<<"2's Complement of given number is : ";
	T.display();
	cout<<"\n"<<endl;
	
	B.create();
	cout<<"Binary Number is : ";
	B.display();
	cout<<"\n"<<endl;
	
	LinkList Sum;
	Sum = Sum.addBin(A,B);
	cout<<"Sum of Binary Numbers is : ";
	Sum.display();
	cout<<"\n"<<endl;

return (0);
}