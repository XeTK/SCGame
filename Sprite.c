#include "Sprite.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//Global variables, sometimes it makes it tidier...

int no_sprite = 0;

//Global sprites.

/*
 * This adds a new sprite to a linked list,
 * this linked list is used to keep track of all the sprites within the game.
 */

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
    no_sprite = i;
}

/* 
 * This method gets the number of sprites that are alive or dead,
 * it takes a boolean to determin if we want to check dead sprites
 * or alive. 
 * 
 * ALIVE = FALSE
 * DEAD  = TRUE
 */

int no_state(int alive_dead)
{
    int total = 0;
    
    if (glob_sprite != NULL)
    {
        struct generic_sprite *gs = glob_sprite;
        while (TRUE)
        {
            if (is_dead(gs) == alive_dead)
                total++;

            gs = gs->next_sprite;
            if (gs == NULL)
                break;
        }
    }
    return total;  
}

//individual 

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

//Get-Sets go here.

int no_sprites()
{
    return no_sprite;
}
int no_alive()
{
    return no_state(FALSE);
}
int no_dead()
{
    return no_state(TRUE);
}