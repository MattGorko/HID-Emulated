project('hid-emulated',
        'cpp',
        version: '0.0.1',
        meson_version: '>= 0.50.0',
        license: 'GPL2',
        default_options:
        ['warning_level=3',
        'werror=true'])


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
    '-Wredundant-decls',
    '-Wnested-externs',
    '-Wundef',
    '-Wunreachable-code',
    '-Wunused-parameter',
    '-Wwrite-strings',
  ]),
  '-D_GNU_SOURCE',
  language: 'cpp'
)

################
# Dependencies #
################

gtk = dependency('gtk+-3.0', version: '>= 3.24.00')

executable('hid-emulated', 'src/main.cc')
