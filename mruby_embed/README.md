## How-To

The C files are linked against `build/host/lib/libmruby.a`, which gets build when you run `make` in mruby.

### Get mrbc byecode

```
mrbc func.rb
```

### Get mrbc bytecode as C hexdump

```
mrbc -Bgreet func.rb
```

### Run wrapper C code

```
gcc  -I mruby/include func_wrap.c  mruby/build/host/lib/libmruby.a -lm -o func
```

Note: `-lm` is required, refer - https://stackoverflow.com/questions/1033898/why-do-you-have-to-link-the-math-library-in-c

## References

- [Read doc at mruby.h](https://github.com/mruby/mruby/blob/master/include/mruby.h)
- [https://github.com/mruby/mruby/wiki/Hello-World](https://github.com/mruby/mruby/wiki/Hello-World)
- [Module with Class example](https://github.com/mruby/mruby/wiki/Building-your-Ruby-environment-and-accessing-it)
- [Introducing mruby](https://matt.aimonetti.net/posts/2012/04/25/getting-started-with-mruby/)
- [Statically compile ruby libs](https://github.com/mruby/mruby/issues/3707#issuecomment-309195329)

