package main

func checkInclusion(s1 string, s2 string) bool {
	mp1 := make(map[byte](int))
	mp2 := make(map[byte](int))
	for i := 0; i < len(s1); i++ {
		mp1[s1[i]]++
	}
	if len(s1) > len(s2) {
		return false
	}
	for i := 0; i < len(s1); i++ {
		mp2[s2[i]]++
	}
	ok := func() bool {
		for k, v := range mp1 {
			if mp2[k] != v {
				return false
			}
		}
		return true
	}
	if ok() {
		return true
	}
	for i := 0; i+len(s1) < len(s2); i++ {
		mp2[s2[i]]--
		mp2[s2[i+len(s1)]]++
		if ok() {
			return true
		}
	}
	return false
}

func main() {

}
