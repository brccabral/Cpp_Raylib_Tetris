#!/bin/bash

source $EMSDK/emsdk_env.sh

emcc -o tetris.html block.cpp blocks.cpp colors.cpp game.cpp grid.cpp main.cpp position.cpp -Os -Wall $RAYLIB_INSTALL_PATH/lib/libraylib.a -I. -I$RAYLIB_INSTALL_PATH/include -L. -L$RAYLIB_INSTALL_PATH/lib -s USE_GLFW=3 -s ASYNCIFY --shell-file $RAYLIB_SRC_PATH/shell.html -DPLATFORM_WEB --preload-file resources/Sounds --preload-file resources/Font

# python -m http.server 8080
