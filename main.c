#include <stdio.h>
#include "item.h"
#include "modes.h"
#include "texts.h"

int main() {
    puts(WELCOME_MESSAGE);

    Item *items = Item_new();

    if (insert_mode(items) == 0) sort_mode(items);
    Item_log(items);
    Item_free(items);
}
