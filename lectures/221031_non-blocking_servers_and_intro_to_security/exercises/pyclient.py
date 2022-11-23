import socket
import sys

ip = sys.argv[1]
port = int(sys.argv[2])

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
    client_socket.connect((ip, port))
    print(f"Connected to {ip}: {port}")
    while True:
        message = input()
        print("Sending: ", message)
        request = bytearray((message + "\n").encode())
        client_socket.sendall(request)
        response = client_socket.recv(1024)
        print(f"Response: {response.decode()}")

