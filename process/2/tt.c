#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("child id=%d,parent id=%d\n",getpid(),getppid());
	printf("this is tt.c\n");
	return 0;
}
