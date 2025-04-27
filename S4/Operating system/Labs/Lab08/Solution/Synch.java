import java.util.concurrent.*;
import java.util.Queue;

public class Synch {
    public static Semaphore mutex;      
    public static Semaphore wrt;         
    public static Semaphore rdQ;        
    public static Semaphore wrtQ;       
    public static Semaphore writerS;    
    public static Semaphore fifoLock;   
    public static Queue<Integer> readerQueue;  
    public static Queue<Integer> writerQueue;  
    public static int readcount = 0;    
    public static boolean writer = false;  
}