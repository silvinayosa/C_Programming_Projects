/*
* Polynomial Evaluation using Linked Lists
* Description: Reads a polynomial from a file, evaluates it for a given x, and prints the result.
*/

#include<stdio.h>
#include<stdlib.h>

struct num
{
	int number;
	int power;
	struct num *next;
};

void BuildPoly (struct num *hi, FILE *fo)
{
	if (fo==NULL)
	{
		printf("Error");
		exit(1);
	}
	//read
	while (!feof(fo))
	{
		hi->next=(struct num*)malloc(sizeof(struct num));
		hi=hi->next;
		fscanf(fo,"%d %d",&hi->number,&hi->power);
		hi->next=NULL;
	}
}


void Print_Poly(struct num *l)
//this last function is to print the polynomial
{
	l=l->next; //because the first node is empty, so we will just continue to the next node
	while(l!=NULL)
	//this while loop is to print the poly and it will stop when it have no value left.
	{
		printf(" %dx^%d ",l->number,l->power); //printing the coe and power of poly
		l=l->next;//moving to the next node (next number of poly)
		
		if(l!=NULL && l->number>0)
		//this if statement is to print + if the number is + (we have to make sure that it is also not NULL)
		{printf("+");}
	}
}

void Value (struct num* poly, int x, int *result)
//this function is to count the value of the polynomial operation after putting the value of x.
{
	*result=0;
	poly=poly->next;
	while(poly!=NULL)
	//this big loop is to perform operation after we get the exact value of each coe and exp.
	{
		int temp=1;
		int powerr=poly->power;
		int coe=poly->number;
		while(powerr>0)
		//this while loop is to count the amount after calculating the value.
		{
			temp=temp*x;
			powerr--;
		}
		temp=temp*coe;
		*result=*result+temp;
		poly=poly->next;
	}
}


int main()
{
	struct num one;
	int x,result;//to store value of x and store the result after operating the value function to the poly
	FILE *fo=fopen("polynomial1.txt","r");
	
	BuildPoly(&one,fo);
	
	printf("First Poly:\n");
	Print_Poly(&one);
	
	printf("\n\nType the value of x!\n");
	scanf("%d",&x);
	Value(&one,x,&result);
	printf("\nThe result if x is %d is %d\n",x,result);

}

