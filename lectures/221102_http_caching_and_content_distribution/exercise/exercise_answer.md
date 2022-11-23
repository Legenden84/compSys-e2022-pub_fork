# Exercises for CN, Application layer

## Exercises from Chapter 2 of Kurose and Ross on "Application Layer"

Review questions

* R3: For a communication session between a pair of processes, which process is the client and which is the server?
      The process which initiates the communications is the client; the process that waits to be contacted is the server.
  
* R4: Why are the terms client and server still used in peer-to-peer applications?
      In a client-server architecture, there is an always-on host, called the server, which services requests
      from many other hosts, called clients.
  
* R5: What information is used by a process running on one host to identify a process running on another host?
      The IP-address of the destination host and the port number of the socket in the destination process.

* R10: What is meant by the handshaking protocol?
       A protocol uses handshaking of the two communicating entities first exchange control packets before sending data to each other. 
       SMTP uses handshaking at the application layer whereas HTTP does not.

* R12: How can a website keep track of users? Do they always need to use cookies?
       
* R15

Problems

* P1
  a) False.
  b) True.
  c) False.
  d) False.
  e) False.

* P4
  a) gaia.cs.umass.edu



  e) Mozilla 5.0
     The browser type is needed because that Internet Explorer for instance have implemented the http protocol differently then other browsers.

* P5
  
* P10: 
      Link: 300 bits / s
      Packets:
            
  
## Programming
Browse the complete HTTP RFC and convince yourself that it is too long to read entirely. It can be found here: https://www.rfc-editor.org/rfc/rfc2616

Now create a simple, HTTP complient request client. It must be capable of sending GET or HEAD requests and only needs to send the Request-Line (section 5.1 of the RFC) with no accompanying message-body or headers. Send your messages to the non-replying server for feedback on if you've done it correctly. 

Optionally, send your request to the replying server to parse and print the response in C. In either case you should assemble your requests in C and parse and response to be printed. Do not simply input one long string to create a request, actually take the different parts (e.g. the method, request-uri and http-version) and join them together to form the request. Similarly, do not just print the entirety of the feedback but identify the seperate parts. Python clients have also been provided as inspiration and a guide, though do remember that just because some logic works in python does not mean it is a good idea to directly copy to C.
