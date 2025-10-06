# Memory management:

- Memory Management System. Is a module of the operating system responsible for managing and controlling the use of the central memory.

### The functions of the memory manager are:
- Keep track of the status of each portion of the central memory.
- Define and adopt a policy for allocating memory space to programs.
- Define and adopt a policy for releasing memory space.
- Protect the access to the memory space.
- Ensure the rearrangement (de-fragmentation) of free memory space.

### Hardware ot improve Access
Since the cpu is too fast and the access RAM is slow:
- CPUs have an internal fast memory, called cache memory, to store the most frequently and recently accessed instructions and data. e.g., Think of instructions and data used within a loop
- When a particular data is required, the hardware first checks whether that data is in the cache or not, if not the data is copied from RAM to cache under the assumption of pretty-soon reuse.
- The update of a particular information must be reflected in all other caches that contain that information (in multiprocessor systems). This is known as cache-coherency
- Sometimes, hardware is used to establish cache-coherency when DMA
is used (fully cache coherent system).

### Hardware to improve control

The OS alone is powerless, without hardware, it cannot enforce rules (e.g., a malicious process could bypass software checks).
- It is not the task of the OS to check which process is trying to perform illegal memory access (for performance reason).
- A hardware is used to implement this control. E.g., Check addresses w-r-t to base and limit registers
- Each process has a dedicated memory space which defines the range of its legal addresses.
- A dedicated hardware determines whether a given address is within that legal range or not

Yet, the hardware alone is dumb, it needs the OS to tell it what to protect.

- Per-process memory space protection can be implemented using two registers, namely, base and limit registers:

1. **Base Register**. Holds the smallest legal physical address of a given process.
2. **Limit Register**. Holds the size of the address space.

### Compiling and loading user programs

- The source code is written in a high-level language (e.g., C, C++, Java, etc.) and is compiled into an object code. The object code is then linked with other object codes to form an executable code. The executable code is then loaded into the memory by the loader program.
- During the program execution, some modules are loaded into the memory and some libraries are linked to the program upon request. i.e., dynamic loading(loader) and linking (linker).

## Dynamic loading & linking
### Dynamic loading
Is a software mechanism in which modules referred in a given program are loaded into the central memory only when being used.
- Modules could be libraries (*.so, *.dll), binaries, classes, plugins, etc.
- Useful for infrequently occurring cases, e.g error handling routines.
- It is the task of the user to design the program in such a way its uses this mechanism. The OS just provides the APIs for that.
- Once a program is done with a module, the module is unloaded from the central memory.

### Dynamic linking
Is a software mechanism that allows a program to link the body of a function to the program by loading the respective library into RAM at runtime only when that particular function is being invoked.

## Logical and Physical Addresses
- Every byte in the memory has a specific address that may range from 0 to some maximum, known as physical address. 
- Whenever a program is brought into memory, it occupies a certain number of memory locations, and the set of all physical addresses used by that program is called physical address space.
- During compilation, all variables and procedures in the source code of a program are assigned some specific addresses, known as logical addresses, where the set of these addresses is called logical address space.

### Address binding

- **Binding** is the process of setting up some relationships between 2 entities
- **Address binding** is a mapping from one address space to another

1. **Compile time** if it is known, at compile time, which addresses the program will occupy in the main memory. In this case, logical addresses are the same as that of physical addresses [static allocation].
`(symbolic @ −−compile−−> absolute @)`
2. **Load time** if it is not known at compile time, but it is known at load time, which addresses the program will occupy in the main memory. In this case, logical addresses are different from physical addresses [dynamic allocation].
`(symbolic @ −−compile−−> relocatable @ −−load--> absolute @`
3. **Execution time** If a process can be moved during its execution from
one memory partition to another, then binding should be delayed till
runtime [dynamic relocation].
`(symbolic @ −−−−compile+loader−−−−−−→ relocatable @ −−−execution−−> absolute @)`
**Logical address** aka, virtual address, is a memory address that is generated by the CPU during program execution e.g., in Mov Ax, [0xF23E] the address [0xF23E] is a logical address.
The set of logical address generated by a program is called the program logical address space.

**Physical address** is a memory address that is seen by the memory unit (the real address in RAM) that points to a physical memory location. e.g., logical addresses are translated/mapped by a hardware component called MMU (Memory Management Unit) into physical addresses

**Swapping** is the process of moving a program (i.e, its address space) from the RAM to the hard disk (swap out) or the reverse (swap in). it is performed by an operating system module called dipatcher

## Memory allocation

There are various strategies that are used to manage the memory:
### continuous memory allocation
#### Single partition
In this strategy, the main memory is divided into two zones, one to store the operating system’s code and the other to store user programs.
#### Multiple partitions 
In this strategy, the main memory is divided into two zones, one to store the OS code and the other for multiple user programs.
**Multiple Static Partitions**  In this scheme, partitions have the same size (a
system parameter).  It was originally used by IBM OS/360. (internal fragmentation)
**Multiple variable partitions**  Partition have variable sizes (depending on program needs). (partition had external fragmentation)

## Address Translation at runtime
During the execution of a program, the address translation takes place by the mean of a dedicated hardware: