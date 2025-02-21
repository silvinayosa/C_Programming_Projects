#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
//making a struct node to form a linked list
{
	char first_name[10];
	char second_name[10];
	int id;
	int grade;
	struct node *next;
};

struct node data;

void Build(struct node *hi, FILE *fo)
//func to create linked list from the input file.
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
		hi->next=(struct node*)malloc(sizeof(struct node));
		hi=hi->next; //the first node is empty and just storing the address of the second node. Starting from the second node, it will store the data
		fscanf(fo,"%s %s %d %d",&hi->first_name,&hi->second_name,&hi->id,&hi->grade);
		hi->next=NULL;
	}

}

void Print(struct node *l)
//func to print the whole linked list
{
	l=l->next; //because the first node is empty, so we will just continue to the next node
	while(l!=NULL)
	//this while loop is to print the data and it will stop when it have no value left.
	{
		printf("%s %s\t%d\t%d\n",l->first_name,l->second_name,l->id,l->grade);
		l=l->next;
	}
}

void Copy(struct node *hi,int data[])
//copying the id from each nodes in linked list to the new array
{
	int i=0;//as the counter/index of the array
	
	while(hi->next!=NULL)
	//loop to copy the id from linked list to array
	//this loop will stop when the linked list is already null
	{
		hi=hi->next;//move to the next node
		data[i]=hi->id;//assigning
		i++;//move to the next index of array
	}
	data[i]=NULL;
}

void Print2(int data[])
//function to print the array
//this function is only to check previous function
{
	int i=0;
	while(data[i])
	{
		printf("%d\t",data[i]);
		i++;
	}
}

int Count(struct node *l)
//function to count the amount of nodes (data) in the linked list
{
	l=l->next; //first node is empty
	int count=0;
	
	while(l!=NULL)
	//creating a loop to count, it will stop after the linked list stop.
	{
		count++; //adding the counter
		l=l->next; //moving to the next node
	}
	return count;
}

void heapify(int arr[], int n, int i)
//recursive function to find the largest value among root, left child and right child
{
	int largest = i;//variable to store the index with largest value (start from root)
	int left = 2 * i + 1; //counting the index of left subtree
	int right = 2 * i + 2; //counting the index of right subtree
	int tmp;
	
	if (left < n && arr[left] > arr[largest]) 
	//if statement to compare the current largest value with the left subtree
    {largest = left;}
	
	if (right < n && arr[right] > arr[largest])
	// if statement to compare the current largest value with the right subtree
  	{largest = right;}
	  
	if (largest != i) 
	//if statement to swicth the value if the root is not the largest value.
	{
		tmp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=tmp;
		heapify(arr, n, largest);//recursion, calling itself for the rest subtree
	}
  
}
  
void heapSort(int arr[], int n)
//main function to perform heapsort
{
	int tmp;//temp variable to store data while swapping
	
	int i=(n/2)-1;
	while (i>=0)
	{
		heapify(arr, n, i);
		i--;
	}
	
	i=n-1;
	while(i>=0)
	{
		tmp=arr[0];
		arr[0]=arr[i];
		arr[i]=tmp;
		heapify(arr, i, 0);
		i--;
	}
  
}

void Match(struct node *l,int data[])
//function to match the id in node with the sorted id in array
{
	struct node *tmp,*hi;//one to store the current node while swapping and one that works like index to compare
	int i=0;//index of the array
	
	l=l->next;//skip the first node as it is empty!
	
	while(l!=NULL&&data[i]!=NULL)
	//a function that will keep checking and will only stop if all of the node is already correct
	{
		hi=l;//the index will also start from l as well.
		
		while (hi->id!=data[i])
		//loop to find the correct data
		{
			hi=hi->next;
		}
		
		if(hi->id!=l->id&&hi->id==data[i])
		//if statement to swap the place after it find the correct data
		{
			tmp=hi;
			hi=l;
			l=tmp;
		}
		
		l=l->next;
		i++;
		
	}
}

int main()
{
	FILE *fo=fopen("student.txt","r");
	Build(&data,fo);
	int size=Count(&data);
	printf("The old data is:\n");
	Print(&data);
	//input data from the file, build the linked list and count the number of data stored.
	
	int ids[size-1];
	Copy(&data,ids);
	//making new array and copy the id from linked list into it.
	
	heapSort(ids,size);
	printf("\n\nThe sorted id is:");
	Print2(ids);
	/*Match(&data,ids);
	Print(&data);*/
	//sorting the array and matching the id in linked list with the sorted array.
	
	return 0;
}
