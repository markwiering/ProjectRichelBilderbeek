QT += core gui

CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

INCLUDEPATH += \
    ../../Classes/CppAbout \
    ../../Classes/CppAsciiArter \
    ../../Classes/CppBinaryNewickVector \
    ../../Classes/CppCodeToHtml \
    ../../Classes/CppConnectThree \
    ../../Classes/CppConnectThreeWidget \
    ../../Classes/CppCopy_if \
    ../../Classes/CppCounter \
    ../../Classes/CppDial \
    ../../Classes/CppDialWidget \
    ../../Classes/CppEncranger \
    ../../Classes/CppExercise \
    ../../Classes/CppFuzzy_equal_to \
    ../../Classes/CppGaborFilter \
    ../../Classes/CppGaborFilterWidget \
    ../../Classes/CppHtmlPage \
    ../../Classes/CppIpAddress \
    ../../Classes/CppKalmanFilter \
    ../../Classes/CppLazy_init \
    ../../Classes/CppLed \
    ../../Classes/CppLedWidget \
    ../../Classes/CppLoopReader \
    ../../Classes/CppManyDigitNewick \
    ../../Classes/CppMatrix \
    ../../Classes/CppMultiVector \
    ../../Classes/CppMultipleChoiceQuestion \
    ../../Classes/CppMultipleChoiceQuestionDialog \
    ../../Classes/CppMusic \
    ../../Classes/CppMysteryMachine \
    ../../Classes/CppMysteryMachineWidget \
    ../../Classes/CppNewick \
    ../../Classes/CppNewickVector \
    ../../Classes/CppOpenQuestion \
    ../../Classes/CppOpenQuestionDialog \
    ../../Classes/CppPylos \
    ../../Classes/CppQtCreatorProFile \
    ../../Classes/CppQrcFile \
    ../../Classes/CppQtModel \
    ../../Classes/CppQuestion \
    ../../Classes/CppQuestionDialog \
    ../../Classes/CppRainbow \
    ../../Classes/CppRandomCode \
    ../../Classes/CppRectangle \
    ../../Classes/CppRichelBilderbeekProgram \
    ../../Classes/CppRubiksClock \
    ../../Classes/CppRubiksClockWidget \
    ../../Classes/CppShape \
    ../../Classes/CppShapeWidget \
    ../../Classes/CppShinyButton \
    ../../Classes/CppShinyButtonWidget \
    ../../Classes/CppSortedBinaryNewickVector \
    ../../Classes/CppStateObserver \
    ../../Classes/CppStopwatch \
    ../../Classes/CppTicTacToe \
    ../../Classes/CppToggleButton \
    ../../Classes/CppToggleButtonWidget \
    ../../Classes/CppTrace \
    ../../Classes/CppTwoDigitNewick \
    ../../Classes/CppWidget \
    ../../Classes/CppWtAboutDialog \
    ../../Classes/CppWtAutoConfig \
    ../../Classes/CppWtConnectThreeWidget \
    ../../Classes/CppWtDialWidget \
    ../../Classes/CppWtEntrance \
    ../../Classes/CppWtExercise \
    ../../Classes/CppWtGroupWidget \
    ../../Classes/CppWtLedWidget \
    ../../Classes/CppWtMultipleChoiceQuestionDialog \
    ../../Classes/CppWtMysteryMachineWidget \
    ../../Classes/CppWtOpenQuestionDialog \
    ../../Classes/CppWtQuestionDialog \
    ../../Classes/CppWtRichelBilderbeekGalleryDialog \
    ../../Classes/CppWtRubiksClockWidget \
    ../../Classes/CppWtSelectFileDialog \
    ../../Classes/CppWtServerPusher \
    ../../Classes/CppWtShapeGroupWidget \
    ../../Classes/CppWtShapeWidget \
    ../../Classes/CppWtShinyButtonWidget \
    ../../Classes/CppWtTicTacToeWidget \
    ../../Classes/CppWtTimedServerPusher \
    ../../Classes/CppWtToggleButtonWidget \
    ../../Games/GameConnectThree \
    ../../Games/GamePylos \
    ../../Games/GameRubiksClock \
    ../../Games/GameTicTacToe \
    ../../Tools/ToolAsciiArter \
    ../../Tools/ToolCodeToHtml \
    ../../Tools/ToolCreateQtProjectZipFile \
    ../../Tools/ToolHometrainer \
    ../../Tools/ToolKalmanFilterer \
    ../../Tools/ToolRandomCode \
    ../../Tools/ToolRegexTester \
    ../../Tools/ToolSimMysteryMachine \
    ../../Tools/ToolStateObserver \
    ../../Tools/ToolTestDial \
    ../../Tools/ToolTestEncranger \
    ../../Tools/ToolTestEntrance \
    ../../Tools/ToolTestExercise \
    ../../Tools/ToolTestFunctionParser \
    ../../Tools/ToolTestGroupWidget \
    ../../Tools/ToolTestLed \
    ../../Tools/ToolTestNewickVector \
    ../../Tools/ToolTestQtCreatorProFile \
    ../../Tools/ToolTestQtArrowItems \
    ../../Tools/ToolTestQrcFile \
    ../../Tools/ToolTestQuestion \
    ../../Tools/ToolTestSelectFileDialog \
    ../../Tools/ToolTestServerPusher \
    ../../Tools/ToolTestShape \
    ../../Tools/ToolTestShinyButton \
    ../../Tools/ToolTestTimedServerPusher \
    ../../Tools/ToolTestToggleButton \
    ../../Tools/ToolTestTwoDigitNewick \
    ../../Tools/ToolTimePoll \
    ../../Projects/ProjectGtst \
    ../../Projects/RichelbilderbeekNl

