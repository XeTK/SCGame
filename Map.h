/* 
 * File:   Map.h
 * Author: xetk
 *
 * Created on 21 November 2013, 17:32
 */

#ifndef MAP_H
#define	MAP_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct lev_y_plane{
        struct generic_block *block;
        struct lev_y_plane   *right_plane;
        struct lev_y_plane   *left_plane;
    };
    
    struct lev_x_plane{
        struct lev_y_place *first_y;
        struct lev_x_plane *top_plane;
        struct lev_x_plane *bottom_plane;
    };
    
    struct level_map {
       struct lev_x_plane *first_x;
       char   map_name[125];
    };
    
    struct level_map *cur_map;
    
    void add_new_block(int x, int y);
    void get_block    (struct generic_block *block);
    void load_map     ();

#ifdef	__cplusplus
}
#endif

#endif	/* MAP_H */

