win32 {
  #Add the line below when cross-compiling
  CONFIG += static
}

QT       += core gui
TEMPLATE = app

#
#
# Common
#
#

INCLUDEPATH += \
    ../../Classes/CppAbout \
    ../../Classes/CppKalmanFilter \
    ../../Classes/CppMatrix \
    ../../Classes/CppQtAboutDialog \
    ../../Classes/CppQtHideAndShowDialog \
    ../../Classes/CppQtMatrix \
    ../../Classes/CppQtModel \
    ../../Classes/CppTrace

SOURCES += \
    ../../Classes/CppAbout/about.cpp \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilter.cpp \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfiltercalculationelements.cpp \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilterfactory.cpp \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilterparameters.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilter.cpp \
    ../../Classes/CppKalmanFilter/kalmanfiltercalculationelements.cpp \
    ../../Classes/CppKalmanFilter/kalmanfiltercalculationelementsfactory.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterexample.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterexperiment.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterexperimentparameter.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterexperimentparametertype.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterfactory.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterparameter.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterparameters.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterparametertype.cpp \
    ../../Classes/CppKalmanFilter/kalmanfiltertype.cpp \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystem.cpp \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystemfactory.cpp \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystemparameters.cpp \
    ../../Classes/CppKalmanFilter/standardkalmanfilter.cpp \
    ../../Classes/CppKalmanFilter/standardkalmanfiltercalculationelements.cpp \
    ../../Classes/CppKalmanFilter/standardkalmanfilterfactory.cpp \
    ../../Classes/CppKalmanFilter/standardkalmanfilterparameters.cpp \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystem.cpp \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystemfactory.cpp \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystemparameters.cpp \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilter.cpp \
    ../../Classes/CppKalmanFilter/steadystatekalmanfiltercalculationelements.cpp \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilterfactory.cpp \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilterparameters.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystem.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemfactory.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemparameter.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemparameters.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemparametertype.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemtype.cpp \
    ../../Classes/CppMatrix/matrix.cpp \
    ../../Classes/CppQtAboutDialog/qtaboutdialog.cpp \
    ../../Classes/CppQtHideAndShowDialog/qthideandshowdialog.cpp \
    ../../Classes/CppQtMatrix/qtmatrix.cpp \
    ../../Classes/CppQtModel/qtstdvectorfunctionmodel.cpp \
    ../../Classes/CppQtModel/qtstdvectorstringmodel.cpp \
    ../../Classes/CppQtModel/qtublasmatrixdoublemodel.cpp \
    ../../Classes/CppQtModel/qtublasvectordoublemodel.cpp \
    kalmanfilterermenudialog.cpp \
    qtfixedlagsmootherkalmanfiltercalculationdialog.cpp \
    qtkalmanfiltercalculationdialog.cpp \
    qtkalmanfilterdialog.cpp \
    qtkalmanfilterermaindialog.cpp \
    qtkalmanfilterermenudialog.cpp \
    qtkalmanfilterermodel.cpp \
    qtkalmanfiltererparameterdialog.cpp \
    qtkalmanfilterexamplesdialog.cpp \
    qtkalmanfilterexperimentdialog.cpp \
    qtkalmanfilterexperimentmodel.cpp \
    qtmain.cpp \
    qtstandardkalmanfiltercalculationdialog.cpp \
    qtsteadystatekalmanfiltercalculationdialog.cpp \
    qtwhitenoisesystemparametersdialog.cpp \
    ../../Classes/CppQtModel/modelfunctionparser.cpp \
    ../../Classes/CppKalmanFilter/kalmanfiltertypes.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemtypes.cpp


