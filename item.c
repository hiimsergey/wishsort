#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

Item *Item_new() {
    Item *item = malloc(sizeof(Item));
    item->value = NULL;
    item->next = NULL;
    return item;
};

void Item_append(Item *items, const char *value) {
    Item *h = items;
    while (h->next) h = h->next;
    h->next = Item_new();
    h->next->value = strdup(value);
    h->next->next = NULL;
};

void Item_log(const Item *items) {
    Item *h = items->next;
    while (h) {
        puts(h->value);
        h = h->next;
    }
};

void Item_free(Item *items) {
    Item *h = items;
    while (h) {
        Item *next = h->next;
        free(h->value);
        free(h);
        h = next;
    }
};
