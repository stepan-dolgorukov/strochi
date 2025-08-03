FROM ubuntu:noble-20240429
LABEL org.opencontainers.image.authors=["Stepan Dolgorukov <stepan.dolgorukov@vk.com>"]

COPY \
  CMakeLists.txt \
  String.cxx \
  String.hxx \
  Test.cxx \
  Sort.cxx \
  ./

RUN \
  apt-get update --assume-yes && \
  apt-get install --assume-yes cmake g++ git

RUN \
  mkdir build && \
  cd build && \
  cmake ../ && \
  make test && \
  mv ./test ../

ENTRYPOINT [ "./test" ]
