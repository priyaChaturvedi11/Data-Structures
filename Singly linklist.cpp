#include<iostream>
using namespace std;
class linklist;
class node
{
	
	public:
	int i;
	node *next;
		node(int x=0, node *n=NULL)
		{
			i=x;
			next=n;
		}
	friend class linklist;
};

class linklist
{
	node *first;
	public:
	linklist()
	{
		first=NULL;
	}
	void add_at_beg(int);
	void add_at_end(int);
	void add_at_pos(int,int);
	void add_after_val(int,int);
	void delete_beg();
	void delete_end();
	void delete_pos(int);
	void search(int);
	void traverse();
	//void merge(linklist l1,linklist l2);
	//void reverse;
};

int main()
{
	linklist l;
	l.add_at_beg(5);
	l.add_at_beg(6);
	l.add_at_beg(8);
	l.add_at_end(7);
	l.add_at_end(1);
	l.add_at_pos(2,2);
	l.add_after_val(0,6);
	cout<<"\n";
	l.search(7);
	l.delete_pos(2);
	cout<<"\n";
	l.traverse();
	/*l.delete_beg();
	l.traverse();
	l.add_at_beg(5);
	cout<<"\n";
	//l.traverse();
	cout<<"\n";
	l.delete_pos(3);
	l.traverse();
	/*l.add_at_end(23);
	l.add_at_beg(36);
	cout<<"\n";
	l.delete_end();
	//l.traverse();
	l.search(7);
	cout<<"\n";
	l.traverse();*/

	return 0;
}

void linklist :: add_at_beg(int x)
{
	node *n=new node(x);
	if(first==NULL)
	{
		first=n;
	}
	else
	{
		n->next=first;
		first=n;
	}
}

void linklist :: add_at_end(int x)
{
	node *n=new node(x);
	if(first==NULL)
	{
		first=n;
	}
	else
	{
		node *temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=n;
	}
}

void linklist :: add_at_pos(int x , int pos)
{
	node *n=new node(x);
	if(pos==1)
	{
		add_at_beg(x);
		return;
	}
	else
	{
		node *temp =first;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		n->next=temp->next;
		temp->next=n;
	}
}

void linklist :: add_after_val(int x,int val)
{
	node *n=new node(x);
	if(first==NULL)
	{
		cout<<"Empty List";
		return;
	}
	else
	{
		node *temp=first;
		while(temp->i!=val)
		{
			temp=temp->next;	
		}
		if(temp==NULL)
		{
			cout<<"\nElement not found";
			return;
		}
		else
		{
			n->next=temp->next;
			temp->next=n;
		}
	}
}

void linklist :: delete_beg()
{
	if(first==NULL)
	{
		cout<<"\nEmpty list nothing to delete";
		return;
	}
	else
	{
		node *temp=first;
		first=first->next;
		delete(temp);
	}
}

void linklist :: delete_end()
{
	if(first==NULL)
	{
		cout<<"\nEmpty list nothing to delete";
		return;
	}
	else
	{
		node *temp=first;
		node *prev;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		delete(temp);
	}
}

void linklist :: delete_pos(int pos)
{
	if(first==NULL)
	{
		cout<<"\nEmpty list nothing to delete";
		return;
	}
	if(pos==1)
	{
		delete_beg();
		return;
	}
	else
	{
		node *temp=first;
		node *prev;
		for(int i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=temp->next;
		delete(temp);
	}
}

void linklist :: search(int s)
{
	int pos=0;
	node *temp=first;
	while(temp->i!=s)
	{
		temp=temp->next;
		pos++;
	}
	if(temp==NULL)
	{
		cout<<"\nNot found";
		return;
	}
	else
	{
		cout<<"\nFound at pos: "<<pos+1;
	}
}

void linklist :: traverse()
{
	/*if(first==NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	else
	{*/
		node *temp=first;
		while(temp!=NULL)
		{
			cout<<temp->i<<" ";
			temp=temp->next;
		}
		//return;
	//}
}






