/*
* Polynomial Multiplication using Linked Lists
* Description: Takes two polynomials as input, multiplies them, sorts the result, and displays it.
*/

#include <stdio.h>
#include <malloc.h>

struct node
{
	int cof;
	int exp;
	struct node *next;
};
struct node input();
struct node multiple(struct node f,struct node g);
void show(struct node head);


void swap(struct node *one, struct node *two)
//a function to swap two nodes
//will be used in org function
{
	int tp1,tp2;//two temp to store cof and exp
	tp1=one->cof;
	tp2=one->exp;
	one->cof=two->cof;
	one->exp=two->exp;
	two->cof=tp1;
	two->exp=tp2;
}
	
	
void org(struct node hi)
//function to organize or sort the selected linked list
{
	struct node* head=&hi; //this one works like a big index
	struct node* tp; //temp place to store a node with the smallest exp
	struct node* h; //this one works like a small index.

	while(head->next!=NULL)
	//loop to perform selection sort on the struct
	{	
		h=head->next;
		tp=h;
		while (h!=NULL)
		//This loop is to find the smallest exp and put the address on tp.
		{
			if(tp->exp>h->exp)
			{
				tp=h;
			}
			h=h->next;
		}
		h=head->next;
		if(h!=tp)
		{swap(h,tp);}
		head=head->next;
	}
}

int main()
//main function that mostly only call the function and get an input.
{
	struct node F,G,fg; //making the linked list
	printf("please input polynomial like : 3x^2+2x^1+1x^0\n");
	printf("input F(x) polynomial :");
	F=input(); //getting the input and put them inside the linked list called F
	printf("input G(x) polynomial :");
	G=input(); //getting the input and put them inside the linked list called G
	fg=multiple(F,G); 
	printf("result:\n");
	show(fg);
	org(fg);
	printf("The output after organizing :\n");
	show(fg);
	return 0;	
}

struct node input()
//function to process the input and return the linked list that has been made.
{
	char ch='+'; 
	struct node head,*tp;
	tp=&head;
	do
//this is the code that will run during the while loop
//it will create a new node and scanning the input to be stored there.
	{
		tp->next=(struct node*)malloc(sizeof(struct node));
		tp=tp->next; //the first node will be empty
		scanf("%dx^%d",&(tp->cof),&(tp->exp));
		if(ch=='-')
			tp->cof=-(tp->cof);
		ch=getchar();
	}while(ch!='\n'); //while the input is still continuing (no newline), the code above will keep running.
	tp->next=NULL; //making the last node points to no other nodes.
	return head;
}

struct node multiple(struct node f,struct node g)
//performing multiplication between 2 nodes and return the result as a new linked list.
{
	struct node *fp,*gp,temp,*tp;
	int flog=0;
	temp.next=NULL;
	fp=f.next;
	gp=g.next;

	while(fp!=NULL)
//this loop is to repeat the multiplication until f(x) is empty
	{
		gp=g.next; //reset gp because according to the next loop, gp stop when g(x) is already empty
		while(gp!=NULL)
//this function repeat multiplication until g(x) is empty.
		{
			tp=&temp;
			flog=0;
			while(tp->next!=NULL)
			{
				if( ( fp->exp+gp->exp )==tp->next->exp)
				{
					tp=tp->next;
					tp->cof=tp->cof+(fp->cof*gp->cof);
					flog=1;
					break;
				}
				else
				tp=tp->next;
			}
			if(flog==0)
			{
				tp->next=(struct node*)malloc(sizeof(struct node));
				tp=tp->next;
				tp->cof=fp->cof * gp->cof;
				tp->exp=fp->exp+gp->exp;
				tp->next=NULL;
			}
			gp=gp->next;
		}
		fp=fp->next;
	}
	return temp;
}

void show(struct node head)
//function to print the linked list
{
	struct node *tp;
	tp=head.next;
	while(tp!=NULL)
//loop that will print the number stored inside linked list.
	{
		if(tp->cof>0||tp->cof<0)
		printf("%dx^%d",tp->cof,tp->exp);
		tp=tp->next;
		if(tp!=NULL)
//if statement to print + in front of the new positive number.
		{
			if(tp->cof>0)
			printf("+");
		}
		
	}
	printf("\n");
}
