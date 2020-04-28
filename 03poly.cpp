#include<iostream>
using namespace std;

int power(int x, int n)
{
	int pro = 1;
	while(n>0)
	{
		pro = pro * x;
		--n;
	}
	return pro;	
}

class Term
{
	public:
	int coeff;
	int expo;
	Term(){coeff=0;expo=0;}
	Term(int c, int e){coeff=c;expo=e;}
	friend class Polynomial;
	void operator = (Term arg)
	{
		coeff = arg.coeff;
		expo = arg.expo;
	}
};

class Polynomial
{
	public:
	int num;
	Term *t;
	friend istream &operator >> (istream &input, Polynomial &arg)
	{
		cout<<"\nEnter number of terms (Highest Power to Lowest Power) :: ";
		input>>arg.num;
		arg.t = new Term[arg.num];
		cout<<"\nEnter the coefficient and degree respectively of "<<arg.num<<" terms ("<<(arg.num*2)<<" inputs) :-\n";
		for(int i=0; i<arg.num; i++)
		{
			input>>arg.t[i].coeff>>arg.t[i].expo;
		}
		arg.SortAndShift();
		return input;
	}
	friend ostream &operator << (ostream &output, Polynomial &arg)
	{
		output<<"("<<arg.t[0].coeff<<"x^"<<arg.t[0].expo<<")";
		for(int i=1; i<arg.num; i++)
		{
			output<<" + ("<<arg.t[i].coeff<<"x^"<<arg.t[i].expo<<")";
		}
		return output;
	}
	void Evaluate()
	{
		int x;
		cout<<"\nEnter the value of x :: ";
		cin>>x;
		int result = 0;
		for(int i=0;i<num;i++)
		{
			result = result + (t[i].coeff*power(x,t[i].expo));
		}
		cout<<"\nThe Value of Polynomial at x="<<x<<" is :: "<<result<<endl;
	}
	void SortAndShift()
	{
		int i,j;
		for(i=num-1;i>0;i--) //Sorting
			for(j=0;j<i;j++)
				if(t[j].expo<t[j+1].expo)
				{
					Term temp(t[j].coeff, t[j].expo);
					t[j] = t[j+1];
					t[j+1] = temp;
				}
		for(i=0;i<(num-1);i++) //If consecutive terms have same exponent
			if(t[i].expo==t[i+1].expo)
			{
				t[i].coeff = t[i].coeff + t[i+1].coeff;
				for(j=i+2;j<num;j++)
					t[j-1]= t[j];
				--num;
				--i;
			}
		for(i=0;i<num;i++) //if coeff is zero
			if(t[i].coeff==0)
			{
				for(j=i+1;j<num;j++)
					t[j-1]= t[j];
				--num;
				--i;
			}
	}
	Polynomial operator +(Polynomial arg)
	{
		Polynomial temp;
		int i=0,j=0,k=0,doub=0;
		temp.num = num + arg.num;
		temp.t = new Term[temp.num];
		do
		{
			if(t[i].expo>arg.t[j].expo)
				temp.t[k++] = t[i++];
			else if(t[i].expo<arg.t[j].expo)
				temp.t[k++] = arg.t[j++];
			else
			{
				temp.t[k].expo = t[i].expo;
				temp.t[k++].coeff = t[i++].coeff + arg.t[j++].coeff;
				++doub;
			}
		}while(i<num && j<arg.num);
		while(i<num)
			temp.t[k++] = t[i++];
		while(j<arg.num)
			temp.t[k++] = arg.t[j++];
		temp.num = temp.num - doub;
		temp.SortAndShift();
		return temp;
	}
	Polynomial operator *(Polynomial arg)
	{
		Polynomial temp;
		int i=0,j=0,k=0;
		temp.num = num * arg.num;
		temp.t = new Term[temp.num];
		for(i=0;i<num;i++)
			for(j=0;j<arg.num;j++)
			{
				temp.t[k].coeff = t[i].coeff * arg.t[j].coeff;
				temp.t[k++].expo = t[i].expo + arg.t[j].expo;
			}
		temp.SortAndShift();
		return temp;
	}
};

int main()
{
		while(true)
		{
				int ch;
				cout<<"\n\nMenu Driven Polynomial Program";
				cout<<"\n1.Addition";
				cout<<"\n2.Multiplication";
				cout<<"\n3.Evaluate";
				cout<<"\n4.Exit";
				cout<<"\nEnter your choice :: ";
				cin>>ch;
				Polynomial obj1, obj2, obj3;
				switch(ch)
				{
						case 1:
							cin>>obj1>>obj2;
							cout<<endl<<obj1<<endl<<obj2;
							obj3 = obj1 + obj2;
							cout<<"\nThe Sum is "<<obj3;
							break;
						case 2:
							cin>>obj1>>obj2;
							cout<<endl<<obj1<<endl<<obj2;
							obj3 = obj1 * obj2;
							cout<<"\nThe Product is "<<obj3;
							break;
						case 3:
							cin>>obj1;
							cout<<endl<<obj1<<endl;
							obj1.Evaluate();
							break;
						case 4:
							return 0;
							break;
						default:
							cout<<"\nInvalid Choice.\n";
				}
		}
}
