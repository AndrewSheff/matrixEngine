#ifndef ITEM_H
#define ITEM_H

typedef enum
{
    SUPPLY,
    WEAPON,
    TOOL
} item_type;

typedef enum
{
    POISON
    //TODO надо придумать
} effect_type;

//для каждого типа свои параметры урона для каждого типа урона
typedef enum
{
    SWORD,
    KNIFE,
    DAGGER,
    HAMMER
    //TODO дополнить
} weapon_type;

typedef enum
{
    PRICKING,
    CUTING,
    HACKING,
    HITING
} damage_type;

typedef struct
{
    item_type type;
    char[32] name;
} item_base_info;

typedef struct
{
    item_base_info item;
    effect_type effect;
    int satiety;
} item_food;

typedef struct
{
    item_base_info item;
    weapon_type type;
} item_weapon;

extern item_weapon sword;

#endif