#include <stdio.h>
#include "../src/ipc.h"

/**
 * Basic IPC Test Case
 * Demonstrates the initialization, sending, and receiving 
 * of messages through the simulated kernel message queue.
 */
int main() {
    // Initialize the Inter-Process Communication system
    init_ipc();

    // Send a message to the queue associated with PID 1
    printf("Test: Sending message to PID 1...\n");
    send_message(1, "Hello World");

    // Attempt to retrieve the message from the queue for PID 1
    printf("Test: Receiving message from PID 1...\n");
    receive_message(1);

    return 0;
}
