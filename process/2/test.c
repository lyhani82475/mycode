#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>  //wait()   waitpid()
#include<stdlib.h>   //exit()
#include<sys/resource.h>   //getpriority()

int main()
{
	pid_t pid=vfork();
	if(pid==0)
	{
		printf("parent pid=%d,child pid=%d\n",getppid(),getpid());
		printf("this is test.c child\n");
		execl("tt","tt",NULL);
		printf("======================\n");
	}
	else if(pid>0)
	{
	//	int status;
	//	wait(&status);
		printf("this is test.c parent\n ");
	}
	else
		perror("fork.");
	return 0;
}


/*
int main()
{
	//execlp("ls","ls",NULL);
	execl("bin/ls","ls",NULL);
	return 0;
}


/*
//nice进程的优先级
int main()
{
	pid_t pid=fork();
	int pri;
	if(pid==0)
	{
		//setpriority(PRIO_PROCESS,getpid(),2);
		pri=getpriority(PRIO_PROCESS,getpid());
		printf("child pri=%d\n",pri);
		nice(2);
		pri=getpriority(PRIO_PROCESS,getpid());
		printf("child newpri=%d\n",pri);
	}
	else if(pid>0)
	{
		//sleep(1);
		pri=getpriority(PRIO_PROCESS,getpid());
		printf("parent pri=%d\n",pri);
	}
	else
		perror("vfork.");
	return 0;
}


/*
//vfork函数，先运行子进程，然后调用exit或_exit函数来结束子进程的运行，从而去运行父进程
int main()
{
	int i=0;
	pid_t pid=vfork();
	if(pid==0)
	{
		i=10;
		printf("child i=%d\n",i);
		exit(1);
	}
	else if(pid>0)
	{
		printf("parent i=%d\n",i);
		int status;
		wait(&status);
	}
	else 
		perror("vfork.");
	return 0;
}


/*
//fork函数中子进程的改变不会像影响到父进程的改变
int main()
{
	int i=0;
	pid_t  pid=fork();
	if(pid==0)
	{
		i=10;
		printf("child i=%d\n",i);
	}
	else if(pid>0)
	{
		sleep(2);
		printf("parent i=%d\n",i);
	}
	else
		perror("fork.");
	return 0;
}


/*
int main()
{

	pid_t pid=fork();

	if(pid==0)
	{
		pid=fork();
		if(pid==0)
		{
			printf("2-1 pid:%d\n",getpid());
			printf("2-1 parent pid:%d\n",getppid());
		}
		else if(pid>0)
		{
			printf("2 pid:%d\n",getpid());
			sleep(2);
		}
		else
		{
			perror("fork.");
		}
	}
	else if(pid>0)
	{
		pid=fork();
		if(pid==0)
		{
			printf("1-1 pid:%d\n",getpid());
			printf("1-1 parent pid:%d\n",getppid());
			sleep(2);
		}
		else if(pid>0)
		{
			printf("1 pid:%d\n",getpid());
			int status;
			pid_t pid_ret=wait(&status);
			printf("pid_ret:%d\n",pid_ret);
		}
		else
			perror("fork.");
	}
	else
	{
		perror("fork.");
	}
	return 0;

}



/*
int main()
{
	pid_t pid;
	pid=fork();

	if(pid==0)
	{
		printf("child pid:%d\n",getpid());
		printf("parent pid:%d\n",getppid());
		sleep(3);
	}
	else if(pid>0)
	{
		printf("parent pid:%d\n",getpid());
		sleep(1);

		kill(pid,SIGINT);

		int status;
		pid_t pid_ret=wait(&status);
		printf("wait return pid:%d\n",pid_ret);

		if(WIFEXITED(status))
			printf("ok finish\n");
		else
			printf("error finish\n");
	}
	else
	{
		perror("fork.");
	}

	printf("%d finish\n",getpid());

	return 0;
}
*/
