# https://levelup.gitconnected.com/how-to-combine-c-cmake-googletest-circleci-docker-and-why-e02d76c060a3
FROM ubuntu:focal
LABEL description="Basic C++ stuff for CircleCi repo." \
      version="0.1.0"

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update -y && \
    apt-get install -y tzdata
RUN apt-get install -y --no-install-recommends\
                    git \
                    curl \
                    gcc-9 \
                    g++ \
                    clang-10 \
                    build-essential \
                    cmake \
                    wget \
                    unzip \
                    tar \
                    ca-certificates && \
    apt-get autoclean && \
    apt-get autoremove && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*