#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *link;
};

void addcirq(struct node **f, struct node **r,int num)
{
	struct node *q;
	q = (struct node *) malloc(sizeof(struct node));
	q->data = num;

	if(*f == NULL)
		*f = q;
	else
		(*r)->link = q;

	*r = q;
	(*r)->link = *f;	
}

int delcirq(struct node **f,struct node **r)
{
	struct node *q;
	int item;

	if(*f == NULL)
		printf("Queue is empty\n");
	else
	{
		if(*f == *r)
		{
			item = (*f)->data;
			free(*f);
			*f = NULL;
			*r = NULL;
		}
		else
		{
			q = *f;
			item = q->data;
			*f = (*f)->link;
			(*r)->link = *f;
			free(q); 
		}
		return item;
	}	 
}

void displaycirq(struct node *f)
{
	struct node *q = f , *p = NULL;

	while(q != p)
	{
		printf("%d ",q->data);
		q = q->link;
		p = f;
	}
	printf("\n");
}


int main()
{
    struct node *f , *r , *t;
	f = r = NULL;

	addcirq(&f,&r,1);
	addcirq(&f,&r,2);
	addcirq(&f,&r,3);
	addcirq(&f,&r,4);
	addcirq(&f,&r,5); 

    displaycirq(f);

    delcirq(&f,&r);
    delcirq(&f,&r);

    displaycirq(f);
    printf("\n");
    return 0;  
}