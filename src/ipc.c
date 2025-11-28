#include <stdio.h>
#include "ipc.h"

void init_ipc() {
    printf("[IPC] Subsistema de comunicación inicializado.\n");
}

void send_message(int to_pid, const char* msg) {
    printf("[IPC] Mensaje enviado a PID %d: %s\n", to_pid, msg);
}

void receive_message(int pid) {
    printf("[IPC] Proceso %d recibe mensaje.\n", pid);
}
