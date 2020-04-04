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

gtkmm = dependency('gtkmm-3.0',
  version: '>= 3.20.00', required: true)

################
#  Executable  #
################

executable('hid-emulated',
  'gtk/app.cc',
  'gtk/mainwindow.cc',
  'gtk/maintoolbar.cc',
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

criterion = dependency('criterion',
  version: '>= 2.3.0', required : false)

if not criterion.found()
  error('Skip test: criterion not installed.')
else
  subdir('tests')
endif


################
#     Doc      #
################

doxygen = find_program('doxygen', required : false)
if not doxygen.found()
  error('Skip doc: doxygen not found.')
else
  doc_config = configuration_data()
  doc_config.set('VERSION', meson.project_version())

  dot = find_program('dot', required : false)

  if dot.found()
    doc_config.set('HAVE_DOT', 'YES')
  else
    doc_config.set('HAVE_DOT', 'NO')
    error('Skip dot in doc: dot not found.')
  endif

  doc_config.set('TOP_SRCDIR', meson.source_root())
  doc_config.set('TOP_BUILDDIR', meson.build_root())

  doxyfile = configure_file(input: 'Doxyfile.in',
                            output: 'Doxyfile',
                            configuration: doc_config,
                            install: false)

  doc_dir = join_paths(get_option('datadir'), 'doc')

  html_target = custom_target('doc',
                              input: doxyfile,
                              output: 'doc',
                              command: [doxygen, doxyfile],
                              install: true,
                              install_dir: get_option('datadir'))
endif

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
