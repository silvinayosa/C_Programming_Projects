/*
* String Replacement Program
* Description: Takes a sentence as input and replaces a given word with another.
*/

#include <stdio.h>

int strln(char *array)
{
	int i=0;
	int res=0;
	while(array[i])
	{
		res++;
		i++;
	}
	return res;
}

void Shift_Left (char *array, int counter)
//array is the string that we want to shiftLeft
//counter is the index where you want to start shifting 
{
	int n=strln(array);
	while (counter<n)
	{
		array[counter]=array[counter+1];
		counter++;
	}
}

void Shift_Right(char *array, int counter)
//array is the string that we want to shiftRight
//counter is the index where you want to stop shifting
{
	int n=strln(array);
	while (n>counter)
	{
		array[n]=array[n-1];
		n--;
	}
}

int Str_Comp(char *words1, char *words2)
//usage: to compare 2 strings
{
	int counter=0;
	while (words1[counter] || words2[counter])
	if(words1[counter]==words2[counter])
	{
		counter++;
	}
	else
	{
		return 0;
	}
	return 1;
}

void Copy_Words(char *source, char *result, int isource, int iresult) 
//usage: copy some part of the array into the temp
{
	while (source[isource]!=' ' && source[isource]!='.' && source[isource]!='\0' && source[isource]!=',' && source[isource]!='?')
	{
		result[iresult]=source[isource];
		iresult++;
		isource++;
	}
	result[iresult]='\0';
}

void Place(char *source, char *result, int isource, int iresult, int end)
//usage: to copy a string into some part of another array
//usage 2: to copy a string into another string
{
	while (isource<end)
	{
		result[iresult]=source[isource];
		iresult++;
		isource++;
	}
}

void Replace(char *array, char *neww, char *old, int i)
//the main function of this replace program
{
	int n;
	if (strln(neww)>strln(old))
	{
		for(n=strln(neww)-strln(old);n>0;n--)
		{
			Shift_Right(array,i);
		}
		Place(neww,array,0,i,strln(neww));
	}
	else if(strln(old)>strln(neww))
	{
		for(n=strln(old)-strln(neww);n>0;n--)
		{
			Shift_Left(array,i);
		}
		Place(neww,array,0,i,strln(neww));
	}
	else
	{
		Place(neww,array,0,i,strln(neww));
	}
}

int main ()
{
	char story[1000000];
	printf("Make your story!\n");
	scanf("%[^\n]%*c",&story);
	char old[100];
	printf("The word you want to be replaced: ");
	scanf("%s",&old);
	char neww[100];
	printf("Replaced by: ");
	scanf("%s",&neww);
	char temp[100];
	int i=0;
	printf("Here is your new story!\n");
	while(story[i]!='\0')
		{
			if (story[i]==' ')
			{
				Copy_Words(story,temp,i+1,0);
				if(Str_Comp(temp,old)==1)
				{
					Replace(story,neww,old,i+1);
					i=i+strln(neww);
				}
				else //if Str_Comp == 0
				{
					i++;
				}
			}
			else //if story[i]!=' '
			{
				i++;
			}
		}
	printf("%s",story);
	return 0;
}
