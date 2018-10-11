for (let i = 0; i < 1025; i++) {
  if ((i > 0) && (i & (i - 1)) == 0) {
		console.log(i, "is power of two")
	}
}