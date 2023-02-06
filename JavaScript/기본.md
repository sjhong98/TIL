# JavaScript 1

### 변수 선언

`let` : 새로운 변수 선언

```javascript
let value = 1;
```

한 번 정의된 이후에는 `let`을 사용하지 않고 값 변경 가능.

---

### 다양한 형태의 데이터 선언
```javascript
# 숫자
let value = 1;

# 문자열
let text = 'hello';

# 불리언
let good = true;
```
---


### 상수 선언

`const` : 새로운 상수 선언 -> 값이 고정적

```javascript
const a = 1;
```
---

### 두 값 일치 확인
`==` : 타입형을 고려하지 않고 확인 -> 1과 '1'이 동일한 것으로 취급

`===` : 타입형을 고려하여 확인 -> 1과 '1'은 다른 것으로 취급


---

### 문자열 붙이기
```javascript
const a = 'hello ';
const b = 'world';
console.log = 'hello world';
```
출력결과 : hello world

---

### 함수

```javascript
function add(a, b) {
  return a + b;
}

const sum = add(1, 2);
console.log(sum);
```

```javascript
function hello(name) {
  console.log('hello, ' + name);
}
hello('hong');
```

`템플릿 리터럴`
```javascript
function hello(name) {
  console.log('hello, ${name}');
}
hello('hong')
```

### 화살표 함수
`=>` : 가리키는 this의 차이
```javascript
const add = (a, b) => {
  return a + b;
};
console.log(add(1, 2));
```





















