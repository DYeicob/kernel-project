#include <stdio.h>
#include "scheduler.h"
#include "process.h"
#include "ipc.h"

int main() {
    init_process_system();
    init_ipc();
    init_scheduler();

    printf("Mini kernel iniciado...\n");

    // Crear procesos de prueba
    create_process("Proceso A");
    create_process("Proceso B");
    create_process("Proceso C");

    // Bucle de simulación
    for (int i = 0; i < 10; i++) {
        scheduler_tick();
    }

    return 0;
}
