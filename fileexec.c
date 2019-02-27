#include<stdio.h>
#include<stdlib.h>

int main()
{
    int exit_code;
    
    // File compilation and excecution script
    // File is compiled to an excecutable - Failure will lead to termination of the program
    exit_code = system("gcc .\\example.c -o .\\executable\\example.exe");
    if(exit_code != 0)
    {
        return exit_code;
    }

    // File is run on the computer and the stream is redirected to streams.txt
    exit_code = system(".\\executable\\example > .\\streams\\streams.txt 2>&1");

    //Fetching the output
    char* output = 0;
    long length;
    FILE* f = fopen(".\\streams\\streams.txt", "rb");
    
    if(f)
    {
        fseek(f, 0 , SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        output = malloc(length);
        if(output)
        {
            fread(output, 1, length, f);
        }
        fclose(f);
    }

    if(output)
    {
        printf("%s\n", output);
    }

    return 0;
}