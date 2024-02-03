package main

import (
	"fmt"
	"math/rand"
	"time"
)

type RandomArray struct {
	array1 []int
	array2 []int
	umap   map[int]int
	size1  int
	size2  int
}

func NewRandomArray() *RandomArray {
	return &RandomArray{
		umap: make(map[int]int),
	}
}

func (ra *RandomArray) findSolution() {
	for _, val := range ra.array1 {
		ra.umap[val] = 0
	}
	for _, val := range ra.array2 {
		if _, ok := ra.umap[val]; ok {
			ra.umap[val]++
		}
	}
}

func (ra *RandomArray) printResult() {
	for key, value := range ra.umap {
		fmt.Printf("%d : %d\n", key, value)
	}
}

func (ra *RandomArray) takeInput() {
	// rand.Seed(time.Now().UnixNano())

	ra.size1 = 5000000
	ra.size2 = 5000000

	for i := 0; i < ra.size1; i++ {
		ra.array1 = append(ra.array1, rand.Intn(100))
	}

	for j := 0; j < ra.size2; j++ {
		ra.array2 = append(ra.array2, rand.Intn(100))
	}
}

func main() {
	startTime := time.Now()

	randomObject := NewRandomArray()
	randomObject.takeInput()
	randomObject.findSolution()
	randomObject.printResult()

	elapsedTime := time.Since(startTime)
	fmt.Printf("The total time taken: %v\n", elapsedTime)
}
