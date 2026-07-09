FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential cmake ninja-build qt6-base-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .
RUN cmake -S . -B build -G Ninja || true
CMD ["/bin/bash"]
