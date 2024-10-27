# SFML Project

## Overview

This project is a mentored initiative aimed at exploring the C++ programming language through the use of the Simple and Fast Multimedia Library (SFML). The goal is to build a solid foundation in C++ while leveraging SFML to create engaging multimedia applications.

## Table of Contents

- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)

## Getting Started

To get started with this project, you'll need to set up your development environment. Follow the instructions below to install the necessary tools and dependencies.

## Prerequisites

- C++17 or higher
- SFML 2.6.1 or higher
- A compatible IDE or text editor (e.g., Visual Studio, Code::Blocks, or Visual Studio Code)

## Installation
### Linux
- ### Arch Linux

If you are using Arch based distribution, you can easily set up SFML the project by running the following commands:

```bash
chmod +x arch-requirements.sh compile.sh # Gain execution access to these both files
./arch-requirements.sh
```

### Building and running the project
After the setup of SFML is complete (its include folder should be located at **/usr/include/SFML** and its libraries should be located at **/usr/lib**, with a name like). You can now compile the project.

```bash
./compile.sh # Compile the project. Can provide two optionnal args :
# - Arg 1 : Filename (its path)
# - Arg 2 : The executable name
```

You can now run the project
```bash
build/main # Or build/Arg 2's value if you gave an executable name
```