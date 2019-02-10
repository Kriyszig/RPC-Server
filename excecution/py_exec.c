#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>

int exec_py()
{
    int exit_code;
    exit_code = system("/usr/bin/python3 /home/kurzgesagt/RPC-server/excecution/example.py > /home/kurzgesagt/RPC-server/streams/output.txt");
    return exit_code;
}
