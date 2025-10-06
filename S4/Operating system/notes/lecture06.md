# Deadlock
are critical issues in the operating system.  Deadlocks occur  when two or more processes are waiting for each other to release resources, creating a circular dependency that prevents any process from proceeding.

## Conditions for Deadlock
1. Mutual Exclusion: Only one process can use the resource at a time.
2. Hold and Wait: A process is holding at least one resource and waiting for another resource.
3. No Preemption: A resource cannot be forcibly removed from a process.
4. Circular Wait: A circular chain of two or more processes exists, where each process is waiting for a resource held by another process in the chain.

## Deadlock dealing 
1. Deadlock ignorance: It is the user who has to detect deadlocks and take actions, eg: terminate processes or take back resources.
2. Deadlock Avoidance and prevention: ensure that the system will never enter the deadlock state.
    - Deadlock avoidance:  This uses dynamic rules. For each request, the operating system determines whether a deadlock may arise or not, before granting a given resource to a given process (e.g., RAGs, Banker’s Algorithm).
    - Deadlock prevention: This uses static rules. The operating system ensures that the four deadlock conditions cannot occur.
3. Deadlock detection and recovery: 
    - Deadlock detection: The operating system checks the system for deadlock periodically and takes action if a deadlock is detected.
    - Deadlock recovery: If a deadlock is detected, the operating system takes action to recover from the deadlock.

## Resource Allocation Graph (RAG)
Resource allocation graphs, not to be confused with PPGs, are directed graph where the vertices V = P ∪R represent the set of processes P = {P1, . . . , Pn} and system resources R = {R1 , . . . , Rm}, whereas the edges E express which process Pi ∈ P has requested or is holding a given resource Rj ∈ R.

An edge from process Pi ∈ P to a resource Rj ∈ R, signifies that
process Pi ∈ P has requested an instance of resource type Rj ∈ R and its currently waiting for it (Pi → Rj is called request edge).

An edge from a resource Ri ∈ R to a process Pj ∈ P , signifies that process Pj ∈ P has been allocated an instance of resource type Rj ∈ R (Ri → Pi is called assignment edge).

Each process Pi ∈ P is depicted by a circle, whereas resources Ri ∈ R are represented by rectangles.

- we use The RAGs to identify whether there is a deadlock or not by checking whether there is closing cycle or not.
- If we don't know whether a process needs a resource in the future or not, we do claims, which means he may request that resource in the future.


## Deadlock prevention techniques:

### Deadlock prevention

In deadlock prevention systems, the operating system ensures that at least one of the four necessary conditions cannot hold by enforcing static rules. in this solution, we need to preserve the mutual exclusion and the no-Preemption conditions, and deals with the other two as follows:
- **Hold and wait.** Here, the system should not allow a process to hold resources and wait for other resources. To that end, systems with deadlock prevention requires from the process to get all the resources at a time or get nothing. E.g., if a process need to copy a file from a DVD-ROM device to the HDD drive, then print the document using a
printer, then the process will have to acquire the three resources first, and then start the task of copying and printing. 
- **Circular wait** The system imposes a global ordering as per requesting resources, e.g., assuming resources are indexed, then we could use an increasing order of enumeration. This is what we did with the dinning philosophers when we asked then to pick up the fork with the small index and then the one with the big index. However, this might not be ideal for all processes.
### Deadlock avoidance
Systems that use deadlock avoidance apply dynamic rules. For each received request, the operating system determines whether a deadlock may arise or not before granting a given resource to a given process.
- A **safe sequence**. Is a sequence S of processes: ∀P_i ∈ S, the resources requested by Pi ∈ S can be allocated from the currently available resources plus the resources held by all `P_[j<i] ∈ S` (i.e., process Pi ∈ S may wait).


#### Thye banker algorithm:
m is an algorithm that allows the avoidance of deadlocks by determining whether a safe sequence S exists or not. The algorithm uses four data structures:

1. Available. A vector of size m (resource types) to express the currently
available number of instances for a given resource R_j. Available[j] = k : there are k instances of resource type Rj
2. Max. A matrix of size n × m to express the maximum number of
resources to be requested by a given process. Max[i, j] = k : at most k instances of resource type Rj will be requested by process Pi .
3. Allocation. A matrix of size n × m to express the currently held instances of each resource type by a given process.
Allocation[i, j] = k : Currently there are k instances of resource type R_j held by process P_i.
4. Need. A matrix of size n × m to express the remaining number of instances of each resource type to be requested by a given process. Need[i, j] = k : There are k instances of resource type Rj to be requested by process Pi at anytime in the future. Need[i, j] = Max[i, j] - Allocation[i, j]

### Deadlock detection


