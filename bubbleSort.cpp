// bubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define NULL	0

void mergeSort(int *A, int left, int right);
void merge(int *A, int lb, int mid, int rb);

// tree node
typedef struct nodeT
{
	struct nodeT *left;
	struct nodeT *right;
	int value;
} node;

node node1, node2, node3, node4, node5, node6, node7, nodeNull;


node * buildTree(void);
node * FindSixNode(node *root);

node * buildTree()
{
	// assign key for each node
	node1.value = 5;
	node2.value = 3;
	node3.value = 10;
	node4.value = 1;
	node5.value = 4;
	node6.value = 7;
	node7.value = 12;
	nodeNull.value = NULL;
	
	// assign children for each parent
	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.right = &node7;
	nodeNull.left = NULL;
	nodeNull.right = NULL;

	// setup the children
	node4.left = NULL;
	node4.right = NULL;
	node5.left = NULL;
	node5.right = NULL;
	node6.left = NULL;
	node6.right = NULL;
	node7.left = NULL;
	node7.right = NULL;

	// return tree parent node
	return &node1;
}


node * FindSixNode(node *root)
{

	node *curNode = root;

	while (curNode)
	{
		if (curNode->value == 4)  return curNode;

		else if (curNode->value < 4) curNode = curNode->right;
		else if (curNode->value > 4) curNode = curNode->left;
	}

	return &nodeNull;
}



/*
void bubbleSort(int *A, int size);
int A[5];

int main()
{

	int i;
	
	printf("Enter data:\n");
	for (i = 0; i < 5; i++)
		scanf("%d", &A[i]);

	bubbleSort( A, 5);

	printf("Answer=");
	for (i = 0; i < 5; i++)
		printf("%d ", A[i]);

	 return 0;
}


void bubbleSort(int *A, int n )
{
	int i, k, temp;

	for (i = 1; i <= n - 1; i++)
	{

		for (k = 0; k <= n - i - 1; k++)

			if (A[k] > A[k + 1])
			{
				temp = A[k + 1];
				A[k + 1] = A[k];
				A[k] = temp;
			}
	}
}

*/


// main to run Binary Search Tree
int main()
{
	int a = 100;
	auto b = 50;
	auto& ref_a = a;

	ref_a = b;


	node * returnParent;
	node * ans;
	
	returnParent = buildTree();
	
	ans = FindSixNode(returnParent);

	return 0;
}





#if 0
int A[] = { 10, 8, 7, 6, 1 };


int main()
{

	int *Aptr;
	int sizeofA;

	Aptr = &A[0];

	sizeofA = sizeof(A);

	mergeSort(Aptr, 0, 4);

	return 1;
}






void mergeSort(int *A, int left, int right)
{
	int middle = (left + right) / 2;


	if (left < right)
	{
		// mergesort the lower half
		mergeSort(A, left, middle);

		// mergesort the upper half
		mergeSort(A, middle + 1, right);

		// merge the halves
		merge(A, left, middle, right);
	}
}


void merge(int *A, int lb, int mid, int rb)
{
	int leftIn, midIn, arrayIn, sizeA;
	int B[5] = { 0,0,0,0,0 };

	leftIn = lb;
	midIn = mid + 1;
	arrayIn = lb;

	// go through until one of the halves is consumed.
	while (leftIn <= mid && midIn <= rb)
	{
		if( A[leftIn] <= A[midIn] )
		{
			B[arrayIn] = A[leftIn];
			leftIn++;
		}
		else
		{
			B[arrayIn] = A[midIn];
			++midIn;
		}
		arrayIn++;
	}


	if (leftIn > mid)
	{
		// copy over the remaining in right half into array
		while (midIn <= rb)
		{
			B[arrayIn] = A[midIn];
			arrayIn++;
			midIn++;
    	}

	}

	else
	{
		// copy over the remaining in left half into array
		while (leftIn <= mid)
		{
			B[arrayIn] = A[leftIn];
			arrayIn++;
			leftIn++;
		}
	}

	// copy sorted temp array into answer array
	for (arrayIn = lb; arrayIn <= rb; arrayIn++)
	{
		A[arrayIn] = B[arrayIn];
	}

//	free(B);
}

#endif


