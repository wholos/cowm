# cowm
Wayland Compositor

How to install!?
``` bash
sudo pacman -S git make gcc wayland wlroot pixbuf pixman wayland-protocols
git clone https://github.com/wholos/cowm/
cd cowm/
chmod +x xdg.sh
./xdg.sh
make all
```

How to test!?
``` bash
sudo pacman -S weston
make run
```
