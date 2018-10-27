import typescript from "rollup-plugin-typescript";
import pkg from "./package.json";

export default {
	input: "src/Prando.ts",
	output: [
		{ name: "Prando", sourcemap: true, file: pkg.module, format: "es" },
		{ name: "Prando", sourcemap: true, file: pkg.main, format: "umd" },
	],
	plugins: [
		typescript({
			typescript: require("typescript")
		})
	]
};
