package main

func rev(s []byte) {
	i := 0
	j := len(s) - 1
	for i < j {
		t := s[i]
		s[i] = s[j]
		s[j] = t
		i++
		j--
	}
}

func reverseWords(s string) string {
	i := 0
	j := i
	ss := []byte(s)
	for i < len(ss) && j < len(ss) {
		for j < len(ss) && ss[j] != ' ' {
			j++
		}
		rev(ss[i:j])
		i = j + 1
		j = i
	}
	return string(ss)
}

func main() {

}
