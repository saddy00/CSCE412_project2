# CSCE412_project2

Project 2 — Load balancer

Overview

In this project, we will learn how to model a simulation of a large company's load-balancing web requests using a load balancer.

This project will require a real-world implementation of a queue. We also need a struct, a lower-level data structure that allows data to be contained in an object.

Load balancers are available commercially, but in this project, you will build one that has:
● Requests - generates random IP addresses, both in and out, and random times for each request to be processed.
o IP in
o IP out
o Time (integer)
● Webserver(s)
o Takes requests from the Load Balancer
o Process the requests
o Asks for another
● Load Balancer
o Queue of requests
o Keeps track of time.

Project Objectives:

You will be able to:
● Show your understanding of building and using a load balancer.
● Develop a guide for your load balancer that does not get overloaded or underutilized.
Instructions:
1. This is a team project, but each team member should be able to run the load balancer on their machine. You must turn in your own work.
2. Collaboration for ideas between teams is acceptable, but duplication of work is not.
3. Use C++ to write this program.
      A) you must design the workflow and write the driver or main program on your own. 
      B) you must design the functions of the methods and classes you need, including the inputs and output of each function.
      C) you can then (and only after the design is complete) use ChatGPT to write the individual functions. For example using ChatGPT, say "write a                       function in C++ that will take a real number value as US currency and convert it to Singapore currency". Your driver program or other functions
           can call that AI written function.
4. Your program will contain multiple .cpp files. The main program should set up the number of
servers (user input), the time you want to run the load balancer (user input) and generate a
full queue (usually servers * 20).
5. You will need a webserver class so you can create the number of webservers requested.
6. You will need a request class (or struct) that holds a request.
7. You will need a queue of type request. (called requestqueue?)
8. You will need a loadbalancer class that manages the webservers and the request queue.
9. You will need to add new requests at random times to simulate new requests after the initial full queue you set up.
10. Exit when the queue is empty and all requests have been completed.
11. Try different numbers as input to understand the capacity of your loadbalancer configurations.
12. All files must be commented with Doxygen using HTML output and loaded to a page on people.tamu.edu. Turn in this link.
13. Demo the load balancer in class
14. Optional, choose a team of 2 or 3 members (or be assigned). Teams of 3 will add an IP range blocker to serve as a firewall or DOS attack prevention mechanism.

Deliverables:
All deliverables must be at least a minimum viable solution to the problem assigned. No attempt at
grading will be made for non-substantial submissions.
1. Create documentation for each of your code files in HTML, hosted on people.tamu.edu
2. Create a log of 10 servers running for 10000 clock cycles
3. Turn in your git repository link. (optional)
4. Demonstration of usability.
Grading:
This project is worth 100 points.

Documentation 30%
Log and successful completion of load balancing 20%
Demonstration, code, and Git usage 50%
