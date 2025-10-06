# Thrashing

**Definition:**
Occurs when a process spends most of its time paging (“page faulting”) than executing due to the fact of having not enough frames.

## Thrashing prevension:
To prevent thrashing we use **Local replacment algorithm** where we cannot steal frames from other processes, but we don't knwo how much pages the program will need during its execution, this is why we need to use the following algorithms:
*Working set (WS)* algorithm and the *page fault frequency (PFF)*

**Locality** Is a set of pages that are actively used together at a specific instant of time during a process execution.
A process from a time to time moves from a locality to another

### Working set algorithm
Estimates the amount of frames needed by a process in its next execution phase based on its current memory requirement to prevent it from thrashing while keeping the degree of the microprogramming as high as possible. It is based on the assumption of locality. it uses a parameter ∆, which defines the Working Set Window. The idea is to examine the most ∆ page references made by a given process to build its WS.
**Working set**. Is the set of pages that are actively in use ≈ locality.

If we consider a number of processes (say N), then the total demand for frames would be: `D = Sum WSSi`
Thus, if the RAM contains m available frames for processes, thrashing will not occur when: D ≤ m
Otherwise, if D > m, then at least one process is thrashing, and a victim process should be swapped out (put to sleep).

**The parameter ∆:**
1. *Fixed System Wide Window*
2. *Dynamic Window per Process*

### Page Fault frequency
the concept of this algrithm is too simple, so when a process has a very high a page faults it will give it more frames and when it has too low  this implies that a process may have too many frames, by this it ensures that each process has a number of frames that is between the max and the min


# Process synchronization
**Monitors**
Are high-level programming language constructs that provides mutual exclusion [and synchronization].
A monitors is an abstract data type that includes:
- A set of programmer-defined operations (procedures or methods) which access is “supposed to be” mutually exclusive. to implement the entry and exit section or critical section
- A set of synchronization variables called condition variables. to implements waiting queues
- A set of local variables, used to determine the state of the system. e.g., to keep track of the number of blocked threads.
- The access to the a monitor is mutually exclusive. If a process attempts to execute any of the monitor’s functions while another process is currently within the monitor, the former process blocks till the latter finishes.
- Operations defined within a monitor can only access those variables declared locally within the monitor as well as their formal parameters.
- If a process is running inside a monitor, it does not imply that the process is executing its critical section.
- A monitor without condition variables is called a pure monitor. It only provides mutual exclusion.
### Relationship between Monitors and Semaphores:
- The compiler will translate monitor source code to a mutually-exclusive accessed area by adding semaphores where needed.
- Monitors ain’t available in all programming languages but can B simulated: e.g., in C programming language there is no monitor, but mutex locks (through pthread.h) can be used to simulate monitors. Other languages support it: Ada, C ♯, Delphi, Java, Python, Ruby, ...

**Condition variables** A particular type of data structure that is used by monitors for process synchronization (Queue + two primitives).
- each variable has a queue associated with it, The queue is made of PCBs
- Two operations are invoked on condition variable x:
1. **x.wait**: The process invoking this operation is suspended.
2. **x.notify**: Resumes exactly one suspended process from the x variable queue (no effect if no process is blocked).
a. **Notify and continue**. The notifying thread keeps the monitor lock.
• Thread that was awakened, will wait at the entry queue (Monitor lock).
• The condition which that thread waited for may not be true any more once that thread resumes (Process has to double-check the condition).
• Used in Java Monitors.
b. **Notify and wait**. The notifying thread is blocked and the notified onegets the lock.
• Awakened thread executes immediately (gets the lock from notifier).
• The condition which the thread waited for is certainly true (no checking).
• The notifying process is blocked at the entry queue (goes out).
if(Condition) wait(); Vs while(Condition) wait();

### Monitors in JAVA:
```java
Public class Monitor Example
{
Public synchronized void Critical section 1() { . . . }
Public synchronized int Critical section 2() { . . . }
...
Public synchronized Object Critical section n() { . . . }
}
```
