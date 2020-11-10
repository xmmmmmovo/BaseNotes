package main

import (
	"fmt"
	"reflect"
)

type t1 int
type t2 int

type aa struct {
	X    int
	Y    float64
	Text string
}

func (a1 aa) conpareStruct(a2 aa) bool {
	r1 := reflect.ValueOf(&a1).Elem()
	r2 := reflect.ValueOf(&a2).Elem()

	for i := 0; i < r1.NumField(); i++ {
		if r1.Field(i).Interface() != r2.Field(i).Interface() {
			return false
		}
	}

	return true
}

func main() {
	var p struct{}
	r := reflect.New(reflect.ValueOf(&p).Type()).Elem()
	fmt.Printf("The type of r is %s\n", reflect.TypeOf(r))

}
