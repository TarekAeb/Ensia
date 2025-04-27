import java.util.concurrent.*;

public class MainMethod {
    public static void main(String argv[]) {
        // Initialize the semaphores/variables needed for thread synchronization
        Synch.mutex = new Semaphore(1, true);
        Synch.wrt = new Semaphore(1, true);
        Synch.rdQ = new Semaphore(1, true);
        Synch.wrtQ = new Semaphore(1, true);
        Synch.writerS = new Semaphore(1, true);
        Synch.fifoLock = new Semaphore(1, true);  // Add the FIFO lock semaphore
        Synch.readerQueue = new ConcurrentLinkedQueue<>();
        Synch.writerQueue = new ConcurrentLinkedQueue<>();
        Synch.writer = false;
        
        // Now create several instances of Reader and Writer.
        Reader R;  // R can hold an instance of class Reader
        Writer W;  // W can hold an instance of class Writer

        for (int i=1; i<=8; i++) {
            W = new Writer(i);
            W.start();
            R = new Reader(i);
            R.start();
        }

        System.out.println("This is main speaking");
    }
}