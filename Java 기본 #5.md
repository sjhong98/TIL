# Java 기본 #5

## 인터페이스

객체를 만들 때, 객체가 어떤 기능을 가져야 할지 정해야 함.

`TV`라는 인터페이스를 만든다고 해보자. `TV`는 어떤 기능을 가져야 할까? 

켜고 끄기, 볼륨 조절, 채널 변경 등등의 기능, 즉 메소드가 있어야 할 것임. <br/><br/>

`인터페이스` : 이러한 메소드들을 구현하지 않고 선언만 해서 가지고 있는 것.



## 인터페이스 정의

```java
public interface TV {

  public int MIN_VOLUME = 0;
  public int MAX_VOLUME = 100;  // 상수 정의 (final 없어도 됨)

  public void turnOn();  // 추상 메소드와 유사 (abstract 붙이면)
  public void turnOff();
  public void changeVolume(int volume);
  public void changeChannel(int channel);
  
}
```


## 인터페이스 사용

객체의 기능들을 정의만 해놓고 구현을 하지 않았음 -> 구현해야 함.

```java
public interface TV {

  public int MIN_VOLUME = 0;
  public int MAX_VOLUME = 100;  // 상수 정의 (final 없어도 됨)

  public void turnOn();  // 추상 메소드와 유사 (abstract 붙이면)
  public void turnOff();
  public void changeVolume(int volume);
  public void changeChannel(int channel);
```

#### ledTV라는 클래스 생성하여 TV를 구현.

- ledTV는 TV가 가진 기능을 모두 가짐.

- ledTV는 TV에 정의된 모든 기능을 구현해야 함.


```java
public class ledTV implements TV {

  public void turnOn() {
    System.out.println("turned on");
  }
  
  public void turnOff() {
    System.out.println("turned off");
  }
  
  public void changeVolume(int volume) {
    System.out.println("volume changed");
  }
  
  public void changeChannel(int channel) {
    System.out.println("channel changed");
  }
  
}
```

```java
public class Exam {

  public static void main(String[] args) {
  
    TV tv = new ledTV();  // 인터페이스도 타입이 될 수 있다
    tv.turnOn();
    tv.changeVolume(8);
    tv.changeChannel(32);
    tv.turnOff();
    
  }
```
`상속`의 개념과 동일.

TV라는 `인터페이스`는 타입이 될 수 있으나, TV가 가진 기능만 사용할 수 있다.

추가 확장해서 사용하려면 `클래스 형변환`을 사용해야 함.

`인터페이스`를 사용하는 이유는 ledTV 뿐만 아니라 다른 TV도 만들 수 있기 때문.



## 인터페이스 default 메소드

Java 8부터 default, static 메소드 구현가능.

인터페이스가 default 키워드로 선언되면 메소드 구현 가능, 구현한 클래스에서 오버라이딩 가능

```java
public interface Calculator {

  public int plus(int i, int j);
  public int muliple(int i, int j);  // 선언만 해놓은 상태
  
  default int exec(int i, int j) {
    return i + j;  // dafautl 키워드로 메소드 구현 가능
  }

}
```
```java
public class MyCal implements Calculator {
  
  public int plus(int i, int j) {
    return i+j;
  }
  
  public int multiple(int i, int j) {
    return i * j;
  }
  
}
```
```java
public class Exam {

  public static void main(String[] args) {
    Calculator cal = new MyCal();
    cal.plus(3, 4);
    cal.multiple(3, 4);
    cal.exec(5, 6);  // 사용가능
  }
  
}
```

인터페이스가 
















