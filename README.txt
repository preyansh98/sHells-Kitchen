- This project was compiled and run on UBUNTU 18.04
- A sample testfile.txt is included, which contains all the different operations. 
- A compile.sh script is also included to generate ./mysh

Key Assumptions:
1. Quit within a script (run script) will quit the shell. 
In my opinion, I don't see why running commands through a script in comparison to running  by stdin directly should be treated differently. 
A script should just be to save work by piling commands in a file, but should mimic same behaviour as someone entering commands manually. 

2. Infinite Recursion on when a script calls to run itself is allowed.
This is an error of the author of the script. 
The faulty program will stack overflow, exceed resource limit and automatically terminate. 

