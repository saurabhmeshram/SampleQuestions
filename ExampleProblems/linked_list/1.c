#include "common_head.h"
int main (void)
{
	WHERE;
	NODE *head = NULL;
	head = get_new_node(head);
	head = add_element(10, head);
	WHERE;
	print_list(head);
	return 0;
}

NODE *add_element(int value, NODE *head)
{
	WHERE;
	if (head == NULL) { 	/* If No element */
		WHERE;
		head->data = value;
		head->link = NULL;
		return head;
	}
	return head;
}

NODE *get_new_node(NODE *temp)
{
	temp = (NODE *) malloc (sizeof(NODE));
	return temp;
}

void print_list(NODE *head)
{
	printf("Contents of List:\n");
	while(NULL != head->link)
	{
		printf("[%d]\t", head->data);
		head = head->link;
	}
	return;
}
