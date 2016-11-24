export default class Prando {

	private static MIN:number = -2147483648; // Int32 min
	private static MAX:number = 2147483647; // Int32 max

	private _seed:number;
	private _value:number;


	// ================================================================================================================
	// CONSTRUCTOR ----------------------------------------------------------------------------------------------------

	constructor();
	constructor(seed:number);
	constructor(seed:string);
	constructor(seed:number|string|undefined = undefined) {
		if (typeof(seed) === "string") {
			// String seed
			this._seed = this.hashCode(seed);
		} else if (typeof(seed) === "number") {
			// Numeric seed
			this._seed = seed;
		} else {
			// Pseudo-random seed
			this._seed = Date.now() + Math.random();
		}
		this.reset();
	}


	// ================================================================================================================
	// PUBLIC INTERFACE -----------------------------------------------------------------------------------------------

	public next(min:number = 0, pseudoMax:number = 1):number {
		this.recalculate();
		return this.map(this._value, Prando.MIN, Prando.MAX, min, pseudoMax);
	}

	public reset():void {
		this._value = this._seed;
	}


	// ================================================================================================================
	// PRIVATE INTERFACE ----------------------------------------------------------------------------------------------

	private recalculate():void {
		// Xorshift*32
		// Based on George Marsaglia's work: http://www.jstatsoft.org/v08/i14/paper
		this._value ^= this._value << 13;
		this._value ^= this._value >> 17;
		this._value ^= this._value << 5;
	}

	private map(val:number, minFrom:number, maxFrom:number, minTo:number, maxTo:number) {
		return ((val - minFrom) / (maxFrom - minFrom)) * (maxTo - minTo) + minTo;
	}

	private hashCode(str:string):number {
		let hash:number = 0;
		if (str) {
			let l:number = str.length;
			for (let i = 0; i < l; i++) {
				hash = ((hash << 5) - hash) + str.charCodeAt(i);
				hash |= 0;
			}
		}
		return hash;
	}
}

