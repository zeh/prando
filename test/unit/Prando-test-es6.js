import Prando from "./../../dist/Prando";

function tests() {
	const rng = new Prando(237622);
	const num = rng.next();

	let min = 0;
	let max = 0;
	let repeatPos = -1;
	for (let i = 1; i < 5000000000; i++) {
		const seed = rng._value;
		if (seed < min) min = seed;
		if (seed > max) max = seed;
		const n = rng.next();
		if (n === num) {
			repeatPos = i;
			break;
		}
	}

	console.log("Position repeats:", repeatPos);
	console.log("min max:", min, max);
}

describe("Prando (ES6)", () => {
	test("is a class", () => {
		expect(Prando).not.toBe("function");
	});

	test("can be instantiated", () => {
		expect(new Prando()).toBeDefined();
		expect(new Prando()).toBeInstanceOf(Prando);
	});

	test("should create with a random seed", () => {
		let rng = new Prando();
		let num1 = rng.next();
		let num2 = rng.next();

		expect(typeof num1).toEqual('number');
		expect(typeof num2).toEqual('number');
		expect(num2).not.toEqual(num1);

		rng.reset();
		expect(rng.next()).toEqual(num1);
		expect(rng.next()).toEqual(num2);
	});

	test("should create with a number seed", () => {
		let rng = new Prando(12345678);
		let num1 = rng.next();
		let num2 = rng.next();

		expect(typeof num1).toEqual('number');
		expect(typeof num2).toEqual('number');
		expect(num2).not.toEqual(num1);

		// Pre-generated values
		expect(num1).toEqual(0.6177754114889017);
		expect(num2).toEqual(0.5784605181725837);

		rng.reset();
		expect(rng.next()).toEqual(num1);
		expect(rng.next()).toEqual(num2);

		let rng2 = new Prando(97342);
		expect(rng2.next()).not.toEqual(num1);
		expect(rng2.next()).not.toEqual(num2);
	});

	test("should create with a string seed", () => {
		let rng = new Prando("some id");
		let num1 = rng.next();
		let num2 = rng.next();

		expect(typeof num1).toEqual('number');
		expect(typeof num2).toEqual('number');
		expect(num2).not.toEqual(num1);

		// Pre-generated values
		expect(num1).toEqual(0.5937333613619519);
		expect(num2).toEqual(0.08739619215191254);

		rng.reset();
		expect(rng.next()).toEqual(num1);
		expect(rng.next()).toEqual(num2);

		let rng2 = new Prando("other id");
		expect(rng2.next()).not.toEqual(num1);
		expect(rng2.next()).not.toEqual(num2);
	});

	test("should skip ahead", () => {
		let seed = Math.random() * 10000;

		let rng = new Prando(seed);
		let num1 = rng.next();
		for (let i = 0; i < 10; i++) {
			rng.next();
		}
		let num2 = rng.next();

		let rng2 = new Prando(seed);
		expect(rng2.next()).toEqual(num1);
		for (let i = 0; i < 10; i++) {
			rng2.skip();
		}
		expect(rng2.next()).toEqual(num2);
		rng2.reset();
		rng2.skip(11);
		expect(rng2.next()).toEqual(num2);
	});

	test("should generate integers", () => {
		let rng = new Prando(1337);

		let num1 = rng.nextInt(5, 15);
		let num2 = rng.nextInt(5, 15);

		expect(typeof num1).toEqual('number');
		expect(typeof num2).toEqual('number');
		expect(num2).not.toEqual(num1);

		// Pre-generated values
		expect(num1).toEqual(11);
		expect(num2).toEqual(8);

		rng.reset();
		expect(rng.nextInt(5, 15)).toEqual(num1);
		expect(rng.nextInt(5, 15)).toEqual(num2);

		// Within range
		let anyFloat = false;
		let anyLower = false;
		let anyHigher = false;

		for (let i = 0; i < 100; i++) {
			let f = rng.nextInt(2, 42);
			if (!Number.isInteger(f)) anyFloat = true;
			if (f < 2) anyLower = true;
			if (f > 42) anyHigher = true;
		}

		expect(anyFloat).toEqual(false);
		expect(anyLower).toEqual(false);
		expect(anyHigher).toEqual(false);
	});

	test("should generate booleans", () => {
		let rng = new Prando(31339);

		expect(rng.nextBoolean()).toEqual(false);
		expect(rng.nextBoolean()).toEqual(true);
		expect(rng.nextBoolean()).toEqual(true);
		rng.reset();
		expect(rng.nextBoolean()).toEqual(false);
		expect(rng.nextBoolean()).toEqual(true);
		expect(rng.nextBoolean()).toEqual(true);
	});

	test("should generate chars", () => {
		let rng = new Prando(31338);

		expect(rng.nextChar()).toEqual("8");
		expect(rng.nextChar()).toEqual("a");
		rng.reset();
		expect(rng.nextChar()).toEqual("8");
		expect(rng.nextChar()).toEqual("a");

		rng.reset();
		expect(rng.nextChar("a")).toEqual("a");
		expect(rng.nextChar("_")).toEqual("_");
		expect(rng.nextChar("123")).toEqual("2");
		expect(rng.nextChar("123")).toEqual("1");
	});

	test("should generate strings", () => {
		let rng = new Prando(31337);

		expect(rng.nextString()).toEqual("72Od8C3vAmYEwmhi");
		expect(rng.nextString()).toEqual("idImokfKzm6YNVs2");
		rng.reset();
		expect(rng.nextString()).toEqual("72Od8C3vAmYEwmhi");
		expect(rng.nextString()).toEqual("idImokfKzm6YNVs2");

		rng.reset();
		expect(rng.nextString(1, "a")).toEqual("a");
		expect(rng.nextString(2, "b")).toEqual("bb");
		expect(rng.nextString(6, "123")).toEqual("231331");
	});

	test("should get from an array", () => {
		let rng = new Prando(31339);
		const lst1 = ["1", "2", "3", "4", "5"];
		const lst2 = ["a", "b", "c", "d", "e"];

		expect(rng.nextArrayItem(lst1)).toEqual("5");
		expect(rng.nextArrayItem(lst1)).toEqual("4");
		rng.reset();
		expect(rng.nextArrayItem(lst2)).toEqual("e");
		expect(rng.nextArrayItem(lst2)).toEqual("d");

		expect(rng.nextArrayItem(lst2)).toEqual("a");
		expect(rng.nextArrayItem(lst2)).toEqual("e");
		expect(rng.nextArrayItem(lst2)).toEqual("e");
		expect(rng.nextArrayItem(lst2)).toEqual("a");
		expect(rng.nextArrayItem(lst2)).toEqual("a");
	});

	test("should randomize more or less evenly", () => {
		const totals = [];
		const tests = 6000;
		const ranges = 10;
		const rng = new Prando(924576);
		for (let i = 0; i < tests * ranges; i++) {
			const pos = rng.nextInt(0, ranges - 1);
			totals[pos] = (totals[pos] || 0) + 1;
		}

		for (let i = 0; i < totals.length; i++) {
			// Percentage off the expected amount
			const delta = (totals[i] - tests) / tests;
			expect(delta).toBeLessThan(0.04);
			expect(delta).toBeGreaterThan(-0.04);
		}
	}, 10 * 1000);

	test("should allow a minimum 2^29-1 sequence", () => {
		const rng = new Prando(237622);
		const num = rng.next();

		// Create a sequence
		let repeatPos = -1;
		let l = Math.pow(2, 30);
		for (let i = 1; i < l; i++) {
			if (rng.next() === num) {
				repeatPos = i;
				break;
			}
		}

		expect(repeatPos).toBeGreaterThan(Math.pow(2, 29) - 2);
	}, 2 * 60 * 60 * 1000);
});
