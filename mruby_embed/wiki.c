#include "mruby.h"
#include "mruby/irep.h"

int
main(void)
{
	mrb_state *mrb = mrb_open();
	if (!mrb) { /* handle error */ }
	FILE *fp = fopen("wiki.rb","r");

	// Load the data from the .rb file into the Ruby environment
	mrb_value obj = mrb_load_file(mrb,fp);

	// close the file
	fclose(fp);

	// First access the module
    struct RClass *module = mrb_module_get(mrb, "WikiExample");

    // Get the class that is defined in the WikiExample module
    struct RClass *class = mrb_class_get_under(mrb, module, "WikiManager");

    // Create a new instance of WikiManager, no arguments are needed (0, NULL)
    mrb_value c = mrb_obj_new(mrb, class, 0, NULL);

    // Call the get_version method on the instance.
	mrb_value res = mrb_funcall(mrb, c, "get_version", 0);

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

