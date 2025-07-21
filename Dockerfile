FROM ubuntu:noble-20240429

COPY \
  CMakeLists.txt \
  String.cxx \
  String.hxx \
  Test.cxx \
  ./

RUN \
  apt-get update --assume-yes && \
  apt-get install --assume-yes cmake g++ git

RUN \
  mkdir build && \
  cd build && \
  cmake ../ && \
  make && \
  cp ./test ../

ENTRYPOINT [ "./test" ]
