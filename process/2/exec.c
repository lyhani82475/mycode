#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[],char **enc)
{
	char *envp[]={"ls","-al",NULL};
	char *a[]={"PATH=/bin",NULL};
	execve("/bin/ls",envp,a);
	//char *envp[]={"ls","-al",NULL};
	//execvp(argv[0],envp);
	//execv("/bin/ls",envp);
	return 0;
}


//execl
/*
int main()
{
	execle("/bin/ls","ls","-al",NULL);
	//execlp("ls","ls",NULL);
	//execl("/bin/ls","ls",NULL);
	return 0;
}
*/
