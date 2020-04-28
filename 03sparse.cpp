#include<iostream>
using namespace std;

class Term{
	public:
	int row, col, value;
	Term(){row=0;col=0;value=0;}
	friend class SparseMatrix;
	void operator = (Term arg){
		row = arg.row;
		col = arg.col;
		value = arg.value;
	}
	void crossValue(Term arg){
		row = arg.col;
		col = arg.row;
		value = arg.value;
	}
};

class SparseMatrix
{
	public:
	bool flag;
	Term *t;
 	SparseMatrix(){flag = false;}
	friend istream &operator >> (istream &input, SparseMatrix &arg){
        int nrow, ncol, nvalue;
		cout<<"\nEnter Number of Rows, Columns & Non-Zero Elements Respectively :-\n";
		input>>nrow>>ncol>>nvalue;
		while(nvalue > (nrow * ncol)){
		  	cout<<"Enter Number of Non-Zero Elements Again!\n(Should be less than or equal to "<<(nrow * ncol)<<") :: ";
			input>>nvalue;
		}
		arg.t = new Term[nvalue+1];
		arg.t[0].row = nrow;
		arg.t[0].col = ncol;
		arg.t[0].value = nvalue;
		arg.flag = true;
		cout<<"\nEnter the row, column and value respectively  of "<<nvalue<<" Non-Zero Entries :-\n\n";
		for(int i=1; i<=nvalue; i++){
			input>>arg.t[i].row>>arg.t[i].col>>arg.t[i].value;	
			while( (arg.t[i].row>=arg.t[0].row) || (arg.t[i].col>=arg.t[0].col) || (arg.t[i].value==0) ){
			    cout<<"\nRow Should be less than "<<arg.t[0].row;
			    cout<<".\nColumn Should be less than "<<arg.t[0].col;
			    cout<<".\nValue Should not be zero.\nEnter the three inputs again:-\n";
				input>>arg.t[i].row>>arg.t[i].col>>arg.t[i].value;
			}
			cout<<endl;
		}
		arg.SortAndShift();
		return input;
	}
	friend ostream &operator << (ostream &output, SparseMatrix &arg){
	 	if(arg.flag == false)
		 		   output<<"\nThe Matrix is not defined.\n";
        else if(arg.t[0].value==0)
 				   cout<<"\nThe Matrix is a Zero-Matrix.\n";	  				  
		else{
			output<<endl;
			output<<arg.t[0].row<<"\t|"<<arg.t[0].col<<"\t|"<<arg.t[0].value<<endl;
			output<<"========|=======|========\n";
			for(int i=1,nvalue=arg.t[0].value; i<=nvalue; i++)
				output<<arg.t[i].row<<"\t|"<<arg.t[i].col<<"\t|"<<arg.t[i].value<<endl;
		}
		return output;
	}
	void fastTranspose(SparseMatrix arg){
 	 	flag = true;
 	 	t = new Term[arg.t[0].value+1];
 	 	t[0].crossValue(arg.t[0]);
 	 	int i, num_cols = arg.t[0].col, num_values = arg.t[0].value, frequency[num_cols], position[num_cols];
		for(i=0;i<num_cols;i++) //initialising frequency of each term to zero
		    frequency[i]=0;
		for(i=1;i<=num_values;i++) //finding out frequency of each term
		    ++frequency[arg.t[i].col];
		for(i=1, position[0] = 1;i<num_cols;i++) //initialising position of each column in the array
 		    position[i] = frequency[i-1] + position[i-1];
		for(i=1;i<=num_values;i++)
		 	t[position[arg.t[i].col]++].crossValue(arg.t[i]);
	}
	