SOURCES += \
    ../../Classes/CppAbout/about.cpp \
    ../../Classes/CppAsciiArter/asciiarter.cpp \
    ../../Classes/CppBinaryNewickVector/binarynewickvector.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlcontent.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlcontenttype.cpp \
    ../../Classes/CppCodeToHtml/codetohtml.cpp \
    ../../Classes/CppCodeToHtml/codetohtmldialog.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlfooter.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlheader.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlinfo.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlpagetype.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlreplacements.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlreplacementscpp.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlreplacementspro.cpp \
    ../../Classes/CppCodeToHtml/codetohtmltechinfo.cpp \
    ../../Classes/CppCodeToHtml/codetohtmltechinfotype.cpp \
    ../../Classes/CppCodeToHtml/codetohtmlversion.cpp \
    ../../Classes/CppConnectThree/connectthree.cpp \
    ../../Classes/CppConnectThreeWidget/connectthreewidget.cpp \
    ../../Classes/CppCounter/counter.cpp \
    ../../Classes/CppDial/dial.cpp \
    ../../Classes/CppDialWidget/dialwidget.cpp \
    ../../Classes/CppEncranger/encranger.cpp \
    ../../Classes/CppExercise/exercise.cpp \
    ../../Classes/CppHtmlPage/htmlpage.cpp \
    ../../Classes/CppIpAddress/ipaddress.cpp \
    ../../Classes/CppLazy_init/lazy_init.cpp \
    ../../Classes/CppLed/led.cpp \
    ../../Classes/CppLedWidget/ledwidget.cpp \
    ../../Classes/CppManyDigitNewick/manydigitnewickcoordinat.cpp \
    ../../Classes/CppManyDigitNewick/manydigitnewick.cpp \
    ../../Classes/CppManyDigitNewick/manydigitnewickderivative.cpp \
    ../../Classes/CppManyDigitNewick/manydigitnewickindexer.cpp \
    ../../Classes/CppManyDigitNewick/manydigitnewickindextable.cpp \
    ../../Classes/CppManyDigitNewick/manydigitnewicks.cpp \
    ../../Classes/CppMultipleChoiceQuestionDialog/multiplechoicequestiondialog.cpp \
    ../../Classes/CppMultipleChoiceQuestion/multiplechoicequestion.cpp \
    ../../Classes/CppMusic/musicchord.cpp \
    ../../Classes/CppMusic/musicnote.cpp \
    ../../Classes/CppMusic/musicscale.cpp \
    ../../Classes/CppMysteryMachine/mysterymachine.cpp \
    ../../Classes/CppMysteryMachineWidget/mysterymachinewidget.cpp \
    ../../Classes/CppNewick/newick.cpp \
    ../../Classes/CppNewick/newickcpp98.cpp \
    ../../Classes/CppNewickVector/newickvector.cpp \
    ../../Classes/CppOpenQuestionDialog/openquestiondialog.cpp \
    ../../Classes/CppOpenQuestion/openquestion.cpp \
    ../../Classes/CppQrcFile/qrcfile.cpp \
    ../../Classes/CppQtCreatorProFile/qtcreatorprofile.cpp \
    ../../Classes/CppQtCreatorProFile/qtcreatorprofilezipscript.cpp \
    ../../Classes/CppQuestionDialog/questiondialog.cpp \
    ../../Classes/CppQuestion/question.cpp \
    ../../Classes/CppRainbow/rainbow.cpp \
    ../../Classes/CppRandomCode/randomcode.cpp \
    ../../Classes/CppRectangle/rectangle.cpp \
    ../../Classes/CppRichelBilderbeekProgram/richelbilderbeekprogram.cpp \
    ../../Classes/CppRichelBilderbeekProgram/richelbilderbeekprogramstatus.cpp \
    ../../Classes/CppRubiksClock/rubiksclock.cpp \
    ../../Classes/CppRubiksClockWidget/rubiksclockdial.cpp \
    ../../Classes/CppRubiksClockWidget/rubiksclockdialwidget.cpp \
    ../../Classes/CppRubiksClockWidget/rubiksclockwidget.cpp \
    ../../Classes/CppShape/shape.cpp \
    ../../Classes/CppShapeWidget/shapewidget.cpp \
    ../../Classes/CppShinyButton/shinybutton.cpp \
    ../../Classes/CppShinyButtonWidget/shinybuttonwidget.cpp \
    ../../Classes/CppSortedBinaryNewickVector/sortedbinarynewickvector.cpp \
    ../../Classes/CppTicTacToe/tictactoe.cpp \
    ../../Classes/CppToggleButton/togglebutton.cpp \
    ../../Classes/CppToggleButtonWidget/togglebuttonwidget.cpp \
    ../../Classes/CppTwoDigitNewick/twodigitnewick.cpp \
    ../../Classes/CppTwoDigitNewick/twodigitnewickderivative.cpp \
    ../../Classes/CppTwoDigitNewick/twodigitnewickindexer.cpp \
    ../../Classes/CppTwoDigitNewick/twodigitnewickindextable.cpp \
    ../../Classes/CppTwoDigitNewick/twodigitnewicks.cpp \
    ../../Classes/CppWidget/widget.cpp \
    ../../Classes/CppWtAboutDialog/wtaboutdialog.cpp \
    ../../Classes/CppWtAutoConfig/wtautoconfig.cpp \
    ../../Classes/CppWtConnectThreeWidget/wtconnectthreewidget.cpp \
    ../../Classes/CppWtDialWidget/wtdialwidget.cpp \
    ../../Classes/CppWtEntrance/wtentrance.cpp \
    ../../Classes/CppWtExercise/wtexercise.cpp \
    ../../Classes/CppWtGroupWidget/wtgroupwidget.cpp \
    ../../Classes/CppWtLedWidget/wtledwidget.cpp \
    ../../Classes/CppWtMultipleChoiceQuestionDialog/wtmultiplechoicequestiondialog.cpp \
    ../../Classes/CppWtMysteryMachineWidget/wtmysterymachinewidget.cpp \
    ../../Classes/CppWtOpenQuestionDialog/wtopenquestiondialog.cpp \
    ../../Classes/CppWtQuestionDialog/wtquestiondialog.cpp \
    ../../Classes/CppWtRichelBilderbeekGalleryDialog/wtrichelbilderbeekgallerydialog.cpp \
    ../../Classes/CppWtRubiksClockWidget/wtrubiksclockwidget.cpp \
    ../../Classes/CppWtSelectFileDialog/wtselectfiledialog.cpp \
    ../../Classes/CppWtServerPusher/wtserverpusherclient.cpp \
    ../../Classes/CppWtServerPusher/wtserverpusher.cpp \
    ../../Classes/CppWtShapeGroupWidget/wtshapegroupwidget.cpp \
    ../../Classes/CppWtShapeWidget/wtshapewidget.cpp \
    ../../Classes/CppWtShinyButtonWidget/wtshinybuttonwidget.cpp \
    ../../Classes/CppWtTicTacToeWidget/wttictactoewidget.cpp \
    ../../Classes/CppWtTimedServerPusher/wttimedserverpusherclient.cpp \
    ../../Classes/CppWtTimedServerPusher/wttimedserverpusher.cpp \
    ../../Classes/CppWtToggleButtonWidget/wttogglebuttonwidget.cpp \
    ../../Games/GameConnectThree/connectthreemenudialog.cpp \
    ../../Games/GameConnectThree/connectthreeresources.cpp \
    ../../Games/GameConnectThree/wtconnectthreegamedialog.cpp \
    ../../Games/GameConnectThree/wtconnectthreemenudialog.cpp \
    ../../Games/GameConnectThree/wtconnectthreeresources.cpp \
    ../../Games/GameConnectThree/wtselectplayerwidget.cpp \
    ../../Games/GameRubiksClock/rubiksclockmenudialog.cpp \
    ../../Games/GameRubiksClock/wtrubiksclockmaindialog.cpp \
    ../../Games/GameRubiksClock/wtrubiksclockmenudialog.cpp \
    ../../Games/GameTicTacToe/tictactoemenudialog.cpp \
    ../../Games/GameTicTacToe/wttictactoegamedialog.cpp \
    ../../Games/GameTicTacToe/wttictactoemenudialog.cpp \
    ../../Projects/ProjectGtst/administrator.cpp \
    ../../Projects/ProjectGtst/administratordialog.cpp \
    ../../Projects/ProjectGtst/administratordialogstate.cpp \
    ../../Projects/ProjectGtst/administratordialogstateloggedin.cpp \
    ../../Projects/ProjectGtst/administratordialogstatenotloggedin.cpp \
    ../../Projects/ProjectGtst/administrators.cpp \
    ../../Projects/ProjectGtst/chatmessage.cpp \
    ../../Projects/ProjectGtst/chatshapefactory.cpp \
    ../../Projects/ProjectGtst/chooseactionoption.cpp \
    ../../Projects/ProjectGtst/debugdialog.cpp \
    ../../Projects/ProjectGtst/groupassigner.cpp \
    ../../Projects/ProjectGtst/group.cpp \
    ../../Projects/ProjectGtst/groupfinished.cpp \
    ../../Projects/ProjectGtst/grouploggedin.cpp \
    ../../Projects/ProjectGtst/groupnotloggedin.cpp \
    ../../Projects/ProjectGtst/groupparticipating.cpp \
    ../../Projects/ProjectGtst/groups.cpp \
    ../../Projects/ProjectGtst/logfile.cpp \
    ../../Projects/ProjectGtst/parametersassignpayoff.cpp \
    ../../Projects/ProjectGtst/parameterschat.cpp \
    ../../Projects/ProjectGtst/parameterschooseaction.cpp \
    ../../Projects/ProjectGtst/parameters.cpp \
    ../../Projects/ProjectGtst/parametersfinished.cpp \
    ../../Projects/ProjectGtst/parametersgroupassign.cpp \
    ../../Projects/ProjectGtst/parametersgroupreassign.cpp \
    ../../Projects/ProjectGtst/parametersquiz.cpp \
    ../../Projects/ProjectGtst/parametersviewresultsgroup.cpp \
    ../../Projects/ProjectGtst/parametersviewresultsvoting.cpp \
    ../../Projects/ProjectGtst/parametersvoting.cpp \
    ../../Projects/ProjectGtst/participant.cpp \
    ../../Projects/ProjectGtst/participantdialog.cpp \
    ../../Projects/ProjectGtst/participantdialogstateassignpayoff.cpp \
    ../../Projects/ProjectGtst/participantdialogstatechat.cpp \
    ../../Projects/ProjectGtst/participantdialogstatechooseaction.cpp \
    ../../Projects/ProjectGtst/participantdialogstate.cpp \
    ../../Projects/ProjectGtst/participantdialogstatefinished.cpp \
    ../../Projects/ProjectGtst/participantdialogstategroupassign.cpp \
    ../../Projects/ProjectGtst/participantdialogstategroupreassign.cpp \
    ../../Projects/ProjectGtst/participantdialogstateloggedin.cpp \
    ../../Projects/ProjectGtst/participantdialogstatenotloggedin.cpp \
    ../../Projects/ProjectGtst/participantdialogstatequiz.cpp \
    ../../Projects/ProjectGtst/participantdialogstates.cpp \
    ../../Projects/ProjectGtst/participantdialogstateviewresultsgroup.cpp \
    ../../Projects/ProjectGtst/participantdialogstateviewresultsvoting.cpp \
    ../../Projects/ProjectGtst/participantdialogstatevoting.cpp \
    ../../Projects/ProjectGtst/participantstateassignpayoff.cpp \
    ../../Projects/ProjectGtst/participantstatechat.cpp \
    ../../Projects/ProjectGtst/participantstatechooseaction.cpp \
    ../../Projects/ProjectGtst/participantstate.cpp \
    ../../Projects/ProjectGtst/participantstatefinished.cpp \
    ../../Projects/ProjectGtst/participantstategroupassign.cpp \
    ../../Projects/ProjectGtst/participantstategroupreassign.cpp \
    ../../Projects/ProjectGtst/participantstateloggedin.cpp \
    ../../Projects/ProjectGtst/participantstatenotloggedin.cpp \
    ../../Projects/ProjectGtst/participantstatequiz.cpp \
    ../../Projects/ProjectGtst/participantstateviewresultsgroup.cpp \
    ../../Projects/ProjectGtst/participantstateviewresultsvoting.cpp \
    ../../Projects/ProjectGtst/participantstatevoting.cpp \
    ../../Projects/ProjectGtst/payoff.cpp \
    ../../Projects/ProjectGtst/payoffs.cpp \
    ../../Projects/ProjectGtst/projectgtstmenudialog.cpp \
    ../../Projects/ProjectGtst/repeatassigner.cpp \
    ../../Projects/ProjectGtst/repeatassignerfixed.cpp \
    ../../Projects/ProjectGtst/repeatassignerrandomgeometric.cpp \
    ../../Projects/ProjectGtst/repeatassignerrandomuniform.cpp \
    ../../Projects/ProjectGtst/resources.cpp \
    ../../Projects/ProjectGtst/server.cpp \
    ../../Projects/ProjectGtst/serverstateassignpayoff.cpp \
    ../../Projects/ProjectGtst/serverstatechat.cpp \
    ../../Projects/ProjectGtst/serverstatechooseaction.cpp \
    ../../Projects/ProjectGtst/serverstate.cpp \
    ../../Projects/ProjectGtst/serverstatefinished.cpp \
    ../../Projects/ProjectGtst/serverstategroupassign.cpp \
    ../../Projects/ProjectGtst/serverstategroupreassign.cpp \
    ../../Projects/ProjectGtst/serverstatequiz.cpp \
    ../../Projects/ProjectGtst/serverstates.cpp \
    ../../Projects/ProjectGtst/serverstateviewresultsgroup.cpp \
    ../../Projects/ProjectGtst/serverstateviewresultsvoting.cpp \
    ../../Projects/ProjectGtst/serverstatevoting.cpp \
    ../../Projects/ProjectGtst/serverstatewaiting.cpp \
    ../../Projects/ProjectGtst/state.cpp \
    ../../Projects/ProjectGtst/test.cpp \
    ../../Projects/ProjectGtst/testparameterparsing.cpp \
    ../../Projects/ProjectGtst/testparameters.cpp \
    ../../Projects/ProjectGtst/testparticipant.cpp \
    ../../Projects/ProjectGtst/teststate.cpp \
    ../../Projects/ProjectGtst/vote.cpp \
    ../../Projects/ProjectGtst/votingoption.cpp \
    ../../Projects/RichelbilderbeekNl/qtrichelbilderbeekgalleryresources.cpp \
    richelbilderbeekmenudialog.cpp \
    ../../Tools/ToolAsciiArter/asciiartermaindialog.cpp \
    ../../Tools/ToolAsciiArter/asciiartermenudialog.cpp \
    ../../Tools/ToolAsciiArter/wtasciiartermaindialog.cpp \
    ../../Tools/ToolCodeToHtml/codetohtmlmenudialog.cpp \
    ../../Tools/ToolCodeToHtml/wtcodetohtmldialog.cpp \
    ../../Tools/ToolCodeToHtml/wtcodetohtmlmenudialog.cpp \
    ../../Tools/ToolCreateQtProjectZipFile/createqtprojectzipfilemenudialog.cpp \
    ../../Tools/ToolCreateQtProjectZipFile/createqtprojectzipfilepath.cpp \
    ../../Tools/ToolHometrainer/hometrainermenudialog.cpp \
    ../../Tools/ToolHometrainer/hometrainerresources.cpp \
    ../../Tools/ToolHometrainer/wthometrainerloadexercisedialog.cpp \
    ../../Tools/ToolHometrainer/wthometrainermenudialog.cpp \
    ../../Tools/ToolHometrainer/wthometrainerstartexercisedialog.cpp \
    ../../Tools/ToolHometrainer/wtselecthometrainerfiledialog.cpp \
    ../../Tools/ToolRandomCode/randomcodemenudialog.cpp \
    ../../Tools/ToolRandomCode/wtrandomcodegeneratedialog.cpp \
    ../../Tools/ToolRandomCode/wtrandomcodemenudialog.cpp \
    ../../Tools/ToolSimMysteryMachine/simmysterymachinemenudialog.cpp \
    ../../Tools/ToolSimMysteryMachine/wtsimmysterymachinemaindialog.cpp \
    ../../Tools/ToolSimMysteryMachine/wtsimmysterymachinemenudialog.cpp \
    ../../Tools/ToolTestDial/testdialmenudialog.cpp \
    ../../Tools/ToolTestDial/wttestdialmaindialog.cpp \
    ../../Tools/ToolTestDial/wttestdialmenudialog.cpp \
    ../../Tools/ToolTestEncranger/testencrangerdialog.cpp \
    ../../Tools/ToolTestEncranger/wttestencrangermaindialog.cpp \
    ../../Tools/ToolTestEncranger/wttestencrangermenudialog.cpp \
    ../../Tools/ToolTestEntrance/testentrancemenudialog.cpp \
    ../../Tools/ToolTestEntrance/wttestentrancemaindialog.cpp \
    ../../Tools/ToolTestEntrance/wttestentrancemenudialog.cpp \
    ../../Tools/ToolTestExercise/testexercisemenudialog.cpp \
    ../../Tools/ToolTestExercise/wttestexercisemaindialog.cpp \
    ../../Tools/ToolTestExercise/wttestexercisemenudialog.cpp \
    ../../Tools/ToolTestFunctionParser/testfunctionparsermenudialog.cpp \
    ../../Tools/ToolTestFunctionParser/wttestfunctionparsermaindialog.cpp \
    ../../Tools/ToolTestFunctionParser/wttestfunctionparsermenudialog.cpp \
    ../../Tools/ToolTestGroupWidget/testgroupwidgetmenudialog.cpp \
    ../../Tools/ToolTestGroupWidget/wttestgroupwidgetmaindialog.cpp \
    ../../Tools/ToolTestGroupWidget/wttestgroupwidgetmenudialog.cpp \
    ../../Tools/ToolTestLed/testledmenudialog.cpp \
    ../../Tools/ToolTestLed/wttestledmaindialog.cpp \
    ../../Tools/ToolTestLed/wttestledmenudialog.cpp \
    ../../Tools/ToolTestNewickVector/testnewickvectordialog.cpp \
    ../../Tools/ToolTestNewickVector/wttestnewickvectordialog.cpp \
    ../../Tools/ToolTestQrcFile/testqrcfilemenudialog.cpp \
    ../../Tools/ToolTestQtCreatorProFile/testqtcreatorprofilemenudialog.cpp \
    ../../Tools/ToolTestQuestion/testquestionmaindialog.cpp \
    ../../Tools/ToolTestQuestion/testquestionmenudialog.cpp \
    ../../Tools/ToolTestQuestion/wttestquestionmaindialog.cpp \
    ../../Tools/ToolTestQuestion/wttestquestionmenudialog.cpp \
    ../../Tools/ToolTestSelectFileDialog/wttestselectfiledialogmaindialog.cpp \
    ../../Tools/ToolTestSelectFileDialog/wttestselectfiledialogmenudialog.cpp \
    ../../Tools/ToolTestServerPusher/testserverpusherdata.cpp \
    ../../Tools/ToolTestServerPusher/testserverpushermenudialog.cpp \
    ../../Tools/ToolTestServerPusher/testserverpusherwtmaindialog.cpp \
    ../../Tools/ToolTestServerPusher/testserverpusherwtmenudialog.cpp \
    ../../Tools/ToolTestShape/testshapemaindialog.cpp \
    ../../Tools/ToolTestShape/testshapemenudialog.cpp \
    ../../Tools/ToolTestShape/wttestshapemaindialog.cpp \
    ../../Tools/ToolTestShape/wttestshapemenudialog.cpp \
    ../../Tools/ToolTestShinyButton/testshinybuttonmenudialog.cpp \
    ../../Tools/ToolTestShinyButton/wttestshinybuttonmaindialog.cpp \
    ../../Tools/ToolTestShinyButton/wttestshinybuttonmenudialog.cpp \
    ../../Tools/ToolTestTimedServerPusher/testtimedserverpusherdata.cpp \
    ../../Tools/ToolTestTimedServerPusher/testtimedserverpushermenudialog.cpp \
    ../../Tools/ToolTestTimedServerPusher/testtimedserverpusherwtmaindialog.cpp \
    ../../Tools/ToolTestTimedServerPusher/testtimedserverpusherwtmenudialog.cpp \
    ../../Tools/ToolTestToggleButton/testtogglebuttonmenudialog.cpp \
    ../../Tools/ToolTestToggleButton/wttesttogglebuttonmaindialog.cpp \
    ../../Tools/ToolTestToggleButton/wttesttogglebuttonmenudialog.cpp \
    ../../Tools/ToolTestTwoDigitNewick/wttesttwodigitnewickdialog.cpp \
    ../../Tools/ToolTimePoll/timepolldata.cpp \
    ../../Tools/ToolTimePoll/timepollmenudialog.cpp \
    ../../Tools/ToolTimePoll/timepollwtmaindialog.cpp \
    ../../Tools/ToolTimePoll/timepollwtmenudialog.cpp \
    wtmain.cpp \
    wtrichelbilderbeekadmindialog.cpp \
    wtrichelbilderbeekmenudialog.cpp \
    wtrichelbilderbeekmenuitem.cpp \
    ../../Classes/CppMatrix/matrix.cpp \
    ../../Tools/ToolRegexTester/regextestertr1maindialog.cpp \
    ../../Tools/ToolRegexTester/regextesterqtmaindialog.cpp \
    ../../Tools/ToolRegexTester/regextestermenudialog.cpp \
    ../../Tools/ToolRegexTester/regextestermaindialog.cpp \
    ../../Tools/ToolRegexTester/regextestercpp11maindialog.cpp \
    ../../Tools/ToolRegexTester/regextesterboostregexmaindialog.cpp \
    ../../Tools/ToolRegexTester/regextesterboostxpressivemaindialog.cpp \
    ../../Classes/CppRichelBilderbeekProgram/richelbilderbeekprogramtype.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemtypes.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemtype.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemparametertype.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemparameters.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemparameter.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystemfactory.cpp \
    ../../Classes/CppKalmanFilter/whitenoisesystem.cpp \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilterparameters.cpp \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilterfactory.cpp \
    ../../Classes/CppKalmanFilter/steadystatekalmanfiltercalculationelements.cpp \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilter.cpp \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystemparameters.cpp \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystemfactory.cpp \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystem.cpp \
    ../../Classes/CppKalmanFilter/standardkalmanfilterparameters.cpp \
    ../../Classes/CppKalmanFilter/standardkalmanfilterfactory.cpp \
    ../../Classes/CppKalmanFilter/standardkalmanfiltercalculationelements.cpp \
    ../../Classes/CppKalmanFilter/standardkalmanfilter.cpp \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystemparameters.cpp \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystemfactory.cpp \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystem.cpp \
    ../../Classes/CppKalmanFilter/kalmanfiltertypes.cpp \
    ../../Classes/CppKalmanFilter/kalmanfiltertype.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterparametertype.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterparameters.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterparameter.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterfactory.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterexperimentparametertype.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterexperimentparameter.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterexperiment.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilterexample.cpp \
    ../../Classes/CppKalmanFilter/kalmanfiltercalculationelementsfactory.cpp \
    ../../Classes/CppKalmanFilter/kalmanfiltercalculationelements.cpp \
    ../../Classes/CppKalmanFilter/kalmanfilter.cpp \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilterparameters.cpp \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilterfactory.cpp \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfiltercalculationelements.cpp \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilter.cpp \
    ../../Classes/CppGaborFilter/gaborfilter.cpp \
    ../../Classes/CppGaborFilterWidget/gaborfilterwidget.cpp \
    ../../Classes/CppStateObserver/multiintegerstateobserver.cpp \
    ../../Classes/CppStateObserver/multialphafilter.cpp \
    ../../Classes/CppStateObserver/integersymmetricalphafilter.cpp \
    ../../Classes/CppStateObserver/integerstateobserver.cpp \
    ../../Classes/CppStateObserver/integeralphafilter.cpp \
    ../../Classes/CppStateObserver/floatingpointstateobserver.cpp \
    ../../Classes/CppStateObserver/alphafilter.cpp \
    ../../Classes/CppStateObserver/alphabetagammafilter.cpp \
    ../../Classes/CppStateObserver/alphabetafilter.cpp \
    ../../Tools/ToolStateObserver/stateobservermenudialog.cpp \
    ../../Tools/ToolStateObserver/noisefunctionparser.cpp \
    ../../Games/GamePylos/pylosmenudialog.cpp \
    ../../Classes/CppQtModel/modelfunctionparser.cpp \
    ../../Classes/CppPylos/pyloswinner.cpp \
    ../../Classes/CppPylos/pylospositionstate.cpp \
    ../../Classes/CppPylos/pylosplayer.cpp \
    ../../Classes/CppPylos/pylosmustremovestate.cpp \
    ../../Classes/CppPylos/pylosmove.cpp \
    ../../Classes/CppPylos/pylosgame.cpp \
    ../../Classes/CppPylos/pyloscurrentmovestate.cpp \
    ../../Classes/CppPylos/pyloscoordinat.cpp \
    ../../Classes/CppPylos/pylosboard.cpp \
    ../../Classes/CppKalmanFilter/gapsfilledwhitenoisesystemparameters.cpp \
    ../../Classes/CppKalmanFilter/gapsfilledwhitenoisesystemfactory.cpp \
    ../../Classes/CppKalmanFilter/gapsfilledwhitenoisesystem.cpp

