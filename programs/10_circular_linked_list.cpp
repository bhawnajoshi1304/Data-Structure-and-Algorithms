#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
}*root;

void insertBeg(int data)
{
	struct node *tmp,*new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=data;
	new_node->next=root;
	root=new_node;
	tmp=root;
	while(1)
	{
		if(tmp->next==NULL)
			tmp->next=root;
		tmp=tmp->next;
	}
}

void deleteElement(int data)
{
	int f=0;
	struct node *tmp=root;
	if(root==NULL)
		printf("Circular Linked List is empty.\n");
	else
	{
	while(1)
	{
		if(tmp->next==root)
			break;
		else if(tmp->next->data==data)
			{
				f=1;
				tmp->next=tmp->next->next;
				printf("%d deleted\n",data);
				break;
			}
		else
			tmp=tmp->next;
	}
	if(f==0)
		printf("Nothing to delete!!!Element not found\n");
	}
}

void insertEnd(int data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=data;
	new_node->next=root;
	if(root==NULL)
	{
		root=new_node;
		new_node->next=root;
	}
	else
	{
		struct node *tmp=root;
		while(tmp->next!=root)
			tmp=tmp->next;
		tmp->next=new_node;	
	}
}

void insertBefore(int data,int before)
{
	int f=0;
	struct node *new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=data;
	new_node->next=NULL;
	if(root==NULL)
	{
		f=1;
		printf("Linked List is empty !!! Element appended in begining\n");
		insertBeg(data);
	}
	else if(root->data==before)
	{
		f=1;
		insertBeg(data);
	}
	else
	{
		struct node*tmp=root;
		while(1)
		{
			if(tmp->next==root||tmp->next->data==before)
				break;
			tmp=tmp->next;
		}
		if(tmp->next!=root&&tmp->next->data==before)
		{
		new_node->next=tmp->next;
		tmp->next=new_node;
		f=1;
		}
	}
	if(f==0)
	{
		printf("Before element not found!!! Element inserted at end.\n");
		insertEnd(data);
	}
}

void insertSorted(int data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=data;
	new_node->next=NULL;
	if(root==NULL||root->data>data)
		insertBeg(data);
	else
	{
		struct node *tmp=root;
		while(1)
		{
			if(tmp->next==root||tmp->next->data>data)
				break;
			tmp=tmp->next;
		}
		new_node->next=tmp->next;
		tmp->next=new_node;
	}
}

void insertAfter(int data,int after)
{
	int f=0;
	struct node *new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=data;
	new_node->next=NULL;
	if(root==NULL)
	{
		f=1;
		printf("Linked List is empty !!! Element appended in begining\n");
		insertBeg(data);
	}
	else
	{
		struct node *tmp=root;
		while(1)
		{
			if(tmp->data==after||tmp->next==root)
				break;
			tmp=tmp->next;
		}
		if(tmp->data==after)
		{
			f=1;
			new_node->next=tmp->next;
			tmp->next=new_node;
		}
	}
	if(f==0)
	{
		printf("After element not found!!! Element inserted at end.\n");
		insertEnd(data);
	}
}

void display()
{
	if(root==NULL)
		printf("Circular Linked List is empty!!!\n");
	else
	{
		struct node *tmp=root;
		do
		{
			printf("%d ",tmp->data);
			tmp=tmp->next;
		}while(tmp!=root);
		printf("\n");
	}
}

int main()
{
	// insertAfter(7,9);
	// insertBefore(8,9);
	// insertAfter(1,9);
	// insertBeg(2);
	// insertBeg(3);
	// insertEnd(5);
	// deleteElement(5);
	// insertAfter(4,2);
	// insertBefore(6,8);
	// for(int i=20;i>10;i--)
	// 	insertSorted(i);
	// deleteElement(17);
	// deleteElement(5);
	display();
	return 0;
}