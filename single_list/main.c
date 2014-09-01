#include "single_list.h"
#include <stdlib.h>
int main()
{
	PNode head = init_slist();
	PNode tail = return_tail(head);
	insert_h_slist(head, tail, 1);
	insert_h_slist(head, tail, 2);
	insert_h_slist(head, tail, 3);
	insert_t_slist(head, tail, 4);
	delete_node(head, tail, 3);
	insert_d_slist(head, tail, 4, 2);
	show_slist(head);
	free_slist(head);
	system("pause");
	return 0;
}