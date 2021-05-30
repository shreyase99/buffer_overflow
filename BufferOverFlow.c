#include <stdio.h>
#include <unistd.h>
#include <string.h>

int vuln() 
{
    char buf[64];
    char pwd[]="password\n";
    int r;
    int allowed =0;
    printf("Vulnerable Function\n\n");
    printf("Enter Password:\n");
    r = read(0, buf, 200);
    printf("Entered Password:\n%s\n", buf);
    if (strcmp(buf, pwd)==0)
    	allowed=1;

    return allowed;
}

int main(int argc, char *argv[]) {
    int allowed=vuln();
    if (allowed)
    	printf("Approved!\n");
   	else
   		printf("Password Wrong.\n");
    return 0;
}