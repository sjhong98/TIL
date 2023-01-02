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
  // str1과 str2는 동일한 영역을 가리킨다.
String str2 = new String("hello");
  // heap 영역에 만듦.





