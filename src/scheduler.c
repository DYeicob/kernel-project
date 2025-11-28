#include <stdio.h>
#include "scheduler.h"
#include "process.h"

static int quantum = 2;
static int quantum_counter = 0;

void init_scheduler() {
    printf("[Scheduler] Inicializado.\n");
}

void scheduler_tick() {
    process_t *p = get_current_process();

    if (p == NULL) {
        p = schedule_next_process();
        return;
    }

    quantum_counter++;

    printf("[Scheduler] Ejecutando proceso %s (pid=%d)\n", p->name, p->pid);

    if (quantum_counter >= quantum) {
        printf("[Scheduler] Quantum agotado, cambio de proceso.\n");
        quantum_counter = 0;
        schedule_next_process();
    }
}
