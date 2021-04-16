from http.server import HTTPServer, SimpleHTTPRequestHandler
import sys

ip = "127.0.0.1"
port = 8000

addr = (ip, port)

httpd = HTTPServer(addr, SimpleHTTPRequestHandler)
Servip, Servport = httpd.socket.getsockname()

try:
	httpd.serve_forever()
except KeyboardInterrupt:
	print("KeyboardInterrupt receiving, Exiting")
	httpd.server_close()
sys.exit(0)