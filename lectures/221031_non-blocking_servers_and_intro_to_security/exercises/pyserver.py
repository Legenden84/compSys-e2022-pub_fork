import socket
import sys

ip = sys.argv[1]
port = int(sys.argv[2])

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    print("Server is running...")
    print("ip: ", ip)
    print("port: ", port)
    server_socket.bind((ip, port))
    server_socket.listen()
    while True:
        connection, connection_address = server_socket.accept()
        with connection:
            message = connection.recv(1024)
            if not message:
                break
            print(f"Message recieved: {message.decode}")
            if message.decode() == "ping\n":
                connection.sendall(bytearray("pong\n".encode()))
            else:
                connection.sendall(bytearray("BAD_REQUEST\n".encode()))
        connection.close()