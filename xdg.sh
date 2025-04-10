#!/bin/bash
WAYLAND_PROTOCOLS=$(pkg-config --variable=pkgdatadir wayland-protocols)
WAYLAND_SCANNER=$(pkg-config --variable=wayland_scanner wayland-scanner)
$WAYLAND_SCANNER client-header \
    $WAYLAND_PROTOCOLS/stable/xdg-shell/xdg-shell.xml \
    ./xdg-shell-protocol.h
