#include <bits/stdc++.h>
using namespace std;
template <class t>
class node
{public:
    t data;
    node *link;
    node()
    {
        link=NULL;
    }
};
template<class t>
class linklist
{
    public:
    node<t> *head,*temp,*ptr;
    linklist()
    {
        head=NULL;
    }
    void create()
    {
        cout<<"Enter the value\n";
        int val;
        cin>> val;
        temp=new node<t>();
        temp->data=val;
        if (head==NULL)
             head=temp;
        else
        {
            for(ptr=head;ptr->link!=NULL;ptr=ptr->link);
            ptr->link=temp;
        }
    }
    void display()
    {
        if(head==NULL)
            cout<<"No elements :(\n";
        else
            for(ptr=head;ptr!=NULL;ptr=ptr->link)
                cout<<ptr->data<<"  ";
        cout<<endl;
    }
    void delend()
    {
        if(head==NULL)
            cout<<"LinkList empty nigga\n";
        else if(head->link==NULL){
            cout<<"Deleted element "<<head->data<<endl;
            head=NULL;
        }
        else
        {
            node<t> *temp;
            for(temp=head;temp->link->link!=NULL;temp=temp->link);
            cout<<"Deleted element "<<temp->link->data<<endl;
            temp->link=NULL;
        }
    }
    void searc()
    {
        node<t> *ptr;
        cout<<"Enter the search element"<<endl;
        t n;int f=0,c=0;
        cin>>n;
        for(ptr=head;ptr!=NULL;ptr=ptr->link,c++)
        {
            if(ptr->data==n)
            {
                f=1;
                cout<<"Found at "<<(c+1)<<endl;
            }}
            if(f>0)
                return ;
            cout<<"Element not found :'("<<endl;
        }
};
int main()
{
    linklist<int> l;
    while(1)
    {
        cout<<"Enter the choice:\n1.Create\n2.Display\n3.Delete from end\n4.Search an element\n";
        int k;
        cin>>k;
        switch(k)
           {
               case 1:l.create();break;
               case 2:l.display();break;
               case 3:l.delend();break;
               case 4:l.searc();break;
               default:cout<<"Thank you";exit(1);
           }
    }
}
