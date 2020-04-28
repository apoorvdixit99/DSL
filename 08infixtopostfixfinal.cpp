#include <iostream>
#include <cstring>
using namespace std;

class Stack;
class Node
{
	char val;
	int num;
	Node *next;
	public:
		friend class Stack;
};

class Stack
{
	Node *start_ll;
	Node *last_ll;
	Node *start;
	Node *last;
	Node *top;
	string exp;
	public:
		Stack()
		{
			top=NULL;
			start_ll=NULL;
			start=NULL;
			last=NULL;
		}
		void push(char c);
		void push_int(int);
		void pop();
		char peek();
		int peek_int();
		string give_exp();
		bool isEmpty();
		void s_display();   
		void input();
		//void display();
		void inf_to_post(string);
		int give_priority(char);
		void input_postfix();
		void eval();
		void pop_int();
		bool isE();
		int pow(int,int);
};

void Stack::push_int(int a)
{
	if(isE())
	{
		Node *new1=new Node;
		new1->num=a;
		new1->next=NULL;
		start=new1;
		start->next=NULL;
		top=new1;
		top->next=NULL;
		cout<<"\nSuccessfully pushed";
	}
	else
	{
		Node *new1=new Node;
		new1->num=a;
		new1->next=NULL;
		top->next=new1;
		top=new1;
		cout<<"\nSuccessfully pushed";
	}
}

int Stack::peek_int()
{
	if(!isE())
		return top->num;
	else
		cout<<"\nStack Empty";
}

void Stack::input_postfix()
{
	cout<<"\nEnter the postfix expression:";
	getline(cin,exp);
	cout<<"\nExp:"<<exp;
	Node *t;
	for(int i=0;exp[i]!='\0';i++)
	{
		if(exp[i]!='^' && exp[i]!='%' && exp[i]!='/' && exp[i]!='*' && exp[i]!='+' && exp[i]!='-')
		{
			if(start_ll==NULL)
			{
				Node *new1=new Node;
				new1->val=exp[i];
				cout<<"\nValue of "<<new1->val;
				cin>>new1->num;
				start_ll=new1;
				t=start_ll;
			}
			else
			{
				Node *new1=new Node;
				new1->val=exp[i];
				cout<<"\nValue of "<<new1->val;
				cin>>new1->num;
				t->next=new1;
				new1->next=NULL;
				t=new1;
			}
		}
	}
}

int Stack::pow(int a,int b)
{
	int r=1;
	for(int i=0;i<b;i++)
	{
		r=r*a;
	}
	return r;
}

void Stack::eval()
{
	Node *t;
	Stack ans;
	for (int i = 0; exp[i]!='\0'; i++)
	{
		cout<<"\n Current:"<<exp[i];
		t=start_ll;
		if(exp[i]!='^' && exp[i]!='%' && exp[i]!='/' && exp[i]!='*' && exp[i]!='+' && exp[i]!='-')
		{
			cout<<"\nIn if";
			while(t)
			{
				if(t->val==exp[i])
				{
					cout<<"\nNum="<<t->num;
					ans.push_int(t->num);
					break;
				}
				t=t->next;
			}
		}
		else
		{
			int a,b,r;
			cout<<"\na="<<ans.peek_int();
			a=ans.peek_int();
			ans.pop_int();
			cout<<"\nb="<<ans.peek_int();
			b=ans.peek_int();
			ans.pop_int();
			switch(exp[i])
			{
				case '^': 
					r=pow(b,a);
					ans.push_int(r);
					break;
				case '%': 
					r=b%a;
					ans.push_int(r);
					break;
				case '/': 
					r=b/a;
					ans.push_int(r);
					break;
				case '*': 
					r=b*a;
					ans.push_int(r);
					break;
				case '+': 
					r=b+a;
					ans.push_int(r);
					break;
				case '-': 
					r=b-a;
					ans.push_int(r);
					break;
				default:
					cout<<"\nSorry";
					break;
			}
			cout<<"\nTemp Answer="<<ans.peek_int();
		}
	}
	cout<<"\nResult: "<<ans.peek_int();
}

int Stack::give_priority(char c)
{
	if(c=='^')
		return 3;
	else if(c=='%'||c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
		return 0;
}

bool Stack::isE()
{
	if(top==NULL)
		return true;
	else
		return false;
}

bool Stack::isEmpty()
{
	if(start==NULL)
		return true;
	else
		return false;
}

void Stack::push(char c)
{
	if(isEmpty())
	{
		Node *new1=new Node;
		new1->val=c;
		start=new1;
		last=new1;
		last->next=NULL;
	}
	else
	{
		Node *new1=new Node;
		new1->val=c;
		last->next=new1;
		new1->next=NULL;
		last=new1;
	}
}

void Stack::s_display()
{
	Node *t=start;
	cout<<"\nStack:";
	while(t)
	{
		cout<<"\n"<<t->num;
		t=t->next;
	}
}

void Stack::pop_int()
{
	if(!isE())
	{
		Node *t;
		t=start;
		if(t->next==NULL)
		{
			delete t;
			t=NULL;
		}
		else
		{
			while(t->next!=top)
			{
				t=t->next;
			}
			delete t->next;
			t->next=NULL;
			top=t;
		}
	}	
	else
	{
		cout<<"\nStack empty";
	}
}

void Stack::pop()
{
	if(!isEmpty())
	{
		Node *t;
		t=start;
		while(t->next!=last)
		{
			t=t->next;
		}
		delete t->next;
		t->next=NULL;
		last=t;
	}
	else
	{
		cout<<"\nStack empty";
	}
}

char Stack::peek()
{
	if(!isEmpty())
		return last->val;
	else
		cout<<"\nStack Empty";
}

void Stack::input()
{
	cout<<"\nEnter the expression";
	getline(cin,exp);
}

void Stack::inf_to_post(string s)
{
	push('N');
	int l = s.length();
	string ns;
	for(int i = 0; i < l; i++)
	{
		if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
			ns+=s[i];
		else if(s[i] == '(')
			push('(');
		else if(s[i] == ')')
		{
			while(peek() != 'N' && peek() != '(')
			{
				char c = peek();
				pop();
				ns += c;
			}
			if(peek() == '(')
			{
				char c = peek();
				pop();
			}
		}
		else
		{
			while(peek() != 'N' && give_priority(s[i]) <= give_priority(peek()))
			{
				char c = peek();
				pop();
				ns += c;
			}
			push(s[i]);
		}
	}
	while(peek() != 'N')	
	{	
		char c = peek();
		pop();
		ns += c;
	}
	cout << ns << endl;
}

string Stack::give_exp()
{
	return exp;
}

int main()
{
	Stack ob,ob1;
	string a;
	ob1.input();
	a=ob1.give_exp();
	ob.inf_to_post(a);
	ob.input_postfix();
	ob.eval();
	int b;
	cin>>b;
	
}
