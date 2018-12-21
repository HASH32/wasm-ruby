#include <stdio.h>
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/irep.h>
#include "mylib.c"

int main()
{
  mrb_int i = 12;
  mrb_state *mrb = mrb_open();
  if (!mrb) { }

  mrb_value obj = mrb_load_irep(mrb, fmathl);
  mrb_value res = mrb_funcall(mrb, obj, "nsquare", 1, mrb_fixnum_value(i));

  mrb_close(mrb);

  printf("result: %d\n", res.value.i);
  return 0;
 }
