public class Reader extends Thread {
    int myName;
    RandomSleep rSleep;

    public Reader(int name) {
        myName = name;
        rSleep = new RandomSleep();
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            try {
                System.out.println("Reader " + myName + " wants to read. Beforehand, readcount is " + Synch.readcount);
                
                Synch.writerS.acquire();
                boolean writerActive = Synch.writer;
                Synch.writerS.release();
                
                if (writerActive) {
                    System.out.println("Reader " + myName + " waiting for writers to finish");
                    rSleep.doSleep(50, 100);
                    continue;
                }
                
                Synch.mutex.acquire();
                
                if (Synch.readcount == 0) {
                    Synch.wrt.acquire();
                }
                
                Synch.readcount++;
                System.out.println("Reader " + myName + " is now reading. Readcount is " + Synch.readcount);
                Synch.mutex.release();
                
                rSleep.doSleep(1, 200);
                
                Synch.mutex.acquire();
                
                Synch.readcount--;
                System.out.println("Reader " + myName + " is finished reading. Readcount decremented to " + Synch.readcount);
                
                if (Synch.readcount == 0) {
                    Synch.wrt.release();
                }
                
                Synch.mutex.release();
                
                rSleep.doSleep(50, 200);
            } catch (Exception e) {
                System.out.println("Exception in Reader " + myName + ": " + e.getMessage());
            }
        }
    }
}