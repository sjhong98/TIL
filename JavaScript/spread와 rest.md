# spread

```javascript
const slime = {
  name: '슬라임'
};

const cuteSlime = {
  name: '슬라임',
  attribute: 'cute'
};

const purpleCuteSlime = {
  name: '슬라임',
  attribute: 'cute',
  color: 'purple'
};
```
위의 식에서 `cuteSlime`과 `purpleCuteSlime`은 위의 객체의 내용을 건들이지 않고 새로운 내용만을 추가한 채 새롭게 생성됨.

이러한 경우에 사용할 수 있는 것이 `spread` 문법.

<br/>

`...` : 해당 객체의 내용을 그대로 가져오기

```javascript
const slime = {
  name: '슬라임'
};

const cuteSlime = {
  ...slime,
  attribute: 'cute'
};

const purpleCuteSlime = {
  ...cuteSlime,
  color: 'purple'
};
```

### 배열에서의 spread

```javascript
const animals = ['개', '고양이', '참새'];
const anotherAnimals = [...animals, '비둘기'];
```

### 함수에서의 spread

배열 안에 있는 원소들을 모두 함수의 파라미터로 넣어주고자 할 때.

```javascript
function sum(...rest) {   // 여기서는 rest
  return rest.reduce((acc, current) => acc + current, 0);
}

const numbers = [1, 2, 3, 4, 5, 6];
const result = sum(...numbers);   // 여기서는 spread
console.log(result);
```

이처럼 spread와 rest를 이용하여 해결 가능.



<br/>

# rest

비구조화와 함께 사용됨.

특정되어 있는 항목을 제외한, 나머지 항목들을 구조화.

```javascript
const purpleCuteSlime = {
  name: '슬라임',
  attribute: 'cute',
  color: 'purple'
};

const { color, ...cuteSlime } = purpleCuteSlime;
```
위의 결과로는 

- `color`에는 'purple'이라는 값이, 
- ...cuteSlime이라는 값에는 {name: "슬라임", attribute: "cute"} 라는 값이 들어감

<br/>

rest를 사용하여 만든 `cuteSlime` 이라는 객체에서 또다시 `attribute`를 제거하고 싶다면 다음과 같이 할 수 있음

```javascript
const purpleCuteSlime = {
  name: '슬라임',
  attribute: 'cute',
  color: 'purple'
};

const { color, ...cuteSlime } = purpleCuteSlime;
console.log(color);
console.log(cuteSlime);

const { attribute, ...slime } = cuteSlime;
console.log(attribute);
console.log(slime);
```

<br/>

### 배열에서의 rest

```javascript
const numbers = [0, 1, 2, 3, 4, 5, 6];

const [one, ...rest] = numbers;
```
`one`에는 0, rest에는 1~6 들어감.

다만, 마지막 값에는 사용할 수 없음.


<br/>

### 함수에서의 rest

함수의 파라미터가 몇 개인지 모르는 상황에서 유용하게 사용.

```javascript
function sum(a, b, c, d, e, f, g) {
  let sum = 0;
  if (a) sum += a;
  if (b) sum += b;
  if (c) sum += c;
  if (d) sum += d;
  if (e) sum += e;
  if (f) sum += f;
  if (g) sum += g;
  return sum;
}

const result = sum(1, 2, 3, 4, 5, 6);
  // sum에 필요한 파라미터는 7개이나, 전달된 것은 6개
  // 이를 처리하기 위해서는 일일히 유효값 여부를 확인해야 함
```

이러한 경우에서 `...rest`를 사용할 수 있음

```javascript
function sum(...rest) {
  return rest.reduce((acc, current) => acc + current, 0);
}

const result = sum(1, 2, 3, 4, 5, 6);
```






















