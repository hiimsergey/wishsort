#ifndef ITEM_H
#define ITEM_H

typedef struct Item {
    char *value;
    struct Item *next;
} Item;

// Returns a linked list with a single empty element.
Item *Item_new();

// Creates a node with a string `value` at the end of the list.
void Item_append(Item *items, const char *value);

// Prints all string `value`s from start to end.
void Item_log(const Item *items);

// Frees all nodes.
void Item_free(Item *items);

#endif
