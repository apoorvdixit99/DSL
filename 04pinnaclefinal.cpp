#include <iostream>
using namespace std;

class Linked_List;
class Club
{
    int prn;
    string name;
    Club *next;
    public:
        friend class Linked_List;
};

class Linked_List
{
    Club *start,*last;
    public:
        Linked_List()
        {
            start=NULL;
            last=NULL;
        }
        void create_pres();
        void create_secr();
        void create_node();
        void delete_node();
        void count_nodes();
        void display();
        Club* ret_start();
        void display_rev(Club*);
        void conc_sort(Linked_List);
};

void Linked_List::create_pres()
{
    Club *newclub;
    newclub=new Club;
    cout<<"\nEnter the PRN of club President:";
    cin>>(newclub->prn);
    cout<<"\nEnter the name of club President:";
    cin>>(newclub->name);
    if(start==NULL)
    {
        newclub->next=NULL;
        start=newclub;
        last=newclub;
        last->next=NULL;
    }
    else
    {
        newclub->next=start;
        start=newclub;
    }
}

void Linked_List::create_secr()
{
    Club *newclub;
    newclub=new Club;
    cout<<"\nEnter the PRN of club secretary:";
    cin>>(newclub->prn);
    cout<<"\nEnter the name of the club Secretary:";
    cin>>(newclub->name);
    if(start==NULL)
    {
        last=newclub;
        newclub->next=NULL;
        start=newclub;
    }
    else
    {
        last->next=newclub;
        last=newclub;
        last->next=NULL;
    }
}

void Linked_List::create_node()
{
    Club *newclub,*p;
    newclub=new Club;
    p=new Club;
    int l,c=0;
    cout<<"\nEnter the PRN of student:";
    cin>>newclub->prn;
    cout<<"\nEnter the name of student:";
    cin>>newclub->name;
    //newclub=start;
    newclub->next=start->next;
    start->next=newclub;
}

void Linked_List::delete_node()
{
    int ch,f=0;
    cout<<"\nWhom do you wanna delete: 1:Prez 2:Secretary 3:Normal Student:";
    cin>>ch;
    Club *p,*q;
    p=new Club;
    p=start;
    q=new Club;
    if(ch==1)
    {
        p=start->next;
        delete start;
        start=p;
    }
    else if(ch==2)
    {
        while(p->next!=last)
        {
            p=p->next;
        }
        p->next=NULL;
        delete last;
        last=p;
    }
    else if(ch==3)
    {
        int dp;
        cout<<"Enter the PRN of student to be deleted:";
        cin>>dp;
        while(p->next!=NULL)
        {
            if(p->next->prn==dp)
            {
                f=1;
                q=p->next;
                p->next=q->next;
                delete q;
                q=NULL;
            }
            else
            {
                p=p->next;
            }
        }
        if(f==0)
        {
            cout<<"\nStudent not found";
        }
    }
    else
    {    
        cout<<"\nWrong choice";
    }
}

void Linked_List::count_nodes()
{
    int count=0;
    Club *p;
    p=new Club;
    p=start;
    while(p->next!=NULL)
    {
        count++;
        p=p->next;
    }
    count++;
    cout<<"\nNumber of current nodes:"<<count;
}    

void Linked_List::display()
{
    Club *p;
    p=new Club;
    p=start;
    cout<<"\nName"<<"\t"<<"PRN";
    cout<<"\n--------------------------\n";
    while(p!=NULL)
    {
        cout<<p->name<<"\t"<<p->prn;
        cout<<"\n";
        p=p->next;
    }
    cout<<"\n";
}    

void Linked_List::display_rev(Club *s)
{
    if(s!=NULL)
    {
        display_rev(s->next);
        cout<<s->name<<"\t"<<s->prn;
        cout<<"\n";
    }
}

Club* Linked_List::ret_start()
{
    return start;
}

void Linked_List::conc_sort(Linked_List ob1)
{
    last->next=ob1.start;
    int c=0;
    last=ob1.last;
    Club *p,*q,*t;
    t=new Club;
    p=new Club;
    q=new Club;
    p=start;
    while(p)
    {
        q=p->next;
        while(q)
        {
            if((p->prn)>(q->prn))
            {
                t->prn=p->prn;
                t->name=p->name;
                p->prn=q->prn;
                p->name=q->name;
                q->prn=t->prn;
                q->name=t->name;
            }
            q=q->next;
        }
        p=p->next;
    }
}
    
int main(void)
{
    Linked_List ob,ob1;
    ob.create_pres();
    ob.create_secr();
    ob.display();
    Club *a;
    a=ob.ret_start();
    int ch=0,f=0;
    do
    {
        cout<<"\nLinked List:";
        cout<<"\n1. Create Student Node";
        cout<<"\n2. Delete Node";
        cout<<"\n3. Number of nodes";
        cout<<"\n4. Reverse Display";
        cout<<"\n5. Concatenate";
        cout<<"\n0. Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: 
                ob.create_node();
                ob.display();
                break;
            case 2: 
                ob.delete_node();
                ob.display();
                break;
            case 3: 
                ob.count_nodes();
                ob.display();
                break;
            case 4: 
                cout<<"\nName"<<"\t"<<"PRN";
                cout<<"\n--------------------------\n";
                ob.display_rev(a);
                break;
            case 5: 
                ob1.create_pres();
                ob1.create_secr();
                do
                {
                    ob1.create_node();
                    cout<<"\nDo you wanna add more students (1:yes 0:No)";
                    cin>>f;
                }
                while(f!=0);
                ob.conc_sort(ob1);
                ob.display();
                break;
            case 0: 
                break;
            default:
                cout<<"\nWrong Choice";
                break;
        }
    }
    while(ch!=0);
    return 0;
}
