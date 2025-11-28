#ifndef IPC_H
#define IPC_H

void init_ipc();
void send_message(int to_pid, const char* msg);
void receive_message(int pid);

#endif
