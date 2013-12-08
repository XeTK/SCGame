/* 
 * File:   Sprite.h
 * Author: xetk
 *
 * Created on October 3, 2013, 6:55 PM
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef SPRITE_H
#define	SPRITE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    struct generic_sprite
    {
        int    id;
        int    x;
        int    y;
        int    width;
        int    height;
        int    health;
        
        struct generic_sprite *next_sprite;
        struct generic_sprite *last_sprite;
    };
    
    struct generic_sprite *glob_sprite;
    
    void add_new_sprite();
    
    void move_left       (struct generic_sprite *gsprite);
    void move_right      (struct generic_sprite *gsprite);
    void move_up         (struct generic_sprite *gsprite);
    void move_down       (struct generic_sprite *gsprite);
    void dec_health      (struct generic_sprite *gsprite, int decrement_by);
    void inc_health      (struct generic_sprite *gsprite, int increment_by);
    void get_sprite_by_id(struct generic_sprite *gsprite, int id);
    
    int  is_dead         (struct generic_sprite *gsprite);
    int  no_sprites      ();
    int  no_alive        ();
    int  no_dead         ();
    int  no_state        (int alive_dead);

#ifdef	__cplusplus
}
#endif

#endif	/* SPRITE_H */

