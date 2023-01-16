import java.util.Scanner; 

public class Queue {

    private int front;
    private int rear;
    private int size;
    private int[] queue;
    int count;

    public Queue(int size) {   // 생성자
        front = 0;
        rear = 0;
        this.size = size;
        queue = new int[size];
        count = 0;
    }

    public int isEmpty() {
        if(front == rear){
            return 1;
        }
        else
            return 0;
    }

    public int isFull() {
        if(rear+1 % size == front)
            return 1;
        else   
            return 0;
    }

    public void enQueue(int data) {
        if(isFull() == 0) {
            queue[++rear] = data;
            rear = rear % size;
            System.out.println("front, rear : "+ front + ". " + rear);
            count++;
        }
        else  
            System.out.println("Queue is full...");
    }

    public int deQueue() {
        if(isEmpty() == 0) {
            front++;
            count--;
            return queue[front%size];
        }
        else   
            return -1;
    }

    public void printq() {
        int j = front+1;
        System.out.println(" ");
        for(int i=0; i<count; i++) {
            System.out.println(queue[j++]);
            front = front % size;
        }
    }

    public static void main(String[] args) {

        Queue q1 = new Queue(10);
        Scanner sc = new Scanner(System.in);    // System.in 으로 입력된 값을 바이트 단위로 읽음

        while(true) {
            System.out.println("===== Circle Queue =====\n\n1. enQueue\n2. deQueue\n3. print\n4. exit\n");
            int sel = sc.nextInt();
            int num;

            switch(sel) { 
                case 1 :
                    System.out.println("삽입할 정수 입력 : ");
                    int data = sc.nextInt();
                    q1.enQueue(data);
                    break;
            
                case 2 : 
                    if((num = q1.deQueue()) == -1)
                        System.out.println("Queue is emtpy");
                    else 
                        System.out.println("출력 완료 : " + num);
                    break; 
        
                case 3 :
                    q1.printq();
                    break;
            
                case 4 :
                    sc.close();
                    System.exit(0);
            }
        }

    }

}
