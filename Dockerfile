FROM debian:bookworm-slim
RUN apt update && apt install -y supervisor g++ libssl-dev nodejs npm
WORKDIR /app
COPY . .
COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf
WORKDIR /app/c++
RUN g++ main.cpp -I. -Iasio -lssl -lcrypto -std=c++20 -o server.out
WORKDIR /app/js
RUN npm install
EXPOSE 8000 3000
CMD ["supervisord", "-n"]