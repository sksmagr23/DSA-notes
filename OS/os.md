# Operating Systems — Complete Notes

---

## Table of Contents

- [Operating Systems — Complete Notes](#operating-systems--complete-notes)
  - [Table of Contents](#table-of-contents)
  - [1. OS Fundamentals \& Architecture](#1-os-fundamentals--architecture)
    - [1.1 What is an Operating System?](#11-what-is-an-operating-system)
    - [1.2 Fundamental Functions of an OS](#12-fundamental-functions-of-an-os)
    - [1.3 Application Software vs. System Software](#13-application-software-vs-system-software)
    - [1.4 Primary Goals \& Design Trade-offs](#14-primary-goals--design-trade-offs)
    - [1.5 OS Architectures: Monolithic, Microkernel, Layered, Hybrid](#15-os-architectures-monolithic-microkernel-layered-hybrid)
  - [2. Types of Operating Systems](#2-types-of-operating-systems)
    - [2.1 Single-Tasking / Batch Processing Systems](#21-single-tasking--batch-processing-systems)
    - [2.2 Multiprogramming Systems](#22-multiprogramming-systems)
    - [2.3 Multitasking \& Time-Sharing Systems](#23-multitasking--time-sharing-systems)
    - [2.4 Multiprocessing Systems (SMP vs. ASMP)](#24-multiprocessing-systems-smp-vs-asmp)
    - [2.5 Distributed \& Clustered Operating Systems](#25-distributed--clustered-operating-systems)
    - [2.6 Real-Time Operating Systems (Hard vs. Soft RTOS)](#26-real-time-operating-systems-hard-vs-soft-rtos)
  - [3. Kernel, System Calls \& Operating Modes](#3-kernel-system-calls--operating-modes)
    - [3.1 The Kernel \& User Space](#31-the-kernel--user-space)
    - [3.2 Dual-Mode Operation (User Mode vs. Kernel Mode)](#32-dual-mode-operation-user-mode-vs-kernel-mode)
    - [3.3 System Calls vs. Library/Function Calls](#33-system-calls-vs-libraryfunction-calls)
    - [3.4 Categories of System Calls](#34-categories-of-system-calls)
    - [3.5 Interrupts, Traps, Faults, and Aborts](#35-interrupts-traps-faults-and-aborts)
  - [4. Booting, Hardware Interface \& Architecture](#4-booting-hardware-interface--architecture)
    - [4.1 The Complete Booting Sequence (POST, BIOS/UEFI, Bootloader)](#41-the-complete-booting-sequence-post-biosuefi-bootloader)
    - [4.2 32-bit vs. 64-bit Systems](#42-32-bit-vs-64-bit-systems)
    - [4.3 Memory \& Storage Hierarchy](#43-memory--storage-hierarchy)
  - [5. Process Management \& Lifecycle](#5-process-management--lifecycle)
    - [5.1 Program vs. Process](#51-program-vs-process)
    - [5.2 Process Control Block (PCB) \& Memory Layout](#52-process-control-block-pcb--memory-layout)
    - [5.3 Process State Transitions (5-State and 7-State Models)](#53-process-state-transitions-5-state-and-7-state-models)
      - [Classic 5-State Transition Diagram](#classic-5-state-transition-diagram)
      - [Extended 7-State Model (With Swapping)](#extended-7-state-model-with-swapping)
    - [5.4 Process Queues \& Schedulers (LTS, STS, MTS)](#54-process-queues--schedulers-lts-sts-mts)
    - [5.5 Dispatcher \& Context Switching](#55-dispatcher--context-switching)
    - [5.6 Process Creation \& Termination (`fork()`, `exec()`, `wait()`, `exit()`)](#56-process-creation--termination-fork-exec-wait-exit)
    - [5.7 Zombie, Orphan, and Daemon Processes](#57-zombie-orphan-and-daemon-processes)
  - [6. CPU Scheduling](#6-cpu-scheduling)
    - [6.1 CPU Burst \& Scheduling Criteria](#61-cpu-burst--scheduling-criteria)
    - [6.2 Preemptive vs. Non-Preemptive Scheduling](#62-preemptive-vs-non-preemptive-scheduling)
    - [6.3 First-Come, First-Served (FCFS) \& Convoy Effect](#63-first-come-first-served-fcfs--convoy-effect)
    - [6.4 Shortest Job First (SJF) \& Exponential Burst Prediction](#64-shortest-job-first-sjf--exponential-burst-prediction)
    - [6.5 Shortest Remaining Time First (SRTF)](#65-shortest-remaining-time-first-srtf)
    - [6.6 Priority Scheduling, Starvation \& Aging](#66-priority-scheduling-starvation--aging)
    - [6.7 Round Robin (RR) \& Quantum Selection](#67-round-robin-rr--quantum-selection)
    - [6.8 Multilevel Queue (MLQ) \& Multilevel Feedback Queue (MLFQ)](#68-multilevel-queue-mlq--multilevel-feedback-queue-mlfq)
    - [6.9 Multiprocessor Scheduling (Affinity \& Load Balancing)](#69-multiprocessor-scheduling-affinity--load-balancing)
  - [7. Threads \& Multithreading](#7-threads--multithreading)
    - [7.1 Concept of a Thread](#71-concept-of-a-thread)
    - [7.2 Process vs. Thread](#72-process-vs-thread)
    - [7.3 User-Level Threads (ULT) vs. Kernel-Level Threads (KLT)](#73-user-level-threads-ult-vs-kernel-level-threads-klt)
    - [7.4 Multithreading Models (Many-to-One, One-to-One, Many-to-Many)](#74-multithreading-models-many-to-one-one-to-one-many-to-many)
  - [8. Inter-Process Communication (IPC)](#8-inter-process-communication-ipc)
    - [8.1 Shared Memory vs. Message Passing](#81-shared-memory-vs-message-passing)
    - [8.2 Pipes (Anonymous Pipes vs. Named Pipes / FIFOs)](#82-pipes-anonymous-pipes-vs-named-pipes--fifos)
    - [8.3 Sockets, Message Queues \& Signals](#83-sockets-message-queues--signals)
  - [9. Process Synchronization \& Critical Section](#9-process-synchronization--critical-section)
    - [9.1 Concurrency, Race Conditions \& Critical Sections](#91-concurrency-race-conditions--critical-sections)
    - [9.2 Requirements of a Valid Critical Section Solution](#92-requirements-of-a-valid-critical-section-solution)
    - [9.3 Hardware-Assisted Synchronization (`TestAndSet`, `CompareAndSwap`)](#93-hardware-assisted-synchronization-testandset-compareandswap)
      - [`TestAndSet`](#testandset)
      - [`CompareAndSwap` (CAS)](#compareandswap-cas)
    - [9.4 Peterson's Solution (Two-Process Software Solution)](#94-petersons-solution-two-process-software-solution)
    - [9.5 Semaphores (Binary vs. Counting Semaphores)](#95-semaphores-binary-vs-counting-semaphores)
      - [Conceptual Operations](#conceptual-operations)
    - [9.6 Mutex vs. Binary Semaphore](#96-mutex-vs-binary-semaphore)
    - [9.7 Condition Variables \& Monitors](#97-condition-variables--monitors)
  - [10. Classical Synchronization Problems](#10-classical-synchronization-problems)
    - [10.1 Producer-Consumer (Bounded-Buffer) Problem](#101-producer-consumer-bounded-buffer-problem)
    - [10.2 Readers-Writers Problem](#102-readers-writers-problem)
    - [10.3 Dining Philosophers Problem](#103-dining-philosophers-problem)
    - [10.4 Sleeping Barber \& Cigarette Smokers Problems](#104-sleeping-barber--cigarette-smokers-problems)
  - [11. Deadlocks](#11-deadlocks)
    - [11.1 Definition \& Necessary Conditions (Coffman Conditions)](#111-definition--necessary-conditions-coffman-conditions)
      - [The 4 Coffman Conditions (Must hold simultaneously)](#the-4-coffman-conditions-must-hold-simultaneously)
    - [11.2 Resource Allocation Graphs (RAG)](#112-resource-allocation-graphs-rag)
    - [11.3 Deadlock Handling Strategies Overview](#113-deadlock-handling-strategies-overview)
    - [11.4 Deadlock Prevention](#114-deadlock-prevention)
    - [11.5 Deadlock Avoidance \& Banker's Algorithm](#115-deadlock-avoidance--bankers-algorithm)
      - [Safe vs. Unsafe State](#safe-vs-unsafe-state)
      - [Banker's Algorithm Data Structures](#bankers-algorithm-data-structures)
      - [Safety Algorithm](#safety-algorithm)
    - [11.6 Deadlock Detection \& Recovery](#116-deadlock-detection--recovery)
  - [12. Memory Management: Contiguous Allocation](#12-memory-management-contiguous-allocation)
    - [12.1 Address Binding \& MMU (Logical vs. Physical Addresses)](#121-address-binding--mmu-logical-vs-physical-addresses)
    - [12.2 Fixed vs. Dynamic Partitioning](#122-fixed-vs-dynamic-partitioning)
    - [12.3 Fragmentation (Internal vs. External)](#123-fragmentation-internal-vs-external)
    - [12.4 Dynamic Allocation Algorithms (First Fit, Best Fit, Worst Fit, Next Fit)](#124-dynamic-allocation-algorithms-first-fit-best-fit-worst-fit-next-fit)
  - [13. Paging \& Non-Contiguous Memory](#13-paging--non-contiguous-memory)
    - [13.1 Basic Architecture of Paging](#131-basic-architecture-of-paging)
    - [13.2 Address Translation in Paging](#132-address-translation-in-paging)
    - [13.3 Page Table Entries \& Flags](#133-page-table-entries--flags)
    - [13.4 Translation Lookaside Buffer (TLB) \& Effective Access Time (EAT)](#134-translation-lookaside-buffer-tlb--effective-access-time-eat)
      - [Effective Access Time (EAT) Formula](#effective-access-time-eat-formula)
    - [13.5 Multi-Level, Hashed, and Inverted Page Tables](#135-multi-level-hashed-and-inverted-page-tables)
    - [13.6 Shared Pages \& Reentrant Code](#136-shared-pages--reentrant-code)
  - [14. Segmentation \& Combined Schemes](#14-segmentation--combined-schemes)
    - [14.1 Segmentation Architecture \& Address Translation](#141-segmentation-architecture--address-translation)
    - [14.2 Paging vs. Segmentation Detailed Comparison](#142-paging-vs-segmentation-detailed-comparison)
    - [14.3 Segmented Paging](#143-segmented-paging)
  - [15. Virtual Memory \& Demand Paging](#15-virtual-memory--demand-paging)
    - [15.1 Concept of Virtual Memory](#151-concept-of-virtual-memory)
    - [15.2 Demand Paging \& The Page Fault Sequence](#152-demand-paging--the-page-fault-sequence)
    - [15.3 Effective Access Time (EAT) with Page Faults](#153-effective-access-time-eat-with-page-faults)
    - [15.4 Pure Demand Paging \& Locality of Reference](#154-pure-demand-paging--locality-of-reference)
  - [16. Page Replacement Algorithms](#16-page-replacement-algorithms)
    - [16.1 FIFO \& Belady's Anomaly](#161-fifo--beladys-anomaly)
    - [16.2 Optimal Page Replacement (Bélády's Min)](#162-optimal-page-replacement-béládys-min)
    - [16.3 Least Recently Used (LRU)](#163-least-recently-used-lru)
    - [16.4 LRU Approximations: Second Chance (Clock) \& Enhanced Second Chance](#164-lru-approximations-second-chance-clock--enhanced-second-chance)
      - [Second Chance (Clock) Algorithm](#second-chance-clock-algorithm)
      - [Enhanced Second Chance](#enhanced-second-chance)
    - [16.5 Counting Algorithms (LFU \& MFU)](#165-counting-algorithms-lfu--mfu)
  - [17. Thrashing \& Frame Allocation](#17-thrashing--frame-allocation)
    - [17.1 Cause \& Mechanism of Thrashing](#171-cause--mechanism-of-thrashing)
    - [17.2 Working Set Model](#172-working-set-model)
    - [17.3 Page-Fault Frequency (PFF) Strategy](#173-page-fault-frequency-pff-strategy)
  - [18. File Systems \& Storage Management](#18-file-systems--storage-management)
    - [18.1 File Concepts, Attributes \& Operations](#181-file-concepts-attributes--operations)
    - [18.2 File Control Block (FCB) \& Directory Structures](#182-file-control-block-fcb--directory-structures)
    - [18.3 Hard Links vs. Soft (Symbolic) Links](#183-hard-links-vs-soft-symbolic-links)
    - [18.4 File Allocation Methods (Contiguous, Linked, Indexed)](#184-file-allocation-methods-contiguous-linked-indexed)
    - [18.5 UNIX Inode Architecture \& Max File Size Calculations](#185-unix-inode-architecture--max-file-size-calculations)
      - [Maximum File Size Formula](#maximum-file-size-formula)
    - [18.6 Free Space Management (Bit Vector, Linked List, Grouping, Counting)](#186-free-space-management-bit-vector-linked-list-grouping-counting)
  - [19. Disk Structure \& Disk Scheduling](#19-disk-structure--disk-scheduling)
    - [19.1 Magnetic Disk Geometry \& Access Times](#191-magnetic-disk-geometry--access-times)
    - [19.2 Disk Scheduling Algorithms (FCFS, SSTF, SCAN, C-SCAN, LOOK, C-LOOK)](#192-disk-scheduling-algorithms-fcfs-sstf-scan-c-scan-look-c-look)
  - [20. I/O Management \& Kernel Subsystems](#20-io-management--kernel-subsystems)
    - [20.1 I/O Hardware: Ports, Buses, Controllers \& Registers](#201-io-hardware-ports-buses-controllers--registers)
    - [20.2 I/O Techniques: Polling, Interrupt-Driven I/O \& DMA](#202-io-techniques-polling-interrupt-driven-io--dma)
    - [20.3 Spooling vs. Buffering vs. Caching](#203-spooling-vs-buffering-vs-caching)
  - [21. Protection, Security \& System Threats](#21-protection-security--system-threats)
    - [21.1 Protection vs. Security](#211-protection-vs-security)
    - [21.2 Access Matrix, Access Control Lists (ACL) \& Capabilities](#212-access-matrix-access-control-lists-acl--capabilities)
    - [21.3 Common System Threats \& Attacks](#213-common-system-threats--attacks)
  - [22. High-Yield Comparison Tables](#22-high-yield-comparison-tables)
    - [22.1 Process vs. Thread](#221-process-vs-thread)
    - [22.2 Mutex vs. Semaphore vs. Spinlock](#222-mutex-vs-semaphore-vs-spinlock)
    - [22.3 Paging vs. Segmentation](#223-paging-vs-segmentation)
  - [23. Complete Formula Cheat Sheet](#23-complete-formula-cheat-sheet)
    - [CPU Scheduling](#cpu-scheduling)
    - [Memory \& Paging](#memory--paging)
    - [Storage \& Inode](#storage--inode)
  - [24. How to Solve OS Numerical Problems](#24-how-to-solve-os-numerical-problems)
    - [24.1 CPU Scheduling Numerical Walkthrough](#241-cpu-scheduling-numerical-walkthrough)
      - [Step 1: Draw Gantt Chart Tracking Remaining Times](#step-1-draw-gantt-chart-tracking-remaining-times)
      - [Step 2: Build Evaluation Table](#step-2-build-evaluation-table)
    - [24.2 Banker's Algorithm Numerical Walkthrough](#242-bankers-algorithm-numerical-walkthrough)
      - [Execution Steps:](#execution-steps)
    - [24.3 Effective Access Time (TLB) Numerical Walkthrough](#243-effective-access-time-tlb-numerical-walkthrough)
    - [24.4 UNIX Inode Maximum File Size Numerical Walkthrough](#244-unix-inode-maximum-file-size-numerical-walkthrough)

---

## 1. OS Fundamentals & Architecture

### 1.1 What is an Operating System?

An **Operating System (OS)** is system software that acts as an intermediary between computer hardware and user applications. It manages hardware resources (CPU, memory, I/O devices, storage) and provides a secure, abstracted, and convenient execution environment.

```text
+-------------------------------------------------------+
|                    Users / Humans                     |
+-------------------------------------------------------+
                           ↓
+-------------------------------------------------------+
|        Application Programs (Browser, Compiler, IDE)  |
+-------------------------------------------------------+
                           ↓
+-------------------------------------------------------+
|        Operating System (Process, Memory, File, I/O)  |
+-------------------------------------------------------+
                           ↓
+-------------------------------------------------------+
|       Computer Hardware (CPU, RAM, Disks, Devices)    |
+-------------------------------------------------------+
```

### 1.2 Fundamental Functions of an OS

1. **Resource Allocator / Manager:** Manages and arbitrates conflicting requests for CPU time, memory space, file storage, and I/O devices fairly and efficiently.
2. **Control Program:** Controls execution of user programs to prevent errors, resource conflicts, and unauthorized hardware access.
3. **Hardware Abstraction Layer (HAL):** Hides low-level hardware peculiarities (e.g., sector formatting, disk geometry) behind clean abstractions (files, streams, sockets).
4. **User Interface:** Provides Command Line Interfaces (CLI), Graphical User Interfaces (GUI), or programmatic Application Binary Interfaces (ABIs).

### 1.3 Application Software vs. System Software

| Dimension | Application Software | System Software |
| :--- | :--- | :--- |
| **Purpose** | Performs specific end-user tasks (e.g., MS Word, Chrome) | Manages and operates the computer hardware platform (e.g., Windows, Linux, Drivers) |
| **Execution Space** | User Space (unprivileged mode) | Kernel Space & privileged system daemons |
| **Hardware Access** | Indirect (must invoke system calls) | Direct or privileged access to hardware |
| **Dependency** | Depends on OS runtime and libraries | Autonomous; serves as the foundation for applications |

### 1.4 Primary Goals & Design Trade-offs

- **Maximize CPU Utilization:** Keep the CPU as busy as possible ($100\%$ theoretical).
- **Maximize Throughput:** Complete the highest number of processes per unit of time.
- **Minimize Turnaround Time (TAT):** Minimize time elapsed between process submission and completion.
- **Minimize Waiting Time (WT):** Minimize total time spent waiting in the ready queue.
- **Minimize Response Time (RT):** Minimize time from submission to the very first CPU output/response.
- **Fairness & Starvation Prevention:** Guarantee every process eventually receives resources.

> [!NOTE]
> Different computing domains prioritize different metrics:
> - **Desktop/Personal OS:** Prioritizes responsiveness and user experience.
> - **Server/Cloud OS:** Prioritizes throughput and resource utilization.
> - **Real-Time Systems:** Prioritizes determinism and strict deadline adherence.

### 1.5 OS Architectures: Monolithic, Microkernel, Layered, Hybrid

```text
Monolithic Architecture                Microkernel Architecture
+-------------------------------+      +-------------------------------+
| User Apps | Shell | Libraries |      | User Apps | Drivers | Servers | (User Space)
+-------------------------------+      +-------------------------------+
| IPC, VFS, Memory, Scheduler,  | (Kernel)           ↓ IPC / System Calls
| Network, Hardware Drivers     |      +-------------------------------+
+-------------------------------+      | IPC | Scheduler | Basic Memory| (Kernel Space)
+-------------------------------+      +-------------------------------+
|            Hardware           |      |            Hardware           |
+-------------------------------+      +-------------------------------+
```

| Feature | Monolithic Kernel | Microkernel |
| :--- | :--- | :--- |
| **Structure** | All OS services (VFS, drivers, networking, IPC) run inside the kernel address space. | Only minimal essential services (IPC, basic scheduling, virtual memory) stay in the kernel; drivers and filesystems run in user space as servers. |
| **Performance** | **High performance:** Communication between components is via direct function calls. | **Slightly lower:** Heavy IPC overhead and context switching between user servers and microkernel. |
| **Extensibility & Reliability** | Poor isolation: A bug in any device driver can crash the entire OS. | High isolation: Crashed user-space drivers can be restarted without bringing down the kernel. |
| **Examples** | Linux, traditional UNIX, MS-DOS | Mach, QNX, Minix, L4 |
| **Hybrid Kernels** | Combines microkernel modularity with monolithic speed (e.g., Windows NT, macOS XNU). |

---

## 2. Types of Operating Systems

### 2.1 Single-Tasking / Batch Processing Systems

- **Single-Tasking:** Only one process resides in memory and executes at a time (e.g., early MS-DOS). CPU sits completely idle during I/O operations.
- **Batch Processing:** Similar jobs are batched together on punched cards/tapes and submitted via a human operator. No interactive execution; high turnaround time.

### 2.2 Multiprogramming Systems

- **Core Concept:** Multiple jobs are loaded into main memory simultaneously.
- **Working Mechanism:** When the currently executing process requests I/O, the OS switches CPU allocation to another process waiting in the ready queue.
- **Primary Goal:** Maximize **CPU Utilization**.

```text
Memory
+---------------+
| OS Kernel     |
+---------------+
| Job 1 (I/O)   | ───> Waiting for Disk/Network
+---------------+
| Job 2 (Ready) | ───> CPU switches here immediately (No CPU Idleness)
+---------------+
| Job 3         |
+---------------+
```

### 2.3 Multitasking & Time-Sharing Systems

- **Logical extension of multiprogramming:** CPU time is sliced into small intervals (time quanta, e.g., $10\text{ ms} - 100\text{ ms}$).
- The CPU switches among active processes so rapidly that users perceive simultaneous execution.
- **Primary Goal:** Minimize **Response Time** and provide interactive computing.

### 2.4 Multiprocessing Systems (SMP vs. ASMP)

Computers containing two or more physical CPUs or multi-core processors sharing memory and system buses.

```text
Symmetric Multiprocessing (SMP)        Asymmetric Multiprocessing (ASMP)
+------+ +------+ +------+             +-------------+  +-------------+
| CPU1 | | CPU2 | | CPU3 |             | Master CPU  |  | Slave CPU 1 |
+--+---+ +---+--+ +---+--+             | (OS tasks)  |  | (User tasks)|
   |         |        |                +------+------+  +------+------+
===+=========+========+=== (Bus)              |                |
     | Main Memory |                   =======+================+======
```

- **Symmetric Multiprocessing (SMP):** All processors are peers; any processor can run OS kernel routines and user tasks. Standard in modern OSes (Linux, Windows, macOS).
- **Asymmetric Multiprocessing (ASMP):** A master processor allocates tasks and runs the OS, while slave processors execute assigned user jobs.

### 2.5 Distributed & Clustered Operating Systems

- **Distributed OS:** Manages a collection of physically independent, networked computers and presents them to users as a single unified system (loosely coupled).
- **Clustered OS:** Combines multiple independent nodes sharing storage area networks (SAN) to provide high availability and load balancing.

### 2.6 Real-Time Operating Systems (Hard vs. Soft RTOS)

An RTOS guarantees processing within strictly defined timing constraints (deadlines).

```text
Hard RTOS vs Soft RTOS
+----------------------------------+----------------------------------+
| Hard Real-Time                   | Soft Real-Time                   |
| Missing a deadline = Catastrophe | Missing a deadline = Performance |
| & complete system failure.       | degradation, but acceptable.     |
| Examples: Airbag controller,     | Examples: Video streaming,       |
| Pacemaker, Flight guidance.      | Online gaming, VoIP audio.       |
+----------------------------------+----------------------------------+
```

---

## 3. Kernel, System Calls & Operating Modes

### 3.1 The Kernel & User Space

- **Kernel Space:** Protected memory region where the core operating system code, device drivers, and kernel data structures reside.
- **User Space:** Sandboxed memory partition where standard user applications, GUI shells, and user libraries execute without direct hardware privileges.

### 3.2 Dual-Mode Operation (User Mode vs. Kernel Mode)

To protect the system from erratic or malicious programs, modern CPU hardware enforces at least two execution modes, tracked by a hardware **Mode Bit** (e.g., $0 = \text{Kernel Mode}$, $1 = \text{User Mode}$).

```text
User Mode (Mode Bit = 1)                 Kernel Mode (Mode Bit = 0)
+------------------------+               +--------------------------+
| User Application       |               | Kernel System Call       |
| calls library wrapper  |               | Handler executes service |
+-----------+------------+               +------------+-------------+
            |                                         |
            | Trap / Syscall (Mode bit -> 0)          | Return (Mode bit -> 1)
            ↓                                         ↓
+-------------------------------------------------------------------+
|                     Hardware Mode Switch                          |
+-------------------------------------------------------------------+
```

- **Privileged Instructions:** Instructions that can only be executed in Kernel Mode (e.g., direct I/O port access, modifying the Page Table Base Register, disabling interrupts, clearing the timer). If executed in User Mode, the CPU raises a hardware trap/exception.

### 3.3 System Calls vs. Library/Function Calls

```text
User Application
       ↓ (e.g., printf("Hello"))
C Standard Library (libc)
       ↓ (wraps write() with SYS_write number in register)
System Call / Trap Instruction (e.g., 'syscall' / 'int 0x80')
       ↓ [Hardware switches to Kernel Mode, consults Interrupt Vector Table]
Kernel System Call Handler (sys_write)
       ↓
Device Driver & Hardware
```

| Property | Library Function Call | System Call |
| :--- | :--- | :--- |
| **Execution Domain** | Executes entirely in User Space | Transitions execution from User Space to Kernel Space |
| **Overhead** | Very low (simple stack push and jump) | Higher (context switch, register saves, privilege change, security validation) |
| **Example** | `sqrt()`, `strcpy()`, `atoi()` | `fork()`, `read()`, `write()`, `mmap()`, `kill()` |

### 3.4 Categories of System Calls

```text
1. Process Control:      fork(), execve(), wait(), exit(), getpid(), brk()
2. File Management:      open(), read(), write(), close(), unlink(), stat()
3. Device Management:    ioctl(), read(), write(), attach/detach
4. Information/System:   gettimeofday(), sysinfo(), uname(), time()
5. Communication / IPC:  pipe(), shmget(), mmap(), msgget(), socket(), send(), recv()
6. Protection/Security:  chmod(), chown(), umask()
```

### 3.5 Interrupts, Traps, Faults, and Aborts

```text
Hardware Interrupt (Asynchronous)     Trap / Exception (Synchronous)
Generated by external hardware        Generated internally by CPU during
(e.g., Timer tick, Disk I/O done)     instruction execution (e.g., Divide by 0, Syscall)
```

- **Hardware Interrupt:** Asynchronous event triggered by physical hardware (timer, keyboard, network card) asserting an interrupt line.
- **Trap (Software Interrupt):** Synchronous instruction purposefully executed by software (e.g., `syscall`) to request kernel services.
- **Fault:** Recoverable exception generated before an instruction completes (e.g., **Page Fault**). Once serviced, the CPU re-executes the faulting instruction.
- **Abort:** Severe unrecoverable hardware or parity failure. Results in process termination.

---

## 4. Booting, Hardware Interface & Architecture

### 4.1 The Complete Booting Sequence (POST, BIOS/UEFI, Bootloader)

```text
[1. Power ON]
      ↓
[2. CPU Reset & Jump to Firmware Entry Address in ROM / Flash]
      ↓
[3. BIOS / UEFI Initialized] ──> Runs POST (Power-On Self-Test: RAM, CPU, Bus check)
      ↓
[4. Locate Boot Device (Disk / NVMe / USB) via Boot Order]
      ↓
[5. Load Bootloader (MBR Sector 0 or EFI System Partition / GRUB)]
      ↓
[6. Bootloader loads Kernel Image & Initrd into Main Memory]
      ↓
[7. Kernel initializes Hardware, Memory Pages, Drivers & Mounts Root FS]
      ↓
[8. Kernel spawns PID 1 (init / systemd in User Space)]
      ↓
[9. System Daemons, Login Prompt & User GUI Shell started]
```

- **BIOS vs. UEFI:**
  - **BIOS (Legacy):** 16-bit real mode, limited to Master Boot Record (MBR) partition tables ($\le 2\text{ TB}$, max 4 primary partitions).
  - **UEFI (Modern):** 32/64-bit mode, supports GPT (GUID Partition Table, $>2\text{ TB}$ disks, $128$ partitions), Secure Boot, and faster initialization.

### 4.2 32-bit vs. 64-bit Systems

- **Addressable Memory Limit:**
  - 32-bit architecture: $2^{32}\text{ bytes} = 4\text{ GiB}$ maximum direct physical memory address space.
  - 64-bit architecture: $2^{64}\text{ bytes} = 16\text{ Exbibytes}$ (in practice, modern architectures use 48-bit or 57-bit virtual addressing, supporting terabytes of RAM).
- **Register Size & Pointer Width:** 32-bit uses 4-byte pointers; 64-bit uses 8-byte pointers, allowing wider arithmetic operations per clock cycle.

### 4.3 Memory & Storage Hierarchy

```text
                       ▲  Fastest, Smallest, Highest Cost / Bit
                      / \
                     /   \    Registers (< 1 KB, ~0.5 ns)
                    /     \
                   /       \   L1, L2, L3 Cache (MBs, 1-10 ns)
                  /         \
                 /           \  Main Memory / RAM (GBs, ~50-100 ns)
                /             \
               /               \ Solid-State Drives / NVMe (TBs, ~10-100 μs)
              /                 \
             /                   \ Hard Disk Drives / Network Storage (~ms)
            /─────────────────────\
             ▼  Slowest, Largest, Lowest Cost / Bit, Non-Volatile
```

---

## 5. Process Management & Lifecycle

### 5.1 Program vs. Process

```text
Program (Passive)                         Process (Active)
+-----------------------+                 +--------------------------------+
| Stored on Disk        |  Loaded via     | Resides in RAM                 |
| Binary file / code    | ─────────────>  | Has Program Counter, Stack,    |
| No CPU/memory consumed|  execve()       | Heap, Open File Descriptors    |
+-----------------------+                 +--------------------------------+
```

### 5.2 Process Control Block (PCB) & Memory Layout

The **Process Control Block (PCB)** is the central data structure maintained by the OS for every active process.

```text
+--------------------------------------+      Process Virtual Memory Layout
|         Process ID (PID, PPID)       |      High Address (0xFFFFFFFF)
+--------------------------------------+      +-----------------------------+
|         Process State                |      | Stack (Local vars, frames)  |
+--------------------------------------+      |              ↓              |
|         Program Counter (PC)         |      |                             |
+--------------------------------------+      |              ↑              |
|         CPU Registers (SP, AX, BX...) |     | Heap (malloc / dynamic mem) |
+--------------------------------------+      +-----------------------------+
|         CPU Scheduling Info          |      | BSS (Uninitialized Globals) |
+--------------------------------------+      +-----------------------------+
|         Memory Management (PTBR)     |      | Data (Initialized Globals)  |
+--------------------------------------+      +-----------------------------+
|         Accounting & Limits          |      | Text (Compiled Code / Read) |
+--------------------------------------+      +-----------------------------+
|         List of Open I/O Files       |      Low Address (0x00000000)
+--------------------------------------+
```

### 5.3 Process State Transitions (5-State and 7-State Models)

#### Classic 5-State Transition Diagram

```text
                [New]
                  │  admitted
                  ▼
            ┌───────────┐
            │   Ready   │◀──────────────┐
            └─────┬─────┘               │
      scheduler   │                     │ timer expire /
      dispatch    │                     │ preemption
                  ▼                     │
            ┌───────────┐               │
            │  Running  │───────────────┘
            └─────┬─────┘
                  │  I/O wait / event wait
                  ▼
            ┌───────────┐
            │  Waiting  │───────────────┐
            │  (Blocked)│  I/O complete │
            └───────────┘ (event occurs)│
                  │                     │
                  └─────────────────────┘
```

#### Extended 7-State Model (With Swapping)

When main memory is constrained, the OS swapper (Medium-Term Scheduler) moves inactive processes to secondary storage:

```text
Ready (RAM)       ──[Suspend / Swap Out]──>  Suspend Ready (Disk)
Waiting (RAM)     ──[Suspend / Swap Out]──>  Suspend Blocked (Disk)
Suspend Blocked   ──[Event Occurs]────────>  Suspend Ready
Suspend Ready     ──[Resume / Swap In]────>  Ready (RAM)
```

### 5.4 Process Queues & Schedulers (LTS, STS, MTS)

- **Job Queue:** Holds all submitted programs awaiting admission.
- **Ready Queue:** Holds all processes resident in main memory, ready and waiting for CPU time.
- **Device / Waiting Queue:** Holds processes waiting for specific I/O devices or synchronization events.

```text
+------------------------+------------------------------------+--------------------------+
| Scheduler              | Primary Function                   | Invocation Frequency     |
+------------------------+------------------------------------+--------------------------+
| Long-Term (Job)        | Selects jobs from pool, loads into | Infrequent (Seconds /    |
|                        | RAM; controls multiprogramming.    | Minutes)                 |
+------------------------+------------------------------------+--------------------------+
| Short-Term (CPU)       | Selects ready process and allocates| Extremely Frequent       |
|                        | CPU.                               | (Every 10-100 ms)        |
+------------------------+------------------------------------+--------------------------+
| Medium-Term (Swapper)  | Swaps processes between RAM and    | Intermediate             |
|                        | secondary storage.                 | (As memory pressure rises)
+------------------------+------------------------------------+--------------------------+
```

### 5.5 Dispatcher & Context Switching

The **Dispatcher** is the kernel module that gives control of the CPU to the process selected by the Short-Term Scheduler:

1. **Saves context** of currently running process $P_1$ into its PCB.
2. Updates $P_1$'s state (Ready/Waiting).
3. Moves PCB of $P_2$ into active CPU registers (PC, SP, Base/Limit registers).
4. Switches CPU to User Mode and jumps to $P_2$'s Program Counter.

> [!IMPORTANT]
> **Context Switch Overhead:** During a context switch, the CPU performs zero useful user work. Context switch latency includes register saving, cache invalidation, and TLB flushes.

### 5.6 Process Creation & Termination (`fork()`, `exec()`, `wait()`, `exit()`)

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        char *args[] = {"/bin/ls", "-l", NULL};
        execvp(args[0], args); // Overlays child address space with new binary
    } else {
        // Parent process
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        int status;
        wait(&status); // Blocks until child terminates and reaps child exit status
        printf("Child reaped successfully.\n");
    }
    return 0;
}
```

- **`fork()`:** Duplicates calling process (creates child). Returns `0` to child, child PID to parent, `-1` on error. Uses **Copy-on-Write (COW)** optimization.
- **`execve()` / `exec()` family:** Replaces current process memory space, stack, heap, and code segment with a new executable program.
- **`wait()` / `waitpid()`:** Suspends parent until a child process terminates; collects child exit code.
- **`exit()`:** Terminates process, frees allocated memory, closes file descriptors, retains exit status in process table until reaped.

### 5.7 Zombie, Orphan, and Daemon Processes

```text
                       Process Lifecycle Quirks
+-------------------------------------------------------------------------------+
| Zombie Process                                                                |
| - A process that has finished execution (via exit()) but still has an entry   |
|   in the Process Table because its parent has NOT yet called wait().          |
| - Consumes no RAM or CPU, but occupies a PID slot.                            |
| - Reaping: Once parent calls wait(), the zombie is removed.                   |
+-------------------------------------------------------------------------------+
| Orphan Process                                                                |
| - A process actively running whose parent terminated before calling wait().   |
| - Adoption: Automatically adopted by systemd / init (PID 1), which            |
|   periodically reaps terminated children.                                     |
+-------------------------------------------------------------------------------+
| Daemon Process                                                                |
| - Background, non-interactive process running detached from any controlling   |
|   terminal (e.g., sshd, cron, systemd-journald).                              |
+-------------------------------------------------------------------------------+
```

---

## 6. CPU Scheduling

### 6.1 CPU Burst & Scheduling Criteria

Processes alternate between **CPU execution bursts** and **I/O wait bursts**.

```text
CPU-Bound Process:    [─── Long CPU Burst ───] [IO] [─── Long CPU Burst ───]
I/O-Bound Process:    [CPU] [────── Long I/O Wait ──────] [CPU] [── Long I/O ──]
```

- **Turnaround Time ($\text{TAT}$):** $\text{TAT} = \text{Completion Time (CT)} - \text{Arrival Time (AT)}$
- **Waiting Time ($\text{WT}$):** $\text{WT} = \text{Turnaround Time (TAT)} - \text{Burst Time (BT)}$
- **Response Time ($\text{RT}$):** $\text{RT} = \text{Time of First CPU Allocation} - \text{Arrival Time (AT)}$
- **Throughput:** Processes completed per unit of time ($\frac{\text{Total Processes}}{\text{Total Schedule Time}}$).
- **CPU Utilization:** Percentage of time CPU is executing instructions.

### 6.2 Preemptive vs. Non-Preemptive Scheduling

- **Non-Preemptive:** Once the CPU is allocated to a process, the process retains it until it either terminates or voluntarily yields the CPU (e.g., requests I/O).
- **Preemptive:** The OS scheduler can forcibly interrupt a currently running process to assign the CPU to a higher-priority or newly arrived process (e.g., timer interrupt, priority arrival).

### 6.3 First-Come, First-Served (FCFS) & Convoy Effect

- **Policy:** Processes are allocated the CPU strictly in order of arrival time (FIFO queue).
- **Type:** Non-Preemptive.
- **Convoy Effect:** If a heavy CPU-bound process arrives before short I/O-bound processes, all subsequent processes get delayed behind it, leading to poor average waiting time and underutilized I/O devices.

### 6.4 Shortest Job First (SJF) & Exponential Burst Prediction

- **Policy:** Allocates CPU to the process with the smallest next CPU burst length.
- **Optimality:** Proven to yield the **minimum average waiting time** for a given set of stationary processes.
- **Limitation:** Cannot know future burst times in advance.
- **Exponential Smoothing Formula:**
  $$\tau_{n+1} = \alpha \cdot t_n + (1 - \alpha) \cdot \tau_n$$
  - $t_n$: Actual duration of the $n$-th CPU burst.
  - $\tau_n$: Predicted duration of the $n$-th burst.
  - $\tau_{n+1}$: Predicted duration for the next $(n+1)$-th burst.
  - $\alpha$: Smoothing factor ($0 \le \alpha \le 1$, typically $\alpha = 0.5$).

### 6.5 Shortest Remaining Time First (SRTF)

- **Policy:** Preemptive version of SJF. When a new process arrives with a remaining burst time smaller than the currently executing process's remaining time, the running process is preempted.
- **Advantage:** Minimizes waiting time for short jobs dynamically.
- **Disadvantage:** Risk of **starvation** for long-burst jobs if short jobs arrive continuously.

### 6.6 Priority Scheduling, Starvation & Aging

- **Policy:** Each process is assigned an integer priority (conventionally, smaller integer = higher priority). The CPU is assigned to the highest-priority process.
- **Problem: Starvation (Indefinite Blocking):** Low-priority processes may never execute in heavily loaded systems.
- **Solution: Aging:** Technique of gradually increasing the priority of processes that have waited in the ready queue for prolonged durations.
- **Priority Inversion & Priority Inheritance:** When a low-priority task holds a resource needed by a high-priority task, medium-priority tasks can preempt the low-priority task, indirectly starving the high-priority task. Solution: Temporarily elevate the low-priority task to the priority of the waiting high-priority task (**Priority Inheritance Protocol**).

### 6.7 Round Robin (RR) & Quantum Selection

- **Policy:** Specifically designed for time-sharing. The ready queue is treated as a circular FIFO queue. Each process is allocated a fixed time slice (**Time Quantum $q$**).
- **Quantum Trade-offs:**
  - $q \to \infty$: Round Robin degenerates into **FCFS**.
  - $q \to 0$: Severe context-switch overhead dominates execution.
  - **Rule of Thumb:** $80\%$ of CPU bursts should be shorter than the time quantum $q$.

```text
Ready Queue: [P1, P2, P3] (Quantum = 4ms)
Gantt Chart:
|   P1 (4ms)   |   P2 (4ms)   |   P3 (2ms)   |   P1 (2ms)   |
0              4              8             10             12
```

### 6.8 Multilevel Queue (MLQ) & Multilevel Feedback Queue (MLFQ)

```text
Multilevel Queue (MLQ)                Multilevel Feedback Queue (MLFQ)
+-------------------------+           +-----------------------------+
| Queue 1: System (RR)    |           | Q1 (RR, q=4ms) [Highest]    | ──(Demote if burst > 4)──┐
+-------------------------+           +-----------------------------+                          │
| Queue 2: Interactive(RR)|           | Q2 (RR, q=8ms) [Medium]     | ◀────────────────────────┘
+-------------------------+           +-----------------------------+                          │
| Queue 3: Batch (FCFS)   |           | Q3 (FCFS)      [Lowest]     | ◀──(Demote if burst > 8)─┘
+-------------------------+           +-----------------------------+
(Processes fixed in queue)            (Processes dynamically move; Aging promotes up)
```

### 6.9 Multiprocessor Scheduling (Affinity & Load Balancing)

- **Processor Affinity:** A process prefers to continue executing on the same CPU core to benefit from cached memory lines (**Soft Affinity** = OS preference; **Hard Affinity** = strictly bound via `sched_setaffinity`).
- **Load Balancing:**
  - **Push Migration:** A specific monitor routine checks imbalances and pushes tasks from overloaded to idle cores.
  - **Pull Migration:** An idle processor pulls pending tasks from the ready queue of busy cores.

---

## 7. Threads & Multithreading

### 7.1 Concept of a Thread

A **thread** is the fundamental unit of CPU utilization (lightweight process). It represents an independent control flow inside a process.

```text
Single-Threaded Process                   Multi-Threaded Process
+------------------------------------+    +------------------------------------+
| Code | Data | Heap | Files         |    | Code | Data | Heap | Files         |
+------------------------------------+    +------------------------------------+
| Registers | Stack                  |    | Regs | Stack | Regs | Stack | Regs |
| (Thread 1)                         |    |  T1  |  T1   |  T2  |  T2   |  T3  |
+------------------------------------+    +------------------------------------+
```

### 7.2 Process vs. Thread

| Dimension | Process | Thread |
| :--- | :--- | :--- |
| **Address Space** | Isolated, private address space | Shares address space (Code, Data, Heap) with peer threads |
| **Creation & Destruction** | Expensive (heavyweight, allocates memory pages, file tables) | Cheap (lightweight, allocates private stack & registers) |
| **Context Switch Overhead** | High (flushes TLB, swaps page tables, invalidates cache) | Low (retains page tables and memory mappings) |
| **Communication** | Requires IPC (Pipes, Shared Memory, Sockets) | Direct memory reads/writes to shared variables |
| **Fault Isolation** | High: One process crash does not terminate others | Low: An illegal memory access in one thread crashes the entire process |

### 7.3 User-Level Threads (ULT) vs. Kernel-Level Threads (KLT)

```text
User-Level Threads (ULT)               Kernel-Level Threads (KLT)
+-----------------------+              +-----------------------+
| Thread Library (User) |              | User App              |
+-----------------------+              +-----------------------+
           │                                       │
+──────────▼────────────+              +───────────▼───────────+
| Single Kernel Entity  |              | Kernel Thread Table   |
+-----------------------+              +-----------------------+
| Operating System      |              | Operating System      |
+-----------------------+              +-----------------------+
```

| Metric | User-Level Threads (ULT) | Kernel-Level Threads (KLT) |
| :--- | :--- | :--- |
| **Management** | Implemented by user library (e.g., Green threads, fibers) | Managed directly by the OS Kernel scheduler |
| **Switching Speed** | Ultra-fast (pure user-space function call; no mode switch) | Slower (requires trap to kernel mode) |
| **System Call Blocking** | If one thread executes a blocking syscall, the **entire process blocks** | If one thread blocks, other threads continue executing on CPU |
| **Multicore Parallelism**| Cannot achieve true multi-core parallel execution | Can schedule different threads on separate physical CPU cores |

### 7.4 Multithreading Models (Many-to-One, One-to-One, Many-to-Many)

- **Many-to-One ($N:1$):** Many user threads mapped to 1 kernel thread. Fast switching, but no multi-core parallelism and blocking syscalls halt everything.
- **One-to-One ($1:1$):** Every user thread maps directly to 1 kernel thread. Supports true parallelism. Default model in Linux (NPTL) and Windows.
- **Many-to-Many ($M:N$):** Multiplexes $M$ user threads over $N$ kernel threads ($M \ge N$). Maximum flexibility, but high implementation complexity.

---

## 8. Inter-Process Communication (IPC)

### 8.1 Shared Memory vs. Message Passing

```text
Shared Memory Model                   Message Passing Model
+-------------+  +-------------+      +-------------+        +-------------+
|  Process A  |  |  Process B  |      |  Process A  |        |  Process B  |
+------+------+  +------+------+      +------+------+        +------+------+
       |                |                    |                      ▲
       ↓                ↓                    ↓                      │
+------------------------------+      +------------------------------------+
|     Shared Memory Region     |      |          Kernel Message            |
| (Fast, Zero Kernel Overhead) |      |          Queue / Pipe              |
+------------------------------+      +------------------------------------+
```

| Feature | Shared Memory | Message Passing |
| :--- | :--- | :--- |
| **Mechanism** | Region of memory mapped into both address spaces | System calls: `send(msg)` and `receive(msg)` via kernel |
| **Performance** | Maximum speed (memory read/write speeds, no syscalls after setup) | Slower (requires context switches and kernel buffer copies) |
| **Synchronization** | Programmer must handle synchronization (Mutex/Semaphores) | Synchronization built-in (blocking/non-blocking queues) |
| **Suitability** | Best for large data exchange on single machine | Natural for distributed systems & microservices |

### 8.2 Pipes (Anonymous Pipes vs. Named Pipes / FIFOs)

- **Anonymous Pipe:** Unidirectional byte stream used for parent-child communication (`pipe()` syscall in UNIX). Exists only while the process is active.
- **Named Pipe (FIFO):** Appears as a special file on the filesystem (`mkfifo`). Unrelated processes can open it for bidirectional/unidirectional communication across lifecycles.

### 8.3 Sockets, Message Queues & Signals

- **Sockets:** Bidirectional communication endpoint across networks (TCP/UDP) or locally (UNIX Domain Sockets).
- **Message Queues:** Kernel-maintained linked lists of typed messages (`msgget`, `msgsnd`, `msgrcv`).
- **Signals:** Asynchronous software notifications delivered to processes (e.g., `SIGINT`, `SIGKILL`, `SIGSEGV`).

---

## 9. Process Synchronization & Critical Section

### 9.1 Concurrency, Race Conditions & Critical Sections

- **Race Condition:** An undesirable situation where multiple concurrent threads access and manipulate shared data, and the final outcome depends on the non-deterministic order of execution.
- **Critical Section:** The section of code that accesses shared mutable state (e.g., shared variables, buffers, files).

```c
// Standard Critical Section Skeleton
do {
    // 1. Entry Section (Acquire permission/lock)
    
    // 2. Critical Section (Access shared variables)
    
    // 3. Exit Section (Release lock / signal others)
    
    // 4. Remainder Section (Non-critical work)
} while (true);
```

### 9.2 Requirements of a Valid Critical Section Solution

Any valid solution to the critical section problem must satisfy three mandatory criteria:

1. **Mutual Exclusion (Safety):** If process $P_i$ is executing in its critical section, no other processes can be executing in their critical sections.
2. **Progress (Liveness):** If no process is in its critical section and some processes wish to enter, only those processes not in their remainder section can participate in deciding who enters next, and this selection cannot be postponed indefinitely.
3. **Bounded Waiting (Starvation Freedom):** There must exist a bound on the number of times other processes are allowed to enter their critical sections after a process has made a request to enter and before that request is granted.

### 9.3 Hardware-Assisted Synchronization (`TestAndSet`, `CompareAndSwap`)

Atomic hardware instructions execute in a single clock cycle without interruption.

#### `TestAndSet`

```c
// Atomic Hardware Primitive
bool TestAndSet(bool *target) {
    bool rv = *target;
    *target = true;
    return rv;
}

// Mutual Exclusion Implementation (Spinlock)
do {
    while (TestAndSet(&lock))
        ; // Busy wait (Spinning)
    
    // Critical Section
    
    lock = false;
    
    // Remainder Section
} while (true);
```

#### `CompareAndSwap` (CAS)

```c
// Atomic Hardware Primitive
int CompareAndSwap(int *value, int expected, int new_value) {
    int temp = *value;
    if (*value == expected)
        *value = new_value;
    return temp;
}
```

### 9.4 Peterson's Solution (Two-Process Software Solution)

A classic algorithmic solution for two processes ($P_0$ and $P_1$) using shared variables:

```c
// Shared Variables
bool flag[2] = {false, false}; // flag[i] = true means Pi wants to enter
int turn;                      // Indicates whose turn it is

// Code for Process Pi (where Pj is the other process)
do {
    flag[i] = true;
    turn = j;
    while (flag[j] && turn == j) {
        // Busy wait
    }

    // --- CRITICAL SECTION ---

    flag[i] = false;

    // --- REMAINDER SECTION ---
} while (true);
```

> [!NOTE]
> **Proof of Correctness:**
> - **Mutual Exclusion:** For both to enter, `turn == 0` and `turn == 1` must hold simultaneously, which is impossible.
> - **Progress:** The `turn` variable resolves ties immediately.
> - **Bounded Waiting:** A process waits at most one entry before gaining access.

### 9.5 Semaphores (Binary vs. Counting Semaphores)

A **Semaphore $S$** is an integer variable accessed solely through two standard atomic operations: `wait()` (also known as `P()`) and `signal()` (also known as `V()`).

#### Conceptual Operations

```c
void wait(Semaphore S) {
    S.value--;
    if (S.value < 0) {
        // Add this process to S.queue
        block();
    }
}

void signal(Semaphore S) {
    S.value++;
    if (S.value <= 0) {
        // Remove a process P from S.queue
        wakeup(P);
    }
}
```

- **Binary Semaphore (Mutex semaphore):** Value can only be $0$ or $1$. Used to guarantee mutual exclusion.
- **Counting Semaphore:** Value spans an unrestricted integer domain ($0$ to $N$). Used to control access to a finite pool of $N$ identical resources.

### 9.6 Mutex vs. Binary Semaphore

| Feature | Mutex | Binary Semaphore |
| :--- | :--- | :--- |
| **Concept** | Locking mechanism | Signaling mechanism |
| **Ownership** | **Strict Ownership:** Only the thread that locked the mutex can unlock it. | **No Ownership:** Any thread can invoke `signal()` to unblock a waiting thread. |
| **Use Case** | Protecting critical sections | Synchronizing events, task coordination |
| **Priority Inversion** | Can be resolved via Priority Inheritance protocols | Difficult to apply priority inheritance due to lack of ownership |

### 9.7 Condition Variables & Monitors

- **Monitor:** High-level language construct that encapsulates shared data structures, procedures, and synchronization. Only one thread can be active inside a monitor at any moment.
- **Condition Variables:** Support synchronization within monitors via two operations:
  - `x.wait()`: Suspends calling thread and releases the monitor lock.
  - `x.signal()`: Resumes exactly one suspended thread waiting on condition `x`.

---

## 10. Classical Synchronization Problems

### 10.1 Producer-Consumer (Bounded-Buffer) Problem

- **Shared State:** Buffer of size $N$, `mutex = 1`, `empty = N`, `full = 0`.

```c
// PRODUCER
do {
    // Produce item
    wait(empty);  // Decrement empty slots (blocks if buffer full)
    wait(mutex);  // Protect buffer insertion
    
    // Insert item into buffer
    
    signal(mutex);
    signal(full);  // Increment filled slots
} while (true);

// CONSUMER
do {
    wait(full);   // Decrement filled slots (blocks if buffer empty)
    wait(mutex);  // Protect buffer extraction
    
    // Remove item from buffer
    
    signal(mutex);
    signal(empty); // Increment empty slots
    
    // Consume item
} while (true);
```

### 10.2 Readers-Writers Problem

- **Rules:** Multiple readers can read simultaneously. Only one writer can write at a time (exclusive access).
- **First Readers-Writers Problem (Reader-Priority):**

```c
// Shared State
int read_count = 0;
Semaphore mutex = 1; // Protects read_count
Semaphore wrt = 1;   // Protects shared dataset

// WRITER PROCESS
do {
    wait(wrt);
    
    // Perform Writing
    
    signal(wrt);
} while (true);

// READER PROCESS
do {
    wait(mutex);
    read_count++;
    if (read_count == 1) {
        wait(wrt); // First reader locks the writer
    }
    signal(mutex);

    // Perform Reading

    wait(mutex);
    read_count--;
    if (read_count == 0) {
        signal(wrt); // Last reader unlocks the writer
    }
    signal(mutex);
} while (true);
```

> [!WARNING]
> In Reader-Priority, continuous arrival of readers will lead to **Writer Starvation**.

### 10.3 Dining Philosophers Problem

Five philosophers sit around a circular table with 5 chopsticks. Each needs 2 chopsticks (left and right) to eat.

```text
       Philosopher 0
       [Chopstick 0]
Philosopher 4     Philosopher 1
 [Chopstick 4]   [Chopstick 1]
    Philosopher 3   Philosopher 2
       [Chopstick 3]
```

- **Deadlock Condition:** If all philosophers sit simultaneously and pick up their left chopstick (`wait(chopstick[i])`), all chopsticks are held, and everyone waits indefinitely for their right chopstick (Circular Wait).
- **Deadlock-Free Solutions:**
  1. **Asymmetric Ordering:** Odd philosophers pick up left then right; even philosophers pick up right then left.
  2. **Atomic Pickups:** Allow a philosopher to pick up chopsticks only if both are simultaneously available (using a monitor or mutex).
  3. **Capacity Limiting:** Allow at most 4 philosophers to sit at the table at the same time.

### 10.4 Sleeping Barber & Cigarette Smokers Problems

- **Sleeping Barber:** Barber sleeps when no customers are present; customers wake the barber or wait in waiting-room chairs; leave if chairs are full (bounded queue coordination).
- **Cigarette Smokers:** Three smokers require three distinct ingredients (tobacco, paper, matches). An agent provides two random items; coordinates which smoker can proceed.

---

## 11. Deadlocks

### 11.1 Definition & Necessary Conditions (Coffman Conditions)

A **Deadlock** is a state where a set of processes are blocked because each process is holding a resource and waiting for another resource held by some other process in the set.

#### The 4 Coffman Conditions (Must hold simultaneously)

1. **Mutual Exclusion:** At least one resource must be held in a non-shareable mode (only one process at a time).
2. **Hold and Wait:** A process must currently hold at least one resource and be waiting to acquire additional resources held by others.
3. **No Preemption:** Resources cannot be forcibly confiscated; they can only be released voluntarily by the holding process.
4. **Circular Wait:** A closed chain of processes exists: $\{P_0, P_1, \dots, P_n\}$ such that $P_0$ waits for a resource held by $P_1$, $P_1$ waits for $P_2$, and $P_n$ waits for $P_0$.

### 11.2 Resource Allocation Graphs (RAG)

- **Vertices:** Processes $P = \{P_1, \dots, P_n\}$ (circles) and Resource types $R = \{R_1, \dots, R_m\}$ (rectangles with dots for instances).
- **Edges:**
  - **Request Edge:** $P_i \to R_j$ (Process $P_i$ is requesting resource $R_j$).
  - **Assignment Edge:** $R_j \to P_i$ (An instance of $R_j$ is allocated to $P_i$).

```text
Single Instance Deadlock                 Cycle WITHOUT Deadlock (Multi-instance)
+----+             +----+                +----+             +----+
| P1 | ──────────> | R1 |                | P1 | ──────────> | R1 | (2 instances)
+----+             +----+                +----+             +----+
  ▲                  │                     ▲                  │
  │                  │                     │                  │
  │                  ▼                     │                  ▼
+----+             +----+                +----+             +----+
| R2 | <────────── | P2 |                | R2 | <────────── | P2 |
+----+             +----+                +----+             +----+
(Cycle = Deadlock guaranteed)              ▲                  │
                                           │  P3 releases R1  │  P4 releases R2
                                           └── [P3]     [P4] ─┘
```

> [!IMPORTANT]
> **RAG Rules:**
> - If graph contains **NO cycles** $\implies$ **No Deadlock**.
> - If graph contains a **cycle** AND resources have **single instances** $\implies$ **Deadlock**.
> - If graph contains a **cycle** AND resources have **multiple instances** $\implies$ **Deadlock is Possible (not guaranteed)**.

### 11.3 Deadlock Handling Strategies Overview

1. **Deadlock Ignorance (Ostrich Algorithm):** Stick head in sand and pretend deadlocks never occur. (Used by Windows and Linux because deadlocks are rare and prevention/avoidance overhead is high).
2. **Deadlock Prevention:** Ensure that at least one of the 4 Coffman conditions can never hold.
3. **Deadlock Avoidance:** Dynamically monitor resource allocation state to ensure the system never enters an **Unsafe State** (Banker's Algorithm).
4. **Deadlock Detection & Recovery:** Allow deadlocks to occur, detect them, and recover by aborting processes or preempting resources.

### 11.4 Deadlock Prevention

- **Eliminating Mutual Exclusion:** Make resources shareable (e.g., read-only files). *Not feasible for printers, mutexes.*
- **Eliminating Hold and Wait:** Require processes to request all resources at once before execution begins, or release current resources before making new requests. *Low resource utilization.*
- **Eliminating No Preemption:** If a process holding resources is denied an additional request, all its currently held resources are preempted.
- **Eliminating Circular Wait:** Impose a strict global numerical ordering on all resources ($F: R \to \mathbb{N}$). A process can only request resources in strictly increasing order ($F(R_i) < F(R_j)$). **Most practical prevention technique.**

### 11.5 Deadlock Avoidance & Banker's Algorithm

#### Safe vs. Unsafe State

```text
+-------------------------------------------------------+
|                     All States                        |
|   +-----------------------------------------------+   |
|   |                  Safe States                  |   |
|   |         (No Deadlock, Safe Sequence exists)   |   |
|   +-----------------------------------------------+   |
|   |                  Unsafe States                |   |
|   |         +---------------------------+         |   |
|   |         |      Deadlock States      |         |   |
|   |         +---------------------------+         |   |
|   +-----------------------------------------------+   |
+-------------------------------------------------------+
```

A state is **Safe** if there exists a **Safe Sequence** $\langle P_1, P_2, \dots, P_n \rangle$ such that for each $P_i$, the resources that $P_i$ still needs can be satisfied by current available resources plus resources held by all preceding processes $P_j$ ($j < i$).

#### Banker's Algorithm Data Structures

For $n$ processes and $m$ resource types:
- `Available[m]`: Available instances of each resource.
- `Max[n][m]`: Maximum demand of each process.
- `Allocation[n][m]`: Currently allocated resources per process.
- `Need[n][m]`: Remaining need of each process:
  $$\text{Need}[i][j] = \text{Max}[i][j] - \text{Allocation}[i][j]$$

#### Safety Algorithm

1. Let `Work = Available` (vector of length $m$) and `Finish[i] = false` for $i = 0, 1, \dots, n-1$.
2. Find an index $i$ such that:
   - `Finish[i] == false`
   - `Need[i] <= Work`
   If no such $i$ exists, go to step 4.
3. `Work = Work + Allocation[i]`
   `Finish[i] = true`
   Go to step 2.
4. If `Finish[i] == true` for all $i$, system is in a **Safe State**.

### 11.6 Deadlock Detection & Recovery

- **Detection:**
  - Single-instance resources: Construct a **Wait-For Graph** (collapse resource nodes); find cycles using DFS in $O(V^2)$ time.
  - Multi-instance resources: Run Banker's-style detection algorithm.
- **Recovery Strategies:**
  - **Process Termination:** Abort all deadlocked processes, or abort one by one until cycle is broken.
  - **Resource Preemption:** Select a victim process, roll it back to a safe checkpoint, and preempt its resources (must prevent starvation of the victim via aging).

---

## 12. Memory Management: Contiguous Allocation

### 12.1 Address Binding & MMU (Logical vs. Physical Addresses)

- **Compile Time:** If memory location is known at compile time, absolute code is generated (MS-DOS `.COM`).
- **Load Time:** If memory location is unknown, compiler generates relocatable code; final addresses bound at load time.
- **Execution Time (Dynamic):** If process can move in memory during runtime, binding is delayed until execution. Requires hardware **Memory Management Unit (MMU)**.

```text
Logical Address (Generated by CPU)
        │
        ▼
   [ < Limit? ] ───(No)───> Trap: Addressing Error / Segmentation Fault
        │ (Yes)
        ▼
   [ + Base / Relocation Register ]
        │
        ▼
Physical Address (Sent to Memory Bus)
```

### 12.2 Fixed vs. Dynamic Partitioning

- **Fixed Partitioning (MFT):** Memory divided into fixed-size partitions at boot time. Suffer from **Internal Fragmentation**.
- **Dynamic Partitioning (MVT):** Partitions created dynamically based exactly on process size. Suffer from **External Fragmentation**.

### 12.3 Fragmentation (Internal vs. External)

```text
Internal Fragmentation                 External Fragmentation
+--------------------------+           +--------------------------+
| Process A (18 KB)        |           | Process A (Allocated)    |
+--------------------------+           +--------------------------+
| Waste (14 KB Unusable)   |           | Free Hole (10 KB)        |
+--------------------------+           +--------------------------+
| 32 KB Fixed Block Limit  |           | Process B (Allocated)    |
+--------------------------+           +--------------------------+
                                       | Free Hole (15 KB)        |
                                       +--------------------------+
                                       Total Free = 25 KB, but a
                                       20 KB request fails!
```

- **Compaction:** Technique of shifting all allocated memory blocks together to merge fragmented free holes into one large block (only possible with dynamic execution-time binding).

### 12.4 Dynamic Allocation Algorithms (First Fit, Best Fit, Worst Fit, Next Fit)

| Strategy | Search Rule | Pros | Cons |
| :--- | :--- | :--- | :--- |
| **First Fit** | Allocates the **first** hole that is large enough from the beginning. | Fastest; lowest search overhead. | Leaves small fragments near beginning of memory. |
| **Best Fit** | Allocates the **smallest** hole that is large enough (searches entire list). | Minimizes wasted space per allocation. | Produces tiny, unusable leftover slivers. |
| **Worst Fit** | Allocates the **largest** available hole. | Leaves the largest remaining hole for future requests. | High search overhead; breaks up large blocks rapidly. |
| **Next Fit** | Like First Fit, but starts scanning from the location of the **last allocation**. | Distributes allocations across memory. | Slightly worse fragmentation than First Fit. |

---

## 13. Paging & Non-Contiguous Memory

### 13.1 Basic Architecture of Paging

Paging eliminates external fragmentation by dividing memory into fixed-size chunks:
- **Physical Memory** is divided into fixed blocks called **Frames**.
- **Logical Memory** is divided into blocks of the exact same size called **Pages**.

```text
Logical Address Space                 Page Table            Physical Memory (RAM)
+------------------+                  +---+---+             +------------------+
| Page 0           |                  | 0 | 2 |             | Frame 0          |
+------------------+                  +---+---+             +------------------+
| Page 1           |                  | 1 | 0 |             | Frame 1          |
+------------------+                  +---+---+             +------------------+
| Page 2           |                  | 2 | 3 |             | Frame 2 (Page 0) |
+------------------+                  +---+---+             +------------------+
                                                            | Frame 3 (Page 2) |
                                                            +------------------+
```

### 13.2 Address Translation in Paging

Given a CPU Logical Address of $m$ bits and a Page Size of $2^d$ bytes:

```text
Logical Address:
+-------------------------------+--------------------------+
|      Page Number (p)          |      Offset (d)          |
|         (m - d bits)          |       (d bits)           |
+-------------------------------+--------------------------+
               │                               │
               ▼                               │
         [ Page Table ]                        │
               │ (Maps p -> f)                 │
               ▼                               ▼
+-------------------------------+--------------------------+
|      Frame Number (f)         |      Offset (d)          |
+-------------------------------+--------------------------+
Physical Address
```

- $\text{Number of Pages} = 2^{m-d}$
- $\text{Page Size} = \text{Frame Size} = 2^d\text{ bytes}$
- $\text{Physical Address Bits} = \text{Frame bits } (f) + \text{Offset bits } (d)$

### 13.3 Page Table Entries & Flags

A typical Page Table Entry (PTE) contains:

```text
+---+---+---+---+---+--------------------------------+
| V | D | R | P | U | Frame Number                   |
+---+---+---+---+---+--------------------------------+
```

- **Valid/Invalid Bit ($V$):** $1 =$ Page is in RAM; $0 =$ Page is on disk (**Page Fault** trigger).
- **Dirty / Modified Bit ($D$):** $1 =$ Page was written to in RAM (must write back to disk upon eviction).
- **Reference / Access Bit ($R$):** $1 =$ Page was recently read/written (used by LRU clock replacement).
- **Protection Bits ($P$):** Read, Write, Execute ($R/W/X$) permissions.
- **User/Supervisor Bit ($U$):** Determines if user-mode code can access this page.

### 13.4 Translation Lookaside Buffer (TLB) & Effective Access Time (EAT)

The **TLB** is an associative on-chip hardware cache that stores recent $\text{Page} \to \text{Frame}$ translations.

```text
CPU Logical Address (p, d)
         │
         ├───> [ Search TLB associative cache in parallel ]
         │         │
         │         ├───(TLB Hit)───> Frame number found immediately!
         │         │
         │         └───(TLB Miss)──> Access Page Table in Main Memory
         │                                   │
         │                                   └──> Update TLB & get Frame
         ▼
Physical Address (f, d)
```

#### Effective Access Time (EAT) Formula

Let:
- $h = \text{TLB Hit Ratio}$ ($0 \le h \le 1$)
- $t_{\text{tlb}} = \text{TLB Lookup Time}$
- $t_{\text{mem}} = \text{Main Memory Access Time}$

$$\text{EAT} = h \cdot (t_{\text{tlb}} + t_{\text{mem}}) + (1 - h) \cdot (t_{\text{tlb}} + 2 \cdot t_{\text{mem}})$$

*(Note: On a TLB miss, two memory accesses occur: one to read the page table, one to access actual data).*

### 13.5 Multi-Level, Hashed, and Inverted Page Tables

```text
Multi-Level Page Table (Two-Level)
Virtual Address:
+-------------------+-------------------+-------------------+
| Outer Page (p1)   | Inner Page (p2)   | Offset (d)        |
+-------------------+-------------------+-------------------+
         │                   │                   │
         ▼                   ▼                   │
  [ Outer Table ] ───> [ Inner Table ] ──(f)─────┴──> Physical Address
```

- **Multi-Level (Hierarchical) Paging:** Page the page table itself. Avoids allocating contiguous memory for sparse page tables.
- **Inverted Page Table:** Exactly one entry per physical frame in RAM (indexed by frame number), containing $\langle \text{PID}, \text{Page Number} \rangle$. Minimizes page table memory footprint, but lookup requires hashing.

### 13.6 Shared Pages & Reentrant Code

- **Reentrant Code (Pure Code):** Non-self-modifying code that never changes during execution.
- Multiple processes running the same program (e.g., standard C library, text editor) map their virtual code pages to the exact same physical memory frames, drastically saving RAM.

---

## 14. Segmentation & Combined Schemes

### 14.1 Segmentation Architecture & Address Translation

Segmentation provides a logical, user-oriented view of memory (Code segment, Stack segment, Heap segment). Segments are **variable in size**.

```text
Logical Address: < Segment Number (s), Offset (d) >
                         │
                         ▼
                  [ Segment Table ]
                  | Base | Limit  |
                         │
                         ├───> [ Is d < Limit? ] ──(No)──> Trap: Segment Fault
                         │            │ (Yes)
                         ▼            ▼
                   Physical Address = Base + d
```

### 14.2 Paging vs. Segmentation Detailed Comparison

| Feature | Paging | Segmentation |
| :--- | :--- | :--- |
| **Unit Size** | Fixed-size blocks (e.g., 4 KB) | Variable-size logical blocks |
| **View** | Physical / OS hardware view | Logical / Programmer view |
| **Address Format** | Single linear address divided into `p` and `d` | 2D address: Segment number `s` and Offset `d` |
| **Fragmentation** | **Internal Fragmentation** (on last page) | **External Fragmentation** (requires compaction) |
| **Page/Segment Table**| Page Table: Maps page to frame | Segment Table: Contains Segment Base & Limit |

### 14.3 Segmented Paging

Combines advantages of both: Each logical segment is divided into fixed-size pages. Eliminates external fragmentation while preserving logical segmentation protection.

---

## 15. Virtual Memory & Demand Paging

### 15.1 Concept of Virtual Memory

Virtual memory separates logical memory from physical memory, allowing execution of processes whose total memory requirements exceed available physical RAM.

### 15.2 Demand Paging & The Page Fault Sequence

Pages are loaded into RAM only when demanded during execution (**Lazy Swapper/Pager**).

```text
[1. CPU references virtual address]
      │
      ▼
[2. MMU checks Page Table Entry]
      │
      ├───(Valid Bit = 1)───> [Memory Access Proceeds Normally]
      │
      └───(Valid Bit = 0)───> [PAGE FAULT TRAP to OS]
                                     │
                                     ▼
[3. OS checks: Invalid reference (terminate) OR Page on Disk]
                                     │
                                     ▼
[4. Find a Free Frame in RAM (If none, run Page Replacement)]
                                     │
                                     ▼
[5. Issue Disk I/O to read missing page into allocated Frame]
                                     │
                                     ▼
[6. Update Page Table: Set Frame number & Valid Bit = 1]
                                     │
                                     ▼
[7. Restart the interrupted CPU instruction]
```

### 15.3 Effective Access Time (EAT) with Page Faults

Let:
- $p = \text{Page Fault Rate}$ ($0 \le p \le 1$)
- $\text{MAT} = \text{Memory Access Time}$ ($\sim 100\text{ ns}$)
- $\text{PFST} = \text{Page Fault Service Time}$ ($\sim 8\text{ ms} = 8,000,000\text{ ns}$)

$$\text{EAT} = (1 - p) \cdot \text{MAT} + p \cdot \text{PFST}$$

> [!IMPORTANT]
> Even a page fault rate of $p = 0.001$ ($0.1\%$) slows down memory access by nearly $8000\%$.

### 15.4 Pure Demand Paging & Locality of Reference

- **Pure Demand Paging:** A process starts with zero pages in RAM; the very first instruction generates a page fault.
- **Locality of Reference:**
  - **Temporal Locality:** If a memory location was referenced, it will likely be referenced again soon (loops, counters).
  - **Spatial Locality:** If a memory location was referenced, nearby locations will likely be referenced soon (array traversals, sequential instructions).

---

## 16. Page Replacement Algorithms

### 16.1 FIFO & Belady's Anomaly

- **FIFO:** Evicts the page that arrived in memory earliest.
- **Belady's Anomaly:** For certain page reference strings, **increasing the number of page frames results in an INCREASE in the number of page faults**. (Affects FIFO, but never affects Stack algorithms like LRU or Optimal).

```text
Reference String: 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
- With 3 Frames: 9 Page Faults
- With 4 Frames: 10 Page Faults (Anomaly demonstrated!)
```

### 16.2 Optimal Page Replacement (Bélády's Min)

- **Rule:** Replace the page that will **not be used for the longest period of time in the future**.
- **Properties:** Guarantees lowest possible page-fault rate; immune to Belady's anomaly.
- **Limitation:** Cannot be implemented practically (requires clairvoyance/future knowledge); serves as theoretical benchmark.

### 16.3 Least Recently Used (LRU)

- **Rule:** Replace the page that has not been referenced for the longest period of time.
- **Implementation:**
  - **Counters / Timestamps:** Each PTE updated with CPU clock on access; search for minimum timestamp.
  - **Doubly Linked Stack:** On access, remove node and move to top. Bottom of stack is victim.
- **Properties:** Stack algorithm; immune to Belady's anomaly.

### 16.4 LRU Approximations: Second Chance (Clock) & Enhanced Second Chance

#### Second Chance (Clock) Algorithm

Arranges page frames in a circular buffer with a clock hand. Uses a 1-bit Reference Bit ($R$):

```text
       Frame 0 (R=0) ───> EVICT THIS PAGE
      ↗             ↘
Frame 3 (R=1)      Frame 1 (R=1) ──> Set R=0, advance hand
      ↖             ↙
       Frame 2 (R=0)
```

- When seeking a victim:
  - If $R == 0$: Evict page and advance hand.
  - If $R == 1$: Clear bit ($R = 0$), give second chance, and advance hand.

#### Enhanced Second Chance

Uses ordered pair $(R, M)$ where $R =$ Reference bit and $M =$ Modify/Dirty bit:
1. $(0, 0)$: Neither recently used nor modified (Best victim to replace, no disk write needed).
2. $(0, 1)$: Not recently used, but modified (Requires writeback).
3. $(1, 0)$: Recently used, but clean.
4. $(1, 1)$: Recently used and modified.

### 16.5 Counting Algorithms (LFU & MFU)

- **Least Frequently Used (LFU):** Replaces page with smallest reference count.
- **Most Frequently Used (MFU):** Replaces page with highest reference count (assumes lowest count pages were just brought in and need to run).

---

## 17. Thrashing & Frame Allocation

### 17.1 Cause & Mechanism of Thrashing

**Thrashing** occurs when a system spends more time paging (swapping pages in and out of disk) than executing instructions.

```text
High Degree of Multiprogramming
         │
         ▼
Processes lack sufficient frames to hold their active working sets
         │
         ▼
Continuous Page Faults ──> High Disk I/O Queue
         │
         ▼
CPU Utilization Drops dramatically (CPU idle waiting for disk)
         │
         ▼
OS mistakenly assumes system is underloaded and admits MORE processes!
         │
         ▼
Total System Collapse (Thrashing)
```

### 17.2 Working Set Model

The **Working Set ($\text{WSS}_i$)** is the set of pages referenced by process $P_i$ in the most recent $\Delta$ page references (Working Set Window).

```text
Let D = Total Demand Frames = Σ WSS_i
Let m = Total Available RAM Frames

If D > m  ===> Thrashing will occur! (OS must suspend / swap out a process)
If D <= m ===> System is stable.
```

### 17.3 Page-Fault Frequency (PFF) Strategy

Directly measures and bounds page fault rate:
- If $\text{Page Fault Rate} > \text{Upper Threshold}$: Process needs more memory $\implies$ allocate more frames.
- If $\text{Page Fault Rate} < \text{Lower Threshold}$: Process has excess memory $\implies$ remove frames.

---

## 18. File Systems & Storage Management

### 18.1 File Concepts, Attributes & Operations

- **File:** Named collection of contiguous or indexed logical bytes stored on secondary storage.
- **Attributes:** Name, Identifier (Inode/FCB number), Type, Location, Size, Protection, Timestamps.
- **Operations:** `create`, `open`, `read`, `write`, `seek`, `truncate`, `close`, `delete`.

### 18.2 File Control Block (FCB) & Directory Structures

- **File Control Block (FCB / Inode):** Contains complete file metadata (permissions, size, block addresses).
- **Directory Systems:**
  - **Single-Level:** All files in one directory (naming collision issues).
  - **Two-Level:** Master directory points to User File Directories (UFD).
  - **Tree-Structured:** Arbitrary subdirectories and path navigation (`/home/user/docs`).
  - **Acyclic-Graph:** Allows shared files and subdirectories across paths via links.

### 18.3 Hard Links vs. Soft (Symbolic) Links

```text
Hard Link                             Soft / Symbolic Link (Symlink)
+-----------+                         +-----------+
| FileA.txt | ──┐                     | LinkA.txt | (Contains path string "/a/b.txt")
+-----------+   │                     +-----+-----+
                ▼                           │
+-----------+   +-------------------+       │
| FileB.txt | ──> Inode 1042 (Data) | <─────┘ (Resolves path to Inode 1042)
+-----------+   +-------------------+
(Both point to same Inode;            (Separate Inode; breaks if target deleted)
 link count = 2)
```

| Feature | Hard Link | Soft / Symbolic Link |
| :--- | :--- | :--- |
| **Inode** | Shares the **same Inode number** as target | Has its **own distinct Inode** containing path string |
| **Across Filesystems**| Cannot span across different disk partitions | Can span across different filesystems/partitions |
| **Target Deletion** | File data retained until all hard links deleted | Becomes a **Dangling / Broken Link** |
| **Directories** | Generally disallowed for directories (prevents cycles) | Allowed for directories |

### 18.4 File Allocation Methods (Contiguous, Linked, Indexed)

```text
Contiguous Allocation                 Linked Allocation                     Indexed Allocation
+---------------------------+         +---------------------------+         +---------------------------+
| Block 0 | Block 1| Block 2|         | Block 4 (Data + Ptr to 7) |         | Index Block [ 4, 7, 2 ]   |
+---------------------------+         +---------------------------+         +-------------+-------------+
- Fast sequential/direct access       - No external fragmentation                   │  │  │
- Suffix: External fragmentation      - Slow random access (must traverse)          ▼  ▼  ▼
- Hard to grow files                  - Pointer reliability loss            - Supports fast random access
```

### 18.5 UNIX Inode Architecture & Max File Size Calculations

A standard UNIX Inode contains **15 Block Pointers**:
- **12 Direct Pointers:** Point directly to data blocks.
- **1 Single Indirect Pointer:** Points to an index block of data block pointers.
- **1 Double Indirect Pointer:** Points to an index block of single indirect blocks.
- **1 Triple Indirect Pointer:** Points to an index block of double indirect blocks.

```text
UNIX Inode
+-----------------------------------+
| Metadata (Mode, UID, Size, Time)  |
+-----------------------------------+
| Direct Block 0                    | ───> [ Data Block 0 ]
| ...                               |
| Direct Block 11                   | ───> [ Data Block 11 ]
+-----------------------------------+
| Single Indirect                   | ───> [ Index Block ] ───> [ Data Blocks... ]
+-----------------------------------+
| Double Indirect                   | ───> [ Index Block ] ───> [ Index Blocks ] ───> [ Data Blocks... ]
+-----------------------------------+
| Triple Indirect                   | ───> [ Index Block ] ───> [ Index Blocks ] ───> ...
+-----------------------------------+
```

#### Maximum File Size Formula

Let $\text{DB} = \text{Disk Block Size}$ and $\text{PTR} = \text{Disk Pointer Size}$.
- Number of pointers per index block: $K = \frac{\text{DB}}{\text{PTR}}$
- $\text{Direct Capacity} = 12 \times \text{DB}$
- $\text{Single Indirect Capacity} = K \times \text{DB}$
- $\text{Double Indirect Capacity} = K^2 \times \text{DB}$
- $\text{Triple Indirect Capacity} = K^3 \times \text{DB}$
$$\text{Max File Size} = (12 + K + K^2 + K^3) \times \text{DB}$$

### 18.6 Free Space Management (Bit Vector, Linked List, Grouping, Counting)

- **Bit Vector (Bitmap):** 1 bit per block ($1 = \text{Free}, 0 = \text{Allocated}$). Fast, easy to find first free block using hardware bit-scan instructions.
- **Linked Free List:** Keeps a linked chain of free blocks. No space waste, but slow traversal.
- **Grouping:** Stores addresses of $N$ free blocks in the first free block; the last pointer points to another group block.
- **Counting:** Stores address of first free block and count $N$ of contiguous free blocks.

---

## 19. Disk Structure & Disk Scheduling

### 19.1 Magnetic Disk Geometry & Access Times

```text
              Read/Write Heads
               ┌──┐
  Platter 1    │  │ ──────> Tracks (Concentric rings)
    ========   └──┘
  Platter 2    ┌──┐
    ========   │  │ ──────> Sectors (Smallest addressable pie slice, 512B / 4KB)
               └──┘
               ▲
               │ Spindle / Actuator Arm
```

- **Seek Time ($T_{\text{seek}}$):** Time taken to move the actuator arm to the target cylinder.
- **Rotational Latency ($T_{\text{rot}}$):** Time waiting for the target sector to rotate under the head:
  $$\text{Average Rotational Latency} = \frac{1}{2 \times \text{RPM}} \times 60\text{ seconds}$$
- **Transfer Time ($T_{\text{trans}}$):** Time to stream the data:
  $$T_{\text{trans}} = \frac{\text{Bytes to Transfer}}{\text{Transfer Rate}}$$
- **Total Access Time:** $T_{\text{access}} = T_{\text{seek}} + T_{\text{rot}} + T_{\text{trans}}$

### 19.2 Disk Scheduling Algorithms (FCFS, SSTF, SCAN, C-SCAN, LOOK, C-LOOK)

```text
Given Request Queue: 98, 183, 37, 122, 14, 124, 65, 67 (Head starts at 53)

1. FCFS:
   Services in strict arrival order (53 -> 98 -> 183 -> 37 -> 122 -> 14 -> 124 -> 65 -> 67).
   High total head movement (640 cylinders).

2. SSTF (Shortest Seek Time First):
   Picks closest request to current head position.
   Prone to STARVATION of outer tracks.

3. SCAN (Elevator Algorithm):
   Moves toward one end (e.g., 0), servicing requests on the way, hits the physical end (0),
   then reverses direction toward 199.

4. C-SCAN (Circular SCAN):
   Moves in one direction to the boundary (199), servicing requests, then immediately
   jumps back to cylinder 0 without servicing on return trip. Provides uniform wait times.

5. LOOK & C-LOOK:
   Optimized variants of SCAN / C-SCAN. The head ONLY goes as far as the LAST pending
   request in that direction, reversing without traveling to the unused physical boundary.
```

---

## 20. I/O Management & Kernel Subsystems

### 20.1 I/O Hardware: Ports, Buses, Controllers & Registers

- **Port:** Physical connection point for peripheral devices.
- **Bus:** Shared electronic transmission line (PCIe, SATA, USB).
- **Controller:** Hardware chip set that manages physical device operations and exposes 4 standard registers:
  1. **Data-In Register:** Read by host to receive input.
  2. **Data-Out Register:** Written by host to send output.
  3. **Status Register:** Bits indicate device state (`BUSY`, `READY`, `ERROR`).
  4. **Control Register:** Written by host to initiate commands (`READ`, `WRITE`, `ENABLE_INTERRUPT`).

### 20.2 I/O Techniques: Polling, Interrupt-Driven I/O & DMA

```text
1. Polling (Programmed I/O)
   CPU repeatedly loops reading Status Register until BUSY bit clears (Busy-waiting / High CPU waste).

2. Interrupt-Driven I/O
   CPU issues command and continues user work. Device controller asserts Interrupt Request Line (IRQ)
   when data ready. CPU jumps to Interrupt Service Routine (ISR).

3. Direct Memory Access (DMA)
   DMA Controller transfers entire data blocks directly between device and RAM without CPU mediation.
   CPU is interrupted only once per entire block transfer.
   - Burst Mode: DMA takes full bus control.
   - Cycle Stealing: DMA sneaks bus cycles between CPU instruction cycles.
```

### 20.3 Spooling vs. Buffering vs. Caching

- **Buffering:** Storing data in a temporary memory region while transferred between devices of different speeds or block sizes (e.g., double buffering).
- **Caching:** Storing high-speed copies of frequently accessed data in faster memory to accelerate future reads.
- **Spooling (Simultaneous Peripheral Operations On-Line):** Intercepts concurrent output from multiple processes destined for a non-shareable device (like a printer) and stores them in temporary disk files until the device is ready to print them sequentially.

---

## 21. Protection, Security & System Threats

### 21.1 Protection vs. Security

- **Protection:** Internal mechanisms that control access of programs, processes, or users to system resources (Authorization: *"Who is allowed to access what?"*).
- **Security:** Defense against external and internal attacks, unauthorized intrusions, and malicious subversion (Defense: *"How do we protect system integrity against threats?"*).

### 21.2 Access Matrix, Access Control Lists (ACL) & Capabilities

```text
Access Matrix: Domains (Rows) x Objects (Columns)
+----------+---------------+---------------+---------------+
| Domain   | File 1        | File 2        | Printer       |
+----------+---------------+---------------+---------------+
| User A   | Read, Write   | Read          | Print         |
| User B   | Read          | None          | None          |
+----------+---------------+---------------+---------------+

Implementation Methods:
1. Access Control List (ACL) - Stored per Object (Column-wise):
   File 1: [User A: RW, User B: R]
2. Capability List (C-List)  - Stored per Domain (Row-wise):
   User A: [File 1: RW, File 2: R, Printer: Print]
```

### 21.3 Common System Threats & Attacks

- **Trojan Horse:** Malicious functionality concealed inside an apparently benign utility.
- **Trapdoor / Backdoor:** Secret, undocumented debugging entrance that bypasses standard authentication checks.
- **Logic Bomb:** Dormant code that triggers a malicious payload when a specific condition occurs (e.g., date, account deletion).
- **Virus:** Self-replicating malicious code that attaches itself to existing host executable files.
- **Worm:** Standalone, self-propagating program that exploits network vulnerabilities to infect remote systems autonomously without requiring host files.
- **Buffer Overflow:** Writing data past allocated array boundaries on the stack to overwrite the return instruction pointer and hijack program control flow.

---

## 22. High-Yield Comparison Tables

### 22.1 Process vs. Thread

| Parameter | Process | Thread |
| :--- | :--- | :--- |
| **Definition** | Program in execution | Lightweight unit of execution within a process |
| **Address Space** | Isolated private address space | Shares address space with other threads in process |
| **Resource Ownership** | Holds files, sockets, memory tables | Holds only private registers and private stack |
| **Creation Overhead** | High | Low |
| **Context Switch Time** | Slower (TLB flushes, page table swaps) | Fast (preserves memory mapping and cache) |
| **Inter-communication** | Requires IPC | Direct memory access to shared globals/heap |

### 22.2 Mutex vs. Semaphore vs. Spinlock

| Feature | Mutex | Counting Semaphore | Spinlock |
| :--- | :--- | :--- | :--- |
| **Mechanism** | Locking | Signaling | Busy-wait Locking |
| **Ownership** | Locked thread must unlock | Any thread can signal | Locked thread must unlock |
| **Blocking Action** | Puts waiting thread to sleep | Puts waiting thread to sleep | Spins in tight loop on CPU |
| **Best Used When** | Critical section takes long time | Managing resource pool of $N$ units | Critical section is extremely short on multicore |

### 22.3 Paging vs. Segmentation

| Parameter | Paging | Segmentation |
| :--- | :--- | :--- |
| **Block Size** | Fixed size (e.g., 4 KB) | Variable size |
| **Programmer Awareness**| Transparent to programmer | Visible to programmer / compiler |
| **Fragmentation** | Suffers from **Internal Fragmentation** | Suffers from **External Fragmentation** |
| **Address Type** | 1D Virtual address $(p, d)$ | 2D Logical address $(s, d)$ |
| **Hardware Mapping** | Page Table Base Register (PTBR) | Segment Table (Base and Limit) |

---

## 23. Complete Formula Cheat Sheet

### CPU Scheduling

$$\text{Turnaround Time (TAT)} = \text{Completion Time (CT)} - \text{Arrival Time (AT)}$$

$$\text{Waiting Time (WT)} = \text{Turnaround Time (TAT)} - \text{Burst Time (BT)}$$

$$\text{Response Time (RT)} = \text{Time of First CPU Start} - \text{Arrival Time (AT)}$$

$$\text{CPU Utilization} = \frac{\text{Total Busy CPU Time}}{\text{Total Elapsed Time}} \times 100\%$$

$$\text{Throughput} = \frac{\text{Number of Completed Processes}}{\text{Total Elapsed Time}}$$

$$\tau_{n+1} = \alpha t_n + (1 - \alpha)\tau_n \quad (0 \le \alpha \le 1)$$

---

### Memory & Paging

$$\text{Offset bits } (d) = \log_2(\text{Page Size in Bytes})$$

$$\text{Page bits } (p) = \text{Total Virtual Address bits } (m) - d$$

$$\text{Number of Pages} = 2^p = \frac{\text{Virtual Address Space Size}}{\text{Page Size}}$$

$$\text{Frame bits } (f) = \text{Physical Address bits } (k) - d$$

$$\text{Number of Physical Frames} = 2^f = \frac{\text{Physical Memory Size}}{\text{Frame Size}}$$

$$\text{Page Table Size} = (\text{Number of Pages}) \times (\text{Page Table Entry Size})$$

$$\text{EAT}_{\text{TLB}} = h \cdot (t_{\text{tlb}} + t_{\text{mem}}) + (1 - h) \cdot (t_{\text{tlb}} + 2 \cdot t_{\text{mem}})$$

$$\text{EAT}_{\text{Demand Paging}} = (1 - p) \cdot \text{MAT} + p \cdot \text{PFST}$$

---

### Storage & Inode

$$\text{Max Inode File Size} = \left[ 12 + \left(\frac{\text{Block Size}}{\text{Ptr Size}}\right) + \left(\frac{\text{Block Size}}{\text{Ptr Size}}\right)^2 + \left(\frac{\text{Block Size}}{\text{Ptr Size}}\right)^3 \right] \times \text{Block Size}$$

$$\text{Average Rotational Latency} = \frac{1}{2} \times \left(\frac{60}{\text{RPM}}\right)\text{ seconds}$$

---

## 24. How to Solve OS Numerical Problems

### 24.1 CPU Scheduling Numerical Walkthrough

**Problem Statement:** Given 4 processes, compute Average TAT and Average WT using Preemptive Shortest Remaining Time First (SRTF):

| Process | Arrival Time (AT) | Burst Time (BT) |
| :--- | :--- | :--- |
| **P1** | 0 | 8 |
| **P2** | 1 | 4 |
| **P3** | 2 | 9 |
| **P4** | 3 | 5 |

#### Step 1: Draw Gantt Chart Tracking Remaining Times

- At $t = 0$: P1 arrives (rem = 8). Executes until $t=1$.
- At $t = 1$: P2 arrives (rem = 4) vs P1 (rem = 7). P2 preempts P1!
- At $t = 2$: P3 arrives (rem = 9). P2 continues (rem = 3).
- At $t = 3$: P4 arrives (rem = 5). P2 continues (rem = 2).
- At $t = 5$: P2 completes. Ready: P1 (7), P3 (9), P4 (5). Smallest is P4! Executes until $t=10$.
- At $t = 10$: P4 completes. Ready: P1 (7), P3 (9). Smallest is P1! Executes until $t=17$.
- At $t = 17$: P1 completes. P3 executes until $t=26$.

```text
Gantt Chart:
|  P1  |     P2     |     P4     |       P1       |          P3          |
0      1            5            10               17                     26
```

#### Step 2: Build Evaluation Table

| Process | AT | BT | Completion Time (CT) | $\text{TAT} = \text{CT} - \text{AT}$ | $\text{WT} = \text{TAT} - \text{BT}$ | First Start | $\text{RT} = \text{Start} - \text{AT}$ |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **P1** | 0 | 8 | 17 | $17 - 0 = 17$ | $17 - 8 = 9$ | 0 | $0 - 0 = 0$ |
| **P2** | 1 | 4 | 5 | $5 - 1 = 4$ | $4 - 4 = 0$ | 1 | $1 - 1 = 0$ |
| **P3** | 2 | 9 | 26 | $26 - 2 = 24$ | $24 - 9 = 15$ | 17 | $17 - 2 = 15$ |
| **P4** | 3 | 5 | 10 | $10 - 3 = 7$ | $7 - 5 = 2$ | 5 | $5 - 3 = 2$ |

- **Average Turnaround Time:** $\frac{17 + 4 + 24 + 7}{4} = \frac{52}{4} = 13.0\text{ ms}$
- **Average Waiting Time:** $\frac{9 + 0 + 15 + 2}{4} = \frac{26}{4} = 6.5\text{ ms}$

---

### 24.2 Banker's Algorithm Numerical Walkthrough

**Problem Statement:** Consider a system with 5 processes ($P_0$ to $P_4$) and 3 resource types ($A=10, B=5, C=7$).

Given Allocation and Max matrices:

| Process | Allocation (A B C) | Max (A B C) | $\text{Need} = \text{Max} - \text{Allocation}$ |
| :--- | :--- | :--- | :--- |
| **P0** | 0 1 0 | 7 5 3 | **7 4 3** |
| **P1** | 2 0 0 | 3 2 2 | **1 2 2** |
| **P2** | 3 0 2 | 9 0 2 | **6 0 0** |
| **P3** | 2 1 1 | 2 2 2 | **0 1 1** |
| **P4** | 0 0 2 | 4 3 3 | **4 3 1** |

$$\text{Total Allocated} = (0+2+3+2+0, 1+0+0+1+0, 0+0+2+1+2) = (7, 2, 5)$$
$$\text{Available} = \text{Total} - \text{Allocated} = (10-7, 5-2, 7-5) = \mathbf{(3, 3, 2)}$$

#### Execution Steps:

1. **Initialize:** `Work = (3, 3, 2)`.
2. Check **P0**: Need $(7, 4, 3) \le (3, 3, 2)$? **False**.
3. Check **P1**: Need $(1, 2, 2) \le (3, 3, 2)$? **True!**
   - $P_1$ finishes: $\text{Work} = (3, 3, 2) + (2, 0, 0) = \mathbf{(5, 3, 2)}$. `Finish[P1] = True`.
4. Check **P3**: Need $(0, 1, 1) \le (5, 3, 2)$? **True!**
   - $P_3$ finishes: $\text{Work} = (5, 3, 2) + (2, 1, 1) = \mathbf{(7, 4, 3)}$. `Finish[P3] = True`.
5. Check **P0**: Need $(7, 4, 3) \le (7, 4, 3)$? **True!**
   - $P_0$ finishes: $\text{Work} = (7, 4, 3) + (0, 1, 0) = \mathbf{(7, 5, 3)}$. `Finish[P0] = True`.
6. Check **P2**: Need $(6, 0, 0) \le (7, 5, 3)$? **True!**
   - $P_2$ finishes: $\text{Work} = (7, 5, 3) + (3, 0, 2) = \mathbf{(10, 5, 5)}$. `Finish[P2] = True`.
7. Check **P4**: Need $(4, 3, 1) \le (10, 5, 5)$? **True!**
   - $P_4$ finishes: $\text{Work} = (10, 5, 5) + (0, 0, 2) = \mathbf{(10, 5, 7)}$. `Finish[P4] = True`.

**Conclusion:** System is in a **SAFE STATE**. A valid Safe Sequence is **$\langle P_1, P_3, P_0, P_2, P_4 \rangle$**.

---

### 24.3 Effective Access Time (TLB) Numerical Walkthrough

**Problem Statement:** A system has a TLB hit ratio of $80\%$. It takes $20\text{ ns}$ to search the TLB and $100\text{ ns}$ to access main memory. Calculate Effective Access Time (EAT).

$$\text{EAT} = h \cdot (t_{\text{tlb}} + t_{\text{mem}}) + (1 - h) \cdot (t_{\text{tlb}} + 2 \cdot t_{\text{mem}})$$
$$\text{EAT} = 0.80 \cdot (20 + 100) + (1 - 0.80) \cdot (20 + 2 \times 100)$$
$$\text{EAT} = 0.80 \cdot (120) + 0.20 \cdot (220)$$
$$\text{EAT} = 96 + 44 = \mathbf{140\text{ ns}}$$

---

### 24.4 UNIX Inode Maximum File Size Numerical Walkthrough

**Problem Statement:** An operating system uses a UNIX-style Inode with 12 direct block pointers, 1 single indirect pointer, 1 double indirect pointer, and 1 triple indirect pointer. Disk block size is $4\text{ KB}$ ($4096\text{ bytes}$) and each disk block address pointer is $4\text{ bytes}$ ($32\text{ bits}$). What is the maximum possible file size?

1. **Calculate Pointers per Index Block ($K$):**
   $$K = \frac{\text{Block Size}}{\text{Pointer Size}} = \frac{4096\text{ bytes}}{4\text{ bytes}} = 1024 = 2^{10}\text{ pointers}$$
2. **Direct Capacity:**
   $$12 \times 4\text{ KB} = 48\text{ KB}$$
3. **Single Indirect Capacity:**
   $$1024 \times 4\text{ KB} = 4096\text{ KB} = 4\text{ MB}$$
4. **Double Indirect Capacity:**
   $$1024^2 \times 4\text{ KB} = 1,048,576 \times 4\text{ KB} = 4,194,304\text{ KB} = 4\text{ GB}$$
5. **Triple Indirect Capacity:**
   $$1024^3 \times 4\text{ KB} = 2^{30} \times 4\text{ KB} = 4\text{ TB}$$
6. **Maximum File Size:**
   $$\text{Max Size} = 48\text{ KB} + 4\text{ MB} + 4\text{ GB} + 4\text{ TB} \approx \mathbf{4.004\text{ TB}}$$