#!/bin/bash
#Script to check the status of native Windows compiles

mytempfile="tmp.txt"
if [ -e $mytempfile ]
then
  rm $mytempfile
fi


for mytest in Boost Cpp0x Cpp11 Qt Qwt World Xpressive
do
myfolder='CppHello'$mytest'QtCreatorWindows'
myscript='CppHello'$mytest'QtCreatorWindows.sh'

if [ ! -d $myfolder ]
then
  echo "Folder '$myfolder' not found"
  continue
fi

cd $myfolder

if [ ! -e $myscript ]
then
  echo "Compile script '$myscript' not found"
  continue
fi

echo $mytest >> ../$mytempfile
./$myscript | egrep "SUCCESS|FAIL" >> ../$mytempfile

cd ..

done

cat $mytempfile | sed 'N;s/\n/: /'
