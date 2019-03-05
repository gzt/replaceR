# replaceR
Drop-in replacement for the standalone R math library if all you need is `runif()`.

This allows you to use `set_seed()` and `runif(a, b)` in `C` just as if you were using the `Rmath.h` standalone library.
While it uses the same random number generator, I cannot guarantee that the seeds will produce the same results as `R`.
However, results are reproducible. There are further functions available in the Mersenne Twister code if you want.
Read their code or their `readme-mt.txt` for more details. Or check out their
[web-page](http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html). I have, essentially, only provided
a small wrapper around their code to make it mimic the behavior the `R` library.

If you want something more than that, don't use this! Either roll your own or, better, use the `R` standalone math library.

The `mt19937ar.*` files are copyright their original owners subject to their
terms. See those files for details.

To compile and run an example, try:

    gcc mt19937ar.c replaceR.c testreplaceR.c -o testreplaceR
    ./testreplaceR

The results here should agree with the results in `ReplaceResults.txt`.
