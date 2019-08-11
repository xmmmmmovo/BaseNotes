package handler

import (
	"github.com/gin-gonic/gin"
	"net/http"
)

func UserSave(context *gin.Context) {
	username := context.Param("name")
	context.String(http.StatusOK, username + "用户已保存")
}