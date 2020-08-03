const addOne = (x: number) => x + 1;
const subtractOne = (x: number) => x - 1;

const compose = <A, B, C>(g: (input: A) => B, f: (input: B) => C) => {
  return (input: A) => f(g(input));
};

const addTow = compose(addOne, addOne);

console.log(addTow(0));
