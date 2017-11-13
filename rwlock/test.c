#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#define N 5

pthread_rwlock_t rwlock;

void* thread_fun(void *arg)
{
	pthread_rwlock_wrlock(&rwlock);
	printf("this is thread_fun\n");
	sleep(12);
	pthread_rwlock_unlock(&rwlock);
}

void* thread_fun1(void* arg)
{
	int i=*(int *)arg;
	pthread_rwlock_rdlock(&rwlock);
	printf("this is read_thread %d\n",i);
	pthread_rwlock_unlock(&rwlock);
}

void* thread_fun2(void* arg)
{
	int i=*(int *)arg;
	pthread_rwlock_wrlock(&rwlock);
	printf("this is write_thread %d\n",i);
	pthread_rwlock_unlock(&rwlock);
}

int main()
{
	pthread_t tid,tid1[N],tid2[N];
	
	pthread_create(&tid,NULL,thread_fun,NULL);
	int i;
	for(i=0;i<= N;++i)
	{
		pthread_create(&tid1[i],NULL,thread_fun1,&i);
		sleep(1);
	}
	for(i=0;i<N;i++)
	{
		pthread_create(&tid2[i],NULL,thread_fun2,&i);
		sleep(1);
	}

	pthread_join(tid,NULL);
	for(i=0;i<N;i++)
	{
		pthread_join(tid1[i],NULL);
		pthread_join(tid2[i],NULL);
	}
	return 0;
}



/*
pthread_rwlock_t rwlock;

void* thread_fun1(void *arg)
{
	pthread_rwlock_rdlock(&rwlock);
	pthread_rwlock_unlock(&rwlock);
	printf("this is thread 1\n");
	//pthread_rwlock_unlock(&rwlock);
	printf("thread 1 finish\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");
	printf("1\n");       //线程在解锁之后并不会立即被上锁，而是要等到整个线程的结束
}

void* thread_fun2(void* arg)
{
	pthread_rwlock_wrlock(&rwlock);
	printf("this is thread 2\n");
	pthread_rwlock_unlock(&rwlock);
	printf("thread 2 finish\n");
}


int main()
{

	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,thread_fun1,NULL);
	sleep(1);
	pthread_create(&tid2,NULL,thread_fun2,NULL);


	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
*/
