# replaceR
Drop-in replacement for the standalone R math library if all you need is `runif()`.

This allows you to use `set_seed()` and `runif(a, b)` in `C` just as if you were using the `Rmath.h` standalone library.
While it uses the same random number generator, I cannot guarantee that the seeds will produce the same results as `R`.
However, results are reproducible. There are further functions available in the Mersenne Twister code if you want.

If you want something more than that, don't use this! Either roll your own or, better, use the `R` standalone math library.
