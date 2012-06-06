#include "thread_pool.h"
#include "config.h"
#include "utility.h"
#include <pthread.h>

using namespace std;

ThreadPool* ThreadPool::thread_pool = NULL;

ThreadPool::ThreadPool()
{
	max_thread_num = Peony::INIT_THREAD_NUM;
	cur_task_num = 0;
	shutdown = 0;
	pthread_mutex_init(&lock, NULL);
	pthread_cond_init(&cond, NULL);

	threads.reserve(max_thread_num);
	int rt;
	for(int i = 0; i < max_thread_num; i++)
	{
		rt = pthread_create(&(threads[i].id), NULL, thread_routine, this);
		require(rt == 0, "pthread_create_error");
		threads[i].num = i;
	}
}

ThreadPool* ThreadPool::Instance()
{
	if(thread_pool == NULL)
	{
		thread_pool = new ThreadPool();
	}
	return thread_pool;
}

ThreadPool::~ThreadPool()
{
	if(shutdown) return;
	shutdown = 1;
	pthread_cond_broadcast(&cond);
	for(int i = 0; i < max_thread_num; i++)
	{
		pthread_join(threads[i].id, NULL);
	}
	while(!tasks.empty()) tasks.pop();
	//pthread_mutex_destory(&lock);
	//pthread_cond_destory(&cond);
}

void* ThreadPool::thread_routine(void* T)
{
	ThreadPool *This = static_cast<ThreadPool*>(T);
	while(true)
	{
		pthread_mutex_lock(&This->lock);
	
		while(This->cur_task_num == 0 && !This->shutdown)
		{
			pthread_cond_wait(&This->cond, &This->lock);
		}
		if(This->shutdown)
		{
			pthread_mutex_unlock(&This->lock);
			pthread_exit(NULL);
		}
		cout << "thread id = " << pthread_self() << endl;
		This->cur_task_num--;
		Task *task = This->tasks.front();
		This->tasks.pop();
		pthread_mutex_unlock(&This->lock);
		task->action();
	}
}
void ThreadPool::add_task(Task* task)
{
	pthread_mutex_lock(&lock);
	tasks.push(task);
	cur_task_num++;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&lock);
}
Task::Task(Httpd* h, string* r, int c) :
	httpd(h), recv(r), cli_sockfd(c)
{
}
Task::~Task()
{
}
void Task::action()
{
	/*
	for(int i = 1; i <= 15; i ++)
	{
		cout << "\t" << i << "\t" << pthread_self() << endl;
		sleep(1);
	}
	*/
	httpd->response(recv, cli_sockfd);
}
