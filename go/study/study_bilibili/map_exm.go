package main

import "fmt"

func modifyUser(users map[string]map[string]string, name string)  {
	if users[name] != nil {
		users[name]["pwd"] = "12345678"
	} else {
		users[name] = make(map[string]string, 2)
		users[name]["pwd"] = "123456"
		users[name]["nickname"] = name
	}
}

func main() {
	users := make(map[string]map[string]string, 10)
	modifyUser(users, "xiaozhang")
	fmt.Println(users)
}
