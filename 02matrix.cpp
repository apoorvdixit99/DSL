#include<iostream>
using namespace std;
class Matrix
{
	int R;
	int C;
	int arr[5][5];
	public:
	void input();
	void display();
	void saddle();
	void up_tri();
	void diagonal();
	void transpose(Matrix);
	void add(Matrix, Matrix);
	void subtract(Matrix, Matrix);
	void multiply(Matrix, Matrix);
};
void Matrix :: input()
{
	int i,j;
	cout<<"\nEnter the Number of rows and columns Respectively:-\n";
	cin>>R>>C;
	cout<<"\nEnter a "<<R<<"x"<<C<<" matrix \n";
	cout<<"\nInput Matrix Row-wise\n\n";
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			cin>>arr[i][j];
		}
		cout<<endl;
	}
	display();
}
void Matrix :: display()
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void Matrix :: saddle()
{
	int i=0, j=0, r=0, c=0, minrow, maxcol;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			minrow=arr[0][j];
			for(r=1;r<R;r++)
			{
				if(minrow<arr[r][j])
				minrow = arr[r][j];
			}
			maxcol=arr[i][0];
			for(c=1;c<C;c++)
			{
				if(maxcol>arr[i][c])
				maxcol = arr[i][c];
			}
			if(minrow==maxcol)
			{
				cout<<endl<<arr[i][j]<<" is a saddle point\n";
				cout<<"Row "<<(i+1)<<" and Col "<<(j+1)<<endl; 
			}
		}
	}
}
void Matrix :: up_tri()
{
	int flag=0, i=0, j=0;
	if(R!=C)
		cout<<"\nMatrix is not a Square Matrix.\n";
	else
	{
		for(i=0;i<R;i++)
		{
			for(j=0;j<i;j++)
				if(arr[i][j]!=0)
				{
					flag=1;
					break;
				}
			for(j=i;j<C;j++)
				if(arr[i][j]==0)
				{
					flag=1;
					break;
				}
		}
		if(flag==0)
			cout<<"\nMatrix is an Upper Triangular Matrix\n";
		else
			cout<<"\nMatrix is not an Upper Triangular Matrix\n";
	}
}
void Matrix :: diagonal()
{
	int i=0, j=0, diag=0;
	if(R!=C)
		cout<<"\nMatrix is not a Square Matrix.\n";
	else
	{
		for(i=0;i<R;i++)
			diag+=arr[i][i];
		cout<<"\nSum of Diagonals is "<<diag<<endl;
	}
}
void Matrix :: transpose(Matrix temp)
{
	int i=0, j=0;
	R = temp.C;
	C = temp.R;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			arr[j][i] = temp.arr[i][j];
		}
	}
	cout<<"\n\nDisplaying Transpose of Matrix :-\n\n";
	display();
}
void Matrix :: add(Matrix temp1, Matrix temp2)
{
	if((temp1.R!=temp2.R)||(temp1.C!=temp2.C))
		cout<<"Addition not Possible";
	else
	{
		R=temp1.R;
		C=temp1.C;
		int i=0, j=0;
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				arr[i][j] = temp1.arr[i][j] + temp2.arr[i][j];
			}
		}
		cout<<"\n\nDisplaying Sum of the 2 Matrices :-\n\n";
		display();
	}
}
void Matrix :: subtract(Matrix temp1, Matrix temp2)
{
	if((temp1.R!=temp2.R)||(temp1.C!=temp2.C))
		cout<<"Subtraction not Possible";
	else
	{
		R=temp1.R;
		C=temp1.C;
		int i=0, j=0;
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				arr[i][j] = temp1.arr[i][j] - temp2.arr[i][j];
			}
		}
		cout<<"\n\nDisplaying Difference between the 2 Matrices :-\n\n";
		display();
	}
}
void Matrix :: multiply(Matrix temp1, Matrix temp2)
{
	if(temp1.C!=temp2.R)
		cout<<"Multiplication not Possible";
	else
	{
		int i=0, j=0, k=0;
		R=temp1.R;
		C=temp2.C;
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				arr[i][j]=0;
				for(k=0;k<temp1.C;k++)
					arr[i][j] += (temp1.arr[i][k]*temp2.arr[k][j]);
			}
		}
		cout<<"\n\nDisplaying Product of the 2 Matrices :-\n\n";
		display();
	}
}
int main()
{
	char pgm='N';
	do
	{
		cout<<"\nMenu-Driven Matrix Program : ";
		int ch=0;
		cout<<endl<<++ch<<". Upper Triangular Matrix";
		cout<<endl<<++ch<<". Sum of Diagonal of Matrix";
		cout<<endl<<++ch<<". Transpose Matrix";
		cout<<endl<<++ch<<". Add Two Matrices";
		cout<<endl<<++ch<<". Subtraction of Two Matrices";
		cout<<endl<<++ch<<". Product of Two Matrices";
		cout<<endl<<++ch<<". Saddle Point";
		cout<<endl<<++ch<<". Exit";
		ch=0;
		cout<<endl<<"Enter your choice :: ";
		cin>>ch;
		if(ch==8)
			return 0;
		Matrix obj1, obj2, obj3;
		obj1.input();
		switch(ch)
		{
			case 1:	
				obj1.up_tri();
			break;
			case 2:	
				obj1.diagonal();
			break;
			case 3:	
				obj2.transpose(obj1);
			break;
			case 4:
				obj2.input();
				obj3.add(obj1,obj2);
			break;
			case 5:
				obj2.input();
				obj3.subtract(obj1,obj2);
			break;
			case 6:
				obj2.input();
				obj3.multiply(obj1,obj2);
			break;
			case 7:
				obj1.saddle();
			break;
			default:
				cout<<"\nInvalid Choice\n";
		}
		cout<<"\nDo you wish to rerun the program [Y/N]? - ";
		cin>>pgm;

	}while((pgm=='Y')||(pgm=='y'));
	return 0;
}
