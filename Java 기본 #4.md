# Java 기본 #4

## 상속
`부모클래스` : 상위 클래스

`자식클래스` : 하위 클래스

> public class `클래스명` extends `부모클래스명`

부모가 가지고 있는 것을 자식이 사용할 수 있게 됨.

```java
// 부모 클래스인 Car 생성
public class Car {
  public void run() {
    System.out.println("달리다");
  }
}
```

```java
// 자식 클래스인 Bus 생성
public class Bus extends Car {
  public void back() {
    System.out.println("후진");
    }
}
```

```java
// 새로운 클래스 생성
public class Exam {
  public static void main(String[] args) {
  
    Bus bus = new Bus();
    bus.run();
    bus.back();
    
    Car car = new Car();
    car.run();
    car.back();  // 컴파일 에로. 단방향 상속만 가능
  }
}
```


## 접근 제한자
`캡슐화` : 관련된 필드와 메소드를 모아서 가지고 있는 것
`접근제한자` : 접근을 제한하는 것.

- `public` : 모든 접근을 허용

- `protected` : 같은 패키지거나 나를 상속을 받은 경우 허용

- `private` : 자기 자신만 접근 가능

- `default` : 아무 것도 적지 않은 경우, 같은 패키지만 허용

```java
public class Access {

  public int p = 3;
  protected int p2 = 4;
  private int i = 1;
  int k = 2;
  
}
```


## 추상 클래스
추상 클래스는 부모로서의 역할 수행 가능하나, 객체로서 역할 X

> public abstract class Bird { 내용 }

추상 메소드가 하나라도 있으면 추상 클래스됨.

> public abstract void `메소드명`

추상 클래스라 하더라도 일반 메소드 가질 수 있음.<br/>

추상 클래스 정의
```java
public abstract class Bird {

  public abstract void sing();  // 추상 메소드, 구현 X
  
  public void fly() {
    System.out.println("날다");  // 일반 메소드
  }
}
```

상속받는 클래스 생성
```java
public class Duck extends Bird {
  
    public void sing() {
      System.out.println("꽥꽥");
    }
  
}
```

일반 클래스 생성
```java
public class Exam {
  public static void main(String[] args) {
   
    Duck duck = new Duck();
    duck.sing();
      // 실행결과 : 꽥꽥
    duck.fly();
      // 실행결과 : 날다
  }
}
```











