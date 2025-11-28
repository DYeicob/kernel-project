#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "process.h"

static process_t* process_list = NULL;
static process_t* current = NULL;
static int next_pid = 1;

void init_process_system() {
    printf("[Process] Sistema de procesos inicializado.\n");
}

int create_process(const char* name) {
    process_t* p = malloc(sizeof(process_t));
    p->pid = next_pid++;
    strcpy(p->name, name);
    p->state = READY;
    p->next = NULL;

    if (process_list == NULL) {
        process_list = p;
    } else {
        process_t *tmp = process_list;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp->next = p;
    }

    printf("[Process] Creado proceso %s (pid=%d)\n", name, p->pid);
    return p->pid;
}

process_t* get_current_process() {
    return current;
}

process_t* schedule_next_process() {
    if (current == NULL)
        current = process_list;
    else
        current = current->next ? current->next : process_list;

    current->state = RUNNING;
    return current;
}
