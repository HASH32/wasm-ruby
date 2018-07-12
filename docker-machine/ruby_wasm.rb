#!/usr/bin/env ruby
require 'fileutils'
# Compilation optimizations flag
@optimize = false

# Extending `String` to include some fancy colors
class String
  def colorize(c); "\e[#{c}m#{self}\e[0m" end
  def bold;  colorize('1')    end
  def success; colorize('1;32') end
  def error; colorize('1;31') end
end

# Build a Ruby file
def build(rb_file)
# Clean up the build directory
  FileUtils.rm_rf 'tmp'

  # Check if source file provided is good
  if !rb_file
    puts 'Please provide a Ruby file to build'
    exit
  elsif !File.exists? "/src/#{rb_file}"
    puts "Can't find file: #{rb_file}"
    exit
  end

  # Create the build directory
  FileUtils.mkdir_p 'tmp'

  # Create MRuby bytecode from Ruby source file
  `mrbc -Bruby_app -otmp/app.c /src/#{rb_file}`

  `cat tmp/app.c`
  # Add MRuby init code to app bytecode
  open('tmp/app.c', 'a') do |f|
    f << "\n\n" << File.read("/build/utils/assets/mruby_init.c")
  end

  # Compile using Emscripten
  `emcc -s WASM=1 #{ if @optimize then '-Os' end } -I '/build/mruby/include' tmp/app.c  /build/mruby/build/emscripten/lib/libmruby.a -o app.js #{ if @optimize then '--closure 1' end }`

  # Clean up
  FileUtils.rm_rf 'tmp'
end

# Check for problems
def doctor
  errors = false

  puts "\nChecking for Emscripten tools"

  # Check for `emcc`
  print '  emcc...'
  if `which emcc`.empty?
    puts 'not found'.error
    errors = true
  else
    puts 'found'.success
  end

  # Check for `emar`
  print '  emar...'
  if `which emar`.empty?
    puts 'not found'.error
    errors = true
  else
    puts 'found'.success
  end

  if errors
    puts "\nErrors were found!\n\n"
    puts "Did you run \`./emsdk_env.sh\` ?", "For help, check out the \"Getting Started\" guide on webassembly.org\n\n"
  else
    puts "\n👍 Everything looks good!\n\n"
  end

end

# Check Command-line Arguments #################################################

usage = 'Ruby on WebAssembly'.bold + "\n
Usage: ruby-wasm <command> <options>
                 [-v|--version]
Summary of commands and options:
  build <file.rb>    Build a Ruby source file
    --optimize         Compile with all optimizations
  doctor             Check for problems with your WebAssembly toolchain
  -v|--version       Prints the installed version\n\n"

case ARGV[0]
when 'build'
  if ARGV.delete '--optimize' then @optimize = true end
  build ARGV[1]
when 'doctor'
  doctor
when '-v', '--version'
  puts WASM::VERSION
else
  puts usage
end
