# Strochi

Define a type that implements a string. Done as an exercise.

## Run tests

### Method №1
```shell
mkdir build && \
cd build && \
cmake ../ && \
make test && \
./test
```

### Method №2
```shell
docker build -t test-strochi . && \
docker run -it test-strochi
```

## Run sort program
```shell
mkdir build && \
cd build && \
cmake ../ && \
make sort && \
./sort
```
