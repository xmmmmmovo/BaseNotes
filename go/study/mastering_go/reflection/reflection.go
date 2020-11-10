package main

import (
	"fmt"
	"reflect"
)

type a struct {
	X int
	Y float64
	Z string
}

type b struct {
	F int
	G int
	H string
	I float64
}

func main() {
	x := 100
	xRefl := reflect.ValueOf(&x).Elem()
	xType := xRefl.Type()
	fmt.Printf("The type of x is %s.\n", xType)
	A := a{100, 200.12, "Struct a"}
	B := b{1, 2, "Struct b", -1.2}
	var rA, rB reflect.Value
	rA = reflect.ValueOf(&A).Elem()
	rB = reflect.ValueOf(&B).Elem()

	iAType := rA.Type()
	iBType := rB.Type()
	fmt.Printf("i Type: %s\n", iAType)
	fmt.Printf("The %d fields of %s are:\n", rA.NumField(), iAType)
	for i := 0; i < rA.NumField(); i++ {
		fmt.Printf("Field name: %s ", iAType.Field(i).Name)
		fmt.Printf("with type: %s ", rA.Field(i).Type())
		fmt.Printf("and value %v\n", rA.Field(i).Interface())
	}

	fmt.Printf("i Type: %s\n", iBType)
	fmt.Printf("The %d fields of %s are:\n", rB.NumField(), iBType)

}
