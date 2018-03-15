#include <stdio.h>
#include <string.h> //define for strcpy and strcmp functions

int min_pos(int ar[],int size) // find the position of the min value in array
{
	int min = ar[0],pos = 0;
	for(int i = 1;i<size;i++)
	{
		if(ar[i]<min)
		{		
		min = ar[i];
		pos = i;
		}
	}
	return pos;
}

void simple_selection_sort(int A[],int B[],int size) //simple selection sort
{	
	for(int i = 0;i<size;i++)
	{
		B[i] = A[min_pos(A,size)];
		A[min_pos(A,6)] = 9999;	
	}
}

int min_pos_for_simple(int ar[],int first,int size)//find min index for selection sort
{
	int min =ar[first], min_pos = first;
	
	for(int i = first + 1 ; i<=size ;i++)
	{
		if(ar[i] < min)
		{
			min = ar[i];
			min_pos = i;
		}
		
	}
	//printf("Min index: %d\n",min_pos);
	return min_pos;
	
}

void swap(int *x, int *y) // swap elemnts of array
{
	int tmp;
	
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void selection_sort(int A[],int size) // selection sort
{
	int tmp,min_index;
	for(int i = 0;i<size;i++)
	{
		
		min_index = min_pos_for_simple(A,i,size-1);
		if(i!=min_index)
		{				
		swap(&A[i], &A[min_index]);
		}
	}
	
}

void bubble_sort(int A[],int n) // bubble sort 1
{
	int i,j;
	
	for(i = 0;i<n-1;i++)
		for(j = 0;j<n-i-1;j++)			
				if(A[j]>A[j+1])
					swap(&A[j],&A[j+1]);				
}

void bubble_sort_new(int A[],int n) // bubble sort new with less loop
{
	int i,j,status;	
	do{
		status = 0;
			for(i = 0;i<n-1;i++)
				if(A[i]>A[i+1])
				{
					swap(&A[i],&A[i+1]);
					status = 1;
				}
	}while(!status);
	
}

void swap_str(char *str1, char *str2)
{
	char tmp[20];
	strcpy(tmp,str1);
	strcpy(str1,str2);
	strcpy(str2,tmp);
}
void bubble_sort_str(char ar[][20],int n) //bubble sorting with string values
{
	int status;
	
	do{
		status = 1;
		for(int i = 0;i<n-1;i++)
			if(strcmp(ar[i],ar[i+1])>0)
			{
				swap_str(ar[i],ar[i+1]);
				status = 0;
			}
		
	}while(!status);
}

int main()
{
	int A[] = {1,3,2,6,5,9}, B[] = {7,4,13,10},C[6];
	char ch[][20] = {"Selam","Ahmet","Mehmet","Kamil","Zeynep"}; //unordered char array with alphabetically
	
	
	/*simple_selection_sort(A,C,6); 
	for(int i = 0;i<6;i++)
	printf("%d ",C[i]);	*/
	
	
	selection_sort(B,4);	
	for(int i = 0;i<4;i++)
		printf("%d ",B[i]); 
	
	
	//printf("Min value: %d",B[min_pos(B,(sizeof B)/4)]); // print the minimum value in B
	//bubble_sort(A,6); //this function makes 21 steps  
	
	//bubble_sort_new(A,6); // this function makes 18 steps so this is better then bubble_sort function
	/*for(int i = 0;i<6;i++)
		printf("%d ",A[i]);*/		
		
/*	bubble_sort_str(ch,5); //bubble sort for string arrays
	for(int i = 0;i<5;i++) // print values in char array loop
		printf("%s ",ch[i]); */
	
	return 0;
}
