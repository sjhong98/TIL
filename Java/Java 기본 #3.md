# Java 기본 #3

## 생성자

클래스를 만들고 객체(인스턴스)를 만들기 위해서는 `new` 사용.

`new` 뒤에 나오는 것이 `생성자`

`생성자` : 객체가 될 때 필드 초기화

```java
// 생성자를 정의하지 않고 Car라는 class 선언
public class Car {
  String name;
  int number;
}
```

```java
public class CarExam {
  public static void main(String[] args) {
    Car c1 = new Car();   // 'Car()'이 생성자
  }
}
```

메소드와 비슷하게 생겼으나, 몇 가지 특징 있음.

- 리턴타입 없음
- 생성자를 만들지 않으면 매개변수 없는 생성자 자동으로 만들어짐 (기본생성자)


하나라도 생성자를 만들었다면, 기본생성자는 자동으로 만들어지지 X



```java
// 생성자 정의
public class Car {
  String name;
  int number;
  
  public Car(String n) {
    name = n; 
  }
  // 반드시 이름을 가지고 Car 객체를 만들도록 함
  // 생성자의 인자로 입력되면 Car 객체의 name으로 사용되게 함.
}
```
```java
public class CarExam {
   public static void main(String[] args) {
      Car c2 = new Car("Sonata");
          //이름 넣어 객체 생성 가능
   }
}
```

## This
현재 객체, 자기 자신을 가리킴.
```java
public class Car {
  String name;
  int number;
  
  public Car(String name) {
    name = name;  // name이 어떤 것을 가리키는지 몰라 에러 발생
  }
}
```
- class 안에서 자기 자신이 가지고 있는 메소드를 사용하고자 할 때
- 나의 생성자를 호출할 때
```java
public class Car {
  String name;
  int number;
  
  public Car(String name) {
    this.name = name;  // this.name은 현재 객체 안에 있는 필드 가리킴
  }
}
```


## 메소드 오버로딩
매개변수, 타입이 다르지만 비슷한 기능하는 메소드 존재

각각 다른 이름으로 정의되어 있으면 헷갈림

`메소드 오버로딩` : 매개변수의 수, 타입이 다른 경우 동일한 이름으로 메소드를 여러 개 정의.

- 타입이 같으면 매개변수 수가 달라야 함

- 매개변수 수가 같으면 타입이 달라야 함

오버로딩 방법

```java
public class MyClass {
  
// method 1
  public int plus (int x, int y) {
    return x + y;  
  }

// method 2
  public int plus (int x, int y, int z) {
    return x + y + z;  // 타입 같지만 매개변수 달라서 가능
  }
  
// method 3
  public String plus (String x, String y) {
    return x + y;  // 매개변수 수 같지만 타입 달라서 가능
  }
  
}
```
사용 방법
```java
public class MethodOveloadExam {
  public static void main(String[] args) {
    MyClass m = new MyClass();  // 객체 생성
    
    System.out.println(m.plus(4, 5));  // 클래스가 가지고 있는 메소드 사용
    // result : 9
    
    System.out.println(m.plus(4, 5, 6));
    // result : 15
    
    System.out.println(m.plus("hello", " world"));
    // result : hello world
  }
  
}
```
    
    
## 생성자 오버로딩
메소드와 마찬가지로 매개변수의 수와 타입이 다르다면 여러 개 생성자 선언 가능

```java
public class Car {
  String name;
  int number;
  
  public Car(String name) {
    this.name = name;
  }
  
  public Car() {
    this.name = "이름없음";
    this.number = 0;
    
    this("이름없음", 0);
    // 스스로 호출하여 2개의 인자 전달. (밑의 코드)
    // car("이름없음", 0)과 동일
    
  }  // 기본 생성자 오버로딩, 초기화
  
  public Car(String name, int number) {
    this.name = name;
    this.number = number;
  }  // 인자 2개 받는 생성자 오버로딩
  
}
  
```
```java
public class CarExam {
  
  public static void main(String[] args) {
    Car c1 = new Car("소방차");
    Car c2 = new Car();  // 기본 생성자 사용하면 컴파일 오류.
                         // 기본 생성자를 선언하면 오류 미발생
    Car c3 = new Car("구급차", 1111);
  }
}
```


## 패키지
자바 파일을 작성한 후 컴파일하면 클래스 생성

`패키지` : 관련 있는 클래스끼리 정리해놓는 것

- 도메인 이름을 거꾸로 적은 후 프로젝트 이름 붙임

- 패키지가 있는 클래스 사용할 때 `import` 사용

> com.eightcruz.javastudy

<br/>

```java
import com.eightcruz.javastudy.*;  // import

public class HelloExam {
  public static void main (String[] args) {
    Hello hello = new Hello();
  }
}
```
    
      
      
      













