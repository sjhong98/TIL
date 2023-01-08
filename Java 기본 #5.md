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

- ledTV라는 클래스 생성하여 TV를 구현.

- TV가 가진 기능을 


```java
public class ledTV implements TV {
  // ledTV는 인터페이스인 TV를 구현하겠다는 의미
  // TV가 가진 기능을 ledTV도 모두 가진다
  // 