HEADERS += \
    ../../Classes/CppAbout/about.h \
    ../../Classes/CppAsciiArter/asciiarter.h \
    ../../Classes/CppAssert/assert.h \
    ../../Classes/CppBinaryNewickVector/binarynewickvector.h \
    ../../Classes/CppCodeToHtml/codetohtmlcontent.h \
    ../../Classes/CppCodeToHtml/codetohtmlcontenttype.h \
    ../../Classes/CppCodeToHtml/codetohtmlcreateemptypagedialog.h \
    ../../Classes/CppCodeToHtml/codetohtmldialog.h \
    ../../Classes/CppCodeToHtml/codetohtmlfooter.h \
    ../../Classes/CppCodeToHtml/codetohtml.h \
    ../../Classes/CppCodeToHtml/codetohtmlheader.h \
    ../../Classes/CppCodeToHtml/codetohtmlinfo.h \
    ../../Classes/CppCodeToHtml/codetohtmlpagetype.h \
    ../../Classes/CppCodeToHtml/codetohtmlreplacements.h \
    ../../Classes/CppCodeToHtml/codetohtmltechinfo.h \
    ../../Classes/CppCodeToHtml/codetohtmltechinfotype.h \
    ../../Classes/CppCodeToHtml/codetohtmlversion.h \
    ../../Classes/CppConnectThree/connectthree.h \
    ../../Classes/CppConnectThreeWidget/connectthreewidget.h \
    ../../Classes/CppCounter/counter.h \
    ../../Classes/CppDial/dial.h \
    ../../Classes/CppDialWidget/dialwidget.h \
    ../../Classes/CppEncranger/encranger.h \
    ../../Classes/CppExercise/exercise.h \
    ../../Classes/CppFuzzy_equal_to/fuzzy_equal_to.h \
    ../../Classes/CppHtmlPage/htmlpage.h \
    ../../Classes/CppIpAddress/ipaddress.h \
    ../../Classes/CppLed/led.h \
    ../../Classes/CppLedWidget/ledwidget.h \
    ../../Classes/CppLoopReader/loopreader.h \
    ../../Classes/CppManyDigitNewick/manydigitnewickcoordinat.h \
    ../../Classes/CppManyDigitNewick/manydigitnewickderivative.h \
    ../../Classes/CppManyDigitNewick/manydigitnewick.h \
    ../../Classes/CppManyDigitNewick/manydigitnewickindexer.h \
    ../../Classes/CppManyDigitNewick/manydigitnewickindextable.h \
    ../../Classes/CppManyDigitNewick/manydigitnewicks.h \
    ../../Classes/CppMultipleChoiceQuestionDialog/multiplechoicequestiondialog.h \
    ../../Classes/CppMultipleChoiceQuestion/multiplechoicequestion.h \
    ../../Classes/CppMultiVector/multivector.h \
    ../../Classes/CppMusic/musicchord.h \
    ../../Classes/CppMusic/musicnote.h \
    ../../Classes/CppMusic/musicscale.h \
    ../../Classes/CppMysteryMachine/mysterymachine.h \
    ../../Classes/CppMysteryMachineWidget/mysterymachinewidget.h \
    ../../Classes/CppNewick/newickcpp98.h \
    ../../Classes/CppNewick/newick.h \
    ../../Classes/CppNewick/newickstorage.h \
    ../../Classes/CppNewickVector/newickvector.h \
    ../../Classes/CppOpenQuestionDialog/openquestiondialog.h \
    ../../Classes/CppOpenQuestion/openquestion.h \
    ../../Classes/CppQrcFile/qrcfile.h \
    ../../Classes/CppQtCreatorProFile/qtcreatorprofile.h \
    ../../Classes/CppQtCreatorProFile/qtcreatorprofilezipscript.h \
    ../../Classes/CppQuestionDialog/questiondialog.h \
    ../../Classes/CppQuestion/question.h \
    ../../Classes/CppRainbow/rainbow.h \
    ../../Classes/CppRandomCode/randomcode.h \
    ../../Classes/CppRectangle/rectangle.h \
    ../../Classes/CppRichelBilderbeekProgram/richelbilderbeekprogram.h \
    ../../Classes/CppRichelBilderbeekProgram/richelbilderbeekprogramstatus.h \
    ../../Classes/CppRubiksClock/rubiksclock.h \
    ../../Classes/CppRubiksClockWidget/rubiksclockdial.h \
    ../../Classes/CppRubiksClockWidget/rubiksclockdialwidget.h \
    ../../Classes/CppRubiksClockWidget/rubiksclockwidget.h \
    ../../Classes/CppShape/shape.h \
    ../../Classes/CppShapeWidget/shapewidget.h \
    ../../Classes/CppShinyButton/shinybutton.h \
    ../../Classes/CppShinyButtonWidget/shinybuttonwidget.h \
    ../../Classes/CppSortedBinaryNewickVector/sortedbinarynewickvector.h \
    ../../Classes/CppStopwatch/stopwatch.h \
    ../../Classes/CppTicTacToe/tictactoe.h \
    ../../Classes/CppToggleButton/togglebutton.h \
    ../../Classes/CppToggleButtonWidget/togglebuttonwidget.h \
    ../../Classes/CppTrace/trace.h \
    ../../Classes/CppTwoDigitNewick/twodigitnewickderivative.h \
    ../../Classes/CppTwoDigitNewick/twodigitnewick.h \
    ../../Classes/CppTwoDigitNewick/twodigitnewickindexer.h \
    ../../Classes/CppTwoDigitNewick/twodigitnewickindextable.h \
    ../../Classes/CppTwoDigitNewick/twodigitnewicks.h \
    ../../Classes/CppWidget/widget.h \
    ../../Classes/CppWtAboutDialog/wtaboutdialog.h \
    ../../Classes/CppWtAutoConfig/wtautoconfig.h \
    ../../Classes/CppWtConnectThreeWidget/wtconnectthreewidget.h \
    ../../Classes/CppWtDialWidget/wtdialwidget.h \
    ../../Classes/CppWtEntrance/wtentrance.h \
    ../../Classes/CppWtExercise/wtexercise.h \
    ../../Classes/CppWtGroupWidget/wtgroupwidget.h \
    ../../Classes/CppWtLedWidget/wtledwidget.h \
    ../../Classes/CppWtMultipleChoiceQuestionDialog/wtmultiplechoicequestiondialog.h \
    ../../Classes/CppWtMysteryMachineWidget/wtmysterymachinewidget.h \
    ../../Classes/CppWtOpenQuestionDialog/wtopenquestiondialog.h \
    ../../Classes/CppWtQuestionDialog/wtquestiondialog.h \
    ../../Classes/CppWtRichelBilderbeekGalleryDialog/wtrichelbilderbeekgallerydialog.h \
    ../../Classes/CppWtRubiksClockWidget/wtrubiksclockwidget.h \
    ../../Classes/CppWtSelectFileDialog/wtselectfiledialog.h \
    ../../Classes/CppWtServerPusher/wtserverpusherclient.h \
    ../../Classes/CppWtServerPusher/wtserverpusher.h \
    ../../Classes/CppWtShapeGroupWidget/wtshapegroupwidget.h \
    ../../Classes/CppWtShapeWidget/wtshapewidget.h \
    ../../Classes/CppWtShinyButtonWidget/wtshinybuttonwidget.h \
    ../../Classes/CppWtTicTacToeWidget/wttictactoewidget.h \
    ../../Classes/CppWtTimedServerPusher/wttimedserverpusherclient.h \
    ../../Classes/CppWtTimedServerPusher/wttimedserverpusher.h \
    ../../Classes/CppWtToggleButtonWidget/wttogglebuttonwidget.h \
    ../../Games/GameConnectThree/connectthreemenudialog.h \
    ../../Games/GameConnectThree/connectthreeresources.h \
    ../../Games/GameConnectThree/wtconnectthreegamedialog.h \
    ../../Games/GameConnectThree/wtconnectthreemenudialog.h \
    ../../Games/GameConnectThree/wtconnectthreeresources.h \
    ../../Games/GameConnectThree/wtselectplayerwidget.h \
    ../../Games/GameRubiksClock/rubiksclockmenudialog.h \
    ../../Games/GameRubiksClock/wtrubiksclockmaindialog.h \
    ../../Games/GameRubiksClock/wtrubiksclockmenudialog.h \
    ../../Games/GameTicTacToe/tictactoemenudialog.h \
    ../../Games/GameTicTacToe/wttictactoegamedialog.h \
    ../../Games/GameTicTacToe/wttictactoemenudialog.h \
    ../../Projects/ProjectGtst/administratordialog.h \
    ../../Projects/ProjectGtst/administratordialogstate.h \
    ../../Projects/ProjectGtst/administratordialogstateloggedin.h \
    ../../Projects/ProjectGtst/administratordialogstatenotloggedin.h \
    ../../Projects/ProjectGtst/administrator.h \
    ../../Projects/ProjectGtst/administrators.h \
    ../../Projects/ProjectGtst/all_groups.h \
    ../../Projects/ProjectGtst/all_parameters.h \
    ../../Projects/ProjectGtst/all_participantdialogstates.h \
    ../../Projects/ProjectGtst/all_participantstates.h \
    ../../Projects/ProjectGtst/all_serverstates.h \
    ../../Projects/ProjectGtst/chatmessage.h \
    ../../Projects/ProjectGtst/chatshapefactory.h \
    ../../Projects/ProjectGtst/chooseactionoption.h \
    ../../Projects/ProjectGtst/debugdialog.h \
    ../../Projects/ProjectGtst/forward_declarations.h \
    ../../Projects/ProjectGtst/groupassigner.h \
    ../../Projects/ProjectGtst/groupfinished.h \
    ../../Projects/ProjectGtst/group.h \
    ../../Projects/ProjectGtst/grouploggedin.h \
    ../../Projects/ProjectGtst/groupnotloggedin.h \
    ../../Projects/ProjectGtst/groupparticipating.h \
    ../../Projects/ProjectGtst/groups.h \
    ../../Projects/ProjectGtst/logfile.h \
    ../../Projects/ProjectGtst/parametersassignpayoff.h \
    ../../Projects/ProjectGtst/parameterschat.h \
    ../../Projects/ProjectGtst/parameterschooseaction.h \
    ../../Projects/ProjectGtst/parametersfinished.h \
    ../../Projects/ProjectGtst/parametersgroupassign.h \
    ../../Projects/ProjectGtst/parametersgroupreassign.h \
    ../../Projects/ProjectGtst/parameters.h \
    ../../Projects/ProjectGtst/parametersquiz.h \
    ../../Projects/ProjectGtst/parametersviewresultsall.h \
    ../../Projects/ProjectGtst/parametersviewresultsgroup.h \
    ../../Projects/ProjectGtst/parametersviewresultsvoting.h \
    ../../Projects/ProjectGtst/parametersvoting.h \
    ../../Projects/ProjectGtst/participantdialog.h \
    ../../Projects/ProjectGtst/participantdialogstateassignpayoff.h \
    ../../Projects/ProjectGtst/participantdialogstatechat.h \
    ../../Projects/ProjectGtst/participantdialogstatechooseaction.h \
    ../../Projects/ProjectGtst/participantdialogstatefinished.h \
    ../../Projects/ProjectGtst/participantdialogstategroupassign.h \
    ../../Projects/ProjectGtst/participantdialogstategroupreassign.h \
    ../../Projects/ProjectGtst/participantdialogstate.h \
    ../../Projects/ProjectGtst/participantdialogstateloggedin.h \
    ../../Projects/ProjectGtst/participantdialogstatenotloggedin.h \
    ../../Projects/ProjectGtst/participantdialogstatequiz.h \
    ../../Projects/ProjectGtst/participantdialogstates.h \
    ../../Projects/ProjectGtst/participantdialogstateviewresultsgroup.h \
    ../../Projects/ProjectGtst/participantdialogstateviewresultsvoting.h \
    ../../Projects/ProjectGtst/participantdialogstatevoting.h \
    ../../Projects/ProjectGtst/participant.h \
    ../../Projects/ProjectGtst/participantstateassignpayoff.h \
    ../../Projects/ProjectGtst/participantstatechat.h \
    ../../Projects/ProjectGtst/participantstatechooseaction.h \
    ../../Projects/ProjectGtst/participantstatefinished.h \
    ../../Projects/ProjectGtst/participantstategroupassign.h \
    ../../Projects/ProjectGtst/participantstategroupreassign.h \
    ../../Projects/ProjectGtst/participantstate.h \
    ../../Projects/ProjectGtst/participantstateloggedin.h \
    ../../Projects/ProjectGtst/participantstatenotloggedin.h \
    ../../Projects/ProjectGtst/participantstatequiz.h \
    ../../Projects/ProjectGtst/participantstateviewresultsgroup.h \
    ../../Projects/ProjectGtst/participantstateviewresultsvoting.h \
    ../../Projects/ProjectGtst/participantstatevoting.h \
    ../../Projects/ProjectGtst/payoff.h \
    ../../Projects/ProjectGtst/payoffs.h \
    ../../Projects/ProjectGtst/projectgtstmenudialog.h \
    ../../Projects/ProjectGtst/repeatassignerfixed.h \
    ../../Projects/ProjectGtst/repeatassigner.h \
    ../../Projects/ProjectGtst/repeatassignerrandomgeometric.h \
    ../../Projects/ProjectGtst/repeatassignerrandomuniform.h \
    ../../Projects/ProjectGtst/resources.h \
    ../../Projects/ProjectGtst/server.h \
    ../../Projects/ProjectGtst/serverstateassignpayoff.h \
    ../../Projects/ProjectGtst/serverstatechat.h \
    ../../Projects/ProjectGtst/serverstatechooseaction.h \
    ../../Projects/ProjectGtst/serverstatefinished.h \
    ../../Projects/ProjectGtst/serverstategroupassign.h \
    ../../Projects/ProjectGtst/serverstategroupreassign.h \
    ../../Projects/ProjectGtst/serverstate.h \
    ../../Projects/ProjectGtst/serverstatequiz.h \
    ../../Projects/ProjectGtst/serverstates.h \
    ../../Projects/ProjectGtst/serverstateviewresultsgroup.h \
    ../../Projects/ProjectGtst/serverstateviewresultsvoting.h \
    ../../Projects/ProjectGtst/serverstatevoting.h \
    ../../Projects/ProjectGtst/serverstatewaiting.h \
    ../../Projects/ProjectGtst/state.h \
    ../../Projects/ProjectGtst/test.h \
    ../../Projects/ProjectGtst/vote.h \
    ../../Projects/ProjectGtst/votingoption.h \
    ../../Projects/RichelbilderbeekNl/qtrichelbilderbeekgalleryresources.h \
    richelbilderbeekmenudialog.h \
    ../../Tools/ToolAsciiArter/asciiartermaindialog.h \
    ../../Tools/ToolAsciiArter/asciiartermenudialog.h \
    ../../Tools/ToolAsciiArter/wtasciiartermaindialog.h \
    ../../Tools/ToolCodeToHtml/codetohtmlmenudialog.h \
    ../../Tools/ToolCodeToHtml/wtcodetohtmldialog.h \
    ../../Tools/ToolCodeToHtml/wtcodetohtmlmenudialog.h \
    ../../Tools/ToolCreateQtProjectZipFile/createqtprojectzipfilemenudialog.h \
    ../../Tools/ToolCreateQtProjectZipFile/createqtprojectzipfilepath.h \
    ../../Tools/ToolHometrainer/hometrainermenudialog.h \
    ../../Tools/ToolHometrainer/hometrainerresources.h \
    ../../Tools/ToolHometrainer/wthometrainerloadexercisedialog.h \
    ../../Tools/ToolHometrainer/wthometrainermenudialog.h \
    ../../Tools/ToolHometrainer/wthometrainerstartexercisedialog.h \
    ../../Tools/ToolHometrainer/wtselecthometrainerfiledialog.h \
    ../../Tools/ToolRandomCode/randomcodemenudialog.h \
    ../../Tools/ToolRandomCode/wtrandomcodegeneratedialog.h \
    ../../Tools/ToolRandomCode/wtrandomcodemenudialog.h \
    ../../Tools/ToolSimMysteryMachine/simmysterymachinemenudialog.h \
    ../../Tools/ToolSimMysteryMachine/wtsimmysterymachinemaindialog.h \
    ../../Tools/ToolSimMysteryMachine/wtsimmysterymachinemenudialog.h \
    ../../Tools/ToolTestDial/testdialmenudialog.h \
    ../../Tools/ToolTestDial/wttestdialmaindialog.h \
    ../../Tools/ToolTestDial/wttestdialmenudialog.h \
    ../../Tools/ToolTestEncranger/testencrangerdialog.h \
    ../../Tools/ToolTestEncranger/wttestencrangermaindialog.h \
    ../../Tools/ToolTestEncranger/wttestencrangermenudialog.h \
    ../../Tools/ToolTestEntrance/testentrancemenudialog.h \
    ../../Tools/ToolTestEntrance/wttestentrancemaindialog.h \
    ../../Tools/ToolTestEntrance/wttestentrancemenudialog.h \
    ../../Tools/ToolTestExercise/testexercisemenudialog.h \
    ../../Tools/ToolTestExercise/wttestexercisemaindialog.h \
    ../../Tools/ToolTestExercise/wttestexercisemenudialog.h \
    ../../Tools/ToolTestFunctionParser/testfunctionparsermenudialog.h \
    ../../Tools/ToolTestFunctionParser/wttestfunctionparsermaindialog.h \
    ../../Tools/ToolTestFunctionParser/wttestfunctionparsermenudialog.h \
    ../../Tools/ToolTestGroupWidget/testgroupwidgetmenudialog.h \
    ../../Tools/ToolTestGroupWidget/wttestgroupwidgetmaindialog.h \
    ../../Tools/ToolTestGroupWidget/wttestgroupwidgetmenudialog.h \
    ../../Tools/ToolTestLed/testledmenudialog.h \
    ../../Tools/ToolTestLed/wttestledmaindialog.h \
    ../../Tools/ToolTestLed/wttestledmenudialog.h \
    ../../Tools/ToolTestNewickVector/testnewickvectordialog.h \
    ../../Tools/ToolTestNewickVector/wttestnewickvectordialog.h \
    ../../Tools/ToolTestQrcFile/testqrcfilemenudialog.h \
    ../../Tools/ToolTestQtCreatorProFile/testqtcreatorprofilemenudialog.h \
    ../../Tools/ToolTestQuestion/testquestionmaindialog.h \
    ../../Tools/ToolTestQuestion/testquestionmenudialog.h \
    ../../Tools/ToolTestQuestion/wttestquestionmaindialog.h \
    ../../Tools/ToolTestQuestion/wttestquestionmenudialog.h \
    ../../Tools/ToolTestSelectFileDialog/wttestselectfiledialogmaindialog.h \
    ../../Tools/ToolTestSelectFileDialog/wttestselectfiledialogmenudialog.h \
    ../../Tools/ToolTestServerPusher/testserverpusherdata.h \
    ../../Tools/ToolTestServerPusher/testserverpushermenudialog.h \
    ../../Tools/ToolTestServerPusher/testserverpusherwtmaindialog.h \
    ../../Tools/ToolTestServerPusher/testserverpusherwtmenudialog.h \
    ../../Tools/ToolTestShape/testshapemaindialog.h \
    ../../Tools/ToolTestShape/testshapemenudialog.h \
    ../../Tools/ToolTestShape/wttestshapemaindialog.h \
    ../../Tools/ToolTestShape/wttestshapemenudialog.h \
    ../../Tools/ToolTestShinyButton/testshinybuttonmenudialog.h \
    ../../Tools/ToolTestShinyButton/wttestshinybuttonmaindialog.h \
    ../../Tools/ToolTestShinyButton/wttestshinybuttonmenudialog.h \
    ../../Tools/ToolTestTimedServerPusher/testtimedserverpusherdata.h \
    ../../Tools/ToolTestTimedServerPusher/testtimedserverpushermenudialog.h \
    ../../Tools/ToolTestTimedServerPusher/testtimedserverpusherwtmaindialog.h \
    ../../Tools/ToolTestTimedServerPusher/testtimedserverpusherwtmenudialog.h \
    ../../Tools/ToolTestToggleButton/testtogglebuttonmenudialog.h \
    ../../Tools/ToolTestToggleButton/wttesttogglebuttonmaindialog.h \
    ../../Tools/ToolTestToggleButton/wttesttogglebuttonmenudialog.h \
    ../../Tools/ToolTestTwoDigitNewick/wttesttwodigitnewickdialog.h \
    ../../Tools/ToolTimePoll/timepolldata.h \
    ../../Tools/ToolTimePoll/timepollmenudialog.h \
    ../../Tools/ToolTimePoll/timepollwtmaindialog.h \
    ../../Tools/ToolTimePoll/timepollwtmenudialog.h \
    wtrichelbilderbeekadmindialog.h \
    wtrichelbilderbeekmenudialog.h \
    wtrichelbilderbeekmenuitem.h \
    ../../Classes/CppMatrix/matrix.h \
    ../../Tools/ToolRegexTester/regextestertr1maindialog.h \
    ../../Tools/ToolRegexTester/regextesterqtmaindialog.h \
    ../../Tools/ToolRegexTester/regextestermenudialog.h \
    ../../Tools/ToolRegexTester/regextestermaindialog.h \
    ../../Tools/ToolRegexTester/regextestercpp11maindialog.h \
    ../../Tools/ToolRegexTester/regextesterboostregexmaindialog.h \
    ../../Tools/ToolRegexTester/regextesterboostxpressivemaindialog.h \
    ../../Classes/CppRichelBilderbeekProgram/richelbilderbeekprogramtype.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemtypes.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemtype.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemparametertype.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemparameters.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemparameter.h \
    ../../Classes/CppKalmanFilter/whitenoisesystemfactory.h \
    ../../Classes/CppKalmanFilter/whitenoisesystem.h \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilterparameters.h \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilterfactory.h \
    ../../Classes/CppKalmanFilter/steadystatekalmanfiltercalculationelements.h \
    ../../Classes/CppKalmanFilter/steadystatekalmanfilter.h \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystemparameters.h \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystemfactory.h \
    ../../Classes/CppKalmanFilter/standardwhitenoisesystem.h \
    ../../Classes/CppKalmanFilter/standardkalmanfilterparameters.h \
    ../../Classes/CppKalmanFilter/standardkalmanfilterfactory.h \
    ../../Classes/CppKalmanFilter/standardkalmanfiltercalculationelements.h \
    ../../Classes/CppKalmanFilter/standardkalmanfilter.h \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystemparameters.h \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystemfactory.h \
    ../../Classes/CppKalmanFilter/laggedwhitenoisesystem.h \
    ../../Classes/CppKalmanFilter/kalmanfiltertypes.h \
    ../../Classes/CppKalmanFilter/kalmanfiltertype.h \
    ../../Classes/CppKalmanFilter/kalmanfilterparametertype.h \
    ../../Classes/CppKalmanFilter/kalmanfilterparameters.h \
    ../../Classes/CppKalmanFilter/kalmanfilterparameter.h \
    ../../Classes/CppKalmanFilter/kalmanfilterfactory.h \
    ../../Classes/CppKalmanFilter/kalmanfilterexperimentparametertype.h \
    ../../Classes/CppKalmanFilter/kalmanfilterexperimentparameter.h \
    ../../Classes/CppKalmanFilter/kalmanfilterexperiment.h \
    ../../Classes/CppKalmanFilter/kalmanfilterexample.h \
    ../../Classes/CppKalmanFilter/kalmanfiltercalculationelementsfactory.h \
    ../../Classes/CppKalmanFilter/kalmanfiltercalculationelements.h \
    ../../Classes/CppKalmanFilter/kalmanfilter.h \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilterparameters.h \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilterfactory.h \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfiltercalculationelements.h \
    ../../Classes/CppKalmanFilter/fixedlagsmootherkalmanfilter.h \
    ../../Classes/CppGaborFilter/gaborfilter.h \
    ../../Classes/CppGaborFilterWidget/gaborfilterwidget.h \
    ../../Classes/CppStateObserver/stateobserverfwd.h \
    ../../Classes/CppStateObserver/multiintegerstateobserver.h \
    ../../Classes/CppStateObserver/multialphafilter.h \
    ../../Classes/CppStateObserver/integersymmetricalphafilter.h \
    ../../Classes/CppStateObserver/integerstateobserver.h \
    ../../Classes/CppStateObserver/integeralphafilter.h \
    ../../Classes/CppStateObserver/floatingpointstateobserver.h \
    ../../Classes/CppStateObserver/alphafilter.h \
    ../../Classes/CppStateObserver/alphabetagammafilter.h \
    ../../Classes/CppStateObserver/alphabetafilter.h \
    ../../Tools/ToolStateObserver/stateobservermenudialog.h \
    ../../Tools/ToolStateObserver/noisefunctionparser.h \
    ../../Games/GamePylos/pylosmenudialog.h \
    ../../Classes/CppQtModel/modelfunctionparser.h \
    ../../Classes/CppPylos/pyloswinner.h \
    ../../Classes/CppPylos/pylospositionstate.h \
    ../../Classes/CppPylos/pylosplayer.h \
    ../../Classes/CppPylos/pylosmustremovestate.h \
    ../../Classes/CppPylos/pylosmove.h \
    ../../Classes/CppPylos/pylosgame.h \
    ../../Classes/CppPylos/pylosfwd.h \
    ../../Classes/CppPylos/pyloscurrentmovestate.h \
    ../../Classes/CppPylos/pyloscoordinat.h \
    ../../Classes/CppPylos/pylosboard.h \
    ../../Classes/CppKalmanFilter/gapsfilledwhitenoisesystemparameters.h \
    ../../Classes/CppKalmanFilter/gapsfilledwhitenoisesystemfactory.h \
    ../../Classes/CppKalmanFilter/gapsfilledwhitenoisesystem.h

