FROM trzeci/emscripten-slim:latest

RUN apt-get update && apt-get install -y curl gcc cmake bison ruby

RUN mkdir /build \
  && cd /build \
  && curl -fSL -o mruby.tar.gz "https://github.com/mruby/mruby/archive/1.4.1.tar.gz" \
  && tar -xvzf mruby.tar.gz \
  && mv mruby-1.4.1 mruby

COPY mruby_build_config.rb /build/mruby/build_config.rb

RUN cd /build/mruby \
  && make

ENV PATH="/build/mruby/bin:${PATH}"

RUN mkdir -p /build/utils/assets
COPY mruby_init.c /build/utils/assets/mruby_init.c
COPY ruby_wasm.rb /usr/local/bin/ruby_wasm
RUN chmod a+x /usr/local/bin/ruby_wasm
