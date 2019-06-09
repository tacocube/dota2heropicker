# Dota 2 Hero Picker
Find out about Dota 2 heroes that might suit you but seldom played by you.

## How to Build
To build from source, cmake is required.
Windows is not supported because pistache cannot run on Windows platform.

```
mkdir build
cd build
cmake ..
make
```

## For Developers
### Visual Studio Code
Developers can use Visual Studio Code's "Remote - Containers" extension to set up a docker environment for development.

1. Install Docker.
2. Install Visual Studio Code.
3. Install Remote - Containers extension.
4. Open this repository from Visual Studio Code.
5. From Visual Studio command-palette, do `Remote-Containers: Reopen Folder in Container`

After Visual Studio creates a docker container and opens this repository inside the container, the source can be built with `cmake`.

```
# If there is no build directory, create one.
mkdir build
cd build

# Use debug build type.
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```