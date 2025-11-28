#include <stdio.h>
#include "../src/ipc.h"

int main() {
    init_ipc();
    send_message(1, "Hola mundo");
    receive_message(1);
}
