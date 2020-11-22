#include "list.h"

// TODO: reimplement this when redefining LIST_DATA_TYPE macrodefinition
pListItem allocateListItem(listDataType itemData, pListItem nextToItem)
{
	pListItem allocated;

	allocated = (pListItem)malloc(sizeof(listItem));
	if (!allocated)
	{
		return NULL;
	}
	allocated->data = itemData;
	allocated->next = nextToItem;
	return allocated;
}

// TODO: reimplement this when redefining LIST_DATA_TYPE macrodefinition
void deallocateListItem(pListItem itemToDeallocate)
{
	free(itemToDeallocate);
}

pList createList(pList listToCreate)
{
	listToCreate->head = NULL;
}

pList insertAtTheListBeginning(pList listToInsertItem, listDataType itemData)
{
	pListItem insertedItem;

	insertedItem = allocateListItem(itemData, listToInsertItem->head);
	listToInsertItem->head = insertedItem;
	return listToInsertItem;
}

pList insertAtTheListEnd(pList listToInsertItem, listDataType itemData)
{
	pListItem insertedItem, iterator;

	if (listToInsertItem->head == NULL)
	{
		return insertAtTheListBeginning(listToInsertItem, itemData);
	}
	insertedItem = allocateListItem(itemData, NULL);
	iterator = listToInsertItem->head;
	while (iterator->next)
	{
		iterator = iterator->next;
	}
	iterator->next = insertedItem;
	return listToInsertItem;
}

pList insertIntoTheListByPosition(pList listToInsertItem, listDataType itemData, uint position)
{
	int counter;
	pListItem insertedItem, iterator, nextToInserted;

	if (listToInsertItem->head == NULL || position == 0)
	{
		return insertAtTheListBeginning(listToInsertItem, itemData);
	}
	insertedItem = allocateListItem(itemData, NULL);
	iterator = listToInsertItem->head;
	for (counter = 0; counter < position - 1; counter++)
	{
		if (iterator->next == NULL)
		{
			iterator->next = insertedItem;
			return listToInsertItem;
		}
		iterator = iterator->next;
	}
	if (iterator->next == NULL)
	{
		iterator->next = insertedItem;
		return listToInsertItem;
	}
	nextToInserted = iterator->next;
	iterator->next = insertedItem;
	insertedItem->next = nextToInserted;
	return listToInsertItem;
}

pList removeFromTheListBeginning(pList listToRemoveItem, pListItemRemovingMetadata metadata)
{
	pListItem itemToRemove;

	if (listToRemoveItem->head == NULL)
	{
		metadata->status = LIST_REMOVING_FAILED_EMPTY_LIST;
		return listToRemoveItem;
	}
	itemToRemove = listToRemoveItem->head;
	listToRemoveItem->head = itemToRemove->next;
	metadata->data = itemToRemove->data;
	metadata->status = LIST_REMOVING_SUCCEEDED;
	deallocateListItem(itemToRemove);
	return listToRemoveItem;
}

pList removeFromTheListEnd(pList listToRemoveItem, pListItemRemovingMetadata metadata)
{
	pListItem itemBeforeItemToRemove;

	if (listToRemoveItem->head == NULL)
	{
		metadata->status = LIST_REMOVING_FAILED_EMPTY_LIST;
		return listToRemoveItem;
	}
	itemBeforeItemToRemove = listToRemoveItem->head;
	if (!itemBeforeItemToRemove->next)
	{
		return removeFromTheListBeginning(listToRemoveItem, metadata);
	}
	while (itemBeforeItemToRemove->next->next)
	{
		itemBeforeItemToRemove = itemBeforeItemToRemove->next;
	}
	metadata->data = itemBeforeItemToRemove->next->data;
	metadata->status = LIST_REMOVING_SUCCEEDED;
	deallocateListItem(itemBeforeItemToRemove->next);
	itemBeforeItemToRemove->next = NULL;
	return listToRemoveItem;
}

pList removeFromTheListByPosition(pList listToRemoveItem, uint position, pListItemRemovingMetadata metadata)
{
	int counter;
	pListItem itemBeforeItemToRemove, itemNextToItemToRemove;

	if (listToRemoveItem->head == NULL)
	{
		metadata->status = LIST_REMOVING_FAILED_EMPTY_LIST;
		return listToRemoveItem;
	}
	if (position == 0)
	{
		return removeFromTheListBeginning(listToRemoveItem, metadata);
	}
	itemBeforeItemToRemove = listToRemoveItem->head;
	if (!itemBeforeItemToRemove->next)
	{
		return removeFromTheListBeginning(listToRemoveItem, metadata);
	}
	for (counter = 0; counter < position - 1; counter++)
	{
		itemBeforeItemToRemove = itemBeforeItemToRemove->next;
		if (!itemBeforeItemToRemove->next->next)
		{
			break;
		}
	}
	metadata->data = itemBeforeItemToRemove->next->data;
	metadata->status = LIST_REMOVING_SUCCEEDED;
	itemNextToItemToRemove = itemBeforeItemToRemove->next->next;
	deallocateListItem(itemBeforeItemToRemove->next);
	itemBeforeItemToRemove->next = itemNextToItemToRemove;
	return listToRemoveItem;
}

void printList(pList listToPrint, FILE *stream, const char *separator)
{
	pListItem iterator;

	if (!listToPrint->head)
	{
		fprintf(stream, "Empty list");
		return;
	}
	iterator = listToPrint->head;
	fprintf(stream, "%d", iterator->data);
	if (!iterator->next)
	{
		return;
	}
	iterator = iterator->next;
	while (iterator->next)
	{
		fprintf(stream, "%s%d", separator, iterator->data);
		iterator = iterator->next;
	}
	fprintf(stream, "%s%d", separator, iterator->data);
}

void removeList(pList listToRemove)
{
	pListItem iterator, temporary;

	iterator = listToRemove->head;
	while (iterator)
	{
		temporary = iterator;
		iterator = iterator->next;
		free(temporary);
	}
	listToRemove->head = NULL;
}