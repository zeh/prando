var Prando = require("./../../dist/Prando.umd");

describe("Prando (ES5)", function() {
	test("is a class", function() {
		expect(Prando).not.toBe("function");
	});

	test("can be instantiated", function() {
		expect(new Prando()).toBeDefined();
		expect(new Prando()).toBeInstanceOf(Prando);
	});

	test("should recover from a bad seed", function() {
		const p1 = new Prando("");
		expect(p1.next()).not.toEqual(p1.next());
		const p2 = new Prando(0);
		expect(p2.next()).not.toEqual(p2.next());
	});
});
