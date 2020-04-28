#include<iostream>
using namespace std;

class Array
{
 	  int *arr;
 	  int len;
 	  public:
	  		 void declare()
	  		 {
			  		 cout<<"\nEnter the number of elements :: ";
			  		 cin>>len;
			  		 arr = new int[len];
			 }
			 void accept()
			 {
			  	  	 cout<<"\nEnter "<<len<<" numbers :-\n";
			  	  	 for(int i=0;i<len;i++)
			  	  	 		 cin>>arr[i];
			 }
			 void display()
			 {
			  	  	 cout<<"\nDisplaying "<<len<<" numbers :-\n";
			  	  	 for(int i=0;i<len;i++)
			  	  	 		 cout<<arr[i]<<"\t";
			 }
			 bool linearSearch()
			 {
			  	  	 cout<<"\nEnter the number to be searched :: ";
			  	  	 int x;
			  	  	 cin>>x;
			  	  	 for(int i=0;i<len;i++)
			  	  	 		 if( arr[i] == x)
			  	  	 		 	      return true;
			  	  	 return false;
			 }
			 bool sentinelSearch()
			 {
			  	  	 cout<<"\nEnter the number to be searched :: ";
			  	  	 int x, last = arr[len-1], i=0;
			  	  	 cin>>x;
			  	  	 arr[len-1] = x;
			  	  	 while( arr[i] != x )
			  	  	 		i++;
	  	  	 		 arr[len-1] = last;
			  	  	 if( i<len-1 || arr[len-1] == x )		 
			  	  	 		 return true;
			  	  	 else		 
			  	  	 		 return false;
			 }
			 bool binarySearch()
			 {
			  	  	 int x, l=0,h=len-1,mid;
			  	  	 cout<<"\nEnter the number to be searched :: ";
			  	  	 cin>>x;
			  	  	 while(l<=h)
			  	  	 {
					  			mid = (l+h)/2;
					  			if( arr[mid] == x )
					  					return true;
					  			else if( x < arr[mid] )
					  				 	h = mid-1;
								else
										l = mid+1;
					 }
					 return false;
			 }
			 void selectionSort()
			 {
			  	  	 for(int i=0;i<len-1;i++)
			  	  	 {
					  		 int min = i;
					  		 for(int j=i+1;j<len;j++)
					  		 {
							  		 if(arr[j]<arr[min])
							  		 		min = j;
							 }
							 if(min!=i)
							 {
							  		   int temp = arr[min];
							  		   arr[min] = arr[i];
							  		   arr[i] = temp;
							 }
					 }
			 }
			 void bubbleSort()
			 {
			  	  	 for(int i=len-1;i>=0;i--)
			  	  	 {
					  		 for(int j=0;j<i;j++)
					  		 {
							  		 if(arr[j]>arr[j+1])
							  		 {
									  		int temp = arr[j];
									  		arr[j] = arr[j+1];
									  		arr[j+1] = temp;
									 }
							 }
					 }
			 }
			 int fibonacciSearch() 
				{
				 				   
				  	cout<<"\nEnter the number to be searched :: ";
			  	  	int x;
			  	  	cin>>x;
			  	  	
				    /* Initialize fibonacci numbers */
				    int fib2 = 0;   // (m-2)'th Fibonacci No. 
				    int fib1 = 1;   // (m-1)'th Fibonacci No. 
				    int fib = fib2 + fib1;  // m'th Fibonacci 
				  
				    /* fibM is going to store the smallest Fibonacci 
				       Number greater than or equal to n */
				    while (fib < len) 
				    { 
				        fib2 = fib1; 
				        fib1 = fib; 
				        fib  = fib2 + fib1; 
				    }
				    
				    // Marks the eliminated range from front 
				    int offset = -1; 
				  
				    /* while there are elements to be inspected. Note that 
				       we compare arr[fib2] with x. When fib becomes 1, 
				       fib2 becomes 0 */
				    while (fib > 1) 
				    { 
				        // Check if fib2 is a valid location 
				        int i = (offset+fib2 < len-1)?(offset+fib2):(len-1); 
				  
				        /* If x is greater than the value at index fibMm2, 
				           cut the subarray array from offset to i */
				        if (arr[i] < x) 
				        { 
				            fib  = fib1; 
				            fib1 = fib2; 
				            fib2 = fib - fib1; 
				            offset = i; 
				        }
				        /* If x is greater than the value at index fibMm2, 
				           cut the subarray after i+1  */
				        else if (arr[i] > x) 
				        { 
				            fib  = fib2; 
				            fib1 = fib1 - fib2; 
				            fib2 = fib - fib1; 
				        } 
				        
				        else return i;			//element found. return index
				    } 
				  
				    if(fib1 && arr[offset+1]==x)		//comparing the last element with x
							return offset+1; 
				  
				    return -1;		//element not found. return -1
				} 
			 void shellSort()
			 {
					for(int gap=gap/2;gap>0;gap=gap/2)
						for(int i=gap;i<len;i++)
							for(int j=i-gap;j>=0;j=j-gap)
								if(arr[j+gap]<arr[j])
								{
									int temp = arr[j+gap];
									arr[j+gap] = arr[j];
									arr[j] = temp;
								}
								else
									break;
			 }
			 void insertionSort()
			 {
			  	  	 int i=1,j,x;
			  	  	 while(i<len)
			  	  	 {
					  		x = arr[i];
					  		j=i-1;
					  		while( j>=0 && arr[j]>x )
					  		{
							 	   arr[j+1] = arr[j];
							 	   j--;
							}
							arr[j+1] = x;
							i++;
					 }
			 }
			 void TF(bool x)
			 {
			  	  if(x==true)
			  	  			 cout<<"\nTrue\n";
		  		  else
		  		  	  		 cout<<"\nFalse\n";
			 }
			 void execute()
			 {
			  	  	 declare();
			  	  	 accept();
			  	  	 display();
			  	  	 shellSort();
			  	  	 display();
			  	  	 cout<<"\n\n\nPosition -> "<<fibonacciSearch()<<endl;
			  	  	 int a;
			  	  	 cin>>a;
			 }
};

int main()
{
 		Array obj;
 		obj.execute();
 		return 0;
}
