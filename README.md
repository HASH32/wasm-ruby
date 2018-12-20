## Overview
Build Ruby files to WebAssembly with mruby.
This repo contains the compile toolchain for ruby to wasm, with docker.

## Usage

### Setup Docker

```
cd docker-machine
docker build -t awin/emcc-mruby .
```

### Build WebAssembly

```
cd intro
docker run \
  --rm \
  -v $(pwd):/src \
  -u emscripten \
  awin/emcc-mruby \
  ruby_wasm build hello.rb
```

This should generate `app.js` and `app.wasm` in the intro directory.

### Serve the Files

```
cd intro
ruby server.rb
```

And open http://localhost:8000 in the browser. In developer tools console, you should find the console statement


## Credits

- Tom Black for the [Ruby on WebAssembly](http://www.blacktm.com/blog/ruby-on-webassembly) article, and the [wasm gem](https://github.com/blacktm/ruby-wasm).
- Piotr Paczkowski for the base docker image ([github repo](https://github.com/asRIA/emscripten-docker))
