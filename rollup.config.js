import typescript from "rollup-plugin-typescript";
import pkg from "./package.json";

export default {
	input: "src/Prando.ts",
	output: [
		{ name: "prando", sourcemap: true, file: pkg.module, format: "es" },
		{
			name: "Prando",
			sourcemap: true,
			file: pkg.main,
			format: "umd",
			footer: "module.exports.default = module.exports; // Terrible injection just so it works regardless of how it's required\n"
		}
	],
	plugins: [
		typescript({
			typescript: require("typescript")
		})
	]
};
