# ----------------------------
# Makefile Options
# ----------------------------

NAME = MANDELB
ICON = icon.png
DESCRIPTION = "Mandelbrot fractals on your 84+ CE"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
