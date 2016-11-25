import { expect } from "chai";
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
	it("is a class", function() {
		expect(Prando).to.not.a.function;
	});

	it("can be instantiated", () => {
		expect(new Prando()).to.be.defined;
		expect(new Prando()).to.be.an.instanceof(Prando);
	});

	it("should create with a random seed", () => {
		let rng = new Prando();
		let num1 = rng.next();
		let num2 = rng.next();

		expect(num1).to.to.be.a('number');
		expect(num2).to.to.be.a('number');
		expect(num2).to.not.be.equal(num1);

		rng.reset();
		expect(rng.next()).to.be.equal(num1);
		expect(rng.next()).to.be.equal(num2);
	});

	it("should create with a number seed", () => {
		let rng = new Prando(12345678);
		let num1 = rng.next();
		let num2 = rng.next();

		expect(num1).to.to.be.a('number');
		expect(num2).to.to.be.a('number');
		expect(num2).to.not.be.equal(num1);

		// Pre-generated values
		expect(num1).to.to.be.equal(0.6177754114889017);
		expect(num2).to.to.be.equal(0.5784605181725837);

		rng.reset();
		expect(rng.next()).to.be.equal(num1);
		expect(rng.next()).to.be.equal(num2);

		let rng2 = new Prando(97342);
		expect(rng2.next()).to.not.be.equal(num1);
		expect(rng2.next()).to.not.be.equal(num2);
	});

	it("should create with a string seed", () => {
		let rng = new Prando("some id");
		let num1 = rng.next();
		let num2 = rng.next();

		expect(num1).to.to.be.a('number');
		expect(num2).to.to.be.a('number');
		expect(num2).to.not.be.equal(num1);

		// Pre-generated values
		expect(num1).to.to.be.equal(0.5937333613619519);
		expect(num2).to.to.be.equal(0.08739619215191254);

		rng.reset();
		expect(rng.next()).to.be.equal(num1);
		expect(rng.next()).to.be.equal(num2);

		let rng2 = new Prando("other id");
		expect(rng2.next()).to.not.be.equal(num1);
		expect(rng2.next()).to.not.be.equal(num2);
	});

	it("should skip ahead", () => {
		let seed = Math.random() * 10000;

		let rng = new Prando(seed);
		let num1 = rng.next();
		for (let i = 0; i < 10; i++) {
			rng.next();
		}
		let num2 = rng.next();

		let rng2 = new Prando(seed);
		expect(rng2.next()).to.be.equal(num1);
		for (let i = 0; i < 10; i++) {
			rng2.skip();
		}
		expect(rng2.next()).to.be.equal(num2);
		rng2.reset();
		rng2.skip(11);
		expect(rng2.next()).to.be.equal(num2);
	});

	it("should generate integers", () => {
		let rng = new Prando(1337);

		let num1 = rng.nextInt(5, 15);
		let num2 = rng.nextInt(5, 15);

		expect(num1).to.to.be.a('number');
		expect(num2).to.to.be.a('number');
		expect(num2).to.not.be.equal(num1);

		// Pre-generated values
		expect(num1).to.to.be.equal(11);
		expect(num2).to.to.be.equal(8);

		rng.reset();
		expect(rng.nextInt(5, 15)).to.be.equal(num1);
		expect(rng.nextInt(5, 15)).to.be.equal(num2);

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

		expect(anyFloat).to.be.equal(false);
		expect(anyLower).to.be.equal(false);
		expect(anyHigher).to.be.equal(false);
	});

	it("should generate booleans", () => {
		let rng = new Prando(31339);

		expect(rng.nextBoolean()).to.be.equal(false);
		expect(rng.nextBoolean()).to.be.equal(true);
		expect(rng.nextBoolean()).to.be.equal(true);
		rng.reset();
		expect(rng.nextBoolean()).to.be.equal(false);
		expect(rng.nextBoolean()).to.be.equal(true);
		expect(rng.nextBoolean()).to.be.equal(true);
	});

	it("should generate chars", () => {
		let rng = new Prando(31338);

		expect(rng.nextChar()).to.be.equal("8");
		expect(rng.nextChar()).to.be.equal("a");
		rng.reset();
		expect(rng.nextChar()).to.be.equal("8");
		expect(rng.nextChar()).to.be.equal("a");

		rng.reset();
		expect(rng.nextChar("a")).to.be.equal("a");
		expect(rng.nextChar("_")).to.be.equal("_");
		expect(rng.nextChar("123")).to.be.equal("2");
		expect(rng.nextChar("123")).to.be.equal("1");
	});

	it("should generate strings", () => {
		let rng = new Prando(31337);

		expect(rng.nextString()).to.be.equal("72Od8C3vAmYEwmhi");
		expect(rng.nextString()).to.be.equal("idImokfKzm6YNVs2");
		rng.reset();
		expect(rng.nextString()).to.be.equal("72Od8C3vAmYEwmhi");
		expect(rng.nextString()).to.be.equal("idImokfKzm6YNVs2");

		rng.reset();
		expect(rng.nextString(1, "a")).to.be.equal("a");
		expect(rng.nextString(2, "b")).to.be.equal("bb");
		expect(rng.nextString(6, "123")).to.be.equal("231331");
	});

	it("should get from an array", () => {
		let rng = new Prando(31339);
		const lst1 = ["1", "2", "3", "4", "5"];
		const lst2 = ["a", "b", "c", "d", "e"];

		expect(rng.nextArrayItem(lst1)).to.be.equal("5");
		expect(rng.nextArrayItem(lst1)).to.be.equal("4");
		rng.reset();
		expect(rng.nextArrayItem(lst2)).to.be.equal("e");
		expect(rng.nextArrayItem(lst2)).to.be.equal("d");

		expect(rng.nextArrayItem(lst2)).to.be.equal("a");
		expect(rng.nextArrayItem(lst2)).to.be.equal("e");
		expect(rng.nextArrayItem(lst2)).to.be.equal("e");
		expect(rng.nextArrayItem(lst2)).to.be.equal("a");
		expect(rng.nextArrayItem(lst2)).to.be.equal("a");
	});

	it("should randomize more or less evenly", function() {
		this.timeout(10 * 1000);
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
			expect(delta).to.be.within(-0.04, 0.04);
		}
	});

	it("should allow a minimum 2^29-1 sequence", function() {
		this.timeout(2 * 60 * 60 * 1000);
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

		expect(repeatPos).to.be.above(Math.pow(2, 29) - 2);
	});
});