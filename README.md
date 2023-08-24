# To compile your .cpp files you have the following options

## 1. Build code using the g++ compiler directly

### <span style="color:red"> Note: In order to compile using the g++ compiler you will need to install and setup SDL and the mingw library in your machine's C drive. The tutorial to install these is given in the combined OOP lecture site on Canvas (https://hulms.instructure.com/courses/3244/files/367336?module_item_id=107766).

- Open this folder in VSCode
- Open VSCode terminal and put this command to compile everything:

	`g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o odyssey.exe`

- Run the game by this command:

	`.\odyssey.exe`

## 2. Build using CMake (a more modern and portable approach)
Please ensure you have gcc and cmake installed. You can check this by opening Powershell and typing:
 - `cmake --version` this should output the version of CMake
 - `gcc --version` this should tell you the version of gcc

If cmake isn't installed, follow the instructions here:
- Install cmake from the following link https://cmake.org/download/. To test if cmake has been installed properly run `cmake --version` from powershell or terminal

To install gcc using mingw, you can follow the instructions from here:
- https://code.visualstudio.com/docs/cpp/config-mingw

Please don't install SDL upfront. If you have already installed SDL, try removing it completely.

Run the following commands on Powershell on Windows or terminal on Linux and MacOS.
- run `git clone https://github.com/habib-university/CS224-HW1-Fall2023.git`
- `cd CS224-HW1-Fall2023`
- `mkdir build`
- `cd build`
- On Linux use `cmake ..`. On windows use `cmake -G "MinGW Makefiles" ..` if you install gcc via MSYS2. If you installed gcc via strawberry perl, use `cmake -G "Unix Makefiles" ..`
- On Linux use `make`. On windows use `mingw-make` if you used MSYS2 to install gcc. If you used strawberry perl, use `gmake`
