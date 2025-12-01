FROM gcc:latest
RUN apt update && apt install -y libssl-dev
WORKDIR /app
COPY . .
RUN g++ main.cpp -I. -Iasio -lssl -lcrypto -std=c++20 -o server
EXPOSE 8000
CMD ["./server"]