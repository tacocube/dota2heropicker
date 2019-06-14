# Dota 2 Hero Picker
Find out about Dota 2 heroes that might suit you but seldom played by you.

## Dependencies
- [Pistache](http://pistache.io/) ([github](https://github.com/oktal/pistache))
- [libcurl](https://curl.haxx.se/libcurl/) ([github](https://github.com/curl/curl))
- [RapidJSON](http://rapidjson.org/) ([github](https://github.com/Tencent/rapidjson/))

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

All required extensions like "C/C++", "CMake" and "CMake Tools" are already installed inside docker, so developers do not need to install extensions themselves.