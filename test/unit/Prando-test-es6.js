import { expect } from "chai";
import Prando from "./../../dist/Prando";

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
});