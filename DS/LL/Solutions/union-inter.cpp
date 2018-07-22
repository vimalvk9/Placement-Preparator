#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

unordered_map <int,int> mp;

void store(struct node *h1,struct node *h2)
{
	struct node *p1 = h1;
	struct node *p2 = h2;

	while(p1 != NULL || p2 != NULL)
	{
		if(p1 != NULL)
		{
			mp[p1->data]++;
			p1 = p1->link;
		}
	
		if(p2 != NULL)
		{
			mp[p2->data]++;
			p2 = p2->link;
		}
	}
}


void push(struct node **head,int num)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->data = num;
	n->link = (*head);
	(*head) = n;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf ("%d ", node->data);
        node = node->link;
    }
    cout << "\n";
}

void Union()
{
	struct node *r = NULL;
	unordered_map <int,int> :: iterator it;

	for(it=mp.begin();it!=mp.end();it++)
		push(&r,it->first);

	printList(r);
}

void inter()
{
	struct node *r = NULL;
	unordered_map <int,int> :: iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		if(it->second == 2)
			push(&r,it->first);
	}
	printList(r);
}

int main()
{
    /* Start with the empty list */
    struct node* head1 = NULL;
    struct node* head2 = NULL;
 
    /* create a linked lits 5 -> 4 -> 3 -> 2 -> 1 */
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 5);
 
    /* printList(head1);*/
 
    /* create a linked lits 6 -> 5 -> 3 -> 1 */
   
    push(&head2, 1);
    push(&head2, 3);
    push(&head2, 5);
    push(&head2, 6);
 
    printf("First list is \n");
    printList(head1);
 
    printf("\nSecond list is \n");
    printList(head2);

    store(head1,head2);
 	Union();
 	inter();

 
    return 0;
}