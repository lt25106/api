FROM gcc:latest
WORKDIR /
COPY . /
CMD ["bash", "-c", "g++ main.cpp -I. -Iasio && ./a.out"]