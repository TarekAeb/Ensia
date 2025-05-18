import java.util.concurrent.Semaphore;

public class Quiz {
    static double a = 1, b = 1, c = 2;
    static double x1, x2, x3, x4, x5, x6,x7, H;
    static Semaphore sem1 = new Semaphore(0);
    static Semaphore sem2 = new Semaphore(0);
    static Semaphore sem3 = new Semaphore(0);
    static Semaphore sem4 = new Semaphore(0);
    static Semaphore sem5 = new Semaphore(0);
    static Semaphore sem6 = new Semaphore(0);
    // static Semaphore sem7 = new Semaphore(0);
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            x1 = a*a;
            sem1.release();
            System.out.println("x1=");
            System.out.println(x1);
        });

        Thread t2 = new Thread(() -> {
            try{
            sem1.acquire();
            x2 = x1+b;
            System.out.println("x2=");
            System.out.println(x2);
            sem2.release();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread t3 = new Thread(() -> {
            try{sem2.acquire();
            x3 = (x2/2);
            System.out.println("x3=");
            System.out.println(x3);
            sem3.release();} catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread t4 = new Thread(()->{
            x4= Math.sqrt(c);
            System.out.println("x4=");
            System.out.println(x4);
            sem4.release();
        });

        Thread t5 = new Thread(()->{
            try{sem4.acquire();
            sem3.acquire();
            x5= (x3+x4)*3;
            System.out.println("x5=");
            System.out.println(x5);
            sem5.release();} catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread t6 = new Thread(()->{
            x6= a*c -b;
            System.out.println("x6=");
            System.out.println(x6);
            sem6.release(); 
        });
        Thread t7 = new Thread(()->{
            try{
            sem5.acquire();
            sem6.acquire();
            x7 = x6+x5;
            System.out.println("H=");
            System.out.println(x7);
} catch (InterruptedException e) {
                e.printStackTrace();
            }

            // sem7.release();
        });

        
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
        t6.start();
        t7.start();

    }
}



