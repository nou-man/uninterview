package main

import (
    "fmt"
)

func main() {
    array1 := []int{1, 2, 3, 1, 5}
    array2 := []int{1, 1, 1, 2, 2}
    umap := make(map[int]int)

    size1 := len(array1)
    size2 := len(array2)

    for i := 0; i < size1; i++ {
        umap[array1[i]] = 0
    }

    for i := 0; i < size2; i++ {
        if _, ok := umap[array2[i]]; ok {
            umap[array2[i]]++
        }
    }

    for key, value := range umap {
        fmt.Printf("%d : %d\n", key, value)
    }
}
