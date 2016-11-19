var webpack = require('webpack')
var path = require('path')

var APP_PATH = path.resolve(__dirname, 'src/Prando.ts')
var BUILD_PATH = path.resolve(__dirname, 'dist')

module.exports = {
	entry: APP_PATH,
	output: {
		path: BUILD_PATH,
		library: 'Prando',
		libraryTarget: 'umd',
		filename: 'Prando.js',
		umdNamedDefine: true
	},

	devtool: 'source-map',

	resolve: {
		root: path.resolve('./src'),
		extensions: [ '', '.js', '.ts', '.jsx', '.tsx' ]
	},

	module: {
		preLoaders: [
			{ test: /\.tsx?$/, loader: "tslint" }
		],
		loaders: [
			{ test: /\.tsx?$/, loader: 'babel!ts-loader' } // , exclude: /node_modules/
		]
	},

	tslint: {
		emitErrors: true,
		failOnHint: true
	},

	plugins: [
		new webpack.optimize.UglifyJsPlugin({
			compress: {
				warnings: false,
				sequences: true,
				dead_code: true,
				conditionals: true,
				booleans: true,
				unused: true,
				if_return: true,
				join_vars: true,
				drop_console: true
			},
			comments: false,
			sourceMap: false,
		}),
	]
}
