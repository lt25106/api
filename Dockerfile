FROM gcc:latest
RUN apt update && apt install -y libssl-dev
WORKDIR /app
COPY . .
RUN g++ c++/main.cpp -Ic++ -Ic++/asio -lssl -lcrypto -std=c++20 -o c++/server.out
EXPOSE 8000
CMD ["c++/server.out"]