HEADERS += \
    ../../Classes/CppAbout/about.h \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilter.h \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfiltercalculationelements.h \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilterfactory.h \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilterparameters.h \
    ../../Classes/CppKalmanFilter/kalmanfilter.h \
    ../../Classes/CppKalmanFilter/kalmanfiltercalculationelements.h \
    ../../Classes/CppKalmanFilter/kalmanfiltercalculationelementsfactory.h \
    ../../Classes/CppKalmanFilter/kalmanfilterexample.h \
    ../../Classes/CppKalmanFilter/kalmanfilterexperiment.h \
    ../../Classes/CppKalmanFilter/kalmanfilterexperimentparameter.h \
    ../../Classes/CppKalmanFilter/kalmanfilterexperimentparametertype.h \
    ../../Classes/CppKalmanFilter/kalmanfilterfactory.h \
    ../../Classes/CppKalmanFilter/kalmanfilterparameter.h \
    ../../Classes/CppKalmanFilter/kalmanfilterparameters.h \
    ../../Classes/CppKalmanFilter/kalmanfilterparametertype.h \
    ../../Classes/CppKalmanFilter/kalmanfiltertype.h \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystem.h \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystemfactory.h \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystemparameters.h \
    ../../Classes/CppKalmanFilter/standardkalmanfilter.h \
    ../../Classes/CppKalmanFilter/standardkalmanfiltercalculationelements.h \
    ../../Classes/CppKalmanFilter/standardkalmanfilterfactory.h \
    ../../Classes/CppKalmanFilter/standardkalmanfilterparameters.h \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystem.h \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystemfactory.h \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystemparameters.h \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilter.h \
    ../../Classes/CppKalmanFilter/steadystatekalmanfiltercalculationelements.h \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilterfactory.h \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilterparameters.h \
    ../../Classes/CppKalmanFilter/whitenoisesystem.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemfactory.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemparameter.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemparameters.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemparametertype.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemtype.h \
    ../../Classes/CppMatrix/matrix.h \
    ../../Classes/CppQtAboutDialog/qtaboutdialog.h \
    ../../Classes/CppQtHideAndShowDialog/qthideandshowdialog.h \
    ../../Classes/CppQtMatrix/qtmatrix.h \
    ../../Classes/CppQtModel/qtstdvectorfunctionmodel.h \
    ../../Classes/CppQtModel/qtstdvectorstringmodel.h \
    ../../Classes/CppQtModel/qtublasmatrixdoublemodel.h \
    ../../Classes/CppQtModel/qtublasvectordoublemodel.h \
    ../../Classes/CppTrace/trace.h \
    ../../Libraries/fparser4.4.3/extrasrc/fpaux.hh \
    ../../Libraries/fparser4.4.3/extrasrc/fptypes.hh \
    ../../Libraries/fparser4.4.3/fpconfig.hh \
    ../../Libraries/fparser4.5.1/extrasrc/fpaux.hh \
    ../../Libraries/fparser4.5.1/extrasrc/fptypes.hh \
    ../../Libraries/fparser4.5.1/fpconfig.hh \
    kalmanfilterermenudialog.h \
    qtfixedlagsmootherkalmanfiltercalculationdialog.h \
    qtkalmanfiltercalculationdialog.h \
    qtkalmanfilterdialog.h \
    qtkalmanfilterermaindialog.h \
    qtkalmanfilterermenudialog.h \
    qtkalmanfilterermodel.h \
    qtkalmanfiltererparameterdialog.h \
    qtkalmanfilterexamplesdialog.h \
    qtkalmanfilterexperimentdialog.h \
    qtkalmanfilterexperimentmodel.h \
    qtstandardkalmanfiltercalculationdialog.h \
    qtsteadystatekalmanfiltercalculationdialog.h \
    qtwhitenoisesystemparametersdialog.h \
    ../../Classes/CppQtModel/modelfunctionparser.h \
    ../../Classes/CppKalmanFilter/kalmanfiltertypes.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemtypes.h

FORMS += \
    ../../Classes/CppQtAboutDialog/qtaboutdialog.ui \
    qtfixedlagsmootherkalmanfiltercalculationdialog.ui \
    qtkalmanfiltercalculationdialog.ui \
    qtkalmanfilterdialog.ui \
    qtkalmanfilterermaindialog.ui \
    qtkalmanfilterermenudialog.ui \
    qtkalmanfiltererparameterdialog.ui \
    qtkalmanfilterexamplesdialog.ui \
    qtkalmanfilterexperimentdialog.ui \
    qtstandardkalmanfiltercalculationdialog.ui \
    qtsteadystatekalmanfiltercalculationdialog.ui \
    qtwhitenoisesystemparametersdialog.ui

