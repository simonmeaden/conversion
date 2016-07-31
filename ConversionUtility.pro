TEMPLATE = subdirs

SUBDIRS += \
    conversion \
    plugin \
    examples

plugin.subdir = plugin

conversion.subdir = conversion
conversion.depends += plugin

examples.subdir = examples
examples.depends += conversion
