/* 
* Hash Table Implementation using Separate Chaining
* Description: A simple hash table implementation in C using linked lists to handle collisions.
*/

#include<stdio.h>
#include<stdlib.h>
#define size 11

struct node
//basic node as the chain
{
    int data;
    struct node *next;
};

struct node *chain[size];
//this one is making the hash table

int hash(int data)
//this is a function to know the location of data
{
	return data%size;
}

void insert(int value)
//this funtion is to process the input value and put it in the right place
{
    //create a newnode with value that will be attached to the main hash table
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    //finding the position
    int key = hash(value);

    //if the chain's position is still empty, we can just put it there
    if(chain[key] == NULL)
        chain[key] = newNode;
        
    //this one is to handle the collision (if the chain's position is already filled)
    else
    {
    	//we don't want to mess with the main hash table, so make a temp to store its address
        struct node *temp = chain[key];
        
        //this while loop is to go to the last value (if the chain filled more than 1 data)
        while(temp->next)
        {
            temp = temp->next;
        }
        
        //just place the input data at the end of the chain
        temp->next = newNode;
    }
}

void print()
//this function is to print the whole hash table
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d] --> ",i);
        while(temp)
        {
            printf("%d --> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
	int data, max, i=0;
	//input data: 36, 8, 15, 54, , 69, 25, 20, 47
	printf("This is a hash table with size %d\n",size);
	printf("How many number do you want to input?");
	scanf("%d",&max);
	
	//this is a loop to take input
	while(i<max)
	{
		printf("Type the input number and '-' for no number!");
		scanf("%d",&data);
		insert(data);
		i++;
	}

    print();
    return 0;
}
