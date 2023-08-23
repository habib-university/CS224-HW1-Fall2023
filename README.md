## Build using CMake (a more modern and portable approach)
Please ensure you have gcc and cmake installed. You can check this by opening Powershell and typing:
 - `cmake --version` this should output the version of CMake
 - `gcc --version` this should tell you the version of gcc

If cmake isn't installed, follow the instructions here:
- Install cmake from the following link https://cmake.org/download/. To test if cmake has been installed properly run `cmake --version` from powershell or terminal

To install gcc using mingw, you can follow the instructions from here:
- https://code.visualstudio.com/docs/cpp/config-mingw

Please don't install SDL upfront. If you have already installed SDL, try removing it completely.

Run the following commands on Powershell on Windows or terminal on Linux and MacOS.
- run `git clone https://github.com/habib-university/sdlcmake.git`
- `cd sdlcmake`
- `mkdir build`
- `cd build`
- `cmake ..`. On windows use `cmake -G "MinGW Makefiles" ..`
- `make`. On windows use `mingw-make`


# Build code using make directly
- Open this folder in VSCode
- Open VSCode terminal and put this command to compile everything:

	g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

- Run the game by this command:

	.\a.exe

