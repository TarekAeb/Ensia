import java.util.concurrent.Semaphore;

public class MultiThreadedComputation {
    static double a = 4, b = 5, c = 2, d = 3;
    static double x1, x2, x3, F;

    static Semaphore sem1 = new Semaphore(0);
    static Semaphore sem2 = new Semaphore(0);
    static Semaphore sem3 = new Semaphore(0);

    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            x1 = Math.sqrt(a + b);
            sem1.release();
        });

        Thread t2 = new Thread(() -> {
            x2 = (b * c) * 10;
            sem2.release();
        });

        Thread t3 = new Thread(() -> {
            x3 = (Math.pow(c, 2) * Math.pow(d, 2)) / 5;
            sem3.release();
        });

        Thread finalComputation = new Thread(() -> {
            try {
                sem1.acquire();
                sem2.acquire();
                sem3.acquire();
                F = x1 + x2 + x3;
                System.out.println("Final result F = " + F);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        t1.start();
        t2.start();
        t3.start();
        finalComputation.start();
    }
}
