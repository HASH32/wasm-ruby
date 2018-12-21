#include <stdio.h>
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/irep.h>
#include <emscripten.h>
#include "mylib.c"


mrb_value load_module(mrb_state* ms) {
  if (!ms) { printf("ERROR: invalid state"); }
  mrb_value obj = mrb_load_irep(ms, fmathl);
  return obj;
}


EMSCRIPTEN_KEEPALIVE
int nsquare(int n) {
  mrb_state *mrb = mrb_open();
  mrb_int arg_n = (mrb_int)n;

  mrb_value module = load_module(mrb);
  mrb_value res = mrb_funcall(mrb, module, "nsquare", 1, mrb_fixnum_value(arg_n));
  mrb_close(mrb);
  return (int)res.value.i;
}

EMSCRIPTEN_KEEPALIVE
int ncube(int n) {
  mrb_state *mrb = mrb_open();
  mrb_int arg_n = (mrb_int)n;

  mrb_value module = load_module(mrb);
  mrb_value res = mrb_funcall(mrb, module, "ncube", 1, mrb_fixnum_value(arg_n));
  mrb_close(mrb);
  return (int)res.value.i;
}

EMSCRIPTEN_KEEPALIVE
long long nfactorial(int n) {
  mrb_state *mrb = mrb_open();
  mrb_int arg_n = (mrb_int)n;

  mrb_value module = load_module(mrb);
  mrb_value res = mrb_funcall(mrb, module, "nfactorial", 1, mrb_fixnum_value(arg_n));
  mrb_close(mrb);
  return res.value.i;
}


int main()
{
  printf("Executing main() \n");

  int x = 32;
  int y = 21;

  int sq = nsquare(x);
  int cb = ncube(y);

  printf("Result: %d, %d\n", sq, cb);
  return 0;
}
