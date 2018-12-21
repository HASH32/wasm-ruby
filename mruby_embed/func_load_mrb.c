#include <stdio.h>
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/dump.h>

int
main()
{
  mrb_value na;
  mrb_state *mrb = mrb_open();

  na = mrb_str_new_lit(mrb, "John");;
  if (!mrb) { }

  FILE *fp = fopen("func.mrb","r");
  mrb_value obj = mrb_load_irep_file(mrb,fp);

  mrb_value res = mrb_funcall(mrb, obj, "hello", 1, na);
  mrb_value res2 = mrb_funcall(mrb, obj, "bye", 1, na);

  mrb_p(mrb, res);
  mrb_p(mrb, res2);


  mrb_close(mrb);
 }
