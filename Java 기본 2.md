# Java 기본 2


## 클래스 선언

프로그램 구성요소를 객체로 보고, 객체간의 상호작용 이루어짐.

`class` : 객체 만들기 위한 틀.

```java
public class Car {

클래스 블록

}
```
컴파일하면 `Car`라는 class를 생성함.

```java
public class CarExam {

  public static void main(String[] args) {
    Car c1 = new Car();
    Car c2 = new Car[];
    
   }
 }
 ```
 이렇게 만들어진 객체는 `인스턴스`라고도 함.
 
 `Car`라는 객체가 2개 만들어지고,
 각각의 개체를 참고하는 c1과 c2 변수가 생성됨.


## 참조 타입
- 기본형 타입 : `boolean` `char` `byte` `short` `int` `long` `float` `double`

- 참조형 타입 : 기본형 타입을 제외한 모든 타입. `배열` `클래스` 등등


```java
int i = 4;
String str = new String("hello");  // String 이라는 class와 생성자.
```

`new` : class를 메모리에 올려줄 것 요청. 메모리에 올라가면 `인스턴스`가 됨.

- `참조한다`는 것은 변수가 인스턴스를 가지고 있는 것 X, 가리킨다는 의미.

- `str`이라는 변수에는 메모리 위치값 저장, `hello`라는 string 객체 가리킴.

- 이후 배울 모든 class는 참조형이다.


## String 클래스
문자열

- `new`를 이용하지 않고서도 생성 가능.
```java
String str1 = "hello";
String str2 = "hello";
  // hello가 상수 영역에 저장됨.
  // str1과 str2는 동일한 곳을 참조한다.
  
String str3 = new String("hello");
String str4 = new String("hello");
  // heap 영역에 생성.
  // str3와 str4는 다른 곳을 참조한다.
```

한 번 생성된 `class`는 변화하지 X


## 필드 선언
클래스의 구성요소, 구조체.

`자동차`라는 클래스는 `이름`과 `번호`라는 속성 가지고 있음. 이러한 속성들을 `필드`라고 함. 

객체마다 속성이 동일함.

```java
public class Car{
  String name;  // string 타입의 필드 선언
  int number;  // int 타입의 필드 선언
  
}
```
```java
public static void main(String[] args) {
  Car c1 = new Car();
  Car c2 = new Car();
  
  c1.name = "소나타";
  c1.number = 1234;
  
  c2.name = "그랜져";
  c2.number = 5678;

}
```
`car`라는 객체가 2개 생성되고, 객체마다 속성을 가지고 있음.


## 메소드
객체지향 언어라는 의미는 하나의 사물을 하나의 클래스로 설명하는 것.<br/>

사물에 대한 것은 `상태`와 `행동`으로 나뉨.

- `필드` : 물체의 상태 (이름 / 번호)
- `메소드` : 물체의 행동 (전진 / 후진)
<br/>
`메소드`란 클래스가 가지고 있는 기능. `함수`와 비슷한 역할.

- `입력값` : 매개변수(Parameter), 인자(Argument)
- `결과값` : 리턴값


### 메소드 선언

클래스 외부에 선언

```java
public class MyClass {
  public 리턴타입 메소드명 (매개변수) {
  
    필요한 기능들 
    
  }
```
```java
public class MyClass {

  // 인자도 없고 리턴값도 없는 메소드
  public void method1() {
    System.out.println("Hello World");
  }

  // 리턴값이 없는 메소드
  public void method2(int x) {
    System.out.println(x);
  }

  // 인자가 없지만 리턴하는 메소드
  public int method3() {
    System.out.println("Hello World");
    return 10;
  }

  // 인자가 여러 개이고 리턴하지 않는 메소드
  public void method4(int x, int y) {
    System.out.println(x + y);
  }

  // 인자를 받아 리턴하는 메소드
  public int method4(int y) {
    System.out.println(y);
    return y + 1;
  }
```


### 메소드 사용
`MyClass`라는 클래스가 가진 메소드를 사용하기 위해서는 반드시 `객체`로 만들어져야 함.
```java
public class MyClassExam {
  public static void main(String[] args) {
  
    MyClass myclass = new MyClass();  // myclass라는 객체 생성
    
    myclass.method1();
    myclass.method2(10);
    int value1 = myclass.method3();
    myclass.method4(5, 10);
    int value2 = myclass.method5(10);
    
  }
}
```

Java는 내가 만든 객체 뿐만 아니라 다른 사람이 만들어 놓은 객체를 사용할 수도 있음.
<br/><br/>

### String 클래스 메소드
문자열 다루는 메소드

- 문자열 선언
```java
String str = new String("hello");
String str = ("hello");
```

- `length` : 문자열의 길이 반환
```java
str.length();

```

- `concat` : 문자열과 문자열을 결합
```java
str.concat(" world");  // str은 여전히 "hello" 가리킴
str = str.concat(" world");  // str이 "hello world"를 가리킴
```
참조하는 것일 뿐이므로 기존의 값 바뀌지 않음. 값 바꾸려면 새로운 값 참조하도록 해야 함.

- `substring` : 문자열 자르기
```java
str.substring(3);  // 3번째 문자열부터
str.substring(3, 6);  // 3번째부터 6번째까지
```













