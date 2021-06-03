package main

import "fmt"

type element struct {
	Name    string
	SurName string
	Id      string
}

var DATA = make(map[string]element)

func ADD(k string, n element) bool {
	if k == "" {
		return false
	}
	if LOOKUP(k) == nil {
		DATA[k] = n
		return true
	}
	return false
}

func DELETE(k string) bool {
	if LOOKUP(k) != nil {
		delete(DATA, k)
		return true
	}
	return false
}

func LOOKUP(k string) *element {
	_, ok := DATA[k]
	if ok {
		n := DATA[k]
		return &n
	} else {
		return nil
	}
}

func CHANGE(k string, n element) bool {
	DATA[k] = n
	return true
}

func PRINT() {
	for k, v := range DATA {
		fmt.Printf("key: %s value: %v", k, v)
	}
}
