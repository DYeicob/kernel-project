#ifndef PROCESS_H
#define PROCESS_H

typedef enum { READY, RUNNING, BLOCKED } state_t;

typedef struct process {
    int pid;
    char name[32];
    state_t state;
    struct process *next;
} process_t;

void init_process_system();
int create_process(const char* name);
process_t* get_current_process();
process_t* schedule_next_process();

#endif
