## How-To

**Steps for running a ruby module functions in the browser by compiling to WASM.**

The ruby functions are exposed from `mylib.rb`.

### STEP1: Get mrbc bytecode as C hexdump

```
mrbc -Bgreet func.rb
```

### STEP2: Add glue wrapper code like in mylib_wrap.c

The C files are linked against `build/host/lib/libmruby.a`, which gets build when you run `make` in mruby.
They are cross compiled to llvm bytecode with `emcc` using the docker image `awin/emcc-mruby` toolchain.

This generates `a.out.wasm` and `a.out.js` files.

```sh
# normal emcc options
emcc -O3 -s WASM=1  -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' -I '/build/mruby/include' mylib_wrap.c /build/mruby/build/emscripten/lib/libmruby.a

# with debug symbols
emcc -O0 -g4 -Werror  -s WASM=1  -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' -s ASSERTIONS=2  -I '/build/mruby/include' mylib_wrap.c /build/mruby/build/emscripten/lib/libmruby.a
```

### STEP3: Serve the Files

```
ruby server.rb
```

### STEP4: Execute from Developer tools console

And open http://localhost:8000 in the browser. In developer tools console, you should find the console statements.

The functions `nsquare(n)`, `ncube(n)` and `nfactorial(n)` are exposed in the global namespace, and can be invoked from the console.



