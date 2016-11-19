var expect = require('chai').expect;
var Prando = require("./../../dist/Prando.js").default;

describe("Prando (ES5)", function() {
	it("is a class", function() {
		expect(Prando).to.not.a.function;
	});

	it("can be instantiated", function() {
		expect(new Prando()).to.be.defined;
		expect(new Prando()).to.be.an.instanceof(Prando);
	});
});
