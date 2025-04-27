import java.util.concurrent.*;

public class Writer extends Thread {
    int myName;
    RandomSleep rSleep;
    private Semaphore myTurn;  

    public Writer(int name) {
        myName = name;
        rSleep = new RandomSleep();
        myTurn = new Semaphore(0, true);  
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            try {
                System.out.println("Writer " + myName + " wants to write");
                
                Synch.writerS.acquire();
                Synch.writer = true;
                Synch.writerS.release();
                
                Synch.wrtQ.acquire();
                
                boolean first = Synch.writerQueue.isEmpty();
                
                Synch.writerQueue.add(myName);
                
                if (!first) {
                    Synch.wrtQ.release();
                    
                    myTurn.acquire();
                } else {
                    Synch.wrtQ.release();
                }
                
                Synch.wrt.acquire();
                
                System.out.println("Writer " + myName + " is now writing");
                
                rSleep.doSleep(1, 200);
                
                System.out.println("Writer " + myName + " is finished writing");
                
                Synch.wrtQ.acquire();
                
                Synch.writerQueue.remove((Integer)myName);
                
                boolean isEmpty = Synch.writerQueue.isEmpty();
                
                if (!isEmpty) {
                    int nextWriter = Synch.writerQueue.peek();
                    
                    for (Thread t : Thread.getAllStackTraces().keySet()) {
                        if (t instanceof Writer && ((Writer)t).myName == nextWriter) {
                            ((Writer)t).myTurn.release();
                            break;
                        }
                    }
                } else {
                    Synch.writerS.acquire();
                    Synch.writer = false;
                    Synch.writerS.release();
                }
                
                Synch.wrtQ.release();
                
                Synch.wrt.release();
                
                rSleep.doSleep(50, 200);
            } catch (Exception e) {
                System.out.println("Exception in Writer " + myName + ": " + e.getMessage());
            }
        }
    }
}