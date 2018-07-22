#include <bits/stdc++.h>
#include <malloc.h>

using namespace std;

struct node
{
	string name;
	int age;
	float sal;
    struct node *link;
};

void display(struct node *q)
{
	while(q != NULL)
    	{
    		cout << q->name << " ";
    		q = q->link;
    	} 
    cout << "\n";
}

void sortname(struct node *q)
{
	struct node *i = NULL , *j = NULL;
	i = q;

	while(i != NULL)
	{
		j = i->link;
		while(j != NULL)
		{
			if((i->name).compare(j->name) > 0)
			{
				swap(i->name,j->name);
			}
			j = j->link;
		}
		i = i->link;
	}  
}

int main()
{
	int n = 10 , i=0;
	string x;
	int y;
	float z;

    struct node *list = NULL , *t = NULL , *p , *q;

	while(i<n)
	{
		cin >> x >> y >> z;
        
        t = (struct node *)malloc(sizeof(struct node));
        
        t->name = x;
        t->age = y;
        t->sal = z;
	    
        if(i == 0)
        {
        	list = t;
        	p = list;
        	q = list; 
        	t->link = NULL;
        }
        else
        {
        	p = list;
        	while(p->link != NULL)
        		p = p->link;

        	p->link = t;
        	t->link = NULL;	 
        }
	   i++;
	}
    
    display(q);
	sortname(q);
    display(q);
}
