def quicksort(list):
	if len(list)<2:
		return list
	part1 = []
	part2 = []
	pivot = list[-1]
	for element in list[:-1]:
		if element<pivot:
			part1.append(element)
		else:
			part2.append(element)
	return quicksort(part1)+[pivot]+quicksort(part2)
