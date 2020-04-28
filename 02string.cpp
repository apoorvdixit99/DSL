#include<iostream>
using namespace std;

class String
{
 	  char str[50];
 	  int len;
 	  public:
	  		 String(){len=0;}
			 void Input(){
				  	 cout<<"\n\nEnter the String :: ";
				  	 cin>>str;
				  	 length();}
			 void Display(){
				  	 cout<<"\nString = "<<str;
					 cout<<"\nLength = "<<len;
			 }
			 int length(){
				  	 len = 0;
				  	 while( str[len] != '\0' )
				  	 		len++;
		  	 		 return len;
			 }
			 void copy(String arg){
			  		 len = arg.len;
			  		 for(int i=0;i<len;i++)
			  		 		 str[i] = arg.str[i];
  		 		 	 str[len] = '\0';
			 }
			 void ConCatenate(String arg)
			 {
			  		 for(int i=0;i<arg.len;i++)
			  		 		 str[i+len] = arg.str[i];
			  		 len = len + arg.len;
  		 		 	 str[len] = '\0';
			 }
			 void reverse()
			 {
				  	 for(int i=0;i<(len/2);i++)
				  	 {
					  		 char temp = str[i];
					  		 str[i] = str[len - i - 1];
					  		 str[len - i - 1] = temp;
		  			 }
			 }
			 int charFrequency(char arg)
			 {
			  	  	 int x = 0;
					 for(int i=0;i<len;i++)
					 		 if(str[i] == arg)
							  		++x;
		  			 return x;
			 }
			 void charDelete(char arg)
			 {
			  	  	 for(int i=0;i<len;i++)
					 		 if(str[i] == arg)
					 		 {
							  		   for(int j=i+1;j<len;j++)
							  		   		   str[j-1] = str[j];
							  		   len--;
							  		   str[len] = '\0' ;
							  		   i--;
							 }
			 }
			 bool equals(String arg)
			 {
						if(len == arg.len)
						{
						 	   for(int i=0;i<len;i++)
						 	   		   if(str[i]!=arg.str[i])
						 	   		   		  return false;
						 	   		   return true;
						}
						else
							   return false;
			 }
			 bool palindrome()
			 {
				  	 for(int i=0;i<(len/2);i++)
				  	 {
					  		 if(str[i] != str[len - i - 1])
					  		 		   return false;
		  			 }
		  			 return true;
			 }
			 int checkSubString(String arg)
			 {
			  	 int occurence = 0;
			  	 for(int i=0;i<len;i++)
			  	 {
				  		 if( str[i] == arg.str[0] && (i+arg.len)<=len )
				  		 {
						  	 bool flag = true;
						  	 for(int j=0;j<arg.len;j++)
						  	 		if( arg.str[j] != str[i+j] )
						  	 			{flag = false;break;}
						  	 if(flag == true )
						  	 		 occurence++;
						 }
		  		 }
			  	 return occurence;
			 }
			 void deleteSubString(String arg)
			 {
			  	 for(int i=0;i<len;i++)
			  	 {
				  		 if( str[i] == arg.str[0] && (i+arg.len)<=len )
				  		 {
						  	 bool flag = true;
						  	 for(int j=0;j<arg.len;j++)
						  	 		if( arg.str[j] != str[i+j] )
						  	 			flag = false;
						  	 if(flag == true )
						  	 {
							  	   for(int j=i+arg.len;j<len;j++)
								   		   str[j-arg.len] = str[j];
						  		   len = len - arg.len;
							  	   str[len] = '\0' ;
							 }
						 }
		  		 }
			 }
			 void replaceSubString(String arg, String arg2)
			 {
			  	 for(int i=0;i<len;i++)											
			  	 {
				  		 if( str[i] == arg.str[0] && (i+arg.len)<=len )			
				  		 {
						  	 bool flag = true;									//This checks for the substring to be replaced
						  	 for(int j=0;j<arg.len;j++)							
						  	 		if( arg.str[j] != str[i+j] )				
						  	 			flag = false;							
						  	 if(flag == true )									
						  	 {
							  		int extra = arg2.len - arg.len;				
									if(extra>=0)								
										for(int j=len-1;j>=i;j--)				
											str[j+extra]=str[j];				
									else
										for(int j=i-extra;j<len;j++)			
											str[j+extra]=str[j];				
									for(int j=0;j<arg2.len;j++)					
										str[i+j]=arg2.str[j];					
								    len = len + extra ;							
							  	    str[len] = '\0' ;							
							 }
						 }
		  		 }
			 }
				int execute()
				{
					while(true)
					{
						cout<<"\nMenu-Driven String Program : ";
						int ch=0;
						cout<<endl<<++ch<<". Length of the String";
						cout<<endl<<++ch<<". ConCatenated String";
						cout<<endl<<++ch<<". Copied String";
						cout<<endl<<++ch<<". Reversed String";
						cout<<endl<<++ch<<". Character Frequency";
						cout<<endl<<++ch<<". Character Delete";
						cout<<endl<<++ch<<". Checking Equality of two Strings";
						cout<<endl<<++ch<<". Palindrome";
						cout<<endl<<++ch<<". Check Sub String";
						cout<<endl<<++ch<<". Replace Sub String";
						cout<<endl<<++ch<<". Delete Sub String";
						cout<<endl<<++ch<<". Exit";
						cout<<endl<<"Enter your choice :: ";
						cin>>ch;
						String obj1, obj2;
						switch(ch)
						{
							case 1:
								cout<<"\nCalculating Length of the String:-\n";
								obj1.Input();
								obj1.Display();
							break;
							case 2:
								cout<<"\nConCatenated String:-\n";
								obj1.Input();
								obj2.Input();
								obj1.ConCatenate(obj2);
								obj1.Display();
							break;
							case 3:
								cout<<"\nCopied String:-\n";
								obj1.Input();
								obj2.Input();
								obj1.copy(obj2);
								obj1.Display();
							break;
							case 4:
								cout<<"\nReversed String:-\n";
								obj1.Input();
								obj1.reverse();
								obj1.Display();
							break;
							case 5:
							{
								cout<<"\nCharacter Frequency:-\n";
								obj1.Input();
								cout<<"\nInput the character to be searched :: ";
								char search;
								cin>>search;
								int oc = obj1.charFrequency(search);
								cout<<"Number of times of Occurence is :: "<<oc;
							break;
							}
							case 6:
						    {
								cout<<"\nCharacter Delete:-\n";
								obj1.Input();
								cout<<"\nInput the character to be deleted :: ";
								char del;
								cin>>del;
								obj1.charDelete(del);
								obj1.Display();
							break;
							}
							case 7:
								cout<<"\nChecking Equality of two Strings\n";
								obj1.Input();
								obj2.Input();
								bool flag;
								flag = obj1.equals(obj2);
								if(flag==true)
									cout<<"\nStrings are Identical.\n";
								else
									cout<<"\nStrings are not Identical.\n";
							break;
							case 8:
								cout<<"\nPalindrome String:- \n";
								obj1.Input();
								flag = obj1.palindrome();
								if(flag==true)
									cout<<"\nString is a palindrome.\n";
								else
									cout<<"\nStrings is not a palindrome.\n";
							break;
							case 9:
							{
								cout<<"\nSubstring\n";
								obj1.Input();
								obj2.Input();
								int oc = obj1.checkSubString(obj2);
								cout<<"Number of times of Occurence is :: "<<oc;	
							break;
							}
							case 10:
						    {
								cout<<"\nReplace SubString:-\n";
								obj1.Input();
								obj2.Input();
								String obj3;
								obj3.Input();
								obj1.replaceSubString(obj2,obj3);
								obj1.Display();
							break;
							}
							case 11:
								cout<<"\nDelete SubString:-\n";
								obj1.Input();
								obj2.Input();
								obj1.deleteSubString(obj2);
								obj1.Display();
							break;
							case 12:
								return 0;
							default:
								cout<<"\nInvalid Choice\n";
						}
					}
				}
			 
};
			 
int main()
{
 	String *obj;
 	obj->execute();
 	return 0;
}



