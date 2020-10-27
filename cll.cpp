#include <iostream>
using namespace std;

class cir_linklist;
class node
{
	public:
		node *next;
		int i;
		node(int x,node *n=NULL)
		{
			i=x;
			next=n;
		}
		friend class cir_linklist;
};

class cir_linklist
{
	node *first;
	public:
		cir_linklist()
		{
			first=NULL;
		}
	void add_beg(int);
	void add_end(int);
	void traverse();
};

void cir_linklist :: add_beg(int x)
{
	node *n= new node(x);
	if(first==NULL)
	{
		first=n;
		n->next=n;
	}
	else
	{
		node *temp=first;
		while(temp->next!=first)
		{
			temp=temp->next;
		}
		n->next=first;
		temp->next=n;
		first=n;
	}
}

void cir_linklist::add_end(int x)
{
	node *n= new node(x);
	if(first==NULL)
	{
		first=n;
		n->next=n;
	}
	else
	{
		node *temp=first;
		while(temp->next!=first)
		{
			temp=temp->next;
		}
		n->next=first;
		temp->next=n;
	}
}
/*
void cir_linklist::traverse()
{
	if(first==NULL)
	{
		cout<<"\nEmpty";
		return;
	}
	else
	{
		node *temp=first;
		while(temp!=NULL)
		{
			cout<<temp->i<<" ";
			temp=temp->next;
		}
	}
}*/
void cir_linklist::traverse()
{
     node *temp=first;
     cout<<"\n Displaying List:";
     do
     {
          cout<<" "<<temp->i;
          temp=temp->next;
     }while(temp!=first);
}
