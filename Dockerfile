FROM debian:bookworm-slim
RUN apt update
RUN apt install -y supervisor g++ libssl-dev nodejs npm python3-pip
RUN pip install --break-system-packages fastapi uvicorn requests
WORKDIR /app
COPY . .
COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf
WORKDIR /app/js
RUN npm install
WORKDIR /app/c++
RUN g++ main.cpp -I. -Iasio -lssl -lcrypto -std=c++20 -o server.out
EXPOSE 8000 3000 5000
CMD ["supervisord", "-n"]