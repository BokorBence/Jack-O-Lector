FROM ubuntu

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get install -y \
    gcc \
    g++ \
    gcc-multilib \
    g++-multilib \
    build-essential \
    libsdl2-dev \
    libsdl2-image-dev \
    cmake

COPY ./ ./

RUN cmake -B ./build -DCMAKE_BUILD_TYPE=Release
RUN cmake --build ./build --target install

ENTRYPOINT [ "JackOLector" ]