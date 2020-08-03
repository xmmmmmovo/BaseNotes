let fs = require("fs");

const randDict: Map<number, number> = new Map();

const main = (): void => {
  for (let i = 0; i < 1000000; i++) {
    let res = parseInt(
      (parseFloat(Math.random().toFixed(4)) * 10000).toFixed(0)
    );

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

  fs.writeFileSync("rkk.txt", k.toString());
  fs.writeFileSync("ryy.txt", y.toString());
};

main();
