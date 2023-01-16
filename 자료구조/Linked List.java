import java.util.Scanner;

public class LinkedList {

    public class node {     // 노드 구성 클래스
        public node link;
        int data;

        public node() {
            this.data = 0;
            this.link = null;
        }

        public node(int data) {
            this.data = data;
            this.link = null;
        }
    }

    node head = new node();
    node tail = new node();

    public void init() {
        head.link = tail;
    }

    public int isEmpty() {
        if(head.link == tail) 
            return 1;
        else 
            return 0;
    }

    public void addFirst(int data) {   // 맨 앞 노드 추가 클래스
        node nnode = new node(data);

        nnode.link = head.link;
        head.link = nnode;
    }

    public void addLast(int data) {
        node nnode = new node(data);
        node tnode = new node();
        tnode = head;

        while(tnode.link != tail) {
            tnode = tnode.link;
        }

        nnode.link = tail;
        tnode.link = nnode;
    }

    public void delete(int data) {
        node tnode = new node(data);
        tnode = head;

        if(isEmpty() == 1) {
            System.out.println("리스트가 비었음");
            return;
        }

        while(tnode.link.data != data) {
            tnode = tnode.link;
        }

        tnode.link = tnode.link.link;
    }

    public void print() {
        node tnode = new node();
        tnode = head;

        if(isEmpty() == 1) {
            System.out.println("리스트가 비었음");
            return;
        }

        while(tnode.link != tail) {
            tnode = tnode.link;
            System.out.println(tnode.data);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList ll = new LinkedList();

        ll.init();

        while(true) {

            System.out.println("===== Linked List =====\n\n1. addFirst\n2. addLast\n3. delete\n4. print\n5. exit\n");
            int sel =  sc.nextInt();
            int data;

            switch(sel) {
                case 1:
                    System.out.println("처음에 삽입할 정수 입력 : ");
                    data = sc.nextInt();
                    ll.addFirst(data);
                    System.out.println("\n입력 완료");
                    break;

                case 2:
                    System.out.println("마지막에 삽입할 정수 입력 : ");
                    data = sc.nextInt();
                    ll.addLast(data);
                    System.out.println("\n입력 완료");
                    break;

                case 3:
                    System.out.println("제거할 정수 입력 : ");
                    data = sc.nextInt();
                    ll.delete(data);
                    System.out.println("\n제거 완료");
                    break;

                case 4:
                    System.out.println("");
                    ll.print();
                    break;

                case 5:
                    System.exit(1);

            }
        }

    }
}
