# Pintool
Software Quality Assurance
Call Graph Generation
I. Objective
The objective of this assignment is to create a Pintool in Pin++ that generates the call
graph of an instrumented program.
II. Goal
The goal of the assignment is to generate a condensed call graph that can be visualized
using the Graphviz Dot.
III. Assignment Directions
You are to create Pintools using Pin++ that can instrument any single-threaded program.
The Pintool must generate a program graph that can be visualized using Graphviz Dot.
Each node in the graph will be a function/routine from the program instrumented. Each
edge in the graph represents the number of times the call occurred. For example, if the
graph has nodes A and B, and the edge between node A and B is 5, then this means the
call between A and B happened 5 times.

Steps to run:

Run following commands: 
>mwc.pl -type vc11 -features pin=1,ia32=1,intel64=0 -include %PINPP_ROOT%\MPC\config 
>devenv /useenv asgmt.sln 
Now open command prompt and go to your PinPP-master folder Run following commands:
>pin -t lib\hcallgraph1.dll -- notepad.exe Now generate dot file
>dot -Tjpg h.gv -o h.jpg 
Open h.jpg to view graph
