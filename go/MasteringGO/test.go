package main

import (
	"fmt"
	"sync"
	"time"
)

var lock sync.Mutex

func f(a int64) {
	wg := sync.WaitGroup{}

	wg.Add(1)
	go func() {
		defer wg.Done()
		for i := 0; i < 1000; i++ {
			lock.Lock()
			a++
			lock.Unlock()

			time.Sleep(time.Millisecond * 10)
		}
	}()
	
	for i := 0; i < 1000; i++ {
		lock.Lock()
		fmt.Println(a)
		lock.Unlock()
	}
	wg.Wait()
}

func main() {
	f(10)
}