OTHER_FILES += \
    ../../Classes/CppAbout/Licence.txt \
    ../../Classes/CppKalmanFilter/Licence.txt \
    ../../Classes/CppMatrix/Licence.txt \
    ../../Classes/CppQtAboutDialog/Licence.txt \
    ../../Classes/CppQtHideAndShowDialog/Licence.txt \
    ../../Classes/CppQtMatrix/Licence.txt \
    ../../Classes/CppTrace/Licence.txt \
    ../../Libraries/fparser4.4.3/extrasrc/fp_identifier_parser.inc \
    ../../Libraries/fparser4.4.3/extrasrc/fp_opcode_add.inc \
    ../../Libraries/fparser4.5.1/extrasrc/fp_identifier_parser.inc \
    ../../Libraries/fparser4.5.1/extrasrc/fp_opcode_add.inc \
    crosscompiletowindows.sh \
    Licence.txt \
    zip.sh

RESOURCES += \
    ToolKalmanFilterer.qrc

#
#
# Type of compile
#
#

CONFIG(debug, debug|release) {
  message(Debug mode)
}

CONFIG(release, debug|release) {
  message(Release mode)

  #Remove all asserts and TRACE
  DEFINES += NDEBUG NTRACE_BILDERBIKKEL
}

#
#
# Platform specific
#
#

#
#
# Compiler flags
#
#
QMAKE_CXXFLAGS += -Wall -Wextra

unix {
  message(Unix)
  #Strict error handling
  QMAKE_CXXFLAGS += -std=c++11 -Werror
}

win32 {
  !static {
    message(Native Windows)
  }

  static {
    message(Crosscompiling from Lubuntu to Windows)
  }

  #Allow the crosscompiler to emit warnings without terminating
  QMAKE_CXXFLAGS += -std=c++11 #-Werror

  #Prevents error:
  #/my_boost_folder/boost/type_traits/detail/has_binary_operator.hp:50: Parse error at "BOOST_JOIN"
  DEFINES += BOOST_TT_HAS_OPERATOR_HPP_INCLUDED
}

#
#
# Boost
#
#

unix {
  LIBS += \
  -lboost_date_time \
  -lboost_filesystem \
  -lboost_program_options \
  -lboost_regex \
  -lboost_signals \
  -lboost_system
}

