################
#    Project   #
################

project('hid-emulated',
        'cpp',
        version: '0.0.1',
        meson_version: '>= 0.50.0',
        license: 'GPL2',
        default_options:
        ['warning_level=3',
        'werror=true',
        'cpp_std=c++17'])

################
#     Files    #
################

uiloc = join_paths(get_option('prefix'),
          get_option('datadir'),
          'ui')

################
#   Compiler   #
################

compiler = meson.get_compiler('cpp')

add_project_arguments(
  compiler.get_supported_arguments([
    '-pedantic',
    '-W',
    '-Wcast-align',
    '-Wduplicated-branches',
    '-Wduplicated-cond',
    '-Wfloat-equal',
    '-Winit-self',
    '-Winline',
    '-Wlogical-op',
    '-Wmissing-declarations',
    '-Wmissing-format-attribute',
    '-Wnested-externs',
    '-Wpointer-arith',
    '-Wnested-externs',
    '-Wunreachable-code',
    '-Wunused-parameter',
    '-Wwrite-strings',
  ]),
  '-D_GNU_SOURCE',
  '-DUI_DIR="@0@"'.format(uiloc),
  language: 'cpp'
)

################
# Dependencies #
################

gtkmm = dependency('gtkmm-3.0', version: '>= 3.20.00', required: true)

################
#  Executable  #
################

executable('hid-emulated', 'gtk/app.cc',
  dependencies: gtkmm,
  install: true,
)

################
#    Install   #
################

install_subdir('gtk/ui', install_dir : get_option('datadir'))

################
#     Tests    #
################

# TODO

################
#     Doc      #
################

# TODO

################
#   Coverage   #
################

# TODO

################
#  Sanitizers  #
################

# TODO

################
#  Scan-build  #
################

# TODO