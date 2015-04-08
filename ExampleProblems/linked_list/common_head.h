#ifndef __COMMON_HEAD_H_
#define __COMMON_HEAD_H_

/* Common Headers */
#include <stdio.h>
#include <stdlib.h>

#define WHERE printf("Func:[%s]\tLine:[%d]\n", __func__, __LINE__)

/* Linked List definition */
typedef struct node {
	int data;
	struct node *link;
} NODE;

/* Function Declarations */
NODE *add_element(int value, NODE *head);
NODE *get_new_node(NODE *temp);
void print_list(NODE *head);

#endif
