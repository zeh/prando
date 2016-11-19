# Prando

Prando is a determistic *pseudo-random number generator* using xorshift32*. It can be used to create a series of random numbers that can later be re-created given the same seed.

Its goals are:

* Generate a random number sequence
* Reproducibility via a seed
* Fast generation

The counterpoint is that it is not trying to be cryptographically strong.

Prando is created in TypeScript for extra code strength, but can be used both in JavaScript and TypeScript. The advantage of using it in TypeScript projects is that you get the benefit of code completion ("intellisense") by default.

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

After being reset, every call to `next()` will generate the same numbers as if the instance had just been created.

## License

[MIT](LICENSE.md).