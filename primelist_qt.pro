TEMPLATE = subdirs

SUBDIRS += primelist_lib primelist primelist_gui
primelist.depends = primelist_lib
primelist_gui.depends = primelist_lib
