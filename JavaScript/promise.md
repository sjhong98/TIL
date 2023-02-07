# Promise

비동기 작업을 편하게 처리할 수 있도록 ES6에서 도입된 기능

다음은 콜백 지옥 예시
```javascript
function increaseAndPrint(n, callback) {
  setTimeout(() => {
    const increased = n + 1;
    console.log(increased);
    if (callback) {
      callback(increased);
    }
  }, 1000);
}   // 1초에 한번 n을 1 증가하고 출력하는 함수

increaseAndPrint(0, n => {
  increaseAndPrint(n, n => {
    increaseAndPrint(n, n => {
      increaseAndPrint(n, n => {
        increaseAndPrint(n, n => {
          console.log('끝!');
        });   // 차례대로 5차례 실행
      });
    });
  });
});
```

`Promise` 형식

> const myPromise = new Promise( (resolve, reject) => {
> 
> // 구현
> 
> })

`resolve` : 성공했을 때 실행되는 부분

`reject` : 실패했을 때 실행되는 부분

`.then` : 작업이 성공한 이후 또 다른 작업 실행되어야 할때

`.catch` : 작업이 실패한 이후 또 다른 작업 실행되어야 할때


```javascript
function increaseAndPrint(n) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      const value = n + 1;
      if (value === 5) {
        const error = new Error();
        error.name = 'ValueIsFiveError';
        reject(error);
        return;
      }
      console.log(value);
      resolve(value);
    }, 1000);
  });
}

increaseAndPrint(0).then((n) => {
  console.log('result: ', n);
})
});
```

이를 이용하여, 성공한 이후에 `.then`을 통하여 재실행해주고, 종료 시에는 '.catch'를 사용하여 탈출하도록 할 수 있음.

```javascript
function increaseAndPrint(n) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      const value = n + 1;
      if (value === 5) {
        const error = new Error();
        error.name = 'ValueIsFiveError';
        reject(error);
        return;
      }
      console.log(value);
      resolve(value);
    }, 1000);
  });
}

increaseAndPrint(0)
  .then(n => {
    return increaseAndPrint(n);
  })
  .then(n => {
    return increaseAndPrint(n);
  })
  .then(n => {
    return increaseAndPrint(n);
  })
  .then(n => {
    return increaseAndPrint(n);
  })
  .then(n => {
    return increaseAndPrint(n);
  })
  .catch(e => {
    console.error(e);
  });
```

이를 더욱 단축하면 다음과 같이 사용할 수 있음.


```javascript
function increaseAndPrint(n) {
  return new Promise((resolve, reject) => {
  
    setTimeout(() => {
      const value = n + 1;
      if (value === 5) {
        const error = new Error();
        error.name = 'ValueIsFiveError';
        reject(error);
        return;
      }
      console.log(value);
      resolve(value);
    }, 1000);
    
  });
}

increaseAndPrint(0)
  .then(increaseAndPrint)
  .then(increaseAndPrint)
  .then(increaseAndPrint)
  .then(increaseAndPrint)
  .then(increaseAndPrint)
  .catch(e => {
    console.error(e);
  });
  ```
  
  


















