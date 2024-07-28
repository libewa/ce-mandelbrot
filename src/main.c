#include <graphx.h>
#include <stdlib.h>

int main(void)
{
    /* Initialize graphics drawing */
    gfx_Begin();

    for (int x = 0; x < GFX_LCD_WIDTH; x++)
    for (int y = 0; y < GFX_LCD_HEIGHT; y++) {
        // Do something with the pixels
    }

    /* End graphics drawing */
    gfx_End();

    return 0;
}