RESOURCES += \
    ../../Games/GameConnectThree/GameConnectThree.qrc \
    ../../Games/GameRubiksClock/GameRubiksClock.qrc \
    ../../Tools/ToolCodeToHtml/ToolCodeToHtml.qrc \
    ../../Tools/ToolRandomCode/ToolRandomCode.qrc \
    ../../Tools/ToolSimMysteryMachine/ToolSimMysteryMachine.qrc \
    ../../Tools/ToolTestDial/ToolTestDial.qrc \
    ../../Tools/ToolTestEncranger/ToolTestEncranger.qrc \
    ../../Tools/ToolTestEntrance/ToolTestEntrance.qrc \
    ../../Tools/ToolTestFunctionParser/ToolTestFunctionParser.qrc \
    ../../Tools/ToolTestGroupWidget/ToolTestGroupWidget.qrc \
    ../../Tools/ToolTestLed/ToolTestLed.qrc \
    ../../Tools/ToolTestQuestion/ToolTestQuestion.qrc \
    ../../Tools/ToolTestSelectFileDialog/ToolTestSelectFileDialog.qrc \
    ../../Tools/ToolTestShape/ToolTestShape.qrc \
    ../../Tools/ToolTestToggleButton/ToolTestToggleButton.qrc \
    ../../Projects/ProjectGtst/ProjectGtst.qrc \
    ProjectRichelBilderbeek.qrc \
    ../../Tools/ToolTestShinyButton/ToolTestShinyButton.qrc \
    ../../Tools/ToolTestExercise/ToolTestExercise.qrc \
    ../../Tools/ToolHometrainer/ToolHometrainer.qrc \
    ../../Projects/RichelbilderbeekNl/qtrichelbilderbeekgalleryresources.qrc \
    ../../Tools/ToolAsciiArter/ToolAsciiArter.qrc \
    ../../Tools/ToolStateObserver/ToolStateObserver.qrc \
    ../../Games/GamePylos/GamePylos.qrc

