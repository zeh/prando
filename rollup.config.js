import typescript from "rollup-plugin-typescript";
import pkg from "./package.json";

export default {
	input: "src/Prando.ts",
	output: [
		{ file: pkg.module, format: "es" },
		{ file: pkg.main, format: "umd" }
	],
	name: "Prando",
	sourcemap: true,
	plugins: [
		typescript({
			typescript: require("typescript")
		})
	]
};
