#!/bin/bash

echo "We clean project ..."
make clean
rm *.bz2
echo "We tar ..."
tar cvf sdatabase_`date +%d%m%y_%H%M`.tar *
echo "We compress ..."
bzip2 sdatabase_`date +%d%m%y_%H%M`.tar 
echo "Archivage sur OceaneDS..."
scp sdatabase_`date +%d%m%y_%H%M`.tar.bz2 192.168.1.102:~/backup/sdatabase/ 
#echo "Archivage sur Thanos..."
#scp sdatabase_`date +%d%m%y_%H%M`.tar.bz2 192.168.1.100:~/backup/ 
#echo "Archivage sur Dell de Laure..."
#scp sdatabase_`date +%d%m%y_%H%M`.tar.bz2 192.168.1.101:~/backup/ 
echo "Fini ..."
