#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <xenomai/alchemy/task.h>

RT_TASK demo_task;

void demo(void *arg) // <−−− USE IT IN APP
{
  RT_TASK *curtask;
  RT_TASK_INFO curtaskinfo;

  printf("Hello World!\n");

  // inquire current task
  rt_task_inquire(curtask,&curtaskinfo);

  // print task name
  printf("Task name : %s \n", curtaskinfo.name);
}

int main(int argc, char* argv[])
{
  char  str[10];

  printf("start task\n");

  sprintf(str,"demo");

  rt_task_create(&demo_task, str, 0, 50, 0);

  rt_task_start(&demo_task, &demo, 0);
}
