#include "Sprite.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void add_new_sprite()
{
    int i = 1;
    
    if (glob_sprite == NULL)
        glob_sprite = malloc(sizeof(struct generic_sprite));
    
    struct generic_sprite *temp = glob_sprite;
    
    while (TRUE) 
    {
        if (temp->next_sprite == NULL)
        {
            struct generic_sprite *gsprite = malloc(sizeof(struct generic_sprite));
            gsprite->id = i;
            temp->next_sprite = gsprite;
            gsprite->last_sprite = temp;
            break;
        }
        temp = temp->next_sprite;
        i++;
    }
}

void move_left(struct generic_sprite *gsprite)
{
    gsprite->x -= 1;
}
void move_right(struct generic_sprite *gsprite)
{
    gsprite->x += 1;
}
void move_up(struct generic_sprite *gsprite)
{
    gsprite->y -= 1;
}
void move_down(struct generic_sprite *gsprite)
{
    gsprite->y += 1;
}
void dec_health(struct generic_sprite *gsprite, int decrement_by)
{
    gsprite->health -= decrement_by;
}
void inc_health(struct generic_sprite *gsprite, int increment_by)
{
    gsprite->health += increment_by;
}
int is_dead(struct generic_sprite *gsprite)
{
    if (gsprite->health <= 0)
        return TRUE;
    return FALSE;
}