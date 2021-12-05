FROM didstopia/msbuild

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