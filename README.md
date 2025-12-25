# 🛡️ Educational Mini Kernel – Scheduler + IPC

The objective of this project is to implement a **Round Robin Scheduler** and a basic **Inter-Process Communication (IPC)** system using message queues.
The kernel is simulated in user space using C and is organized into independent, modular components.

---

## ⚙️ Core Functionalities

### 🧵 Process Management

* Process creation and lifecycle management.
* States: **READY**, **RUNNING**, **BLOCKED**.
* Implementation of a basic **Process Control Block (PCB)** containing PID and metadata.

### ⏱️ Scheduler (Planificador)

* **Round Robin** algorithm.
* Configurable **Time Quantum**.
* Automatic rotation among processes in the **READY** queue.

### 🔗 IPC (Inter-Process Communication)

* Message sending and receiving primitives.
* Simulation of **Message Queues**.
* Blocking/Unblocking logic for processes awaiting data.

### 📂 Modular Architecture

* `process.c / .h`: Logic for process handling.
* `scheduler.c / .h`: Planning algorithm implementation.
* `ipc.c / .h`: Communication protocols.
* `main.c`: Kernel entry point and simulation loop.

---

## 📁 Repository Structure

```text
.
├── README.md           # Project overview
├── LICENSE             # MIT License
├── Makefile            # Build automation
│
├── src/                # Source code
│   ├── main.c
│   ├── scheduler.c
│   ├── scheduler.h
│   ├── process.c
│   ├── process.h
│   ├── ipc.c
│   └── ipc.h
│
├── include/            # Global headers
│   └── common.h
│
├── docs/               # Technical documentation
│   ├── diagrams/
│   ├── report.pdf
│   └── plan.md
│
├── tests/              # Unit testing suite
│   ├── test_scheduler.c
│   └── test_ipc.c
│
└── examples/           # Use cases
    └── run_example.sh

```

---

## 🛠️ Compilation

Ensure you have the `gcc` compiler installed.

```bash
make

```

---

## ▶️ Execution

To start the kernel simulation, run:

```bash
./kernel

```

---

## 🧹 Maintenance

To remove object files and binaries:

```bash
make clean

```

---

## 📚 Final Notes

This project is a **didactic simulation**. While it is not a "bare-metal" kernel, it accurately replicates key OS concepts such as **Preemptive Scheduling** and **Memory-safe Communication** between isolated processes.
