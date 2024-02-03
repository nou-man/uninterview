package main

import (
    "fmt"
    "os"
    "bufio"
    "time"
)

type ObjectOriented struct {
    array1 []int
    array2 []int
    umap   map[int]int
}

func NewObjectOriented() *ObjectOriented {
    return &ObjectOriented{
        umap: make(map[int]int),
    }
}

func (o *ObjectOriented) findSolution() {
    for _, val := range o.array1 {
        o.umap[val] = 0
    }
    for _, val := range o.array2 {
        if _, ok := o.umap[val]; ok {
            o.umap[val]++
        }
    }
}

func (o *ObjectOriented) printResult() {
    for key, value := range o.umap {
        fmt.Printf("%d : %d\n", key, value)
    }
}

func (o *ObjectOriented) takeInput() {
    file1, err := os.Open("array1.txt")
    if err != nil {
        fmt.Println("Error opening array1.txt:", err)
        os.Exit(1)
    }
    defer file1.Close()

    scanner1 := bufio.NewScanner(file1)
    for scanner1.Scan() {
        val := 0
        fmt.Sscanf(scanner1.Text(), "%d", &val)
        o.array1 = append(o.array1, val)
    }

    file2, err := os.Open("array2.txt")
    if err != nil {
        fmt.Println("Error opening array2.txt:", err)
        os.Exit(1)
    }
    defer file2.Close()

    scanner2 := bufio.NewScanner(file2)
    for scanner2.Scan() {
        val := 0
        fmt.Sscanf(scanner2.Text(), "%d", &val)
        o.array2 = append(o.array2, val)
    }
}

func main() {
    start := time.Now()

    object := NewObjectOriented()
    object.takeInput()
    object.findSolution()
    object.printResult()

    elapsed := time.Since(start)
    fmt.Printf("The total time taken: %v\n", elapsed)
}
// array1.txt array2.txt