win32 {

  #Boost libraries
  INCLUDEPATH += \
    ../../Libraries/boost_1_53_0

  #Prevent the following error:
  #../../Libraries/boost_1_53_0/libs/program_options/src/parsers.cpp: In function 'boost::program_options::parsed_options boost::program_options::parse_environment(const boost::program_options::options_description&, const boost::function1<std::basic_string<char>, std::basic_string<char> >&)':
  #../../Libraries/boost_1_53_0/libs/program_options/src/parsers.cpp:194:36: error: 'environ' was not declared in this scope
  DEFINES += __COMO_VERSION__


  #Boost.Data_time
  HEADERS += \
    ../../Libraries/boost_1_53_0/libs/date_time/src/gregorian/greg_names.hpp
  SOURCES += \
    ../../Libraries/boost_1_53_0/libs/date_time/src/gregorian/greg_weekday.cpp \
    ../../Libraries/boost_1_53_0/libs/date_time/src/gregorian/gregorian_types.cpp \
    ../../Libraries/boost_1_53_0/libs/date_time/src/gregorian/greg_month.cpp \
    ../../Libraries/boost_1_53_0/libs/date_time/src/gregorian/date_generators.cpp

  #Boost.Filesystem
  HEADERS += \
    ../../Libraries/boost_1_53_0/libs/filesystem/src/windows_file_codecvt.hpp
  SOURCES += \
    ../../Libraries/boost_1_53_0/libs/filesystem/src/codecvt_error_category.cpp \
    ../../Libraries/boost_1_53_0/libs/filesystem/src/operations.cpp \
    ../../Libraries/boost_1_53_0/libs/filesystem/src/path.cpp \
    ../../Libraries/boost_1_53_0/libs/filesystem/src/path_traits.cpp \
    ../../Libraries/boost_1_53_0/libs/filesystem/src/portability.cpp \
    ../../Libraries/boost_1_53_0/libs/filesystem/src/unique_path.cpp \
    ../../Libraries/boost_1_53_0/libs/filesystem/src/utf8_codecvt_facet.cpp \ #Keep, comment program_options/src/utf8_codecvt_facet.cpp
    ../../Libraries/boost_1_53_0/libs/filesystem/src/windows_file_codecvt.cpp

  #Boost.Program_options
  #
  #This lib does not seem to work well together with Boost.Filesystem
  #when compiled from source like this
  #
  #SOURCES += \
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/cmdline.cpp \
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/config_file.cpp \
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/convert.cpp \
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/options_description.cpp \
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/parsers.cpp \
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/positional_options.cpp \
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/split.cpp \
  #  #../../Libraries/boost_1_53_0/libs/program_options/src/utf8_codecvt_facet.cpp \ #Comment, keep filesystem/src/utf8_codecvt_facet.cpp
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/value_semantic.cpp \
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/variables_map.cpp \
  #  ../../Libraries/boost_1_53_0/libs/program_options/src/winmain.cpp

  #Boost.Regex
  HEADERS += \
    ../../Libraries/boost_1_53_0/libs/regex/src/internals.hpp

  SOURCES += \
    ../../Libraries/boost_1_53_0/libs/regex/src/winstances.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/wide_posix_api.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/wc_regex_traits.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/w32_regex_traits.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/usinstances.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/static_mutex.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/regex_traits_defaults.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/regex_raw_buffer.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/regex_debug.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/regex.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/posix_api.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/instances.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/icu.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/fileiter.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/c_regex_traits.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/cregex.cpp \
    ../../Libraries/boost_1_53_0/libs/regex/src/cpp_regex_traits.cpp

  #Boost.System
  HEADERS += \
    ../../Libraries/boost_1_53_0/libs/system/src/local_free_on_destruction.hpp
  SOURCES += \
    ../../Libraries/boost_1_53_0/libs/system/src/error_code.cpp
}

#
#
# Warp's function parser
#
#
#unix {
  INCLUDEPATH += \
    ../../Libraries/fparser4.5.1

  HEADERS += \
    ../../Libraries/fparser4.5.1/extrasrc/fpaux.hh \
    ../../Libraries/fparser4.5.1/extrasrc/fptypes.hh \
    ../../Libraries/fparser4.5.1/fparser_gmpint.hh \
    ../../Libraries/fparser4.5.1/fparser.hh \
    ../../Libraries/fparser4.5.1/fparser_mpfr.hh \
    ../../Libraries/fparser4.5.1/fpconfig.hh

  SOURCES += \
    ../../Libraries/fparser4.5.1/fparser.cc \
    ../../Libraries/fparser4.5.1/fpoptimizer.cc


  OTHER_FILES += \
    ../../Libraries/fparser4.5.1/extrasrc/fp_identifier_parser.inc \
    ../../Libraries/fparser4.5.1/extrasrc/fp_opcode_add.inc
#}


#
#
# Big integer
#
#
INCLUDEPATH += \
    ../../Libraries/bigint-2010.04.30

HEADERS += \
    ../../Libraries/bigint-2010.04.30/BigIntegerAlgorithms.hh \
    ../../Libraries/bigint-2010.04.30/BigInteger.hh \
    ../../Libraries/bigint-2010.04.30/BigIntegerLibrary.hh \
    ../../Libraries/bigint-2010.04.30/BigIntegerUtils.hh \
    ../../Libraries/bigint-2010.04.30/BigUnsigned.hh \
    ../../Libraries/bigint-2010.04.30/BigUnsignedInABase.hh \
    ../../Libraries/bigint-2010.04.30/NumberlikeArray.hh

SOURCES += \
    ../../Libraries/bigint-2010.04.30/BigIntegerAlgorithms.cc \
    ../../Libraries/bigint-2010.04.30/BigInteger.cc \
    ../../Libraries/bigint-2010.04.30/BigIntegerUtils.cc \
    ../../Libraries/bigint-2010.04.30/BigUnsigned.cc \
    ../../Libraries/bigint-2010.04.30/BigUnsignedInABase.cc

#
#
# Qwt
#
#

