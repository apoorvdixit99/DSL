#include<iostream>
using namespace std;
# define max 10

class Marks
{
 	  int roll[max];
 	  int arr[max];
 	  int highest,lowest;
 	  float avg;
 	  public:
	  		 void accept()
	  		 {
			  	     avg = 0.0;
			  	     int abs=0;
			  		 cout<<"\nEnter 5 students' marks\n";
			  		 for(int i=0;i<max;i++)
			  		 {
					  		 roll[i] = i+1;
			  		 		 cin>>arr[i];
			  		 		 if(arr[i]==0)
			  		 		 		abs++;
			  		 		 avg+=arr[i];
					 }
					 avg = (float) avg / (5.0 - abs); 
					 //cout<<"\nAverage = "<<avg;
			 }
	  		 void display()
	  		 {
			  		 cout<<"\nDisplaying 5 students' marks\n";
			  		 for(int i=0;i<max;i++)
			  		 		 cout<<roll[i]<<"\t"<<arr[i]<<endl;
			 }
			 void sort()
			 {
			  	  	 for(int i=max-1;i>=0;i--)
			  	  	 {
					  		 for(int j=0;j<i;j++)
					  		 {
							  		 if(arr[j]>arr[j+1])
							  		 {
									  		int temp = arr[j];
									  		arr[j] = arr[j+1];
									  		arr[j+1] = temp;
									  		temp = roll[j];
									  		roll[j] = roll[j+1];
									  		roll[j+1] = temp;
									 }
							 }
					 }
			 }
			 void mode()
			 {
			  	  	 sort();		//sort it
			  	  	 int modefreq=1;
			  	  	 for(int i=0;i<max;i++)		//calculate the frequency of mode
			  	  	 {
					  		 int mfreq = 1;
					  		 for(int j=i+1;j<max;j++)
					  		 {
							  		 if(arr[j] == arr[i])
							  		 		  mfreq++;
							  		 else
							  		 {
									  	 	  i = i + j - 1;
									  	 	  break;
									 }
							 }
							 if(mfreq>modefreq)
							 		 modefreq = mfreq;
					 }
					 if(modefreq == 1)
					 		cout<<"\nNo Modes.";
			 		 else						
			 		 {
			 		 	  	cout<<"\nMode Frequency = "<<modefreq;
			 		 	  	for(int i=0;i<=max-modefreq;i++)
			 		 	  	{
							 		if(arr[i]==arr[i+modefreq-1])
										   cout<<endl<<arr[i]<<" is a mode.\n";
							}
					 }	  	
			 }
	  		 void absentees()
	  		 {
			  		 cout<<"\nDisplaying Absentees\n";
			  		 for(int i=0;i<max;i++)
			  		 		 if(arr[i]==0)
			  		 		 		cout<<roll[i]<<endl;
			 }
			 void extremes()
			 {
    		  	  	 int high = -1, low = 101;
    		  	  	 for(int i=0;i<max;i++)
    		  	  	 {
					  		 if(arr[i]>high)
					  		 		high = arr[i];
					  		 if(arr[i]<low && arr[i]!=0)
					  		 		low = arr[i];
					 }
					 cout<<"\nHighest Marks";
    		  	  	 for(int i=0;i<max;i++)
    		  	  	 {
					  		 if(arr[i]==high)
					  		 		cout<<endl<<roll[i];
					 }
					 cout<<"\nLowest Marks";
    		  	  	 for(int i=0;i<max;i++)
    		  	  	 {
					  		 if(arr[i]==low)
					  		 		cout<<endl<<roll[i];
					 }
					 highest = high;
					 lowest = low;
			 }
			 void evaluate()
			 {
			  	  	 accept();
			  	  	 mode();
			  	  	 
			 }
			 
};

int main()
{
 	  Marks obj;
 	  obj.evaluate();
 	  int a;
 	  cin>>a;
}
