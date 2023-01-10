# Java 기본 #6

## Exception (예외처리)

예외 상황 발생을 예측하고 처리할 수 있음.<br/><br/>

#### `try` : 오류 발생이 예상되는 구간

- 오류 발생할 경우 `catch` 블럭으로 넘어감

#### `catch` : 발생할 수 있는 오류 타입

- `try` 블럭에서 발생한 오류와 `catch` 블럭에 명시된 오류 코드가 같아야 함

- 여러 개 사용 가능

#### `finally` : 오류가 발생하든, 하지 않든 실행 사능

- `try`나 `catch`와 달리 반드시 실행되므로, 꼭 실행되어야 하는 부분 기재

- 생략 가능



```java
try {

} 
catch(예외클래스 변수명) {

} 
finally {

}
```

```java
public class Exception {
  
  public static void main(String[] args) {
    int i = 10;
    int j = 0;
    
    try {
      int k = i/j;  // 예외상황 발생
    }
    catch(ArithmeticException) {
      System.out.println("0으로 나눌 수 없습니다");
    }
    finally {
      System.out.println("main ends");
    }
     
  }
}
```


## Throws
연산을 하는 쪽이 아닌, 메소드를 호출한 쪽에서 오류를 처리하도록 넘길 수 있음.


```java
public class Exception {
  
  public static void main(String[] args) {
    int i = 10;
    int j = 0;
    
    try {
      int k = divide(i, j);  // 이곳에서 오류 처리하게 됨
      System.out.println(k);
    }
    catch {
      System.out.println("오류");
    }
      
  }
  
  public static int divide(int i, int j) throws ArithmeticException{
                                         // divide를 호출한 쪽으로 넘기기
    int k = i/j;
    return k;
  }
  
}
```


## Throw

강제로 오류 발생시키기.

```java
public class Exception {
  
  public static void main(String[] args) {
    int i = 10;
    int j = 0;
    
    int k = divide(i, j);
    System.out.println(k);
  }
  
  public static int divide(int i, int j) {
    if(j == 0) {
      System.out.println("0 불가");
      return 0;  // 잘못된 값 넘어가게 됨
    }
    int k = i/j;
    return k;
  }
}
```
```java
public class Exception {
  
  public static void main(String[] args) {
    int i = 10;
    int j = 0;
    
    try {
      int k = divide(i, j);
      System.out.println(k);
    }
    catch {
      System.out.println("e.toString());
    }
  }
  
  public static int divide(int i, int j) throws IllegalArgumentException{
                                         //divide를 호출한 쪽에서 처리하라
    if(j == 0) {
      throw new IllegalArgumentException("0 불가");
    }
    int k = i/j;
    return k;
  }
}
```


## 사용자 정의 Exception

에러 이름에 의미가 담겨 있기 때문.

```java
public class 클래스이름 extends Exception {
  
  오류 내용
 
}
```
<br/><br/>
Exception명 바꾸기 : 동일한 기능 가지고 있는 부모 exception 클래스에게 넘기기
```java
public class BizEx extends RuntimeException {

  public BizEx(String msg) {
    super(msg);
  }
  
  public BizEx(Exception ex) {
    super(ex);
  }
  // 같은 기능 가지고 있는 부모 exception 클래스에게 넘기기
  
}
```
<br/><br/>
만들어진 exception을 사용하는 클래스 생성
```
```java
public class BizService {

  public void bizMethod(int i) throws BizEx {
    System.out.println("비즈니스 메소드 시작");
    
    if(i < 0)
      throw new BizEx("0 이상");
      
    System.out.println("종료");
  }
  
}
```
<br/><br/>
사용하는 방법
```java
public class Exam {
  
  public static void main(String[] args) {
    BizService biz = new BizService();
    biz.bizMethod(5);
    biz.bizMethod(-3);
  }

}
```









