#!/bin/bash

# Check if build directory exists
if [ ! -d build ]; then
    # Make the directory build
    mkdir build
fi

# Downlading SFML
sudo pacman -S sfml