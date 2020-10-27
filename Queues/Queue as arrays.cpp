//Queue implementation using arrays

#include <iostream>
#define max 5
using namespace std;

void insert(int);
void traverse();
void del();

int front = -1, rear= - 1;

int q[max];

int main()
{
	cout<<"After Insertion in queue: \n";
	insert(5);
	insert(9);
	insert(2);
	insert(3);
	insert(7);
	traverse();
	cout<<"\nAfter Deletion in queue:\n";
	del();
	traverse();
	return 0;
}
void insert(int x)
{
	if(rear >= max-1 )
	{
		cout<<"Overflow! can't add\n";
		return ;
	}
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		q[rear]=x;
	}
	else
	{
		rear++;
		q[rear]=x;
	}
}

void del()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Nothing to delete!\n";
		return ;
	}
	if(front == rear)
	{
		q[rear]='\0';
		front=-1;
		rear=-1;
	}
	else
	{
		q[front]='\0';
		front++;
	}
}

void traverse()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Empty list!\n";
		return ;
	}
	for(int i=front;i<=rear;i++)
	{
		cout<<q[i]<<" ";
	}
}


