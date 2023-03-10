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



## 인터페이스 default, static 메소드

Java 8부터 `default`, `static` 메소드 구현가능.

인터페이스가 `default` 키워드로 선언되면 메소드 구현 가능, 구현한 클래스에서 오버라이딩 가능

`default` 키워드를 사용한 구현
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

인터페이스가 변경될 경우, 인터페이스를 구현하는 모드 클래스들이 해당 메소드를 구현하도록 변경되어야 함. 이러한 문제 방지.<br/><br/>

`static` 키워드를 사용한 구현

```java
public interface Calculator {

  public static int exec2(int i, int j) {
    return i * j;
  }
  
}
```

static 메소드는

> 인터페이스명.메소드형식

으로 호출해야 함

```java
public class Exam {
  
  public static void main(String[] args) {
    Calculator.exec2(3, 4);  // static 메소드 호출
  }

}
```


## 내부클래스

클래스 안에 선언된 클래스

- `instance 클래스` : 클래스 안의 인스턴스 변수, 즉 필드 선언하는 위치에 선언되는 경우 

```java
public calss Inner {

  class Cal {
    int value = 0;
    public void plus() {
      value++;
    }
  }
  
  public static void main(String[] args) {
  
    Inner i = new Inner();  // 인스턴스 클래스는 독자적으로 생성될 수 없음
    Inner.Cal cal = i.new Cal()   // Cal이라는 객체 생성
    
    cal.plus();
    System.out.println(cal.value);
    
  }
```
<br/><br/>
- `static 클래스` : 인스턴스가 static한 필드로 선언되는 경우 

```java
public class Inner {

  static class Cal {
    int value = 0;
    public void plus() {
      value++;
    }
  }
  
  public static void main(String[] args) {
  
    Inner.Cal cal = new Inner.Cal();  // 바깥 쪽 클래스를 따로 선언할 필요 X
    
    cal.plus();
    System.out.println(cal.value);
    
  }
  
}
```
<br/><br/>
- `local 클래스` : 메소드 안에서 선언되는 경우 

```java
public class Inner {

  public void exec() {  // exec이라는 메소드 생성
    class Cal {
      int value = 0;
      public void plus() {
        value++;
      }
    }
    
    Cal cal = new Cal();  // 메소드 내에서만 Cal이라는 객체를 생성할 수 있음
    
    cal.plus();
    System.out.println(cal.value);
  }

  public static void main(String[] args) {
    Inner i = new Inner();  // 객체 생성
    
    i.exec();  // 내부적으로 클래스가 정의되어 있음.
  }
  
}
```

<br/><br/>
- `익명 클래스` : 클래스 내부에서만 필요한 추상 클래스의 경우, 별도의 상속 받는 클래스를 생성할 필요 없이, 클래스 내부에서 직접 구현할 수 있도록 함.

```java
public abstract class Action {  // 추상 클래스

  public abstract void exec();  // 상속 받은 자식 메소드가 구현해야만 사용가능
  
}
```
```java
public class MyAction extends Action {
  
  public void exec() {
    System.out.println("exec");
  }
  
}
```
```java
public class Exam {

  public static void main(String[] args) {
  
    Action action = new MyAction();  // Action은 추상클래스이므로 객체로 생성불가 -> 자식 클래스로 객체 생성해야 함
    action.exec();  // 일반적인 추상클래스 사용형태
    
    Action action = new Action() {
      public void exec() {
        System.out.println("exec");
      }
    };  // 생성자 이름에 해당하는 클래스를 상속받은 익명객체 생성
        // 괄호 내부에선 메소드 구현, 추가할 수 있음
    action.exec();
    
  }
  
}
```
Exam이라는 클래스 내부에서만 Action 클래스가 사용될 때에는, 굳이 Action을 상속받는 MyAction이라는 클래스를 만들어 메소드를 구현할 필요가 없기 때문에, 클래스 내부에서 익명클래스를 사용하여 직접 구현할 수 있음.
    
    













