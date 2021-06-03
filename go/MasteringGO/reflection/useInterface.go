package main

import "fmt"

type Shape interface {
	Area() float64
	Perimeter() float64
}

type square struct {
	X float64
}

func (s square) Area() float64 {
	return s.X * s.X
}

func (s square) Perimeter() float64 {
	return s.X * 4
}

func Calculate(shape Shape) {
	fmt.Println(shape.Area())
	fmt.Println(shape.Perimeter())
}

func main() {
	x := square{X: 10}
	fmt.Println("Perimeter:", x.Perimeter())
	Calculate(x)
}
