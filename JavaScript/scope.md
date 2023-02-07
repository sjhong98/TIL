# scope

선언된 변수나 함수가 유효한 범위

1. `Global Scope` : 코드의 모든 범위에서 사용가능
2. `Function Scope` : 함수 안에서만 사용가능
3. `Block Scope` : it, for, switch 등 특정 블록내부에서만 이용가능


- `const`, `let`으로 선언된 값 : Block Scope
- `var` : Function Scope

<br/>

## Hoisting

`hoisting` : 아직 선언되지 않은 함수나 변수를 끌어올려 사용하는 방식

hoisting이 발생할 경우 이해가 어려워지고 유지보수가 어려워지므로, 최대한 방지할 것.

### 방지하는 법

- `var`보다는 `let`이나 `const`를 사용하기
- 함수 선언 이후에 












