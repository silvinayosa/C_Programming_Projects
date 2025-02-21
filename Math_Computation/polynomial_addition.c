/*
* Polynomial Addition using Linked Lists
* Description: Reads two polynomials from files, stores them in linked lists, adds them, and prints the result.
* Input files: "polynomial1.txt", "polynomial2.txt"
*/

#include<stdio.h>
#include<stdlib.h>

struct num
//this is the basic struct to form the linked list
{
	int number;
	int power;
	struct num *next;
};

void BuildPoly (struct num *hi, FILE *fo)
//this is a function to build a poly from the other file,, one file consist of one poly
{
	if (fo==NULL)
	//this if statement is to make sure the file is exist and not empty
	{
		printf("Error");
		exit(1);
	}
	
	while (!feof(fo))
	//this while loop is to read the file and making it as an input. It will stop when it reached the end of the file 
	{
		hi->next=(struct num*)malloc(sizeof(struct num));
		hi=hi->next; //the first node is empty and just storing the address of the second node. Starting from the second node, it will store the poly
		fscanf(fo,"%d %d",&hi->number,&hi->power);
		hi->next=NULL;
	}
}

void polyadd(struct num* poly1, struct num* poly2,struct num* poly)
//this is a function to perform an addition of 2 polynomial (poly 1 and 2) and store it on the other polynomial (poly three)
{
	poly1 = poly1->next; //I store the number starting on the second node, so we will just skip to the second node.
	poly2 = poly2->next;
	
	while (poly1!=NULL && poly2!=NULL) 
	//this loop is to perform the addition and storing the left number
	{
		poly->next = (struct num*)malloc(sizeof(struct num));
		poly = poly->next; //as what i have said before, the first node will only store the addres of the next node.
		poly->next = NULL;
		// If power of 1st polynomial is greater then 2nd,
		// then store 1st as it is and move its pointer
		if (poly1->power > poly2->power)
		{
			poly->power = poly1->power;
			poly->number = poly1->number;
			poly1 = poly1->next;
		}
		// If power of 2nd polynomial is greater then 1st,
		// then store 2nd as it is and move its pointer
		else if (poly1->power < poly2->power)
		{
			poly->power = poly2->power;
			poly->number = poly2->number;
			poly2 = poly2->next;
		}
		// If power of both polynomial numbers is same then we add their coe
		else
		{
			poly->power = poly1->power;
			poly->number = poly1->number + poly2->number;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
	}
	while (poly1!=NULL || poly2!=NULL)
	//this is to handle the case when one of the poly have less number than the other.
	//no addition here, just storing the left number.
	{
		poly->next = (struct num*)malloc(sizeof(struct num));
		poly = poly->next;
		poly->next = NULL;
		
		if(poly1==NULL && poly2==NULL)
		{
			break;
		}
		else if(poly1!=NULL)
		{
			poly->power = poly1->power;
			poly->number = poly1->number;
			poly1 = poly1->next;
		}
		else if(poly2!=NULL)
		{
			poly->power = poly2->power;
			poly->number = poly2->number;
			poly2 = poly2->next;
		}
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

int main()
//basically just calling every function
{
	struct num one, two, three;//making the linked list that will store all of our poly
	
	FILE *fo=fopen("polynomial1.txt","r");
	FILE *ft=fopen("polynomial2.txt","r");
	
	BuildPoly(&one,fo);
	BuildPoly(&two,ft);
	
	printf("First Poly:\n");
	Print_Poly(&one);
	
	printf("\n\nSecond Poly:\n");
	Print_Poly(&two);
	
	printf("\n\nAdd Poly:\n");
	polyadd(&one,&two,&three);
	Print_Poly(&three);
}
