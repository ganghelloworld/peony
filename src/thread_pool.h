#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include "httpd.h"

#include <pthread.h>
#include <queue>
#include <iostream>

class Task
{
public:
	Task(Httpd*, std::string*, int);
	~Task();
	void action();
public:
	std::string* recv;
	int cli_sockfd;
	Httpd* httpd;
};

class Thread
{
public:
	pthread_t id;
	int num;
};


/*
 * Singleton
 *
*/
class ThreadPool
{
private:
	ThreadPool();
	ThreadPool(const ThreadPool&){};
	ThreadPool& operator=(const ThreadPool&){};
public:
	static ThreadPool* Instance();
	~ThreadPool();
	void add_task(Task*);
public:
	static ThreadPool *thread_pool;
	static void* thread_routine(void*);
	pthread_mutex_t lock;
	pthread_cond_t cond;

	std::queue<Task*> tasks;
	std::vector<Thread> threads;

	int max_thread_num;
	int cur_task_num;
	bool shutdown;
};
#endif //THREAD_POOL_H
