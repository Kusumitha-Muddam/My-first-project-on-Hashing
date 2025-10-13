#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node
{
	int data;
	struct node *next;
	
};
struct node *hashtb[MAX];
int hash( int key)
{
	return key%MAX;
}
void insert(int key);
int delete1(int key);
void search(int key);
void traverse();
int main()
{
	for(int i=0;i<MAX;i++)
	hashtb[i]=NULL;
	while(1)
	{
		int ch,key;
		printf("enter choice 1:insert 2:delete 3:traverse\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter key");
				scanf("%d",&key);
				insert(key);
				break;
			case 2:
			    printf("enter key to delete");
				scanf("%d",&key);
				delete1(key);
				break;
			case 3:
				traverse();
				break;
			case 4:
				 printf("enter key to search");
				scanf("%d",&key);
				search(key);
				break;
			case 5:exit(0);
		}
	}
}
void insert( int key)
{
int i=hash(key);
struct node *p=(struct node *)malloc(sizeof(struct node));
p->data=key;
p->next=NULL;
    if(hashtb[i]==NULL)
    {
	hashtb[i]=p;
	}	
	else
	{
		struct node *q=hashtb[i];
		while(q->next!=NULL)
		q=q->next;
		q->next=p;
	}
}
int delete1( int key)
{
	struct node *temp,*prev=NULL;
	int i=hash(key);
	temp=hashtb[i];
	while(temp!=NULL &&temp->data!=key ){
	prev=temp;
	temp=temp->next;
}
if(temp==NULL)
printf("element not found");
if(prev==NULL)
hashtb[i]=temp->next;
else
prev->next=temp->next;
	printf("the deleted element is %d",temp->data);
	free(temp);
}
void traverse()
{
	for(int i=0;i<MAX;i++)
	{
	struct node *temp=hashtb[i];
	while(temp!=NULL)
	{

	printf("%d->",temp->data);
		temp=temp->next;
	}
	//printf("NULL\n");
	}
}
void search(int key)
{
	int i=hash(key);
	struct node *temp=hashtb[i];
	while(temp!=NULL){
		if(temp->data==key){
		printf("element found");
		return;
	}
			
		temp=temp->next;
	}
	
//	else
	printf("not found");
}