OTHER_FILES += \
    ../../Classes/CppQrcFile/Licence.txt \
    ../../Classes/CppAbout/Licence.txt \
    ../../Classes/CppAsciiArter/Licence.txt \
    ../../Classes/CppBinaryNewickVector/Licence.txt \
    ../../Classes/CppCodeToHtml/Licence.txt \
    ../../Classes/CppConnectThree/Licence.txt \
    ../../Classes/CppConnectThreeWidget/Licence.txt \
    ../../Classes/CppCounter/Licence.txt \
    ../../Classes/CppDial/Licence.txt \
    ../../Classes/CppDialWidget/Licence.txt \
    ../../Classes/CppEncranger/Licence.txt \
    ../../Classes/CppExercise/Licence.txt \
    ../../Classes/CppIpAddress/Licence.txt \
    ../../Classes/CppLazy_init/Licence.txt \
    ../../Classes/CppLed/Licence.txt \
    ../../Classes/CppLedWidget/Licence.txt \
    ../../Classes/CppManyDigitNewick/Licence.txt \
    ../../Classes/CppMultipleChoiceQuestion/Licence.txt \
    ../../Classes/CppMultipleChoiceQuestionDialog/Licence.txt \
    ../../Classes/CppMysteryMachine/Licence.txt \
    ../../Classes/CppMysteryMachineWidget/Licence.txt \
    ../../Classes/CppNewick/Licence.txt \
    ../../Projects/ProjectGtst/TotalExperimentFlow.png \
    ../../Projects/ProjectGtst/RichelbilderbeekNlBackground.png \
    ../../Projects/ProjectGtst/R.png \
    ../../Projects/ProjectGtst/ProjectGtstArchitectureServer.png \
    ../../Projects/ProjectGtst/ProjectGtstArchitectureServer.dia \
    ../../Projects/ProjectGtst/ProjectGtstArchitectureMenuDialog.png \
    ../../Projects/ProjectGtst/ProjectGtstArchitectureMenuDialog.dia \
    ../../Projects/ProjectGtst/ProjectGtst.odp \
    ../../Projects/ProjectGtst/Period_100_58.png \
    ../../Projects/ProjectGtst/Licence.txt \
    ../../Projects/ProjectGtst/IPGG.png \
    ../../Projects/ProjectGtst/helgrind_test_concurrency.sh \
    ../../Projects/ProjectGtst/helgrind.sh \
    ../../Projects/ProjectGtst/gtst_start_and_auto_update.sh \
    ../../Projects/ProjectGtst/Groups.png \
    ../../Projects/ProjectGtst/GroupDynamics_100.png \
    ../../Projects/ProjectGtst/ExperimentFlow.png \
    ../../Projects/ProjectGtst/Experiment_100.png \
    ../../Projects/ProjectGtst/drd.sh \
    ../../Projects/ProjectGtst/Cycle_100.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogVotingParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogVoting2.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogVoting.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogViewResultsVotingParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogViewResultsVoting.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogViewResultsGroupParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogViewResultsGroup.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogNotLoggedInParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogNotLoggedIn.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogLoggedInParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogLoggedIn.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogGroupReAssignParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogGroupReAssign.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogGroupAssignParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogGroupAssign2Parameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogGroupAssign2.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogGroupAssign.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogFinishedParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogFinished.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogChooseActionParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogChooseAction2.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogChooseAction.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogChatParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogChat.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogAssignPayoffParameters.png \
    ../../Projects/ProjectGtst/ProjectGtstParticipantDialogAssignPayoff.png \
    ../../Games/GameRubiksClock/Licence.txt \
    ../../Games/GameRubiksClock/GameRubiksClockWelcomeNoLegend.png \
    ../../Games/GameRubiksClock/GameRubiksClockWelcome_2_1.png \
    ../../Games/GameRubiksClock/GameRubiksClock.png \
    ../../Tools/ToolAsciiArter/RichelbilderbeekNlBackground.png \
    ../../Tools/ToolAsciiArter/R.png \
    ../../Tools/ToolAsciiArter/Licence.txt \
    ../../Tools/ToolAsciiArter/AsciiArter.png \
    ../../Classes/CppHtmlPage/Licence.txt \
    ../../Classes/CppMusic/Licence.txt \
    ../../Classes/CppMatrix/Licence.txt \
    ../../Tools/ToolRegexTester/Licence.txt \
    ../../Classes/CppKalmanFilter/Licence.txt \
    ../../Classes/CppGaborFilter/Licence.txt \
    ../../Classes/CppGaborFilterWidget/Licence.txt \
    ../../Classes/CppStateObserver/Licence.txt \
    ../../Tools/ToolStateObserver/zip.sh \
    ../../Tools/ToolStateObserver/ToolStateObserverWelcome.png \
    ../../Tools/ToolStateObserver/Licence.txt \
    ../../Games/GamePylos/zip.sh \
    ../../Games/GamePylos/sprite_player2_select.png \
    ../../Games/GamePylos/sprite_player2_remove.png \
    ../../Games/GamePylos/sprite_player2.png \
    ../../Games/GamePylos/sprite_player1_select.png \
    ../../Games/GamePylos/sprite_player1_remove.png \
    ../../Games/GamePylos/sprite_player1.png \
    ../../Games/GamePylos/sprite_hole.png \
    ../../Games/GamePylos/R.png \
    ../../Games/GamePylos/PylosSquare.png \
    ../../Games/GamePylos/PylosRemove2.png \
    ../../Games/GamePylos/PylosRemove1.png \
    ../../Games/GamePylos/PylosPlace.png \
    ../../Games/GamePylos/PylosMove.png \
    ../../Games/GamePylos/PylosLine.png \
    ../../Games/GamePylos/PylosGoal2.png \
    ../../Games/GamePylos/PylosGoal1.png \
    ../../Games/GamePylos/Licence.txt \
    ../../Classes/CppQtModel/Licence.txt \
    ../../Classes/CppPylos/Licence.txt



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
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra


