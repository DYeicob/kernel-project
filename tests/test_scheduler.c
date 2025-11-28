#include <stdio.h>
#include "../src/scheduler.h"
#include "../src/process.h"

int main() {
    init_process_system();
    init_scheduler();

    create_process("Test1");
    create_process("Test2");

    for (int i = 0; i < 5; i++) scheduler_tick();
}
