#include <stdio.h>
#include <mruby.h>
#include "mruby/compile.h"

int
main()
{
  mrb_value na;
  mrb_state *mrb = mrb_open();
  na = mrb_str_new_lit(mrb, "Awin");;
  if (!mrb) { }
  FILE *fp = fopen("test.rb","r");
  mrb_value obj = mrb_load_file(mrb,fp);
  mrb_value res = mrb_funcall(mrb, obj, "hello", 1, na);
  // printf("result: %s\n", res);
  mrb_p(mrb, res);

  fclose(fp);
  mrb_close(mrb);
 }