unix {
  message(Unix)
  #Strict error handling
  QMAKE_CXXFLAGS += -Werror
}

win32 {
  !static {
    message(Native Windows)
    #Allow native Windows to emit warnings without terminating
    QMAKE_CXXFLAGS += -Werror

  }

  static {
    message(Crosscompiling from Lubuntu to Windows)
    #Allow the crosscompiler to emit warnings without terminating
    QMAKE_CXXFLAGS += -std=c++0x #-Werror
  }


  #Prevents error:
  #/my_boost_folder/boost/type_traits/detail/has_binary_operator.hp:50: Parse error at "BOOST_JOIN"
  #DEFINES += BOOST_TT_HAS_OPERATOR_HPP_INCLUDED
}

#
#
# Boost
#
#

unix {
  message(Unix dynamic link to Boost)

  LIBS += \
  -lboost_date_time \
  -lboost_filesystem \
  -lboost_program_options \
  -lboost_regex \
  -lboost_signals \
  -lboost_system
}

win32 {

  message(Windows dynamic link to Boost)

  INCLUDEPATH += \
    ../../Libraries/boost_1_54_0

  debug {
    LIBS += ../../Libraries/boost_1_54_0/stage/lib/libboost_filesystem-mgw48-mt-d-1_54.a
    LIBS += ../../Libraries/boost_1_54_0/stage/lib/libboost_regex-mgw48-mt-d-1_54.a
    LIBS += ../../Libraries/boost_1_54_0/stage/lib/libboost_system-mgw48-mt-d-1_54.a
  }
  release {
    LIBS += ../../Libraries/boost_1_54_0/stage/lib/libboost_filesystem-mgw48-mt-1_54.a
    LIBS += ../../Libraries/boost_1_54_0/stage/lib/libboost_regex-mgw48-mt-1_54.a
    LIBS += ../../Libraries/boost_1_54_0/stage/lib/libboost_system-mgw48-mt-1_54.a
  }
}

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
  message(Windows: Qwt: link dynamically)
  INCLUDEPATH+= ../../Libraries/qwt-6.1.0/src
  LIBS+= -L../../Libraries/qwt-6.1.0/lib

  CONFIG(release, debug|release) {
    message(Windows: Qwt: Linking to qwt)
    LIBS += -lqwt
  }

  CONFIG(debug, debug|release) {
    message(Windows: Qwt: Linking to qwtd)
    LIBS += -lqwtd
  }
}

#
#
# Warp's function parser
#
#
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

#
#
# Wt
#
#
unix {

  LIBS += \
  -lwt \
  -lwthttp
}
