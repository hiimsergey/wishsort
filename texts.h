#ifndef TEXTS_H
#define TEXTS_H

#define WELCOME_MESSAGE \
    "\033[0;33mwishsort v0.1.1 <https://github.com/hiimsergey/wishsort>\n" \
    "Type /help for an explanation of the program.\n" \
    "Type /commands to see available commands.\033[0;0m"

#define HELP_MESSAGE \
    "\033[0;33mwishsort - create hierarchies of multiple items through simplified comparisons\n" \
    "\n" \
    "When starting out, type whatever you want line-by-line and it gets added\n" \
    "to the list. Type /start to repeatedly get a selection of two of those\n" \
    "items that you need to choose from based on your criteria.\n" \
    "In the end, the program logs the full list sorted by your criteria in\n" \
    "descending order.\033[0;0m"

#define INSERT_MODE_COMMANDS \
    "\033[0;33m/commands  print this message\n" \
    "/help      what is this place?\n" \
    "/log       print all items\n" \
    "/start     proceed with sorting items\n" \
    "/quit      self-explanatory\033[0;0m"

#define SORT_MODE_COMMANDS \
    "\033[0;33m1          first option is higher (acc. to your criteria)\n" \
    "2          second option is higher (acc. to your criteria)\n" \
    "/commands  print this message\n" \
    "/help      what is this place?\n" \
    "/quit      self-explanatory\n\033[0;0m"

#endif
