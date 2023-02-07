
# Truthy and Falsy

다음과 같은 상황에서 함수의 인자가 `undefined`이거나 `null`일 경우에 대비하여 그에 맞는 조치 필요

```javascript
function print(person) {
  if (person === undefined || person === null) {
    console.log('person이 없네요');
    return;
  }
  console.log(person.name);
}

const person = null;
print(person);
```

`undefined`나 `null`값은 `Falsy`한 값임. 따라서 다음과 같이 작성할 수 있음
```javascript
function print(person) {
  if (!person) {  // falsy한 값
    console.log('person이 없네요');
    return;
  }
  console.log(person.name);
}

const person = null;
print(person);
```

<br/>

### Falsy한 값들

```javascript
console.log(!undefined);
console.log(!null);
console.log(!0);
console.log(!'');
console.log(!NaN);
```


---






















