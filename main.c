/* 
 * File:   main.c
 * Author: xetk
 *
 * Created on October 3, 2013, 6:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Sprite.h"

#define TRUE 1
#define FALSE 0

/*
 * 
 */
int main(int argc, char** argv) {

    int i;
    
    for (i =0;i<5;i++)
        add_new_sprite();
    
    struct generic_sprite *gs = glob_sprite;
    while (TRUE)
    {

        
        printf("%i\n",gs->id);
        
        gs = gs->next_sprite;
        if (gs == NULL)
            gs = glob_sprite;
    }
    return (EXIT_SUCCESS);
}

