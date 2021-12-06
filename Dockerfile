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

COPY . sources 
RUN echo $(ls sources)
RUN cd sources && \
    cmake -B ./build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build ./build --target install

ENTRYPOINT [ "JackOLector" ]