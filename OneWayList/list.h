#pragma once

#include <stdio.h>
#include <stdlib.h>

#define LIST_REMOVING_SUCCEEDED 0
#define LIST_REMOVING_FAILED_EMPTY_LIST 1

typedef unsigned int uint;
typedef int listDataType;

typedef struct listItem
{
	listDataType data;
	struct listItem *next;
} listItem, *pListItem;

typedef struct list
{
	listItem *head;
} list, *pList;

typedef struct listItemRemovingMetadata
{
	listDataType data;
	char status;
} listItemRemovingMetadata, *pListItemRemovingMetadata;

pListItem allocateListItem(listDataType itemData, pListItem nextToItem);
void deallocateListItem(pListItem itemToDeallocate);
pList createList(pList listToCreate);
pList insertAtTheListBeginning(pList listToInsertItem, listDataType itemData);
pList insertAtTheListEnd(pList listToInsertItem, listDataType itemData);
pList insertIntoTheListByPosition(pList listToInsertItem, listDataType itemData, uint position);
pList removeFromTheListBeginning(pList listToRemoveItem, pListItemRemovingMetadata metadata);
pList removeFromTheListEnd(pList listToRemoveItem, pListItemRemovingMetadata metadata);
pList removeFromTheListByPosition(pList listToRemoveItem, uint position, pListItemRemovingMetadata metadata);
void printList(pList listToPrint, FILE *stream, const char *separator);
void removeList(pList listToRemove);