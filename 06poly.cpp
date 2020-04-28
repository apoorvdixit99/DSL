#include<iostream>

using namespace std;


class LinkList;

class Node{

	int exp;
	int coeff;

	Node *next;
	
	public:
	Node(){
		next = NULL;
	}

	friend class LinkList;
};

class LinkList{
	
	Node *last;
	Node *head;
	
	public:
	LinkList(){
		last = NULL;
		head = NULL;				
	}
	
	
	void insert(int exp1, int coeff1){
	
		Node *new1;
		new1 = new Node;
		
		new1->exp = exp1;
		new1->coeff = coeff1;	
		
		if(last == NULL){
			last = new1;
			last->next = new1;
		}
		
		else{
			new1->next = last->next;
			last->next = new1;
			last = new1;		
		}		
	}
	
	
	void create(){
		
		int n;
		cout<<"Enter the number of terms in Polynomial : ";
		cin>>n;
		
		int exp1;
		int coeff1;
		
		int i;
		
		for(i=0; i<n; i++){
		
			cout<<"Enter the "<<i<<" exponent : ";
			cin>>exp1;
			
			cout<<"Enter the "<<i<<" coefficient : ";
			cin>>coeff1;
			
			insert(exp1, coeff1);
			
		}
		
		Node *new1;
		new1 = new Node;
		
		new1->exp = -1;
		new1->coeff = 0;	
		
		new1->next = last->next;
		last->next = new1;
		head = new1;		
		
		
	}
	
	void display(){
	
		Node *curr;
		curr = head->next;
		
		while(curr->exp != -1){
		
			cout<<curr->coeff<<"x^"<<curr->exp<<" + ";
			curr = curr->next;
		
		}	
		
		cout<<"0\n";
	}
	
	void evaluate(){
	
		Node *curr;
		curr = head->next;
			
		int eval;
		int x,j,px;
		
		cout<<"Input the value of x : ";
		cin>>x;
		
		while(curr->exp != -1){

			px=1;
			for(j=0;j<curr->exp;j++){
			px=px*x;
			}
			eval = eval + curr->coeff * px;
			
			curr = curr->next;
			
		}	
			cout<<"Evaluation is : ";
			cout<<eval<<endl<<endl;
	}
	
	LinkList Addition(LinkList A, LinkList B){
	
		Node *ai;
		Node *bi;
	
		ai = A.head->next;
		bi = B.head->next;
	
		LinkList C;
	
		while(1){
			
			if(ai->exp == bi->exp){
				if(ai->exp == -1){
				
					Node *new1;
					new1 = new Node;
		
					new1->exp = -1;
					new1->coeff = 0;	
		
					new1->next = C.last->next;
					C.last->next = new1;
					C.head = new1;
					
					return C;
				}
				
				else{
					int sum;
					sum = ai->coeff + bi->coeff;
					
					C.insert(ai->exp, sum);
					ai = ai->next;
					bi = bi->next;
				}
			}
			
			else if(ai->exp > bi->exp){
			
				C.insert(ai->exp, ai->coeff);
				ai = ai->next;
			
			}
			
			else if(bi->exp > ai->exp){
			
				C.insert(bi->exp, bi->coeff);
				bi = bi->next;
			
			}			
			
		}
	
	
	}
	
};

int main(){

	LinkList A;
	LinkList B;
	LinkList Sum;
	
	cout<<"1st LinkList : \n";
	A.create();
	cout<<"LinkList A is : \n";
	A.display();
	A.evaluate();
	
	cout<<"2nd LinkList : \n";
	B.create();
	cout<<"LinkList B is : \n";
	B.display();
	cout<<endl;
	
	cout<<"Sum is : \n";
	Sum = Sum.Addition(A,B);
	Sum.display();
	
int a;
cin>>a;
	
return 0;	

}
