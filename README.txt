- This project was compiled and run on UBUNTU 18.04
- A sample testfile.txt is included, which contains all the different operations. 
- A compile.sh script is also included to generate ./mysh

Key Assumptions:
1. I am letting the infinite recursion happen when a script asks to run itself. 
This is an error of the author of the script. 
The faulty program will stack overflow, exceed resource limit and nevertheless automatically terminate. 
