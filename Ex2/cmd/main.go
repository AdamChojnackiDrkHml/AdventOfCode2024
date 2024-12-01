package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	input := os.Args[1]
	x, y := readInput(input)

	xMap := createMap(x)
	yMap := createMap(y)

	fmt.Println(calcSimilarity(xMap, yMap))
}

func readInput(path string) (a, b []int) {
	f, err := os.Open(path)

	if err != nil {
		fmt.Println("Error occured")
		os.Exit(1)
	}
	defer f.Close()

	scanner := bufio.NewScanner(f)

	for scanner.Scan() {
		line := scanner.Text()

		var x, y int

		fmt.Sscanf(line, "%d\t%d\n", &x, &y)

		a = append(a, x)
		b = append(b, y)
	}

	return a, b
}

func createMap(l []int) map[int]int {
	m := make(map[int]int)

	for _, a := range l {
		m[a]++
	}

	return m
}

func calcSimilarity(x, y map[int]int) int {
	var sum int

	for i, n := range x {
		yy := y[i]
		sum += n * i * yy
	}

	return sum
}
