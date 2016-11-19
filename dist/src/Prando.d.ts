export default class Prando {
    private static MIN;
    private static MAX;
    private _seed;
    private _value;
    constructor();
    constructor(seed: number);
    constructor(seed: string);
    next(min?: number, pseudoMax?: number): number;
    reset(): void;
    private recalculate();
    private map(val, minFrom, maxFrom, minTo, maxTo);
    private hashCode(str);
}
