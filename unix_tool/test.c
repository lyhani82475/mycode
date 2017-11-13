#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	pid_t pid;
	int fd1[2];
	int fd2[2];

	pipe(fd1);
	pipe(fd2);
	
	char *parent_talk[]={"hi","hao are you","mo too","bye",NULL};
	char *child_talk[]={"hello","i am fine","too","byebye",NULL};


	pid=fork();
	if(pid==0)   //子进程fd2
	{
		int i=0;
		char buffer[256];

		close(fd1[1]);
		close(fd2[0]);
		
		char *child=child_talk[i];
		while(child!=NULL)
		{
			read(fd1[0],buffer,256);
			printf("Parent:>%s\n",buffer);
			write(fd2[1],child,strlen(child)+1);
			
			i++;
			child=child_talk[i];
		}
		close(fd1[0]);
		close(fd2[1]);
	}
	else if(pid>0)
	{
		int i=0;
		char buffer[256];
		char *parent=parent_talk[i];
		close(fd1[0]);
		close(fd2[1]);

		while(parent!=NULL)
		{
			write(fd1[1],parent,strlen(parent)+1);
			read(fd2[0],buffer,256);
			printf("child:>%s\n",buffer);

			i++;
			parent=parent_talk[i];
		}

		close(fd1[1]);
		close(fd2[0]);
	}
	else
	{
		perror("fork.");
	}
}

/*
int main()
{
	pid_t pid;
	int fd[2];

	pipe(fd);

	pid=fork();

	if(pid==0)   //子进程用来读
	{
		close(fd[1]);

		char buf[256];
		read(fd[0],buf,256);
		printf("From Parent Process msg:>%s\n",buf);
		close(fd[0]);
	}
	else if(pid>0)
	{
		char *buff="i am g a girl!";
		close(fd[0]);

		write(fd[1],buff,strlen(buff)+1);
		close(fd[1]);

		int status;
		wait(&status);
	}
	else
	{
		perror("fork.");
	}
}
*/
