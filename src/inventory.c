#include "inventory.h"
#include "screen.h"
#include "item.c"
#include <stdlib.h>

struct inventory inventory;

void open_inventory()
{
    inventory.is_opened = 1;
    print_inventory();
}

void init_inventory()
{
    inventory.weapons = calloc(1, sizeof(item_weapon *));
    inventory.weapons[0] = sword;
}