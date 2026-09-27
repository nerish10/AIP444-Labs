package main

import (
	"fmt"
	"strconv"
	"strings"
)

func summarizeRanges(values []int) string {
	if len(values) == 0 {
		return "none"
	}

	var builder strings.Builder
	n := len(values)
	i := 0

	for i < n {
		start := values[i]

		for i+1 < n && values[i+1] == values[i]+1 {
			i++
		}
		end := values[i]

		if start == end {
			builder.WriteString(strconv.Itoa(start))
		} else {
			builder.WriteString(strconv.Itoa(start))
			builder.WriteString("-")
			builder.WriteString(strconv.Itoa(end))
		}

		if i+1 < n {
			builder.WriteString(", ")
		}

		i++
	}

	return builder.String()
}

func main() {
	fmt.Println("[] ->", summarizeRanges([]int{}))
	fmt.Println("[7] ->", summarizeRanges([]int{7}))
	fmt.Println("[1, 2, 3, 4, 5] ->", summarizeRanges([]int{1, 2, 3, 4, 5}))
	fmt.Println("[98, 99, 100] ->", summarizeRanges([]int{98, 99, 100}))
	fmt.Println("[1, 3, 5, 7] ->", summarizeRanges([]int{1, 3, 5, 7}))
	fmt.Println("[0, 10, 20] ->", summarizeRanges([]int{0, 10, 20}))
	fmt.Println("[1, 2, 3, 5, 7, 8, 9] ->", summarizeRanges([]int{1, 2, 3, 5, 7, 8, 9}))
	fmt.Println("[0, 1, 2, 6, 7, 10] ->", summarizeRanges([]int{0, 1, 2, 6, 7, 10}))
}