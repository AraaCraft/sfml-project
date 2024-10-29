#!/bin/bash

# Source the environment configuration
source ./config.sh

# File to compile, default to src/main.cpp if not provided
FILE="${1:-src/main.cpp}"

# Check if filename is provided
if [[ -z "$FILE" ]]; then
    echo "Usage: $0 <file.cpp> [executable_name]"
    echo "Argument 1 (required): <file.cpp>"
    echo "Argument 2 (optional): executable_name"
    exit 1
fi

# Check if an executable name is provided
if [[ -z "$2" ]]; then
    OUTPUT="${OUTPUT_DIR}/$(basename "${FILE}" .cpp)"
else
    OUTPUT="${OUTPUT_DIR}/$2"
fi

# Create output directory if it does not exist
mkdir -p "${OUTPUT_DIR}"

# Compile command
${CXX} ${DIAGNOSTICS} ${STD} "${FILE}" -I${INCLUDE_DIR} -L${LIB_DIR} ${LIBS} -o "${OUTPUT}"

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Compilation succeeded : ${OUTPUT}${NC}"
else
    echo -e "${RED}Compilation error.${NC}"
    exit 1
fi


# #!/bin/bash

# # Color definitions to output colored text
# GREEN='\033[0;32m'
# RED='\033[0;31m'
# NC='\033[0m' # No color

# CXX=g++  # Compiler
# STD="-std=c++17"  # C++ standard
# DIAGNOSTICS="-fdiagnostics-color=always"
# INCLUDE_DIR="/usr/include/SFML"  # SFML include path
# LIB_DIR="/usr/lib"  # Libraries path
# LIBS="-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lsfml-network"  # Libraries to use
# OUTPUT_DIR="build"  # Output directory
# FILE="${1:-src/main.cpp}"  # File to compile, default to src/main.cpp if not provided

# # Check if filename is provided
# if [[ -z "$FILE" ]]; then
#     echo "Usage: $0 <file.cpp> [executable_name]"
#     echo "Argument 1 (required): <file.cpp>"
#     echo "Argument 2 (optional): executable_name"
#     exit 1
# fi

# # Check if an executable name is provided
# if [[ -z "$2" ]]; then
#     OUTPUT="${OUTPUT_DIR}/$(basename "${FILE}" .cpp)"  # Default name bases on filename
# else
#     OUTPUT="${OUTPUT_DIR}/$2"  # Assign the executable name
# fi

# # Creates output directory if it does not exist yet
# mkdir -p "${OUTPUT_DIR}"

# # Compile command
# ${CXX} ${DIAGNOSTICS} ${STD} "${FILE}" -I${INCLUDE_DIR} -L${LIB_DIR} ${LIBS} -o "${OUTPUT}"

# # Check if compilation succeeded
# if [ $? -eq 0 ]; then
#     echo -e "${GREEN}Compilation succeeded : ${OUTPUT}${NC}"
# else
#     echo -e "${RED}Compilation error.${NC}"
#     exit 1
# fi
