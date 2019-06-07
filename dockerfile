FROM ubuntu:latest AS base
RUN apt-get update && \
    apt-get upgrade --yes && \
    apt-get install --yes \
        build-essential \
        cmake

FROM base
COPY ./ /root/
WORKDIR /root
RUN mkdir build
WORKDIR /root/build
RUN cmake -G "Unix Makefiles" ..
RUN make
CMD LD_LIBRARY_PATH=/root/build/prefix/lib /root/build/prefix/bin/Dota2HeroPickerRest