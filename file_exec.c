#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>

int main(){
	
	// exit_code: number
	// Stores the value returned a the tremination of system() call 
   	int exit_code;
	
	// output.txt - file to redirect the stdout to
	// Create a file output.txt if the file doesn't exist previously
	// If the file does exist, remove the old one and recreate a blank file
	exit_code = system("if [ ! -f /home/kurzgesagt/RPC-server/output.txt ]; then\n	touch /home/kurzgesagt/RPC-server/output.txt\nelse\n    rm /home/kurzgesagt/RPC-server/output.txt\n	touch /home/kurzgesagt/RPC-server/output.txt\nfi");
	if(exit_code != 0)
		return exit_code;

	// error.txt - File to redirect stderr to
	// Create a file error.txt if the file doesn't exist previously
	// If the file does exist, remove the old one and recreate a blank file
	exit_code = system("if [ ! -f /home/kurzgesagt/RPC-server/error.txt ]; then\n	touch /home/kurzgesagt/RPC-server/error.txt\nelse\n    rm /home/kurzgesagt/RPC-server/error.txt\n	touch /home/kurzgesagt/RPC-server/error.txt\nfi");
	if(exit_code != 0)
		return exit_code;

	// Compiling the fine stored [For testing purpose we use example.c]
	//	In case of an error - the error stream is redirected to output.txt
	exit_code = system("/usr/bin/gcc /home/kurzgesagt/RPC-server/example.c -o /home/kurzgesagt/RPC-server/prog_out 2>error.txt");

	// Executing the excecutable file given by GCC
	// The output is written to output.txt
	exit_code = system("/home/kurzgesagt/RPC-server/prog_out > /home/kurzgesagt/RPC-server/output.txt");
		
	return 0;
}