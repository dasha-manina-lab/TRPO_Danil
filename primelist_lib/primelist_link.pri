CONFIG += debug_and_release build_all

CONFIG(debug, debug|release): library_config = debug
else: library_config = release

DESTDIR = $$library_config
UI_DIR = $$library_config

INCLUDEPATH += $$PWD
library_dir = $$clean_path($$OUT_PWD/../primelist_lib/$$library_config)

win32-msvc*: library_file = $$library_dir/primelist_lib.lib
else: library_file = $$library_dir/libprimelist_lib.a

LIBS += $$quote($$library_file)
PRE_TARGETDEPS += $$quote($$library_file)
