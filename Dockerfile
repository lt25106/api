FROM gcc:latest
WORKDIR /app
COPY . .
RUN g++ main.cpp -I. -Iasio -o server
EXPOSE 8000
CMD ["./server"]