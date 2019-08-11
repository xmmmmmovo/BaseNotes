package main

import (
	"ginProject/initProject"
)

func main() {
	// router 相当于路由器
	router := initProject.SetupRouter()

	_ = router.Run()
}
