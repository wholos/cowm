C=gcc
CFLAGS=-o cowm -DWLR_USE_UNSTABLE -I/usr/include/wlroots-0.18  -I/usr/include/pixman-1  -I. -lwlroots-0.18 -lwayland-server -lxkbcommon -lpixman-1

all:
	@echo "Build..."
	@$(C) $(CFLAGS) cowm.c

clean:
	@echo "Clean..."
	@rm cowm

run: all
	@weston --width=1024 --height=768 --use-pixman &
	@sleep 2
	@WAYLAND DISPLAY=wayland-1 ./cowm