	SparseMatrix operator + (SparseMatrix arg)
	{
		int i=1,j=1,k=1,doub=0;
		SparseMatrix temp;
		if(t[0].row!=arg.t[0].row || t[0].col!=arg.t[0].col)
			cout<<"\nMatrix Addition Not Possible.\n";
		else{
		 	temp.flag = true;
		 	temp.t = new Term[t[0].value + arg.t[0].value+1]; //IMPORTANT!! Why does it work when we cin twice?
		 	temp.t[0].row = t[0].row;
		  	temp.t[0].col = t[0].col;
			temp.t[0].value = t[0].value + arg.t[0].value;
			do{
				if(t[i].row==arg.t[j].row && t[i].col==arg.t[i].col){ //if rows and column are equal, add them
					temp.t[k].row = t[i].row;
		   			temp.t[k].col = t[i].col;
					temp.t[k++].value = t[i++].value + arg.t[j++].value;
					doub++;
				}
				//IMPORTANT!!! somehow if i use separate if conditions instead of if else, program works!?!?!
				if(t[i].row<arg.t[j].row) //if row of 1st element is less, copy it's entry
					temp.t[k++] = t[i++];
				if(t[i].row>arg.t[j].row)	//if row of 2nd element is less, copy it's entry
					temp.t[k++] = arg.t[j++];
				if(t[i].row==arg.t[j].row && t[i].col<arg.t[j].col) //if col of 1st element is less, copy it's entry
					temp.t[k++] = t[i++];
				if(t[i].row==arg.t[j].row && t[i].col>arg.t[j].col)//if row of 2nd element is less, copy it's entry
					temp.t[k++] = arg.t[j++];
			}while((i<=t[0].value) && (j<=arg.t[0].value));
			while(i<=t[0].value)
				temp.t[k++] = t[i++];
			while(j<=arg.t[0].value)
				temp.t[k++] = arg.t[j++];
			temp.t[0].value = temp.t[0].value - doub;
		}
		temp.CheckForZero();
		return temp;
	}
	void SortAndShift()
	{
	 	 int i,j;
	 	 for(i=t[0].value-1;i>=1;i--)	//Sorting
		     for(j=1;j<=i;j++)
 				  if( (t[j].row>t[j+1].row) || ( (t[j].row==t[j+1].row) && (t[j].col>t[j+1].col) ) ){
	   			      Term temp = t[j];
					  t[j] = t[j+1];
					  t[j+1] = temp; 	  
				  }
		 for(i=1;i<=t[0].value-1;i++)	//Shifting in case of multiple entries for same row and column
	 		 if( (t[i].row==t[i+1].row) && (t[i].col==t[i+1].col) ){
				 cout<<"\nMultiple non-zero entries for row="<<t[i].row<<" and column="<<t[i].col;
				 cout<<"\nSelecting the non-zero value of the latest entry\n";
 				 for(j=i+1;j<=t[0].value;j++)
					 t[j-1] = t[j];
				 --t[0].value;
				 --i;
			 }
	}
	void CheckForZero()
	{
         int i, j;
         for(i=1;i<=t[0].value;i++)
   		     if(t[i].value==0){
                 for(j=i+1;j<=t[0].value;j++)
                     t[j-1] = t[j];
       	  		 --t[0].value;
      		  	 --i;
             }
    }
};
int main(){
	char pgm = 'N';
	do{
		int ch;
		SparseMatrix obj1, obj2, obj3;
		cout<<"\nMenu-Driven Sparse-Matrix Program :-\n1.Addition\n2.Fast Transpose\n3.Exit\nEnter your choice :: ";
		cin>>ch;
		switch(ch){
			case 1:
				cin>>obj1>>obj2;
				obj3 = obj1 + obj2;
				cout<<"\nFirst Matrix :-"<<obj1<<"\nSecond Matrix :-"<<obj2<<"\nResultant Matrix :-"<<obj3<<endl;
			break;
			case 2:
				cin>>obj1;
				obj2.fastTranspose(obj1);
				cout<<"\nFirst Matrix :-"<<obj1<<"\nTranspose Matrix :-"<<obj2<<endl;
			break;
			case 3:
				return 0;
			break;
			default:
				cout<<"\nInvalid Choice.\n";
		}
		cout<<"\nDo you want to Re-Run the Program[Y/N] :: ";
		cin>>pgm;
	}while((pgm=='Y')||(pgm=='y'));
	return 0;
}
