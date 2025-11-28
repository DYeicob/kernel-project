# Proyecto SO — Scheduler y Comunicación entre Procesos (IPC)

## 1. Introducción
Este proyecto forma parte de la asignatura **Sistemas Operativos** y consiste en implementar una simulación sencilla de un kernel educativo. Nos centramos en dos módulos fundamentales de cualquier sistema operativo real:

- Gestión y representación de procesos.
- El **scheduler** o planificador de CPU.
- La **comunicación entre procesos (IPC)**.

El propósito es comprender cómo se gestionan los procesos a bajo nivel, cómo un sistema operativo decide qué proceso se ejecuta en cada instante y cómo los procesos pueden comunicarse entre sí de forma segura.

---

## 2. Arquitectura del Proyecto

La estructura del proyecto sigue un diseño modular para separar las responsabilidades.
```
src/
├── main.c
├── process.c / process.h
├── scheduler.c / scheduler.h
└── ipc.c / ipc.h
include/
docs/
tests/
```

Cada módulo representa una parte real del kernel.

---

## 3. Módulo de Procesos (`process.c`)

Este módulo implementa:

- **Estructura `Process`**, con:
  - PID
  - estado
  - prioridad (opcional)
  - quantum restante
  - buzón IPC
- Gestión de estados:
  - READY
  - RUNNING
  - BLOCKED
  - FINISHED

Funciones clave:
- `create_process()`
- `block_process()`
- `finish_process()`
- `unblock_process()`

Este módulo permite representar procesos reales en el sistema y preparar su interacción con el scheduler.

---

## 4. Scheduler (`scheduler.c`)

El planificador ejecuta los procesos usando un algoritmo **Round Robin**, habitual en sistemas time-sharing.

### Características:
- Cola de procesos listos (READY)
- Quantum configurable
- Cambio de contexto simulado
- Reintroducción en cola tras agotar quantum
- Bloqueo y desbloqueo de procesos
- Selección del siguiente proceso a ejecutar

Este módulo reproduce el comportamiento de un kernel básico de planificación real.

---

## 5. Comunicación entre Procesos (IPC) — `ipc.c`

El IPC se implementa mediante **buzones de mensajes** (message queues).

### Funciones principales:
- `send(pid_destino, mensaje)`
- `recv(pid_origen, &mensaje)`
- Bloqueo automático si no hay mensajes disponibles
- Desbloqueo cuando un mensaje llega

El IPC es esencial para procesos cooperativos y para comunicaciones asíncronas dentro del sistema.

---

## 6. Diagramas del Sistema

### 6.1. Estados de un Proceso
(archivo: `diagramas/process_states.png`)

Representa la transición entre:
- NEW → READY  
- READY → RUNNING  
- RUNNING → BLOCKED / FINISHED  
- BLOCKED → READY  

---

### 6.2. Cola del Scheduler
(archivo: `diagramas/scheduler_queue.png`)

Muestra:
- Entrada de procesos a la cola
- Rotación por RR
- Salida hacia RUNNING
- Retorno a READY al agotar quantum

---

### 6.3. Flujo de Comunicación IPC
(archivo: `diagramas/ipc_flow.png`)

Incluye:
- Envío de mensaje
- Almacenamiento en buzón
- Bloqueo/desbloqueo de receptor
- Notificación al scheduler

---

## 7. Pruebas

Las pruebas del proyecto comprueban:

### 7.1 Scheduler
- Orden correcto en RR
- Respeto del quantum
- Bloqueo y desbloqueo

### 7.2 IPC
- Envío y recepción de mensajes
- Bloqueo cuando no hay mensajes
- Integración con scheduler

### 7.3 Procesos
- Creación correcta de estructuras
- Estados válidos en todo momento

---

## 8. Conclusiones

Este proyecto permite entender los fundamentos de un kernel real:

- Cómo se representan procesos.
- Cómo un scheduler reparte equitativamente la CPU.
- Cómo los procesos cooperan mediante IPC.
- Cómo se integran estas piezas en un sistema coherente.

Además, sirve como base para ampliaciones más avanzadas:

- Schedulers multinivel o con prioridades.
- Semáforos y sincronización real.
- Gestión de memoria o threads.
- Señales o interrupciones.

La implementación modular facilita el aprendizaje, la depuración y la mejora futura.

---

## 9. Trabajo Futuro

Este proyecto podría evolucionar hacia un minikernel completo añadiendo:
- Gestión de memoria
- Sistema de archivos
- Drivers simulados
- Multiprocesamiento (SMP)
