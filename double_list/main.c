#include "double_list.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	PNode head = init_dlist();
	PNode tail = return_tail(head);
	insert_h_list(head, tail, 1);
	insert_h_list(head, tail, 2);
	show_list(head);
	free_list(head);

	system("pause");
	return 0;
}