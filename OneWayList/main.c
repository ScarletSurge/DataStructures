#pragma once

#include <stdio.h>
#include "list.h"

#define LIST_ITEMS_SEPARATOR " -> "

int main()
{
	list l;
	listItemRemovingMetadata metadata;
	createList(&l);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	insertAtTheListBeginning(&l, 10);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	insertAtTheListEnd(&l, 20);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	insertAtTheListBeginning(&l, 5);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	insertAtTheListEnd(insertAtTheListEnd(&l, 8), 9);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	insertIntoTheListByPosition(&l, 85, 6);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	removeFromTheListBeginning(&l, &metadata);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	removeFromTheListEnd(&l, &metadata);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	removeFromTheListByPosition(&l, 1, &metadata);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	removeFromTheListByPosition(&l, 2, &metadata);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	removeFromTheListByPosition(&l, 0, &metadata);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	removeList(&l);
	printList(&l, stdout, LIST_ITEMS_SEPARATOR); printf("\n");
	return 0;
}