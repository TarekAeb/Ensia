# Process Synchronization

Process synchronization is a critical aspect of multi-threaded software, in general, and operating systems, in particular. It ensures that multiple processes or threads can coordinate and share resources consistently and effectively.

## Synchronization:

a system that operates based on the speed of another system is refered to as a synchronous system.
**deadlock**: is a situation where each of te process will wait for the others to complete, and they enter in a loop

## Race condition and data corruption:

The problem of shared data corruption (race condition) occurs when:

- Threads can execute in (fake) concurrency, i.e., any process/thread can be interrupted at any point in its instruction flow (e.g.,quantum expires, or I/O operation), and the CPU is assigned to another thread.
- Threads can execute in (real concurrency) parallel (e.g., two execution of two different processes/threads are simultaneously executing on separate CPUs or processing cores).
- These concurrent or parallel executing threads share some data.
- The outcome of the execution depends on the order in which those concurrent threads modified the shared variable.

## Critical section:

```
Thread()
{
Remainder section
Entry section
Critical section
Exit section
Remainder section
}
```

In multi-threading and multi-processing systems, a critical section is a part of a thread code in which the program requests to use shared resources on which the access is mutually exclusive.
so before using shared variable we should lock them, so we need to design a protocol can apply to cooperate while accessing shared resources without any issues. it must satisfy the following requirements:
**Mutual exclusion:** at most one process is executing its critical section at a time.
**Progress:** A process or a thread that is outside its critical section should not block a process or thread from getting into
their critical section.
**bounding waiting:** a process or thread must not waste CPU cycles

## Synchronization Mechanisms

### Mutex

which stands for **Mut**ual **ex**clusion consist of a boolean variable whether it is true or false acquire, release

### Test and Set() and Intel’s XCHG

the test and set() is a hardware instruction that sets a memory location to a value and returns the old value. it is used to implement a mutex lock.
XCHG is an instruction where no interrupt can occur for two clock cycles.

### Semaphore

The semaphore is all based on an integer value

**wait:**

```
P(S)
{
    while(S>=0);
    S--;
}
```

**signal:**

```
V (S)
{
S++;
}
```

when some process is modified the semaphore value, it should be atomic, so we need to use the test and set() or XCHG instruction.

#### types of semaphore:

1. **Binary semaphore:** it can take only two values 0 and 1, it is used to implement mutex locks.
2. **Counting semaphore:** it can take any value greater than or equal to 0, it is used to implement the producer-consumer problem.

#### Style of semaphore:

- Mutual exclusion style, in which case M is initialized to n | n ≥ 1.
- Waiting style, in which case M is initialized to 0.

* The semaphore could be implemented using two methods, first the busy waiting, in which it keep spinning when the variable is locked or without busy waiting which basically queue the process that request a locked resource and once that resource is freed, it wake it.

```
P(S){
 S=S-1;
 if(S<0)
 {
    BLOCK & place P in Q;
 }
}

V(S){
    S=S+1;
    if (S<=0){
        Wake up P from Q;
    }
}
```

### Peterson’s Algorithm

Peterson’s algorithm is a solution for the critical section problem involving two processes that alternate their critical section execution.

```
do{
flag[i]=true;
turn=j;
while(flag[j] && turn==j);
critical section
flag[i]=false;
remainder section
}while(1);
```

### Interrupt Disabling

Old operating systems used to disable interrupts to protect critical sections. This method is not used anymore because it is not safe and can cause a system to hang.

## PPG for synchronization

Recall PPGs (Process Precedence Graphs) are directed graph that are used to graphically express the order on which processes or threads are executed with respect to other processes or threads.
**CoBeing/CoEnd** construct cannot represent any arbitrary precedence constraints.

### Semaphores with PPGs

We can use PPGs to manage semaphore assignment where solving critical section problems
we follow the following steps:
![first step](image-4.png)
then we initialize the semaphore to 0
![second step](image-5.png)
![third step](image-6.png)
![fourth step](image-7.png)
given code, of a given process, we are making n acquire calls on the same semaphore, we can then make it one single call and initialize the semaphore to −n + 1. We can apply this technique to our previous code on semaphore s3 and obtain the following code:
![last step](image-8.png)

## classical synchronization problems

### 1. Readers-Writers Problem

This problem consists of: (1) A set of reader threads R = {r1, . . . , rn} and (2) a set of writer threads W = {w1, . . . , wm}. Both readers and writers share a data structure D (e.g., file, database, variable, ...) such that:

- Multiple readers R′ ⊆ R can read at the same time.
- Only one writer wi ∈ W can write at a time.
- If ∃r ∈ R that is reading, new writers have to wait (no preemption).
- If ∃w ∈ W that is writing, new writers and readers have to wait.
- If ∃r ∈ R that is reading, new readers can start reading.

* When it comes to one reader R = {r} and one write W = {w}, the solution is straightforward. We use a binary semaphore m in mutual exclusive style (i.e., initialized to 1):
  ![one reader, one writer](image-9.png)
  However when there are multiple readers and writers, we have three solution , readers have priority, writers have priority, and no priority.

#### Readers Priority

In readers have priority solution, we consider the following facts: when a new reader arrives while a writer is already waiting for previous readers to terminate, then the new reader can start reading (i.e., it joins) with the other readers without waiting. This solution is not a starvation-free solution because if there is a steady stream of readers, writers may not get the chance to write. We discuss the algorithm in the class.

#### Writers have priority

In this solution, when a new reader arrives and a writer is already waiting for previous readers to terminate, then the new reader cannot start reading along with the other readers but has to wait. And when there is waiting readers and writers during a writing, writers have the priority to be waken up over the readers at the end of the writing.Similar to the previous solution, this solution is not a starvation-free solution. In fact, if there is a steady stream of writers, readers may not get the chance to read. We discuss the algorithm in the class. Also, the solution will be the subject for Lab 8.

#### Starvation-free

In the starvation-free solution, readers yield for writers and writers yield for readers. Basically, when a reader shows up, it cannot start if a writer is waiting. Also, when writers are waiting, one writer can start after the last current reader finishes, i.e., a busy system: ..., one writer, batch of readers, one writer, ...

### 2. Dining Philosophers Problem

A set of five philosophers sit around a table, each philosopher has a plate of spaghetti, and a fork to the left and a fork to the right. The philosophers spend their time thinking and eating. When they get hungry, they try to pick up the two forks next to them. If a philosopher cannot pick up both forks, he puts them down and waits for a while before trying again. The problem is to design a protocol for the philosophers to share the forks in a way that avoids deadlock and starvation.

### 3. Producer-Consumer Problem

This problem consists of: (1) A set of producer threads P = {p1, . . . , pn} & (2) a set of consumer threads C = {c1, . . . , cm}. Each producer thread pi produces an item and places it into a buffer B, and each consumer ci consumes one item from that buffer such that:
