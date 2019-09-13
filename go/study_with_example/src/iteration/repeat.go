package iteration

func Repeat(char string) string {
	var rep string
	for i := 0; i < 5; i++ {
		rep += char
	}
	return rep
}
