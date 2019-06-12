FROM ubuntu:latest

ARG CMAKE_VERSION=3.14
ARG CMAKE_BUILD=5
ARG CURL_VERSION=7.65
ARG CURL_BUILD=1

RUN apt-get update && \
    apt-get upgrade --yes && \
    apt-get install --yes \
        autoconf \
        build-essential \
        gdb \
        git \
        libssl-dev \
        pkg-config \
        wget

# Install CMake.
WORKDIR /usr/local
RUN wget "https://github.com/Kitware/CMake/releases/download/v3.14.5/cmake-$CMAKE_VERSION.$CMAKE_BUILD-Linux-x86_64.tar.gz" \
        -O cmake.tar.gz
RUN tar xzf cmake.tar.gz --strip 1

# Install libcurl.
# Requires autoconf, automake, libtool, libssl.
WORKDIR /usr/local/src
RUN wget "https://curl.haxx.se/download/curl-$CURL_VERSION.$CURL_BUILD.tar.gz" -O curl.tar.gz
RUN tar xzf curl.tar.gz
WORKDIR /usr/local/src/curl-$CURL_VERSION.$CURL_BUILD
RUN ./configure --with-ssl && make -j4 && make install

# Install Pistache.
WORKDIR /usr/local/src
RUN git clone "https://github.com/oktal/pistache.git"
WORKDIR /usr/local/src/pistache
RUN git submodule update --init
RUN mkdir build
WORKDIR /usr/local/src/pistache/build
RUN cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
RUN make -j4 && make install

# Install RapidJSON.
WORKDIR /usr/local/src
RUN git clone "https://github.com/Tencent/rapidjson.git"
WORKDIR /usr/local/src/rapidjson
RUN mkdir build
WORKDIR /usr/local/src/rapidjson/build
RUN cmake -DCMAKE_BUILD_TYPE=Release ..
RUN make -j4 && make install

ENV SHELL /bin/bash