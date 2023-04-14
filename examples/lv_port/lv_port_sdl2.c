/**
* @file lv_port_sdl2.c
*
*/

/*********************
 *      INCLUDES
 *********************/
#include "lv_drv_conf.h"

#if USE_SDL

#include "lv_port.h"
#include "lvgl/lvgl.h"

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*********************
*      DEFINES
*********************/

/**********************
*      TYPEDEFS
**********************/

/**********************
*  STATIC PROTOTYPES
**********************/

/**********************
*  STATIC VARIABLES
**********************/

/**********************
*      MACROS
**********************/

/**********************
*   GLOBAL FUNCTIONS
**********************/
int lv_port_init(void)
{
   lv_disp_t * disp = lv_sdl_window_create(LV_SCREEN_HOR_RES, LV_SCREEN_VER_RES);
   lv_indev_t * mouse = lv_sdl_mouse_create();
   lv_indev_set_group(mouse, lv_group_get_default());
   lv_indev_set_disp(mouse, disp);

   //    LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
   //    lv_obj_t * cursor_obj;
   //    cursor_obj = lv_img_create(lv_scr_act());         /*Create an image object for the cursor */
   //    lv_img_set_src(cursor_obj, &mouse_cursor_icon);   /*Set the image source*/
   //    lv_indev_set_cursor(mouse, cursor_obj);           /*Connect the image  object to the driver*/

   lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
   lv_indev_set_disp(mousewheel, disp);
   lv_indev_set_group(mousewheel, lv_group_get_default());

   lv_indev_t * keyboard = lv_sdl_keyboard_create();
   lv_indev_set_disp(keyboard, disp);
   lv_indev_set_group(keyboard, lv_group_get_default());

   return 0;
}


void lv_port_sleep(uint32_t ms)
{
   usleep(ms * 1000);
}

/**********************
*   STATIC FUNCTIONS
**********************/

#endif /*USE_SDL*/
