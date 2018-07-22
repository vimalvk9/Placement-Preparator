#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *link;
};

void append(struct node **,int);
void addatbeg(struct node **,int);
void addafter(struct node *,int,int);
void display(struct node *);
int count(struct node *);
void del(struct node **,int);

int main()
{
	struct node *p;
	p = NULL; // Empty linkedlist

    printf("No of elements in the linked list = %d\n",count(p));
    append(&p,14);
    append(&p,30);
    append(&p,25);
    append(&p,42);
    append(&p,17);

    display(p);
    
    addatbeg(&p,999);
    addatbeg(&p,888);
    addatbeg(&p,777);  
    
    display(p);

    addafter(p,7,0);
    addafter(p,2,1);
    addafter(p,5,99);
    
    display(p);
    printf("No of elements in the linked list = %d\n",count(p));

    del(&p,99);
    del(&p,1);
    del(&p,10);

    display(p);
    printf("No of elements in the linked list = %d\n",count(p));
}

// add at the end
void append(struct node **q,int num)
{
    struct node *temp , *r;

    if(*q == NULL)
    {
    	temp = (struct node *)malloc(sizeof(struct node));
    	temp->data = num;
    	temp->link = NULL;
    	*q = temp;
    }
    else 
    {
    	temp = *q;

    	while(temp->link != NULL)
    		temp = temp->link;
        r = (struct node *)malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;
    } 
}

// add at beginning
void addatbeg(struct node **q,int num)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = *q;
    *q = temp;
}

// add after specified number of nodes

void addafter(struct node *q,int loc,int num)
{
	struct node *temp,*r;
	int i;

	temp = q;

	// skip to desired position;
    for(i=0;i<loc;i++)
    {
    	temp = temp->link;
    	
 		// if end of linkedlist encountered
    	if(temp == NULL)
    	{
    		printf("There are less than %d elements in the list",loc);
    		return;
    	}
    }

    // insert
    r = (struct node *)malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

// display contents of list

void display(struct node *q)
{
	while(q != NULL)
	{
		printf("%d ",q->data);
		q =q->link;
	}
	printf("\n");
}

// count the number of nodes
int count(struct node *q)
{
	int i=0;
	while(q != NULL)
	{
		q = q->link;
		i++;
	}
	return i;
}

void del(struct node **q,int num)
{
	struct node *old , *temp;
	temp = *q;

	while(temp != NULL)
	{
		if(temp->data == num)
		{
			// for first node
			if(temp == *q)
				*q = temp->link;
		    else 
		    	old->link = temp->link;

		    free(temp);
		    return;
		}
		else
		{
			old = temp; // old points to the previous node
			temp = temp->link;
		}
	}

	printf("Element %d not fount \n",num);	
}

























