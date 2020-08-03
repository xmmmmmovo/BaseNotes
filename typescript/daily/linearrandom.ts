let fs = require("fs");

const randDict: Map<number, number> = new Map();

var rand = (function () {
  var today = new Date();
  var seed = today.getTime();

  function rnd() {
    seed = (seed * 9301 + 49297) % 233280;
    return seed / 233280.0;
  }
  return function rand(number) {
    return Math.ceil(rnd() * number);
  };
})();

const main = (): void => {
  for (let i = 0; i < 1000000; i++) {
    let res = rand(10000);

    if (randDict.has(res)) {
      randDict.set(res, randDict.get(res) + 1);
    } else {
      randDict.set(res, 1);
    }
  }
  console.log(randDict.size);

  const sl = Array.from(randDict);
  sl.sort(function (a, b) {
    return a[0] - b[0];
  });

  let k: number[] = [];
  let y: number[] = [];

  //   console.log(sl);

  for (let it of sl) {
    k.push(it[0]);
    y.push(it[1]);
  }

  //   console.log(k);
  //   console.log(y);

  fs.writeFileSync("rly.txt", y.toString());
};

main();
