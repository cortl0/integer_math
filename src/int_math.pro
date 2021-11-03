#
#   integer_math
#   created by Ilya Shishkin
#   cortl@8iter.ru
#   https://github.com/cortl0/integer_math
#   licensed by GPL v3.0
#

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fraction.cpp \
        main.cpp \
        unit_tests.cpp

HEADERS += \
    fraction.h \
    unit_tests.h
