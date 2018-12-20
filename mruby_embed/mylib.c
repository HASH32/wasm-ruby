#include "mruby.h"
#include "mruby/irep.h"

int
main(void)
{
  mrb_int i = 4;
  mrb_state *mrb = mrb_open();
  if (!mrb) { /* handle error */ }
  FILE *fp = fopen("mylib.rb","r");

  // Load the data from the .rb file into the Ruby environment
  mrb_value obj = mrb_load_file(mrb,fp);

  // close the file
  fclose(fp);

  // Get the class MyLib
  struct RClass *class = mrb_class_get(mrb, "MyLib");

  // Create a new instance of MyLib, no arguments are needed (0, NULL)
  mrb_value c = mrb_obj_new(mrb, class, 0, NULL);

  // Call the ruby_sq method on the instance, passing arguments wrapped
  mrb_value res = mrb_funcall(mrb, c, "ruby_sq", 1, mrb_fixnum_value(i));

  // Convert the result (a fixed number wrapped in a mrb_value)
  printf("result: %i\n", mrb_fixnum(res));

  // If crashed, provide exception info
  if (mrb->exc)
    {
      mrb_print_error(mrb);
    }
    // Close the Ruby environment
  mrb_close(mrb);
}

