int main() {
  var worstCase = [10, 6, 4, 2, 1];
  var bestCase = [1, 2, 4, 6, 10];

  print(insertionSort(worstCase));
  print(insertionSort(bestCase));
}

List insertionSort(List<int> list) {
  int temp;

  for (int j = 0; j < list.length; j++) {
    for (int i = 0; i < list.length; i++) {
      if (i < list.length - 1 && list[i] > list[i + 1]) {
        temp = list[i + 1];
        list[i + 1] = list[i];
        list[i] = temp;
      }
    }
  }

  return list;
}