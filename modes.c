#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "texts.h"

volatile sig_atomic_t ctrl_c_pressed = 0;
void ctrl_c_handler() { ctrl_c_pressed = 2; }

_Bool insert_mode(Item *items) {
    signal(SIGINT, ctrl_c_handler);

    char input[32];

    while (!ctrl_c_pressed) {
        printf("\033[0;34mwishsort/insert> \033[0;0m");

        // Using scanf would only take the first word.
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

        if (!strcmp(input, "/start")) return 0;
        if (!strcmp(input, "/quit")) break;

        if (!strcmp(input, "/commands")) puts(INSERT_MODE_COMMANDS);
        else if (!strcmp(input, "/help")) puts(HELP_MESSAGE);
        else if (!strcmp(input, "/log")) Item_log(items);
        else if (input[0] == '/') puts("invalid command!");
        else Item_append(items, input);
    }

    return 1;
};

unsigned short a_is_higher_than_b(const Item *a, const Item *b) {
    signal(SIGINT, ctrl_c_handler);
    if (!a) return 0;

    while (ctrl_c_pressed != 2) {
        printf("\033[0;36m1. %s\n2. %s\n\033[0;34mwishsort/sort> \033[0;0m", a->value, b->value);

        char input[9];
        scanf("%s", input);

        if (!strcmp(input, "1")) return 1;
        if (!strcmp(input, "2")) return 0;
        if (!strcmp(input, "/quit")) break;
        if (!strcmp(input, "/commands")) puts(SORT_MODE_COMMANDS);
        else if (!strcmp(input, "/help")) puts(HELP_MESSAGE);
        else puts("invalid command!\n");
    }

    return 2;
}

void sort_mode(Item *items) {
    if (!items->next) return;

    Item *unsorted = items->next->next,
         *cmp_prev = items,
         *moving;

    items->next->next = NULL;

    while (unsorted) {
        unsigned short sort_signal = a_is_higher_than_b(cmp_prev->next, unsorted);

        if (sort_signal == 0) {
            // Steps to insert the first item from `unsorted` before `cmp_prev`'s
            // next element.
            moving = unsorted;
            unsorted = unsorted->next;
            moving->next = cmp_prev->next;
            cmp_prev->next = moving;
            cmp_prev = items;
            continue;
        }

        // If the user typed "/quit" in the sorting prompt ...
        if (sort_signal == 2) {
            Item_free(unsorted);
            return;
        }

        cmp_prev = cmp_prev->next;
    }
};
