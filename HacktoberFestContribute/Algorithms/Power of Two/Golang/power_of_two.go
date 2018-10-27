package main

import (
	"fmt"
)

func main() {
	for i := 0; i < 1025; i++ {
		if ((i > 0) && (i & (i - 1)) == 0) {
			fmt.Println(i, "is power of two")
		}
	}
}