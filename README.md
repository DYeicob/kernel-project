# Mini Kernel Educativo – Scheduler + IPC

Proyecto académico para la asignatura de **Sistemas Operativos**.  
El objetivo es implementar un **scheduler Round Robin** y un sistema básico de **comunicación entre procesos (IPC)** mediante colas de mensajes.  
El kernel está simulado en espacio de usuario con código C y se organiza en módulos independientes.

---

## ⚙️ Funcionalidades principales

### 🧵 Gestión de procesos
- Creación de procesos
- Estados: READY, RUNNING, BLOCKED
- Estructura de proceso con PID y nombre

### ⏱️ Scheduler (Planificador)
- Algoritmo **Round Robin**
- Quantum configurable
- Rotación automática entre procesos READY

### 🔗 IPC (Comunicación entre procesos)
- Envío y recepción de mensajes
- Simulación de colas de mensajes
- Desbloqueo de procesos al recibir información

### 📂 Modularización
- `process.c / process.h` → Gestión de procesos  
- `scheduler.c / scheduler.h` → Algoritmo de planificación  
- `ipc.c / ipc.h` → Comunicación entre procesos  
- `main.c` → Simulación del kernel  

---

## 📁 Estructura del repositorio
```

.
├── README.md
├── LICENSE
├── Makefile
│
├── src/
│   ├── main.c
│   ├── scheduler.c
│   ├── scheduler.h
│   ├── process.c
│   ├── process.h
│   ├── ipc.c
│   └── ipc.h
│
├── include/
│   └── common.h
│
├── docs/
│   ├── diagramas/
│   ├── report.pdf
│   └── plan.md
│
├── tests/
│   ├── test_scheduler.c
│   └── test_ipc.c
│
└── examples/
└── run_example.sh

````

---

## 🛠️ Cómo compilar
Asegúrate de tener `gcc` instalado.

```bash
make
````

---

## ▶️ Cómo ejecutar

```bash
./kernel
```

---

## 🧹 Limpiar archivos de compilación

```bash
make clean
```

---

## 📄 Licencia

Este proyecto se distribuye bajo la licencia **MIT**.
Consulta el archivo `LICENSE` para más información.

---

## 📚 Notas finales

Este proyecto es una simulación didáctica:
no es un kernel real, pero replica los conceptos clave de la gestión de procesos y la comunicación entre ellos.
