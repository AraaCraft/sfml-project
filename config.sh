# config.sh

# Color definitions for colored output
export GREEN='\033[0;32m'
export RED='\033[0;31m'
export NC='\033[0m'  # No color

# Compiler settings
export CXX=g++
export STD="-std=c++17"
export DIAGNOSTICS="-fdiagnostics-color=always"

# Set paths depending on OS
if [[ "$(uname)" == "Darwin" ]]; then
    # macOS paths
    export INCLUDE_DIR="/opt/homebrew/Cellar/sfml/2.6.1/include"
    export LIB_DIR="/opt/homebrew/Cellar/sfml/2.6.1/lib"
elif [[ "$(uname)" == "Linux" ]]; then
    # Linux paths
    export INCLUDE_DIR="/usr/include/SFML"
    export LIB_DIR="/usr/lib"
fi

# Libraries and output settings
export LIBS="-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lsfml-network"
export OUTPUT_DIR="build"
