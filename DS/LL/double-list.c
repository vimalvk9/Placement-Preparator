#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *ll;
	struct node *rl;
};

void addend(struct node **p,int num)
{
   struct node *q = *p , *r = NULL;
   
   r = (struct node *)malloc(sizeof(struct node));
   r->data = num; 

   if(*p == NULL)
   {
   		r->ll = NULL;
   		r->rl = NULL;
   		(*p) = r;
   }
   else
   {
   		while(q->rl != NULL)
   			q = q->rl;

   		r->rl = NULL;
   		r->ll = q;
   		q->rl = r;
   }
}

void addbeg(struct node **p,int num)
{
	struct node *q;
	q = (struct node *)malloc(sizeof(struct node));

	q->ll = NULL;
	q->rl = *p;
	q->data = num;
	(*p)->ll = q;
	*p = q;
}

void addafter(struct node *p,int loc,int num)
{
	struct node *t;
    int i;

    for(i=0;i<loc;i++)
    {
    	(p) = (p)->rl;
    	
    	if( (p) == NULL )
    	{
    		printf("Empty\n");
    		return;
    	}
    }

    (p) = (p)->ll;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = num;
    
    t->ll = (p);
    t->rl = (p)->rl;
    (t->rl)->ll = t;
    (p)->rl =t;
}    

void display(struct node *q)
{
   while(q != NULL)
   {
   	printf("%d\t",q->data);
   	q=q->rl;
   }
   printf("\n");
}

int Count(struct node *q)
{
	int c = 0;
	while(q != NULL)
	{
		q = q->rl;
		c++;
	}
	return c;
}

void del(struct node **p,int num)
{
	struct node *q = *p;
	while(q != NULL)
	{
		if(q->data == num)
		{
			if(q == *p)
			{
				(*p) = (*p)->rl;
				(*p)->ll = NULL; 
			}
			else
			{
				if(q->rl == NULL)
				{
					(q->ll)->rl = NULL;
				}
				else
				{
					(q->ll)->rl = (q->rl);
					(q->rl)->ll = (q->ll);
				}
					free(q);
			}
			return;		
		}

		q = q->rl;
	}
	printf("%d Not found\n",num);
}



int main()
{
	struct node *p;
	p = NULL;

	addend(&p,1);
	addend(&p,2);
	addend(&p,3);
	addend(&p,4);

	display(p);

	addbeg(&p,6);
	addbeg(&p,7);

	printf("Count %d\n",Count(p));
display(p);
	addafter(p,2,100);
	addafter(p,3,150);

	printf("Count %d\n",Count(p));

	del(&p,3);
	display(p);
		printf("Count %d\n",Count(p));


}
