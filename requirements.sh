#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# Check if build directory exists
if [ ! -d build ]; then
    # Make the directory build
    mkdir build
fi

# Downlading SFML
# macOS
if [[ "$(uname)" == "Darwin" ]]; then
    if [[ ! -x "$(command -v brew)" ]]; then
        echo -e "${RED}Homebrew is not installed. Please install Homebrew first : ${NC}https://brew.sh/"
        exit 1
    fi
    brew install sfml
elif [[ "$(uname)" == "Linux" ]]; then
    # Arch Linux
    if [[ "$(grep '^ID=' /etc/os-release | cut -d= -f2)" == "arch" ]]; then
        sudo pacman -S sfml
    else
        echo -e "${RED}SFML installation instructions for your distribution are not provided. Please install SFML manually.${NC}"
        echo -e "${GREEN}SFML installation instructions : ${NC}https://www.sfml-dev.org/tutorials/2.6/start-linux.php"
    fi
else
    echo -e "${RED}SFML installation instructions for your operating system are not provided. Please install SFML manually.${NC}"
    echo -e "${GREEN}SFML installation instructions : ${NC}https://www.sfml-dev.org/download.php"
fi
