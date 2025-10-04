#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"

struct inventory 
{
    item_weapon* weapons;
    item_food* foods;
    int is_opened;
    int selected_tab;
};

extern struct inventory inventory; 
void open_inventory(void);
void init_inventory(void);

#endif