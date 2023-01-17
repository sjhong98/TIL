import java.util.Scanner;

public class Hash2 {
    int size;
    Node[] hash;

    public Hash2(int size) {  // 해시 생성자
        this.size = size;
        hash = new Node[size];
        for(int i=0; i<size; i++) {
            hash[i] = new Node(i);   // node initiation
        }
    }

    public class Node {   // 
        Node link;
        String data;
        int key;

        public Node(String data) {
            this.data = data;
        }

        public Node(int i) {
            this.data = null;
            this.key = i;
        }

        public Node() {
            this.data = null;
            this.key = 0;
        }
    }

    int convert(String data) {
        char[] arr = data.toCharArray();
        int key = 0;
        for(int i=0; i<arr.length; i++)
            key += (int)arr[i];
        return key % size;
    }

    int collisionCheck(int key) {
        if(hash[key].data == null)
            return -1;
        else    
            return 0;
    }

    void addList(String data) {
        int key = convert(data);
        if(collisionCheck(key) == -1) {     // 비었다면
            hash[key].data = data;
            System.out.println(key + "에 신규 노드 추가");
        }
        else {
            Node nnode = new Node(data);
            hash[key].link = nnode;     // 충돌 1회만 해결 가능한 상태
            System.out.println(key + "에서 충돌 발생");
        }
    }

    void printh() {
        System.out.println("");

        for(int i=0; i<size; i++) {
            Node tnode = new Node();
            tnode = hash[i];
            System.out.print((i+1) + "번째 배열 : ");
            while(tnode != null) {  // 3번째 노드가 null이기 때문
                System.out.print(tnode.data + " ");
                tnode = tnode.link;
            } 
            System.out.println("");
        }
    }

    public static void main(String[] args) {
        Hash2 hash = new Hash2(10);
        Scanner sc = new Scanner(System.in);

        while(true) {
            System.out.println("\n===== Hash =====\n1. Add\n2. Print\n3. Exit\n");     
            int sel = sc.nextInt();

            switch(sel) {
                case 1 :
                    System.out.println("추가할 문자열 입력 : ");
                    sc.nextLine();
                    String str = sc.nextLine();
                    hash.addList(str);
                    break;
            
                case 2 :
                    hash.printh();
                    break;
            
                case 3 :
                    System.exit(0);
            
                default :
                    System.out.println("잘못 입력");
                    break;
            }
        }
    }
}

