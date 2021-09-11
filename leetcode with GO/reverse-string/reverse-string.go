package main

func swap(x *byte, y *byte) {
	z := *x
	*x = *y
	*y = z
}

func reverseString(s []byte) {
	i := 0
	j := len(s) - 1
	for i < j {
		swap(&s[i], &s[j])
		i++
		j--
	}
}

func main() {

}
