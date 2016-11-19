# Prando

Prando is a determistic pseudo-number generator using xorshift32*. It can be used to create a series of random numbers that can later be re-created given the same seed.

Its goals are:

* Generate a random number sequence
* Reproducibility via a seed
* Fast generation

The counterpoint is that it is not trying to be cryptographically strong.

Prando is created in TypeScript for extra code strength, but can be used both in JavaScript and TypeScript.

## Install

```
$ npm install prando
```

## Usage

Import:

```
// Include (JavaScript ES5)
var Prando = require('prando').default;

// Include (JavaScript ES6)
import Prando from 'prando';

// Include (TypeScript)
import Prando from 'prando';
```

Create an instance:

```
// Pseudo-random (time-based) seed
let rng = new Prando();

// Specific number seed
let rng = new Prando(123);

// Specific string (checksum-based) seed
let rng = new Prando("some-id");
```

Get a number:

```
// Between 0 (inclusive) and 1 (exclusive)
let num = rng.next();

// Between a min (inclusive) and a max (exclusive)
let num = rng.next(2, 10);
```

You can generate as many pseudo-random values as you want.

You can also reset the generator:

```
rng.reset();
```

## License

[MIT](LICENSE.md).