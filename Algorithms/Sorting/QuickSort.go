package main
import (
	"fmt"	
)

func main(){
	arr:= []int{10,7,8,9,1,5} 
	n:= len(arr)
	quickSort(arr,0,n-1)
	fmt.Print("Sorted array: ")
	printArray(arr,n)
} 

func swap(a,b *int){
	t:= *a
	*a = *b
	*b = t
}

func partition(arr []int,low,high int) int{
	pivot:= arr[high]
	i:= (low - 1)
	j:= low

	for j <= high-1 {
		if arr[j] <= pivot {
			i++
			swap(&arr[i], &arr[j])
		}
		j++
	}
	swap(&arr[i+1], &arr[high])

	return (i+1)
}

func quickSort(arr []int,low,high int){
	if low < high {
		pi:= partition(arr,low,high)

		quickSort(arr,low,pi-1)
		quickSort(arr,pi+1,high)
	}
}

func printArray(arr []int,size int){
	i:=0

	for i < size {
		fmt.Print(arr[i]," ")
		i++
	}
}
