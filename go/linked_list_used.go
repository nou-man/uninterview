package main

import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	// Open and read array1.txt
	file1, err := os.Open("array1.txt")
	if err != nil {
		fmt.Println("Error opening array1.txt:", err)
		return
	}
	defer file1.Close()

	var array1 []int
	scanner := bufio.NewScanner(file1)
	for scanner.Scan() {
		var num int
		_, err := fmt.Sscanf(scanner.Text(), "%d", &num)
		if err != nil {
			fmt.Println("Error parsing array1.txt:", err)
			return
		}
		array1 = append(array1, num)
	}

	// Open and read array2.txt
	file2, err := os.Open("array2.txt")
	if err != nil {
		fmt.Println("Error opening array2.txt:", err)
		return
	}
	defer file2.Close()

	var array2 []int
	scanner = bufio.NewScanner(file2)
	for scanner.Scan() {
		var num int
		_, err := fmt.Sscanf(scanner.Text(), "%d", &num)
		if err != nil {
			fmt.Println("Error parsing array2.txt:", err)
			return
		}
		array2 = append(array2, num)
	}

	// Create a map to store counts
	counts := make(map[int]int)

	// Count occurrences of array2 elements in array1
	for _, num := range array1 {
		counts[num] = 0
	}
	for _, num := range array2 {
		if _, ok := counts[num]; ok {
			counts[num]++
		}
	}

	// Print the result
	for key, value := range counts {
		fmt.Printf("%d : %d\n", key, value)
	}
}