unix {
  INCLUDEPATH += /usr/include/qwt-qt4
  LIBS += -lqwt-qt4
}

win32 {
  !static {
    INCLUDEPATH+=C:/qwt-6.0.1/include
    LIBS += -LC:/qwt-6.0.1/lib

    #Use the correct version, otherwise
    #the following error occurs: 'QWidget: Must construct a QApplication before a QPaintDevice'
    CONFIG(debug, debug|release) {
      message(Use Qwt debug library)
      LIBS+= -lqwtd
    }
    CONFIG(release, debug|release) {
      message(Use Qwt release library)
      LIBS+= -lqwt
    }

  }

  static {
    message(Compile and link Qwt from source)
  INCLUDEPATH+=../../Libraries/qwt-6.0.1/include

  SOURCES += \
    ../../Libraries/qwt-6.0.1/src/qwt_abstract_scale_draw.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_abstract_slider.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_analog_clock.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_arrow_button.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_clipper.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_color_map.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_column_symbol.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_compass.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_compass_rose.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_counter.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_curve_fitter.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_dial.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_dial_needle.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_double_range.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_dyngrid_layout.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_event_pattern.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_interval.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_interval_symbol.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_knob.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_legend.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_legend_item.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_magnifier.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_math.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_matrix_raster_data.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_null_paintdevice.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_painter.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_panner.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_picker.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_picker_machine.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_axis.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_canvas.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_curve.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_dict.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_directpainter.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_grid.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_histogram.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_item.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_layout.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_magnifier.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_marker.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_panner.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_picker.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_rasteritem.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_renderer.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_rescaler.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_scaleitem.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_seriesitem.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_spectrocurve.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_xml.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_zoomer.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_point_3d.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_point_polar.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_raster_data.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_round_scale_draw.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_sampling_thread.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_div.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_draw.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_engine.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_map.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_widget.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_series_data.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_slider.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_spline.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_symbol.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_system_clock.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_text.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_text_engine.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_text_label.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_thermo.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_wheel.cpp \
#    ../../Libraries/qwt-6.0.1/src/qwt_plot_intervalcurve.cpp \
#    ../../Libraries/qwt-6.0.1/src/qwt_plot_spectrogram.cpp \
#    ../../Libraries/qwt-6.0.1/src/qwt_plot_svgitem.cpp \
    ../../Libraries/qwt-6.0.1/src/qwt_abstract_scale.cpp

  HEADERS += \
    ../../Libraries/qwt-6.0.1/include/qwt_abstract_scale.h \
    ../../Libraries/qwt-6.0.1/include/qwt_abstract_scale_draw.h \
    ../../Libraries/qwt-6.0.1/include/qwt_abstract_slider.h \
    ../../Libraries/qwt-6.0.1/include/qwt_analog_clock.h \
    ../../Libraries/qwt-6.0.1/include/qwt_arrow_button.h \
    ../../Libraries/qwt-6.0.1/include/qwt_clipper.h \
    ../../Libraries/qwt-6.0.1/include/qwt_color_map.h \
    ../../Libraries/qwt-6.0.1/include/qwt_column_symbol.h \
    ../../Libraries/qwt-6.0.1/include/qwt_compass.h \
    ../../Libraries/qwt-6.0.1/include/qwt_compass_rose.h \
    ../../Libraries/qwt-6.0.1/include/qwt_compat.h \
    ../../Libraries/qwt-6.0.1/include/qwt_counter.h \
    ../../Libraries/qwt-6.0.1/include/qwt_curve_fitter.h \
    ../../Libraries/qwt-6.0.1/include/qwt_dial.h \
    ../../Libraries/qwt-6.0.1/include/qwt_dial_needle.h \
    ../../Libraries/qwt-6.0.1/include/qwt_double_range.h \
    ../../Libraries/qwt-6.0.1/include/qwt_dyngrid_layout.h \
    ../../Libraries/qwt-6.0.1/include/qwt_event_pattern.h \
    ../../Libraries/qwt-6.0.1/include/qwt_global.h \
    ../../Libraries/qwt-6.0.1/include/qwt_interval.h \
    ../../Libraries/qwt-6.0.1/include/qwt_interval_symbol.h \
    ../../Libraries/qwt-6.0.1/include/qwt_knob.h \
    ../../Libraries/qwt-6.0.1/include/qwt_legend.h \
    ../../Libraries/qwt-6.0.1/include/qwt_legend_item.h \
    ../../Libraries/qwt-6.0.1/include/qwt_legend_itemmanager.h \
    ../../Libraries/qwt-6.0.1/include/qwt_magnifier.h \
    ../../Libraries/qwt-6.0.1/include/qwt_math.h \
    ../../Libraries/qwt-6.0.1/include/qwt_mathml_text_engine.h \
    ../../Libraries/qwt-6.0.1/include/qwt_matrix_raster_data.h \
    ../../Libraries/qwt-6.0.1/include/qwt_null_paintdevice.h \
    ../../Libraries/qwt-6.0.1/include/qwt_painter.h \
    ../../Libraries/qwt-6.0.1/include/qwt_panner.h \
    ../../Libraries/qwt-6.0.1/include/qwt_picker.h \
    ../../Libraries/qwt-6.0.1/include/qwt_picker_machine.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_canvas.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_curve.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_dict.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_directpainter.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_grid.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_histogram.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_item.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_layout.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_magnifier.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_marker.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_panner.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_picker.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_rasteritem.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_renderer.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_rescaler.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_scaleitem.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_seriesitem.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_spectrocurve.h \
    ../../Libraries/qwt-6.0.1/include/qwt_plot_zoomer.h \
    ../../Libraries/qwt-6.0.1/include/qwt_point_3d.h \
    ../../Libraries/qwt-6.0.1/include/qwt_point_polar.h \
    ../../Libraries/qwt-6.0.1/include/qwt_raster_data.h \
    ../../Libraries/qwt-6.0.1/include/qwt_round_scale_draw.h \
    ../../Libraries/qwt-6.0.1/include/qwt_sampling_thread.h \
    ../../Libraries/qwt-6.0.1/include/qwt_scale_div.h \
    ../../Libraries/qwt-6.0.1/include/qwt_scale_draw.h \
    ../../Libraries/qwt-6.0.1/include/qwt_scale_engine.h \
    ../../Libraries/qwt-6.0.1/include/qwt_scale_map.h \
    ../../Libraries/qwt-6.0.1/include/qwt_scale_widget.h \
    ../../Libraries/qwt-6.0.1/include/qwt_series_data.h \
    ../../Libraries/qwt-6.0.1/include/qwt_slider.h \
    ../../Libraries/qwt-6.0.1/include/qwt_spline.h \
    ../../Libraries/qwt-6.0.1/include/qwt_symbol.h \
    ../../Libraries/qwt-6.0.1/include/qwt_system_clock.h \
    ../../Libraries/qwt-6.0.1/include/qwt_text.h \
    ../../Libraries/qwt-6.0.1/include/qwt_text_engine.h \
    ../../Libraries/qwt-6.0.1/include/qwt_text_label.h \
    ../../Libraries/qwt-6.0.1/include/qwt_thermo.h \
    ../../Libraries/qwt-6.0.1/include/qwt_wheel.h \
    ../../Libraries/qwt-6.0.1/src/qwt.h \
    ../../Libraries/qwt-6.0.1/src/qwt_abstract_scale.h \
    ../../Libraries/qwt-6.0.1/src/qwt_abstract_scale_draw.h \
    ../../Libraries/qwt-6.0.1/src/qwt_abstract_slider.h \
    ../../Libraries/qwt-6.0.1/src/qwt_analog_clock.h \
    ../../Libraries/qwt-6.0.1/src/qwt_arrow_button.h \
    ../../Libraries/qwt-6.0.1/src/qwt_clipper.h \
    ../../Libraries/qwt-6.0.1/src/qwt_color_map.h \
    ../../Libraries/qwt-6.0.1/src/qwt_column_symbol.h \
    ../../Libraries/qwt-6.0.1/src/qwt_compass.h \
    ../../Libraries/qwt-6.0.1/src/qwt_compass_rose.h \
    ../../Libraries/qwt-6.0.1/src/qwt_compat.h \
    ../../Libraries/qwt-6.0.1/src/qwt_counter.h \
    ../../Libraries/qwt-6.0.1/src/qwt_curve_fitter.h \
    ../../Libraries/qwt-6.0.1/src/qwt_dial.h \
    ../../Libraries/qwt-6.0.1/src/qwt_dial_needle.h \
    ../../Libraries/qwt-6.0.1/src/qwt_double_range.h \
    ../../Libraries/qwt-6.0.1/src/qwt_dyngrid_layout.h \
    ../../Libraries/qwt-6.0.1/src/qwt_event_pattern.h \
    ../../Libraries/qwt-6.0.1/src/qwt_global.h \
    ../../Libraries/qwt-6.0.1/src/qwt_interval.h \
    ../../Libraries/qwt-6.0.1/src/qwt_interval_symbol.h \
    ../../Libraries/qwt-6.0.1/src/qwt_knob.h \
    ../../Libraries/qwt-6.0.1/src/qwt_legend.h \
    ../../Libraries/qwt-6.0.1/src/qwt_legend_item.h \
    ../../Libraries/qwt-6.0.1/src/qwt_legend_itemmanager.h \
    ../../Libraries/qwt-6.0.1/src/qwt_magnifier.h \
    ../../Libraries/qwt-6.0.1/src/qwt_math.h \
    ../../Libraries/qwt-6.0.1/src/qwt_matrix_raster_data.h \
    ../../Libraries/qwt-6.0.1/src/qwt_null_paintdevice.h \
    ../../Libraries/qwt-6.0.1/src/qwt_painter.h \
    ../../Libraries/qwt-6.0.1/src/qwt_panner.h \
    ../../Libraries/qwt-6.0.1/src/qwt_picker.h \
    ../../Libraries/qwt-6.0.1/src/qwt_picker_machine.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_canvas.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_curve.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_dict.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_directpainter.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_grid.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_histogram.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_item.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_layout.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_magnifier.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_marker.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_panner.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_picker.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_rasteritem.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_renderer.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_rescaler.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_scaleitem.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_seriesitem.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_spectrocurve.h \
    ../../Libraries/qwt-6.0.1/src/qwt_plot_zoomer.h \
    ../../Libraries/qwt-6.0.1/src/qwt_point_3d.h \
    ../../Libraries/qwt-6.0.1/src/qwt_point_polar.h \
    ../../Libraries/qwt-6.0.1/src/qwt_raster_data.h \
    ../../Libraries/qwt-6.0.1/src/qwt_round_scale_draw.h \
    ../../Libraries/qwt-6.0.1/src/qwt_sampling_thread.h \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_div.h \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_draw.h \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_engine.h \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_map.h \
    ../../Libraries/qwt-6.0.1/src/qwt_scale_widget.h \
    ../../Libraries/qwt-6.0.1/src/qwt_series_data.h \
    ../../Libraries/qwt-6.0.1/src/qwt_slider.h \
    ../../Libraries/qwt-6.0.1/src/qwt_spline.h \
    ../../Libraries/qwt-6.0.1/src/qwt_symbol.h \
    ../../Libraries/qwt-6.0.1/src/qwt_system_clock.h \
    ../../Libraries/qwt-6.0.1/src/qwt_text.h \
    ../../Libraries/qwt-6.0.1/src/qwt_text_engine.h \
    ../../Libraries/qwt-6.0.1/src/qwt_text_label.h \
    ../../Libraries/qwt-6.0.1/src/qwt_thermo.h \
    ../../Libraries/qwt-6.0.1/src/qwt_wheel.h \
#    ../../Libraries/qwt-6.0.1/include/qwt_plot_intervalcurve.h \
#    ../../Libraries/qwt-6.0.1/include/qwt_plot_spectrogram.h \
#    ../../Libraries/qwt-6.0.1/include/qwt_plot_svgitem.h \
#    ../../Libraries/qwt-6.0.1/src/qwt_plot_intervalcurve.h \
#    ../../Libraries/qwt-6.0.1/src/qwt_plot_spectrogram.h \
#    ../../Libraries/qwt-6.0.1/src/qwt_plot_svgitem.h \
    ../../Libraries/qwt-6.0.1/include/qwt.h
  }
}