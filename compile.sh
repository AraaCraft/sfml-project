#!/bin/bash

# Color definitions to output colored text
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No color

CXX=g++  # Compiler
STD="-std=c++17"  # C++ standard
DIAGNOSTICS="-fdiagnostics-color=always"
INCLUDE_DIR="/usr/include/SFML"  # SFML include path
LIB_DIR="/usr/lib"  # Libraries path
LIBS="-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lsfml-network"  # Libraries to use
OUTPUT_DIR="build"  # Output directory
FILES=$(find src -name '*.cpp')  # All .cpp files in src directory
OUTPUT="${OUTPUT_DIR}/main"  # Default output executable name

# Creates output directory if it does not exist yet
mkdir -p "${OUTPUT_DIR}"

# Compile command with all .cpp files
${CXX} ${DIAGNOSTICS} ${STD} ${FILES} -I${INCLUDE_DIR} -L${LIB_DIR} ${LIBS} -o "${OUTPUT}"

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Compilation succeeded : ${OUTPUT}${NC}"
else
    echo -e "${RED}Compilation error.${NC}"
    exit 1
fi