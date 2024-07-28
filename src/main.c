#include <graphx.h>
#include <keypadc.h>
#include <ti/ui.h>
#include <stdlib.h>

double currentX, currentY;
const double cxmin = -2;
const double cxmax = 1;
const double cymin = -1.5;
const double cymax = 1.5; 
const int maxIterations = 100;
const double limit = 100.0;

int countIterations(int x, int y) {
    double cx = cxmin + (cxmax - cxmin) / GFX_LCD_WIDTH * x;
    double cy = cymin + (cymax - cymin) / GFX_LCD_HEIGHT * y;
    double zx = 0, zy = 0;
    int i = 0;

    while (i < maxIterations && zx * zx + zy * zy < limit ) {
        double zxn = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = zxn;
        i++;
    }

    return i;
}

int main(void) {
    /* Enable the On latch to allow the user to quit the long program. */
    kb_EnableOnLatch();

    /* Initialize graphics drawing */
    gfx_Begin();
    gfx_SetDrawScreen();
    gfx_FillScreen(255);
    gfx_SetColor(0);

    os_RunIndicOn();

    for (int x = 0; x < GFX_LCD_WIDTH; x++)
    for (int y = 0; y < GFX_LCD_HEIGHT; y++) {
        if (kb_On) {
            goto end;
        }
        if (countIterations(x, y) == 100) {
            gfx_SetPixel(x, y);
        }
    }

    os_RunIndicOff();

    while (!kb_On);

    end:
    /* End graphics drawing */
    gfx_End();

    /* Disable the On latch */
    kb_ClearOnLatch();
    kb_DisableOnLatch();

    return 0;
}
