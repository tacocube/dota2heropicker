FROM ubuntu:latest

ARG CMAKE_VERSION=3.14
ARG CMAKE_BUILD=5

RUN apt-get update && \
    apt-get upgrade --yes && \
    apt-get install --yes \
        build-essential \
        gdb \
        git \
        wget

# Install CMake.
ADD https://github.com/Kitware/CMake/releases/download/v3.14.5/cmake-$CMAKE_VERSION.$CMAKE_BUILD.tar.gz /usr/local/src/cmake.tar.gz
WORKDIR /usr/local/src
RUN tar xzvf cmake.tar.gz
WORKDIR /usr/local/src/cmake-$CMAKE_VERSION.$CMAKE_BUILD
RUN ./bootstrap && make && make install

# Install Pistache.
WORKDIR /usr/local/src
RUN git clone "https://github.com/oktal/pistache.git"
WORKDIR /usr/local/src/pistache
RUN git submodule update --init
RUN mkdir build
WORKDIR /usr/local/src/pistache/build
RUN cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
RUN make
RUN make install
ENV SHELL /bin/bash