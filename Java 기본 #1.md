# Java 기본 #1


## 주석

// : 행단위 주석

/* */ : 블럭단위 주석



## 변수

별 내용 없었음




## 상수

한번 저장하면 데이터값 변경 불가

상수는 대문자로 정의

```java
int i = 10;
i = 5;

final int J = 10;
J = 5   // 불가
```

## 데이터타입

### 논리형
- boolean
### 문자형
- char
### 실수형
- float (뒤에 f 붙여야 함)
- double
### 정수형
- int
- long (뒤에 l 붙여야 함)


## 기본형의 타입 변환

### 묵시적 형변환
크기가 더 큰 타입으로 변환할 때 사용
```java
int x = 50000;
long y = x;
```
### 명시적 형변환
크기가 더 작은 타입으로 변환할 때 사용
```java
long x = 50000;
int y = (int) x;
// int y = x -> 에러
```


## 배열
- 변수타입에 [] 
- `new` 붙이기

### 배열 선언
```java
int[] array1 = new int[100]; // 배열 생성
array1[0] = 1;

int[] array2 = new int[]{1, 2, 3, 4};

int[] array3 = {1, 2, 3, 4};
```

### 2차원 배열 선언
```java
int[][] array1 = new int[10][10];

int [3][] array2;
array2[0] = new int[1];
array2[1] = new int[2];
array2[2] = new int[3];
// 각각 1차원 배열의 길이 다른 2차원 배열 선언

int[][] array3 = {{1, 2}, {3, 4}, {5, 6}};
```

### for each 구문
자동으로 돌면서 값을 꺼내줌
```java
int [] iarr = {10, 20, 30, 40, 50);
 
for(int i = 0; i<iarr.length; i++)
  int value = iarr[i]; 
  System.out.println(value);
// 위 식을 for each를 사용하여 표현
   
for(int value:iarr) {
  System.out.println(value);
}



