var Prando = require("./../../dist/Prando.umd");

describe("Prando (ES5)", function() {
	test("is a class", function() {
		expect(Prando).not.toBe("function");
	});

	test("can be instantiated", function() {
		expect(new Prando()).toBeDefined();
		expect(new Prando()).toBeInstanceOf(Prando);
	});
});
