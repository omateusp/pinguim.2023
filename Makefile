run:
	@- cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -S. -Bbuild -G "Unix Makefiles"
	@- cd build && make
	@- cd build && ./penguins-game

install:
	- sudo apt update
	- sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev gcc
	- sudo snap install cmake --classic
	